#!/bin/bash

clear
echo "Hello $USER"
echo -n "Today is "
date +"%A %d %B %y"
echo "There is "
who | wc -l
echo connection on $HOSTNAME
echo Calendar ; cal 
exit 0
