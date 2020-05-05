executable('010-mmap', ['010-mmap.cc'])

executable('020-shm-create', ['020-shm-create.cc'], dependencies: [librt])
executable('030-shm-produce', ['030-shm-produce.cc'], dependencies: [librt])
executable('040-shm-consume', ['040-shm-consume.cc'], dependencies: [librt])

executable('100-sem-create', ['100-sem-create.cc'], dependencies: [librt, thread_dep])
executable('110-sem-wait', ['110-sem-wait.cc'], dependencies: [librt, thread_dep])
executable('120-sem-post', ['120-sem-post.cc'], dependencies: [librt, thread_dep])
