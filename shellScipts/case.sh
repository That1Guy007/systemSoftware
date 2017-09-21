#!/bin/bash

#test case statements

echo "Please input a number from 1 to 12"
read input
case $input in 
	1)
		echo "january";;
	2)
		echo "February";;
	3)
		echo "March";;
	4)
		echo "April";;
	5)
		echo "May";;
	6)
		echo "June";;
	7)
		echo "July";;
	8)
		echo "August";;
	9)
		echo "September";;
	10)
		echo "October";;
	11)
		echo "November";;
	12)
		echo "December";;
esac
exit 0
