# How to install SNOPT

Tested on a fresh Ubuntu 20.04 installation with `miniconda` for Python 3.9

Some requirements:
- A trial version license from https://ccom.ucsd.edu/~optimizers/downloads/
- `anaconda` or `miniconda`
- `git`
- `autoconf`, `build-essential` and `libtool` packages
- g++ (pre-installed with Ubuntu 20.04)
- A Fortran compiler, we used gfortran
- `cmake`


Some thoughts:
-  Add the path with libsnopt7.so to LD_LIBRARY_PATH or to /etc/ld.so.conf.d/ create a file like snopt.conf and write the directory there. Path to directory with file, not path to file
- Add SNOPT_LICENSE to /etc/environment

## SNOPT

1. Request a "Non-U.S.-based" 3-month trial license for SNOPT7 from https://ccom.ucsd.edu/~optimizers/downloads/. The license should be requested for Linux and should have the Fortran libraries.

## This `git` repository
(Very much inspired by https://github.com/tudat-team/tudat-bundle)

1. Clone the repository and enter directory

```
git clone <git_repo_url>
cd install-snopt-tutorial
```

2. Initialize the submodules after the clone.

```
git submodule update --init --recursive
````
3. Install what is required for the setup of the snopt-interface.
```
sudo apt-get update
sudo apt-get upgrade
sudo apt-get install autoconf build-essential libtool gfortran

```

4. Setup the snopt-interface(Taken from https://github.com/esa/pagmo_plugins_nonfree/issues/2).

```
cd snopt-interface
./autogen
./configure
```

5. Download the Fortran libraries from the link provided in the email with the license. Should look like http://ccom.ucsd.edu/~optimizers/downloads/software/academic?id=XXXXXXXXXXXX . The libsnopt7.zip file should be extracted into `/install-snopt-tutorial/snopt_interface/lib`. Note that this directory is only generated after the previous step. 

```
make snopt_c
make install snopt_c
```

6. Add libsnopt to LD_LIBRARY_PATH

7. 
```
sudo apt-get install libgfortran4
```
if not found
```
sudo add-apt-repository universe
sudo apt-get update
sudo apt-get install libgfortran4<>

8. Add path to the license to SNOPT_LICENSE