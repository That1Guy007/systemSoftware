#!/bin/bash

#tests out an until loop

i=10

until test $i -lt 0;do
	echo $i
	let i--
done
exit 0
