from jf.topic.task import Task
from jf.topic.group import Group
from jf.topic.soup import Soup

import unittest


class ProjectPlanTest(unittest.TestCase):
    def test_basic(self):
        soup = Soup()

        task_a = Task(
            title='TaskA', 
            path=('package', 'task_a'), 
            docname='docname-task-a.rst', 
            initial_estimate=0,
            spent=0,
            percent_done=0,
            dependencies=[])
        task_b = Task(
            title='TaskB', 
            path=('package', 'task_b'), 
            docname='docname-task-b.rst', 
            initial_estimate=0,
            spent=0,
            percent_done=0,
            dependencies=['package', 'task_a'])
        
        package = Group(
            title='Workpackage', 
            path=('package',), 
            docname='docname-package.rst')

        soup.add_element(task_a)
        soup.add_element(task_b)
        soup.add_element(package)

        soup.commit()

        self.assertEqual(task_a.parent, package)
        self.assertEqual(task_b.parent, package)
        self.assertEqual(len(package._children), 2)
        self.assertTrue(package.has_element(task_a))
        self.assertTrue(package.has_element(task_b))


suite = unittest.defaultTestLoader.loadTestsFromTestCase(ProjectPlanTest)
