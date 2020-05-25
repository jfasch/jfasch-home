#!/usr/bin/python3


from distutils.core import setup

setup(
    name="xsv",
    license="GPLv3", url="http://exercise.avl", version='0',
    description="xsv highly sophisticated things", author="Joerg Faschingbauer",
    author_email="jf@faschingbauer.co.at",
    
    packages=[
        'xsv',
    ],
       
    scripts=[
        'scripts/georg.py',
    ],
)
