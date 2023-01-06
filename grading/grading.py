#!/usr/bin/env python

import sys
import tempfile
import shutil
import os
import signal
import subprocess
from pathlib import Path


basedir = Path(sys.argv[1])
name = Path(sys.argv[2])

testnames = [
    'point_suite-ctor_and_getters',
    'point_suite-ctor_and_getters_const',
    'point_suite-default_ctor',
    'point_suite-equal_method',
    'point_suite-equal_method_const',
    'point_suite-operator_equals',
    'point_suite-operator_equals_const',
    'point_suite-move_method',
    'point_suite-operator_plus_equals',
    'point_suite-add_method',
    'point_suite-add_method_const',
    'point_suite-operator_plus',
    'point_suite-operator_plus_const',
    'circle_suite-ctor_and_getters',
    'circle_suite-ctor_and_getters_using_operator_equals',
    'circle_suite-area',
    'circle_suite-area_const',
    'square_suite-ctor_and_getters',
    'square_suite-ctor_and_getters_using_operator_equals',
    'square_suite-area',
    'square_suite-area_const',
    'shape_suite-circle_is_a_shape',
    'shape_suite-square_is_a_shape',
    'shape_suite-area_is_shape_functionality__circle',
    'shape_suite-area_is_shape_functionality__square',
]

cmakelists_template = """
ADD_EXECUTABLE(
  cxx-exercises-shapes--suite

  {test}
)

TARGET_LINK_LIBRARIES(
  cxx-exercises-shapes--suite

  cxx-exercises-shapes
  gtest_main 
)
"""

def status(msg):
    print('-'*10, msg)

with tempfile.TemporaryDirectory(prefix='LabExam-') as d:
    workpath = Path(d)
    tarpath = basedir / name / 'submission.tar.gz'
    buildroot = workpath / 'build'
    
    os.mkdir(buildroot)

    shutil.unpack_archive(tarpath, workpath)

    projroot = workpath / '2022-12-21-FH-Lab-Exam'

    for testname in testnames:
        status(testname)
        with open(projroot / 'tests' / 'CMakeLists.txt', 'w') as cm:
            cm.write(cmakelists_template.format(test=testname+'.cpp'))

        subprocess.run(['cmake', str(projroot)], cwd=buildroot)
        subprocess.run(['make'], cwd=buildroot)
        subprocess.run([str(buildroot / 'tests' / 'cxx-exercises-shapes--suite')])
