#!/bin/bash

x=1
y=1
expr $1 + 1
if [ $? -eq 0 ] 
then 
	x=0
fi

expr $2 + 1 
if [ $? -eq 0 ] 
then
	y=0
fi

if [ $x -eq 0 ]
then
	if [ $y -eq 0 ]
	then
		echo "Addition:" `expr $1 + $2`
		echo "Subtraction:" `expr $1 - $2`
		echo "Multiplication:" `expr $1 \* $2`
		if [ $2 -ne 0 ]
		then
			echo "Division:" `expr $1 / $2`
		fi		
	else
		echo "Invalid1!"
	fi
else
	echo "Invalid!"
fi
