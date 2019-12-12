Instructions on how to run this FreeBSD app on Unikraft
-------------------------------------------------------

This is a 'hello world' proof-of-concept that was compiled & linked on FreeBSD
to create an ELF executable file called 'hellobsd'. The following instructions
explain how to take this app and delink it so that it can run on Unikraft
without any modifications.

You must have the following tools:
1) delinker
https://github.com/jnider/delinker.git

2) readelf
Strongly suggested, but not completely necessary

3) objdump
Strongly suggested, but not completely necessary

Create a directory called 'delink'. This is where you will put all of the
resulting files from delinking. Most of them are garbage and you don't want
them cluttering up your nice workspace.
Enter the 'delink' directory. Delink the app like this:

delinker -S ../hellobsd

This will create 15 or so .o files. The only one we are really interested in
is main.o. We will need it in a minute - now let's set up the Unikraft target.

There is already a directory called 'uk' with some linker scripts in it. This
is where we will build the final unikernel image. Copy all of the libraries
from some other project (such as nginx-app) into 'uk'. You can delete (or just
don't copy) any .ld.o files, just the .o files are enough. There should be 40
or so. This is much more than we need for this trivial example, but it is more
work to get rid of the ones we don't need than to just link them all. The only
price we pay is a larger executable, and a bit of runtime at the beginning
while the system loads up the rootfs and waits for a network address when we
don't really need those features for 'hello world'.
Assuming you are still in the 'uk' directory, copy the main.o file that the
delinker created like this:

cp ../delink/main.o .

The linker scripts and Unikraft build system will do the rest. Run ./build.sh
from the 'uk' directory, which should create 'hello-kvm', among other files.
This is the final image, ready to run. If the script complains about 'strip.py'
not being found, you may have to adjust the 'base' variable at the beginning
of the script.

Once you have the image, move up one directory (back to 'hellobsd') and run:

sudo ./run.sh uk

This will run a KVM virtual machine with 'uk/hello-kvm' as the guest. The
output will be redirected to a file called 'output-uk.txt'. It should contain
the Unikraft banner, followed by "Hello BSD" which is the output of the
FreeBSD program.
