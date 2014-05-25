#!/bin/bash

checkValue() {
    boolCheck=0
    while [ $boolCheck -eq 0 ]; do
	echo -n "How many questions do you want ? (the number you enter must be <= 20) : "
	read amount	
	if [ $amount -gt 20 ] || [ $amount -lt 1 ]; then
	    echo "The number you entered is invalid ! Please choose another one."
	    continue
	else
	    let boolCheck=1
	fi
    done
}

randomQuestion () {
    i=0
    while [ $i -lt $amount ]; do
	let a[$i]=$RANDOM%21
	j=0
	while [ $j -lt $i ]; do
	    if [ ${a[$j]} -eq ${a[$i]} ] || [ ${a[$i]} -eq 0 ]
	    then
		let i=i-1
	    fi
	    let j=j+1
	done
	let i=i+1
    done
}

sortNbQuestion() {    
    n=0
    while [ $n -lt $amount ]; do
	echo ${a[$n]}
	let n=n+1
    done
}

pickQuestion() {
    echo;echo "---------- QUESTIONS ----------"
    n=0
    while [ $n -lt $amount ]; do
	l=1
	let nbQuestion=3*${a[$n]}-2
	while read line; do
	    if [ $l -eq $nbQuestion ]; then
		echo $line
	    elif [ $l -eq $(($nbQuestion+1)) ] ||  [ $l -eq $(($nbQuestion+2)) ]; then
		echo "   " $line
	    fi
	    let l=l+1
	done < question.txt
	let n=n+1
    done
}

sortAnswer() {
    echo; echo "---------- ANSWERS ----------"
    n=0
    while [ $n -lt $amount ]; do
	l=1
	while read line; do
	    if [ ${a[$n]} -eq $l ]; then
		echo $line
	    fi
	    let l=l+1
	done < answer.txt
	let n=n+1
    done
}

clear
checkValue
randomQuestion
pickQuestion
sortAnswer
