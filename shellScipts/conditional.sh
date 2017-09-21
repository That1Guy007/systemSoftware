#using the test command versus brackets []
#!/bin/bash
#condition.sh

echo "file name to cheack?"
read fname
if [ -e $fname ]; then
	#returns true from (-e) if the flie exists
	echo "the file $fname exists in the current directory"
else
	echo "there is no file $fname within the current directory"
fi

if test -f $fname; then
	echo "$fname is regular"
else
	echo "$fname is non-regular"
fi

exit 0;
