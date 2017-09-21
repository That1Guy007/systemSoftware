#arithmetic.sh
#testing comparisons between numbers

#!/bin/bash

if [ 4 -eq 4 ]; then 
	echo " 4 is equal to 4"
else 
	echo "4 is not equal to 4"
fi

a=4
b=5
if  [ $a -eq $b ]; then 
	echo " 4 is equal to $b"
else
	echo " 4 is not equal to $b"
fi 
exit 0
