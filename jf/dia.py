from sphinx.errors import ExtensionError
from sphinx.transforms.post_transforms.images import ImageConverter
from sphinx.util import logging, images

import subprocess
from subprocess import CalledProcessError, PIPE


logger = logging.getLogger(__name__)

class DiaConverter(ImageConverter):
    conversion_rules = [
        ('image/x-dia', 'image/svg+xml'),
    ]

    def is_available(self):
        cmd = ['dia', '--version']
        try:
            logger.debug(f'Invoking {cmd} ...')
            subprocess.run(cmd, stdout=PIPE, stderr=PIPE, check=True)
            return True
        except OSError:
            logger.warning(f'convert command {cmd} cannot be run.')
            return False
        except CalledProcessError as exc:
            logger.warning(f'{cmd} exited with error:\n'
                           '[stderr]\n%r\n[stdout]\n%r',
                           exc.stderr, exc.stdout)
            return False

    def convert(self, _from, _to):
        cmd = ['dia', '--export', _to, '--filter', 'svg', _from]
        try:
            logger.debug(f'Invoking {cmd} ...')
            subprocess.run(cmd, stdout=PIPE, stderr=PIPE, check=True)
            return True
        except OSError:
            logger.warning('{cmd} failed')
            return False
        except CalledProcessError as exc:
            raise ExtensionError(f'{cmd} exited with error:\n'
                                 '[stderr]\n%r\n[stdout]\n%r' %
                                 (exc.stderr, exc.stdout))

def setup(app):
    # I found this the
    # simplest. (sphinx.environment.collectors.asset.ImageCollector
    # appears to add someting to node['candidates'], but I don't get
    # it.)
    assert '.dia' not in images.mime_suffixes
    images.mime_suffixes['.dia'] = 'image/x-dia'

    app.connect('builder-inited', _debug)
    app.add_post_transform(DiaConverter)

    return {
        'version': 'builtin',
        'parallel_read_safe': True,
        'parallel_write_safe': True,
    }

def _debug(app):
    # print('jjjjjjjjjjjjjjjj', app.builder.supported_image_types)
    pass
