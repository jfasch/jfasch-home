from submission import Submission
from exam import Exam

import pytest
import csv
import signal


def test_summary(monkeypatch):
    def myevaluate(self, tests):
        return [
            ('test1', 5, 'blah'),
            ('test2', 5, 'blah'),
            ('test3', 5, 'blah'),
        ]

    monkeypatch.setattr(Submission, 'evaluate', myevaluate)

    ex = Exam(
        base_dir = 'irrelevant',
        tar_name = 'irrelevant',
        project_name = 'irrelevant',
        library_name = 'irrelevant',
        
        students = [
            'studentA',
            'studentB',
        ],
        tests = [
            ('test1', 'code here', 5),
            ('test2', 'code here', 5),
            ('test3', 'code here', 5),
        ],
    )

    result = ex.evaluate()
    
    assert len(result) == 2
    
    studentA_result = result[0]
    assert studentA_result.name == 'studentA'
    assert studentA_result.total == 15
    assert len(studentA_result.detail) == 3
    assert studentA_result.detail['test1'] == (5, 'blah')
    assert studentA_result.detail['test2'] == (5, 'blah')
    assert studentA_result.detail['test3'] == (5, 'blah')

    studentB_result = result[1]
    assert studentB_result.name == 'studentB'
    assert studentB_result.total == 15
    assert len(studentB_result.detail) == 3
    assert studentB_result.detail['test1'] == (5, 'blah')
    assert studentB_result.detail['test2'] == (5, 'blah')
    assert studentB_result.detail['test3'] == (5, 'blah')

def test_csv(monkeypatch, tmpdir):
    def myevaluate(self, tests):
        return [
            ('test1', 5, 'well yeah ok'),
            ('test2', 5, 'well yeah ok too'),
            ('test3', 5, 'well also ok'),
        ]

    monkeypatch.setattr(Submission, 'evaluate', myevaluate)

    ex = Exam(
        base_dir = 'irrelevant',
        tar_name = 'irrelevant',
        project_name = 'irrelevant',
        library_name = 'irrelevant',
        
        students = [
            'studentA',
            'studentB',
        ],
        tests = [
            ('test1', 'code here', 5),
            ('test2', 'code here', 5),
            ('test3', 'code here', 5),
        ],
    )

    ex.write_csv(tmpdir / 'exam.csv')

    rdr = csv.DictReader(open(tmpdir / 'exam.csv'), delimiter=';', quotechar='"')
    results = list(rdr)

    assert len(results) == 2

    studentA = results[0]
    assert studentA['Student'] == 'studentA'
    assert studentA['Total'] == '15'
    assert studentA['test1'] == '5'
    assert studentA['test1 comment'] == 'well yeah ok'
    assert studentA['test2'] == '5'
    assert studentA['test2 comment'] == 'well yeah ok too'
    assert studentA['test3'] == '5'
    assert studentA['test3 comment'] == 'well also ok'

    studentB = results[1]
    assert studentB['Student'] == 'studentB'
    assert studentB['Total'] == '15'
    assert studentB['test1'] == '5'
    assert studentB['test1 comment'] == 'well yeah ok'
    assert studentB['test2'] == '5'
    assert studentB['test2 comment'] == 'well yeah ok too'
    assert studentB['test3'] == '5'
    assert studentB['test3 comment'] == 'well also ok'
