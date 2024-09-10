# mpss-cli

## Description
Command line interface for mpsslib

## Dependencies

There are a few tools required to build the project: 
git, cmake, make, and a compiler with support for C++17.
Plus, dev packages for libssl are required to access _https://_ URLs.

One way to install these tools would be to run the following commands:

### Debian, Ubuntu:

```
sudo apt install build-essential git cmake libssl-dev
```

### Arch Linux:

```
sudo pacman -S base-devel git cmake openssl
```

### CentOS, Fedora:

```
yum install gcc gcc-c++ kernel-devel make git cmake openssl-devel
```

### MacOS:

```
brew install cmake openssl git 
export LDFLAGS="-L/opt/local/lib"
export CPPFLAGS="-I/opt/local/include/openssl"
```

Additionally, [install XCode](https://developer.apple.com/support/xcode/).

### Windows:

Perhaps, the easiest way to build will be using Visual Studio.

Additionally, you will need to install [OpenSSL](https://slproweb.com/products/Win32OpenSSL.html) and [CMake](https://cmake.org/download/), and [Git](https://git-scm.com/download/win).

Or, using [Chocolatey](https://chocolatey.org/install
), you can install all the required tools with the following command:

```
choco install cmake openssl git visualstudio2022community visualstudio2019-workload-vctools
```

## Build instructions:

Clone the repository using git or by downloading files directly.

On Linux or MacOS, run terminal.
On Windows, run Developer Command Prompt for VS 2022.

In terminal, `cd` to the repository root directory and run the following commands. Alternativel, for Windows the build script can be used, located at `./scripts/build_win_msvc2022.cmd`, setting up the release build.

First, configure the project.

```
mkdir build
cd build
cmake ..
```

Then, for Linux and MacOS, build the project using:

```
make -j9 
```

For Windows, build the project using:

```
cmake --build . -j9 
```

> Similarly, on Windows MinGW can be used for configuring and building the project. For that I personally prefer using QtCreator.

## Usage:

  mpss-cli [OPTION...]

### Options:

#### -l, --list
Get list of currently supported Ubuntu releases, latest versions.

#### -c, --current
Get the version of current Ubuntu LTS release. 
If used together with -l, the current version will always be printed last.
Note that in that case 2 lines will be printed for the current release.

#### -s, --sha256 arg
Get the sha256 of the image file for the specified release.
Works only with currently supported releases.
For supported releases see output of -l.

#### -h, --help
Print usage