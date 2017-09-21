#!/bin/bash
#conditions in bash

myname="Carlos H"
echo "What is your Name?"
read urname
if [ -z "$urname" ]; then #including the quotes preserves the white space within a passed variable
	echo "no input from keyboard"
	#exit 1
	#true if the string is NULL (-z)
elif [ "$myname" = "$urname" ]; then #Spaces around the  (=) is different then no spaces around the equals sign
	echo "we have same name $myname"
	#true if two string are equal
else
	echo "My name is $myname. Your name is $urname"
	#if all else fails...
fi
	#if statements executes until it reaches a fi
	#exit 0  means exit with no errors.
exit 0;
