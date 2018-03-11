#!/bin/bash

arr=(`ls`)
for i in ${arr[*]}
do
	
	if [ -f $i ]
	then
		
		#IFS=$'.' a=( $i )       it will store in data in array
		IFS=$(echo -en ".")
		set $i
		IFS=$" "
		if [ $2 ]
		then
			mkdir -p $2
			mv $i $2
		fi
		
	fi
done
	
