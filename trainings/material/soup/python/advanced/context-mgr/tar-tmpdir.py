import tempfile
import shutil
import os
import tarfile

with tempfile.TemporaryDirectory() as tmpd:
    # create toplevel tar directory, and cram stuff in it
    subdir = tmpd + '/os-credentials'
    os.mkdir(subdir)
    shutil.copy('/etc/passwd', subdir)
    shutil.copy('/etc/group', subdir)

    # tar it
    tarname = tmpd + 'os-credentials.tar.bz2'
    with tarfile.open(tarname, 'w') as tf:
        tf.add(subdir, 'os-credentials')

    # copy tarfile into its final location
    shutil.copy(tarname, os.path.expandvars('$HOME/os-credentials.tar.bz2'))
