#!/bin/bash

echo -n "Nhap file can backup : "
read source

echo -n "Nhap noi chua file : "
read destination

if ! [ -d $destination ]
then
    mkdir $destination
fi

if [ -f $source ]
then    
    cp -p $source $destination
    echo "Da copy file $source vao thu muc $destination"
elif [ -d $source ]
then
    cp -pr $source $destination
    echo "Da copy thu muc $source vao thu muc $destination"
else
    echo "Chi copy file va thu muc !"
    exit 255
fi
