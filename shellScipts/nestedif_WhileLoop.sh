#!/bin/bash
# program exploring nested if statements and while loops

#declaring a choice variable  which is used for the while variable

choice=1

#print to stdout

echo "1. Bash"
echo "2. Scripting"
echo "3. Tutorial"

echo -n "Please choose a word [1, 2, or 3]?"

#loop while choice !0

while [ "$choice" -ne 0 ]; do
	read choice
	if test $choice -eq 1; then 
		echo "you have chosen bash"
	elif  test $choice -eq 2; then
		echo "You have chosen scripting"
	elif  test $choice -eq 3; then
		echo "Tutorial #3 has been chosen"
	else
		echo "You have entered an incorrect input. press 0 to exit"
	fi
done
exit 0

