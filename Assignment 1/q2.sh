#!/bin/bash


file=$1
if [ ! -f  $file ]
then
	echo "Not a file"
	exit
fi

count=1
while read line
do
	res=`expr $count % 2`
	if [ $res -eq 0 ]
	then
		echo $line >>evenfile.txt
	else
		echo $line >>oddfile.txt
	fi
	(( count++ ))
done < $file

