from submission import Submission

from dataclasses import dataclass
import csv
from pathlib import Path

@dataclass
class _StudentResult:
    name: str
    total: int
    detail: dict

class Exam:
    def __init__(self, base_dir, tar_name, project_name, library_name, students, tests):
        self.base_dir = Path(base_dir)
        self.tar_name = tar_name
        self.project_name = project_name
        self.library_name = library_name
        self.students = students
        self.tests = tests

    def evaluate(self):
        all_results = []
        for s in self.students:
            sub = Submission(
                tar_name=self.base_dir / s / self.tar_name,
                project_name=self.project_name,
                library_name=self.library_name,
            )
            test_results = sub.evaluate(self.tests)

            total = 0
            detail = {}
            for testname, points, comment in test_results:
                total += points
                detail[testname] = (points, comment)

            all_results.append(_StudentResult(name = s, total = total, detail = detail))

        return all_results

    def write_csv(self, filename):
        results = self.evaluate()

        fieldnames = ['Student', 'Total']

        for t in self.tests:
            fieldnames.append(t[0])
            fieldnames.append(t[0]+' comment')

        with open(filename, 'w', newline='') as f:
            writer = csv.DictWriter(f, fieldnames, delimiter=';', quotechar='"')
            writer.writeheader()
            for r in results:
                row = {'Student': r.name, 'Total': r.total}
                for testname, (points, comment) in r.detail.items():
                    row[testname] = points
                    row[testname+' comment'] = comment
                writer.writerow(row)
