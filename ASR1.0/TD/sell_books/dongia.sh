#!/bin/bash

total=0
while read line; do
    SL=`echo $line | awk '{print $3}'`
    DG=`echo $line | awk '{print $4}'`
    let GT=$SL*$DG
    let total=$total+$GT
    echo $line | awk '{ print $1 "\t" $2 "\t$" '$GT'}'
done < bookdetails.txt

echo "Total : \$$total"
