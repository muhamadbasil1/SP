#!/bin/bash

arr=(`pidof bash`)
end=`expr ${#arr[*]} - 1`
for i in `seq 0 $end`
do
	arr1=(`cut -d ":" -f2 /proc/${arr[$i]}/status`)
	echo "PID: ${arr[$i]}"
	echo "Name: ${arr1[0]}"
	echo "PPID: ${arr1[7]}"
	echo -e "State: ${arr1[2]} ${arr1[3]}\n"
done
