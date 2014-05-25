#!/bin/bash

enterTab() {
    echo "Enter the number, press 's' or 'S' to stop : "
    boolCheck=0
    i=0
    while [ $boolCheck -eq 0 ]; do
	read -p "Enter tab[$i] = " tab[$i]
	if [ "${tab[$i]}" = "s" ] || [ "${tab[$i]}" = "S" ]; then
	    boolCheck=1
	    total=$i
	fi
	let i=i+1
    done
}

printTab() {
    echo;echo "Here's your table, whose size is $total : "
    j=0
    while [ $j -lt $total ]; do
	echo "tab[$j] = ${tab[$j]}"
	let j=j+1
    done
}

findMax() {
    max=${tab[0]}
    m=1
    while [ $m -lt $total ]; do
	if [ $max -lt ${tab[$m]} ]; then
	    max=${tab[$m]}
	fi
	let m=m+1
    done
    echo "The number maximum : $max"
}

findMin() {
    min=${tab[0]}
    n=1
    while [ $n -lt $total ]; do
	if [ $min -gt ${tab[$n]} ]; then
	    min=${tab[$n]}
	fi
	let n=n+1
    done
    echo "The number minimum : $min"
}

findMax-bis() {
    a=0
    while [ $a -lt $k ]; do
	max[$a]=${tab[0]}
	b=1
	while [ $b -lt $total ]; do
	    if [ ${max[$a]} -lt ${tab[$b]} ]; then
		max[$a]=${tab[$b]}
		temp=$b
	    fi	    
	    let b=b+1
	done
	tab[$temp]=-99999
	echo "max[$a] = ${max[$a]}"
	let a=a+1
    done
}

findMin-bis() {
    c=0
    while [ $c -lt $k ]; do
	min[$c]=${tab[0]}
	d=1
	while [ $d -lt $k ]; do
	    if [ ${min[$c]} -gt ${tab[$d]} ]; then
		min[$c]=${tab[$d]}
		temp=$d
	    fi
	    let d=d+1
	done
	tab[$temp]=99999
	echo "min[$c] = ${min[$c]}"
	let c=c+1
    done
}

enterTab
printTab
echo -e "\nWhich one do you like to find ? \n1) Maximum \n2) Minimum \n3) Find k numbers maximum \n4) Find k numbers minimum"
read -p "Your choice : " choice
case $choice in
    1) findMax;;
    2) findMin;;
    3) read -p "How many maximum numbers do you want to find ? : " k
	findMax-bis;;
    4) read -p "How many minimum numbers do you want to find ? : " k
	findMin-bis;;
    *) echo "Invalid option. Program stops."
	exit 1;;
esac
