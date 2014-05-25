#!C:\bin\bash

$DIRS=`echo $PATH || tr ':' ' '`
for $D in $DIRS {
    for $F in $D/*$1* {
	if ( -x $F ) {
		echo ($F)
	    }
    }
}
