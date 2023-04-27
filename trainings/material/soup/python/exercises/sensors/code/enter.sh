project_rootdir=$(realpath $(dirname ${BASH_SOURCE[0]}))

project_pythonpath=$project_rootdir/src
project_path=$project_rootdir/bin

PYTHONPATH=$project_pythonpath:$PYTHONPATH
PATH=$project_path:$PATH

export PYTHONPATH
export PATH

PS1="(sensors) $PS1"

echo '***Path settings updated:'; echo

echo PYTHONPATH=$PYTHONPATH
echo PATH=$PATH
