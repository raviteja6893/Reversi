# Reversi

1. Install CImg library

Instructions for installing on ubuntu
	I. sudo apt-get install cimg-dev cimg-doc cimg-examples
	II. Reference link - https://charmie11.wordpress.com/2014/03/03/install-cimg-library-on-ubuntu/

2. Compile reversi.cpp
     I. g++ -o reversi reversi.cpp -O2 -L/usr/X11R6/lib -lm -lpthread -lX11
     II. Reference link - http://cimg.eu/reference/group__cimg__overview.html

3. Run the executable created in the 2nd step
     I. ./reversi