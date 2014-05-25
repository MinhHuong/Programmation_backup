#!/bin/bash

enterTab() {
    i=0    
    while [ $i -lt $size ]; do
	echo -n "Enter the elem tab[$i] : "
	read tab[$i]
    let i=i+1
    done
}

printTab() {
    echo; echo "Tab after sort :"
    i=0 
    while [ $i -lt $size ]; do
	echo "tab[$i] =" ${tab[$i]}
	let i=i+1
    done
}

swapPosition() {
    x=${tab[$1]}
    tab[$1]=${tab[$2]}
    tab[$2]=$x
}

sortList() {
    i=0
    while [ $i -lt $(($size-1)) ]; do
	let j=i+1
	while [ $j -lt $size ]; do
	    if [ ${tab[$i]} -gt ${tab[$j]} ]; then
		swapPosition i j
	    fi
	    let j=j+1
	done
	let i=i+1
    done
}

sortListFixeSize() {
    echo -n "Enter the size of your array : "
    read size
    enterTab
    sortList
    printTab
}

enterTab-bis() {
    echo "Make your list, enter 's' to stop and begin to sort list"
    i=0
    boolCheck=1
    while [ $boolCheck -eq 1 ]; do
	echo -n "Enter tab[$i] : "
	read tab[$i]
	if [ "${tab[$i]}" = "s" ]; then
	    break;
	fi
	let i=i+1
    done
}

printTab-bis() {
    echo; echo "Your tab after sort: "
    j=0
    while [ $j -lt $i ]; do
	echo "tab[$j] =" ${tab[$j]}
	let j=j+1
    done
}

sortList-bis() {
    a=0
    while [ $a -lt $(($i-1)) ]; do
	let b=a+1
	while [ $b -lt $i ]; do
	    if [ ${tab[$a]} -gt ${tab[$b]} ]; then
		swapPosition a b
	    fi
	    let b=b+1
	done
	let a=a+1
    done    
}

sortListNoFixeSize() {
    enterTab-bis
    sortList-bis
    printTab-bis
}

echo "How do you want to sort a list ?"
echo "1) Array with fixe size"
echo "2) Array with no fixe size"
echo; echo "Your choice : "
read choice
case $choice in
    1) sortListFixeSize
	;;
    2) sortListNoFixeSize
	;;
    *) echo "Your choice is invalid !"
	exit 1
	;;	
esac
