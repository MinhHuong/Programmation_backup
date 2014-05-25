#!/bin/bash

info_date=`date +"%A %d %B %Y (%T %p)"`
content=`echo -e "\n\tGood morning $USER, have a nice day !\n\n\tThis is $info_date"`

dialog --title "(-: Welcome to Linux :-)" \
       --infobox "$content" 8 50 
