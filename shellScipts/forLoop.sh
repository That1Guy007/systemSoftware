#!/bin/bash
#for loop example

echo -n "Choose string or numbers loop (1 or 2):  "
read choice
if test $choice -eq 1; then

for m in For loop of strings #dont put do here
do
	echo  "$m"
done

else

for i in $(seq 0 9);do 
	echo "$i"
done
fi

exit 0;
