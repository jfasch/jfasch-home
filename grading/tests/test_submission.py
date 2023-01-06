from submission import Submission

import os
import os.path
import shutil
from pathlib import Path
import pytest

import signal


toplevel_cm = """
CMAKE_MINIMUM_REQUIRED(VERSION 3.16)
PROJECT(PROJECT-OK)

FIND_PACKAGE(Threads REQUIRED)
set(CMAKE_CXX_STANDARD 20)

if (${CMAKE_COMPILER_IS_GNUCC})
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -g3 -Wall -Werror")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g3 -Wall -Werror")
endif()

ADD_SUBDIRECTORY(googletest)
ADD_SUBDIRECTORY(ok)
ADD_SUBDIRECTORY(tests)
"""

ok_cm = """
ADD_LIBRARY(
  ok

  ok.h
  ok.cpp
)

TARGET_INCLUDE_DIRECTORIES(
  ok  

  PUBLIC
  .
)
"""

ok_h = """
#pragma once
bool ok();
"""
ok_cpp = """
#include "ok.h"
bool ok()
{
    return true;
}
"""

@pytest.fixture
def project_ok_tar(tmpdir):
    projdir = tmpdir / 'PROJECT-OK'
    okdir = projdir / 'ok'
    testdir = projdir / 'tests'
    
    os.mkdir(projdir)
    os.mkdir(okdir)
    os.mkdir(testdir)

    with open(projdir / 'CMakeLists.txt', 'w') as cm:
        cm.write(toplevel_cm)

    shutil.unpack_archive(Path(os.path.dirname(__file__)) / 'googletest-0296d7d37007ec54441cb9f8cd001da6ac58eea8.tar.xz', projdir)

    with open(projdir / 'ok' / 'CMakeLists.txt', 'w') as cm:
        cm.write(ok_cm)
    with open(okdir / 'ok.h', 'w') as h:
        h.write(ok_h)
    with open(okdir / 'ok.cpp', 'w') as cpp:
        cpp.write(ok_cpp)

    yield shutil.make_archive('submission', format='gztar', root_dir=tmpdir, base_dir='PROJECT-OK')

def test_only(project_ok_tar, tmpdir):
    '''
    googletest build takes ages, so we have only one test case for the entire thing.
    will try to extract googletest into a separate project, and have one fixture for the whole suite.
    '''

    with open(tmpdir / 'ok-pass-file--src.cpp', 'w') as f:
        f.write(
            '''
            #include <ok.h>
            #include <gtest/gtest.h>
            TEST(ok_suite, ok_pass_file)
            {
                ASSERT_TRUE(ok());
            }
            '''
        );

    with open(tmpdir / 'ok-fail-file--src.cpp', 'w') as f:
        f.write(
            '''
            #include <ok.h>
            #include <gtest/gtest.h>
            TEST(ok_suite, ok_fail_file)
            {
                ASSERT_FALSE(ok());
            }
            '''
        );

    sm = Submission(
        tar_name=project_ok_tar,
        project_name = 'PROJECT-OK',
        library_name = 'ok',
    )
    
    sm.warmup()
    result = sm.evaluate(tests=[
        # PASS: pass code as string
        (
            'ok-pass-string',
            '''
            #include <ok.h>
            #include <gtest/gtest.h>
            TEST(ok_suite, ok_pass_string)
            {
                ASSERT_TRUE(ok());
            }
            ''',
            5,
        ),
        # PASS: pass code as path
        (
            'ok-pass-file',
            Path(tmpdir / 'ok-pass-file--src.cpp'),
            5,
        ),

        # FAIL: pass code as string
        (
            'ok-fail-string',
            '''
            #include <ok.h>
            #include <gtest/gtest.h>
            TEST(ok_suite, ok_fail_string)
            {
                ASSERT_FALSE(ok());
            }
            ''',
            5,
        ),
        # FAIL: pass code as path
        (
            'ok-fail-file',
            Path(tmpdir / 'ok-fail-file--src.cpp'),
            5,
        ),
    ])


    assert len(result) == 4

    testname, points, comment = result[0]
    assert testname == 'ok-pass-string'
    assert points == 5
    assert type(comment) is str

    testname, points, comment = result[1]
    assert testname == 'ok-pass-file'
    assert points == 5
    assert type(comment) is str

    testname, points, comment = result[2]
    assert testname == 'ok-fail-string'
    assert points == 0
    assert type(comment) is str

    testname, points, comment = result[3]
    assert testname == 'ok-fail-file'
    assert points == 0
    assert type(comment) is str
