#!/bin/bash

showAllOwners()
{
	x=$1
	for i in `ls`
	do
		if [ -f $i ]
		then
			set `ls -li $i`
		else
			continue
		fi
		if [ $4 = $x ]
		then
			echo "$i | Regular | $x"
		fi 
	done
	
}

if [ $# -eq 1 ]
then
	showAllOwners $1
else
	echo "Invalid"
fi


