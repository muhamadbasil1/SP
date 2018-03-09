#!/bin/bash

showTable()
{
	start=1
	end=10
	case $# in
	3) 
		if [ $2 = "s" ]
		then
			start=$3
		fi	
		if [ $2 = "e" ]
		then
			end=$3
		fi
	;;
	5)
		if [ $2 = "s" -a $4 = "e" ]
		then
			start=$3
			end=$5
		fi
	;;
	6)
		if [ $2 = "s" -a $4 = "e" -a $6 = "r" ]
		then
			start=$3
			end=$5
			while [ $end -ge $start ]
			do
				echo "$1 x $end = `expr $1 \* $end`"
				end=`expr $end - 1`
			done
			exit
		fi
	;;
	esac
		
	for i in `seq $start $end`
	do
		echo "$1 x $i = `expr $1 \* $i`"
	done
}

if [ $# -eq 0 ]
then
	echo "No Args!"
elif [ $# -gt 6 ]
then
	echo "Too much Args"
elif [ $# -eq 1 ]
then
	expr $1 + 1 >/dev/null
	if [ $? ]
	then
		showTable $1
	else
		echo "Invalid Args"
	fi
elif [ $# -eq 2 ]
then
	echo "Few Args"
elif [ $# -eq 4 ]
then
	echo "Few Args"
elif [ $# -eq 3 ]
then
	expr $1 + 1 >/dev/null
	if [ $? ]
	then
		expr $3 + 1 >/dev/null
		if [ $? ]
		then
			showTable $1 $2 $3
		else
		echo "Invalid Args"	
		fi
	else
		echo "Invalid Args"
	fi
elif [ $# -eq 5 ]
then
	expr $1 + 1 >/dev/null
	if [ $? ]
	then
		expr $3 + 1 >/dev/null
		if [ $? ]
		then
			expr $5 + 1 >/dev/null
			if [ $? ]
			then
				showTable $1 $2 $3 $4 $5
			else
				echo "Invalid Args"	
			fi
		else
			echo "Invalid Args"
		fi
	else
		echo "Invalid Args"
	fi
elif [ $# -eq 6 ]
then
	expr $1 + 1 >/dev/null
	if [ $? ]
	then
		expr $3 + 1 >/dev/null
		if [ $? ]
		then
			expr $5 + 1 >/dev/null
			if [ $? ]
			then
				showTable $1 $2 $3 $4 $5 $6
			else
				echo "Invalid Args"	
			fi
		else
			echo "Invalid Args"	
		fi
	else
		echo "Invalid Args"
	fi
			


fi
	
