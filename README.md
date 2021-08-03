# How to install SNOPT

Tested on a fresh Ubuntu 20.04 installation with `miniconda` for Python 3.9

Some requirements:
- A trial version license from https://ccom.ucsd.edu/~optimizers/downloads/
- `anaconda` or `miniconda`
- `git`

Some thoughts:
-  Add the path with libsnopt7.so to LD_LIBRARY_PATH or to /etc/ld.so.conf.d/ create a file like snopt.conf and write the directory there
- Add SNOPT_LICENSE to /etc/environment