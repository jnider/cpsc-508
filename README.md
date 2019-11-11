# cpsc-508
environment for OS class final project

First run setup-env.sh to clone the environment. Most of the files come from various git repositories, but
some of the files are in this repository, such as 'nginx-app'.

In order to test anything with the network, you will need a bridge. I am lazy, so usually I just install virt-manager,
which installs lib-virt as a dependency which automatically creates a bridge called 'virbr0'. The other scripts depend
on the bridge having this name (such as qemu-ifup).

The nginx-app requires a config file. Copy the 'config' file into .config before running 'make'.
