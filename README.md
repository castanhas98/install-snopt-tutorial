# How to install SNOPT for optimization with pagmo

This repository is a tutorial on how to install and run SNOPT for optimization using pagmo (https://github.com/esa/pagmo2). A `conda` environment is used to install both   `pagmo` and `pagmo_plugins_nonfree` (https://github.com/esa/pagmo_plugins_nonfree) with ease.

Works with Ubuntu 20.04 and `miniconda` for Python 3.9 but is yet to be tested on a fresh installation of the operating system.

(Very much inspired by https://github.com/tudat-team/tudat-bundle)

Some requirements:
- A trial version license from https://ccom.ucsd.edu/~optimizers/downloads/
- `anaconda` or `miniconda`
- `git`
- `autoconf`, `build-essential` and `libtool` packages
- g++ (pre-installed with Ubuntu 20.04)
- A Fortran compiler, we used gfortran
- `cmake`


Some thoughts:
-  Add the path with libsnopt7.so to LD_LIBRARY_PATH or to /etc/ld.so.conf.d/ create a file like snopt.conf and write the directory there. Path to directory with file, not path to file. Absolute paths from root /, not from ~
- Add SNOPT_LICENSE to /etc/environment

## SNOPT

### 1. Request a "Non-U.S.-based" 3-month trial license for SNOPT7 from https://ccom.ucsd.edu/~optimizers/downloads/. 

![Asking for a License](./screenshots/snopt_ask_license.png)

The license should be requested for Linux and should have the Fortran libraries.

![License Specifications](./screenshots/library_type.png)


### 2. Clone the repository and enter directory

```
git clone http://github.com/castanhas98/install-snopt-tutorial
cd install-snopt-tutorial
```

### 3. Initialize the submodules after the clone.

```
git submodule update --init --recursive
```
According to https://github.com/esa/pagmo_plugins_nonfree/issues/2, a very specific commit of the `snopt-interface` (https://github.com/snopt/snopt-interface/commit/76b166ecdf5c55a3289ce0f849d8d3d101954a22). However, this is handled but the command above, so there is nothing else to be done in that regard.


### 4. Install what is required for the setup of the `snopt-interface`.
```
sudo apt-get update
sudo apt-get upgrade
sudo apt-get install autoconf build-essential libtool gfortran
```

### 5. Configure the `snopt-interface` (taken from https://github.com/esa/pagmo_plugins_nonfree/issues/2#issuecomment-421500114).

```
cd snopt-interface
./autogen
./configure
```

### 6. Download the Fortran libraries from the link provided in the email with the license. 

Some amount of time after requesting the license, an email will be sent to the registered email address. That email will contain both the license (`snopt7.lic`) and a link to the downloads, which look like http://ccom.ucsd.edu/~optimizers/downloads/software/academic?id=XXXXXXXXXXXX. The "Fortran (only) Libraries" are the ones that should be downloaded.

![Download Page](./screenshots/fortran_library_download.png)

 The `libsnopt7.zip` file should be extracted into `/install-snopt-tutorial/snopt-interface/lib`. Note that this directory is only generated after Step 5 is carried out.

 ### 7. Building the C libraries.

 Similarly to Step 5, the commands below are ran insed the `/install-snopt-tutorial/snopt-interface` directory.

```
make snopt_c
make install snopt_c
```

### 8. Add the libraries to LD_LIBRARY_PATH.

For a temporary addition, that exists while the current terminal exists and that needs to be ran every time a new terminal is opened:
```
export LD_LIBRARY_PATH=`realpath ./lib`
```
or
```
export LD_LIBRARY_PATH=/absolute/path/to/snopt-interface/lib`
```
In order to avoid having to do this every time a new terminal window is opened, one can create a new `.conf` file under `/etc/ld.so.conf.d`:
```
sudo nano /etc/ld.so.conf.d/snopt.conf
```
And writing `/absolute/path/to/snopt-interface/lib` inside, which can be obtained through the `realpath` command shown above. <kbd>Ctrl</kbd> + <kbd>X</kbd>, <kbd>Y</kbd>, <kbd>Enter</kbd> to save and exit. Afterwards, run:
```
sudo ldconfig
```
to update the system with the new libraries.

### 9. Setting up the License.

The `snopt7.lic` file that is sent in the email must be saved somewhere in the computer. Assuming that it is saved under `/install-snopt-tutorial`:
```
cd ..         # to get back to the /install-snopt-tutorial directory
export SNOPT_LICENSE=`realpath ./snopt7.lic`
```

Again, a more permanent solution by adding a line to the `/etc/environment` file. Open it by doing:
```
sudo nano /etc/environment
```
and add a new line to the file with the following:
```
SNOPT_LICENSE="/absolute/path/to/snopt7.lic"
```
where `/absolute/path/to/snopt7.lic` is the absolute path to the `snopt7.lic` file. Again,  <kbd>Ctrl</kbd> + <kbd>X</kbd>, <kbd>Y</kbd>, <kbd>Enter</kbd> to save and exit. **The computer should be restarted after this step.**


7. 
```
sudo apt-get install libgfortran4
```
if not found
```
sudo add-apt-repository universe
sudo apt-get update
sudo apt-get install libgfortran4
```

8. Add path to the license to SNOPT_LICENSE

## Setting up the `conda` environment