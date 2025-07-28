Blah
====

CHROOT=$HOME/Machines/fedora-41

sudo mkdir -p $CHROOT/proc
sudo mkdir -p $CHROOT/dev
sudo mkdir -p $CHROOT/etc
sudo touch $CHROOT/etc/resolv.conf
sudo mount -t proc proc $CHROOT/proc/
sudo mount --bind /etc/resolv.conf $CHROOT/etc/resolv.conf 
sudo mount -t devtmpfs devtmpfs $CHROOT/dev
sudo mount -t tmpfs shm $CHROOT/dev/shm

# minimal install
PACKAGES="\
dnf \
fedora-release \
glibc \
glibc-langpack-en \
glibc-langpack-de \
gcc \
g++ \
cmake \
util-linux \
"

# for bitbake itself
PACKAGES="$PACKAGES python3"
# these had to be installed on the host (when it used to be at fedora 40)
PACKAGES="$PACKAGES chrpath diffstat lz4 patch rpcgen"
# these were discovered, on the host, as needed somewhere deep inside the build
PACKAGES="$PACKAGES perl-FindBin perl-STD"
# these are needed on top of the minimal chroot install
PACKAGES="$PACKAGES bunzip2 bzip2 cmp cpio diff file git hostname pzstd tar unzstd wget which zstd"

sudo dnf -y --releasever=41 --best --setopt=install_weak_deps=False --installroot=$CHROOT --use-host-config install $PACKAGES

sudo mkdir $CHROOT/home/jfasch
sudo mount --bind ~ $CHROOT/home/jfasch
sudo chroot $CHROOT useradd --shell /bin/bash --uid 1000 --user-group --home-dir /home/jfasch jfasch
