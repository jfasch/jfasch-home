import os
import tempfile
import shutil
import subprocess
from pathlib import Path


class Submission:
    def __init__(self, tar_name, project_name, library_name):
        self.tar_name = tar_name
        self.project_name = project_name
        self.library_name = library_name

        self.tests_cmakelists_template = """
        ADD_EXECUTABLE(
          run-tests
        
          {testname}
        )
        
        TARGET_LINK_LIBRARIES(
          run-tests
        
          {libname}
          gtest_main 
        )
        """

    def warmup(self):
        self.tempdir = tempfile.TemporaryDirectory(prefix='Submission-')

        workpath = Path(self.tempdir.name)

        self.buildroot = workpath / 'build'
        self.projroot = workpath / self.project_name

        shutil.unpack_archive(self.tar_name, workpath)

        os.mkdir(self.buildroot)
        
        # place empty test in tests/ subdir (so we can uncondidionally
        # register tests/ in toplevel CMakeLists.txt)
        with open(self.projroot / 'tests' / '_warmup_.cpp', 'w') as testf:
            testf.write('// empty')

        with open(self.projroot / 'tests' / 'CMakeLists.txt', 'w') as cmf:
            cmf.write(self.tests_cmakelists_template.format(testname='_warmup_.cpp', libname=self.library_name))

        subprocess.run(['cmake', str(self.projroot)], cwd=self.buildroot)
        subprocess.run(['make'], cwd=self.buildroot)
        subprocess.run([str(self.buildroot / 'tests' / 'run-tests')])

    def evaluate(self, tests):
        results = []
        for name, code, points in tests:
            with open(self.projroot / 'tests' / 'CMakeLists.txt', 'w') as cm:
                cm.write(self.tests_cmakelists_template.format(testname=name+'.cpp', libname=self.library_name))
            if type(code) is str:
                with open(self.projroot / 'tests' / (name + '.cpp'), 'w') as tf:
                    tf.write(code)
            elif isinstance(code, os.PathLike):
                shutil.copyfile(code, self.projroot / 'tests' / (name + '.cpp'))

            completed = subprocess.run(['make'], cwd=self.buildroot)
            if completed.returncode != 0:
                results.append((name, 0, 'make failed'))
                continue
            completed = subprocess.run([str(self.buildroot / 'tests' / 'run-tests')])
            if completed.returncode != 0:
                results.append((name, 0, 'test run failed'))
                continue

            results.append((name, points, 'all well'))

        return results
