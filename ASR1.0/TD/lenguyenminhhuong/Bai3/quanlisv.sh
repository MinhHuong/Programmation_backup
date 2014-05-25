#!/bin/bash

checkValue() {
    if [ $# -lt 1 ] || [ $# -gt 2 ]; then
	echo "Nhap tham so sai. Chi cho phep nhap 1 hoac 2 ma so"
	exit 255
    fi
}

themSV() {
    echo "Them thong tin SV : "
    read -p "Ten : " ten
    read -p "NTNS : " birth
    read -p "Khoa : " khoa
    read -p "Lop : " lop
    info=`echo "$ten",$birth,$khoa,$lop`
    i=1
    while read line; do
	let i=i+1
    done < datasv.txt
    echo "000$i,$info" >> datasv.txt
    cat datasv.txt

}

tim1SV() {
    if [ $# -eq 1 ]; then
	while read line; do
	    ma_data=`echo $line | awk -F"," '{ print $1 }'`
	    if [ $1 = "$ma_data" ]; then
		tenSV=`echo $line | awk -F"," '{ print $2 }'`
		khoaSV=`echo $line | awk -F"," '{ print $4 }'`
		echo "$ma_data" "$tenSV" "$khoaSV"
	    fi
	done < datasv.txt
    fi
}

timNhieuSV() {
    if [ $# -eq 2 ]; then
	thongso1=$1
	thongso2=$2
	ma1=`echo ${thongso1:3:1}`
	ma2=`echo ${thongso2:3:1}`
	l=1
	while read line; do
	    if [ $l -ge $ma1 ] && [ $l -le $ma2 ]; then
		ma_data=`echo $line | awk -F"," '{ print $1 }'`
		tenSV=`echo $line | awk -F"," '{ print $2 }'`
		khoaSV=`echo $line | awk -F"," '{ print $4 }'`
		echo "$ma_data" "$tenSV" "$khoaSV"	 
	    fi
	    let l=l+1
	done < datasv.txt
    fi
}

echo "Chuong trinh quan li sinh vien: "
echo "1) Them SV"
echo "2) Tim SV"
read -p "Lua chon cua ban : " option
case $option in
    1)
	themSV
	;;
    2) 
	read -p "Nhap ma so SV can tim (chi nhap tu 1 den 2 ma so) : " sv1 sv2
	if [ -z $sv2 ]; then	    
	    tim1SV $sv1
	else
	    timNhieuSV $sv1 $sv2
	fi
	;;
    *)
	echo "Lua chon sai"
	exit 255
	;;
esac
