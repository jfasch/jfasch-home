import os
import os.path
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

    def evaluate(self, tests):
        self._prepare_workdir()

        results = self._unpack_tar(tests)
        if results is not None:
            return results

        self._warmup()
        return self._run_tests(tests)

    def _run_tests(self, tests):
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

    def _prepare_workdir(self):
        self.tempdir = tempfile.TemporaryDirectory(prefix='Submission-')

        self.workdir = Path(self.tempdir.name)

        self.buildroot = self.workdir / 'build'
        self.projroot = self.workdir / self.project_name

        os.mkdir(self.buildroot)

    def _unpack_tar(self, tests):
        try:
            shutil.unpack_archive(self.tar_name, self.workdir)
            return None     # all well so far, result not yet clear
        except FileNotFoundError as e:
            results = []
            comment = os.path.basename(self.tar_name) + ' missing'
            for testname, _, _ in tests:
                results.append((testname, 0, comment))
            return results

    def _warmup(self):
        # place empty test in tests/ subdir (so we can uncondidionally
        # register tests/ in toplevel CMakeLists.txt)
        with open(self.projroot / 'tests' / '_warmup_.cpp', 'w') as testf:
            testf.write('// empty')

        with open(self.projroot / 'tests' / 'CMakeLists.txt', 'w') as cmf:
            cmf.write(self.tests_cmakelists_template.format(testname='_warmup_.cpp', libname=self.library_name))

        subprocess.run(['cmake', str(self.projroot)], cwd=self.buildroot)
        subprocess.run(['make'], cwd=self.buildroot)
        subprocess.run([str(self.buildroot / 'tests' / 'run-tests')])

