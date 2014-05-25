#!/bin/bash

countLine() {
    l=0
    while read line; do
	let l=l+1
    done < datasv.txt
}

findNb() {
    countLine
    let maSV=l+1
    if [ $maSV -lt 10 ]; then
	nb_SV="000$maSV"
    elif [ $maSV -lt 100 ]; then
	nb_SV="00$maSV"
    elif [ $maSV -lt 1000 ]; then
	nb_SV="0$maSV"
    else
	nb_SV="$maSV"
    fi
}

ask-info() {
    read -p "Ten sinh vien : " name
    read -p "Ngay thang nam sinh : " birth
    read -p "Nganh hoc : " khoa
    read -p "Lop : " lop
}

echo "===== Chuong trinh quan li sinh vien ====="
ask-info
findNb
echo "$nb_SV", "$name", "$birth", "$khoa", "$lop" >> datasv.txt
cat datasv.txt
