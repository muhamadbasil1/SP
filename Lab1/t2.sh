#!/bin/bash

if [ $# -eq 4 ]
then
	file1=$1
	user1=$2
	file2=$3
	user2=$4

	a1=(`ls -li $file1`)
	a2=(`ls -li $file2`)
	cheating=1
	if [ $user1 != $user2 ]
	then
		test diff -c $file1 $file2 && cheating=0
		echo "Owner:  ${a1[3]}"
		echo "Group: ${a1[4]}"
		echo "Permission: ${a1[1]}"
		echo "Filename: $file1"
		echo "Cheating: $cheating"

		echo "Owner:  ${a2[3]}"
		echo "Group: ${a2[4]}"
		echo "Permission: ${a2[1]}"
		echo "Filename: $file2"
		echo "Cheating: $cheating"
	else
		echo "Invalid arguments"	
	fi
else
	file1=$1
	user1=$2
	cheating=1
	set `ls -li $file1`
	if [ $user1 = $4 ]
	then
		cheating=0
	fi
	echo "Owner:  $4"
	echo "Group: $5"
	echo "Permission: $2"
	echo "Filename: $file1"
	echo "Cheating: $cheating"
fi
