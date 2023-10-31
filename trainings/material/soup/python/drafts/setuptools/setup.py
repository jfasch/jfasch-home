from setuptools import setup

setup(
    name='python-course-2022-11-07',
    version='0.0.1',
    description='Lotsa coding',

    # long_description='blah',
    # long_description_content_type='text/markdown',

    url='https://company.com',
    author='Joerg Faschingbauer',

    # https://pypi.org/classifiers/
    classifiers=[
        #   3 - Alpha
        #   4 - Beta
        #   5 - Production/Stable
        'Development Status :: 5 - Production/Stable',
        # 'Intended Audience :: Developers',
        # 'Topic :: Software Development :: Build Tools',
        # 'License :: OSI Approved :: MIT License',
        'Programming Language :: Python :: 3',
        'Programming Language :: Python :: 3.6',
        'Programming Language :: Python :: 3.7',
        'Programming Language :: Python :: 3.8',
        'Programming Language :: Python :: 3.9',
        'Programming Language :: Python :: 3 :: Only',
    ],

    keywords='training, examples, stuff',  # Optional
    package_dir = {'': 'src'},
    packages = ['.'],
    scripts=['bin/do-the-acquisition.py'],
    python_requires='>=3.6, <4',
    install_requires=[
        'paho-mqtt',
    ],
)
