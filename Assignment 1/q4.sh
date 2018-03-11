#!/bin/bash


case $# in
1)	
	var=$1
	if [ -f $var ]
	then
		sort $var | uniq >abc.txt
		rm $var
		mv abc.txt $var
	else
		echo "Not Exists"
	fi
;;
*)	echo "Invalid Options"
;;
esac
