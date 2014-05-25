#!/bin/bash

mk-header() {
    maj=$(echo $1 | tr 'a-z' 'A-Z')
    cat <<EOF
#ifndef ${maj}_H
#define ${maj}_H
class $1 {
public:
$1();
~$1();
};
#endif
EOF
}

mk-code() {
    cat <<EOF
#include "$1.h"
$1::$1() {
}
$1::~$1() {
}
EOF
}

mk-prog() {
    cat <<EOF
#include <iostream>
using namespace std;
int main() {
}
EOF
}

for nom in $*
do
    case $nom in
	*cc)
	    mk-prog $nom > $1
	    ;;
	*) 
	    mk-header $nom > $1.h
	    mk-code $nom > $1.cc
	    ;;
    esac
done
