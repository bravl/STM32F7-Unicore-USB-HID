README
=======

The UniCore-MX project aims to create an open-source firmware library for
various ARM Cortex-M microcontrollers.

Currently (at least partly) supported microcontrollers:

 - ST STM32F0xx/F1xx/F2xx/F30x/F37x/F4xx/F7xx/L0xx/L1xx series
 - Atmel SAM3A/3N/3S/3U/3X series
 - NXP LPC1311/13/17/42/43
 - Stellaris LM3S series (discontinued, without replacement)
 - TI (Tiva) LM4F series (continuing as TM4F, pin and peripheral compatible)
 - EFM32 Gecko series (only core support)
 - NXP Vybrid VF6xx (formerly Freescale)
 - Nordic Semiconductor nRF51

The library is a fork of [libopencm3](https://github.com/libopencm3/libopencm3).
We highly value all the work done in libopencm3, but for our projects we need a higher
commit rate than libopencm3 has at this point. We consider ourselves a friendly fork of
libopencm3. We have different needs and wishes. These are in short:

- higher commit rate, we make changes, and we need those fast in order to continue with our projects.
- higher merge rate, we want to merge pull requests in a timely fashion, for us,
  for the contributors and for the community.
- unified API, we have a strong desire to have a unified API across vendors.
- stable API, we want to define an API and stick to it.
- CI/testing, we want proper Continuous Integration and tests.
- up to date examples that are compatible with our unified API.

Libopencm3 itself was written completely from scratch based on the vendor datasheets,
programming manuals, and application notes. The code is meant to be used
with a GCC toolchain for ARM (arm-elf or arm-none-eabi), flashing of the
code to a microcontroller can be done using the OpenOCD ARM JTAG software.

In naming we will break compatibility with libopencm3 itself. While we feel it is a
good choice to name subsytems according to the datasheet, this has caused the API to be
incompatible across vendors. We wish it to be unified.


Status and API
--------------

UniCore-MX is currently work in progress. Not all subsystems
of the microcontrollers are supported, yet.

**IMPORTANT**: The API of the library is _NOT_ yet considered stable! Please do
           not rely on it, yet! Changes to function names, macro names etc.
           can happen at any time without prior notice! We will shortly define our future API
           and work to achieve this as soon as possible.

_TIP_: Include this repository as a GIT submodule in your project. To make sure
     your users get the right version of the library to compile your project.
     For how that can be done refer to the unicore-mx-examples repository.


Prerequisites
-------------

Building requires python. (Some code is generated)

**For Linux:**

 - An arm-none-eabi/arm-elf toolchain.

**For Windows:**

 Download and install:

 - msys - http://sourceforge.net/projects/mingw/files/MSYS/Base/msys-core/msys-1.0.11/MSYS-1.0.11.exe
 - Python - http://www.python.org/ftp/python/2.7/python-2.7.msi (any 2.7 release)
 - arm-none-eabi/arm-elf toolchain (for example this one https://launchpad.net/gcc-arm-embedded)

Run msys shell and set the path without standard Windows paths, so Windows programs such as 'find' won't interfere:

    export PATH="/c//Python27:/c/ARMToolchain/bin:/usr/local/bin:/usr/bin:/bin"

After that you can navigate to the folder where you've extracted libopencm3 and build it.


Toolchain
---------

The most heavily tested toolchain is "gcc-arm-embedded"
https://launchpad.net/gcc-arm-embedded

Other toolchains _should_ work, but have not been nearly as well tested.
Toolchains targeting linux, such as "gcc-arm-linux-gnu" or the like are
_not_ appropriate.

_NOTE_ We recommend, that you use g-a-c version 2.8 2014q3 or newer
to build all platforms covered by UniCore-MX successfully.


Building
--------

    $ make

If your have an arm-elf toolchain (uncommon) you may want to override the
toolchain prefix (arm-none-eabi is the default)

    $ PREFIX=arm-elf make

For a more verbose build you can use

    $ make V=1


Fine-tuning the build
---------------------

The build may be fine-tuned with a limited number of parameters, by specifying
them as environment variables, for example:

    $ VARIABLE=value make

* `FP_FLAGS` - Control the floating-point ABI

   If the Cortex-M core supports a hard float ABI, it will be compiled with
   best floating-point support by default. In cases where this is not desired, the
   behavior can be specified by setting `FP_FLAGS`.

   Currently, M4F cores default to `-mfloat-abi=hard -mfpu=fpv4-sp-d16`,
   M7 cores defaults to double precision `-mfloat-abi=hard -mfpu=fpv5-d16` if available,
   and single precision `-mfloat-abi=hard -mfpu=fpv5-sp-d16` otherwise.
   Other architectures use no FP flags, in otherwords, traditional softfp.

   You may find which FP_FLAGS you can use in particular architecture in readme.txt
   shipped with gcc-arm-embedded package.

   Examples:

        $ FP_FLAGS="-mfloat-abi=soft" make               # No hardfloat
        $ FP_FLAGS="-mfloat-abi=hard -mfpu=magic" make   # New FPU we don't know of

* `CFLAGS` - Add to or supersede compiler flags

   If the library needs to be compiled with additional flags, they can be
   passed to the build system via the environment variable `CFLAGS`. The
   contents of `CFLAGS` will be placed after all flags defined by the build
   system, giving the user a way to override any default if necessary.

   Examples:

        $ CFLAGS="-fshort-wchar" make    # compile lib with 2 byte wide wchar_t


Example projects
----------------

The libopencm3 community has written and is maintaining a huge collection of
examples, displaying the capabilities and uses of the library. We have forked this repository
as well, in order to maintain up-to-date examples for our diverging API.
You can find all of them in the unicore-mx-examples repository (not up yet):

https://github.com/insane-adding-machines/unicore-mx-examples/


Installation
------------

Simply pass -I and -L flags to your own project.  See the unicore-mx-examples
repository for an example of using this library as a git submodule, the most
popular method of use.

It is strongly advised that you do not attempt to install this library to any
path inside your toolchain itself.  While this means you don't have to include
any `-I` or `-L` flags in your projects, it is _very_ easy to confuse a multilib
linker from picking the right versions of libraries.  Common symptoms are
hardfaults caused by branches into arm code.  You can use `arm-none-eabi-objdump`
to check for this in your final elf.  You have been warned.


Coding style and development guidelines
---------------------------------------

See HACKING.


License
-------

The UniCore-MX code is released under the terms of the GNU Lesser General
Public License (LGPL), version 3 or later, as this is the license libopencm3 uses
and our work is just a continuation of their efforts and codebase.

See COPYING.GPL3 and COPYING.LGPL3 for details.


Community
---------

 * Our IRC channel on the freenode IRC network is called #unicore-mx


Mailing lists
-------------

For any questions or support, we kindly invite you to post to our mailinglists:

 * Developer mailing list (for patches and discussions):
   dev@lists.unicore-mx.org


Website
-------

 * http://unicore-mx.org
 * https://github.com/insane-adding-machines/unicore-mx/


