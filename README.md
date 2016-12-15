# C2MHTTPS

Download the CURL Library by following link:
https://github.com/curl/curl
https://curl.haxx.se/download.html

A normal Unix installation is made in three or four steps (after you've unpacked the source archive):

./configure
make
make test (optional)
make install

You probably need to be root when doing the last command.

Get a full listing of all available configure options by invoking it like:

./configure --help

If you want to install curl in a different file hierarchy than /usr/local, specify that when running configure:

./configure --prefix=/path/to/curl/tree

 Complilation : g++ main.cpp -o test -lcurl
