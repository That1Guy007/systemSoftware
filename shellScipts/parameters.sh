#! /bin/bash

#parameters.sh explores parameter values

salutations=Sup
echo $salutations
echo "The program $0 is now running"
echo "The first parmeter was $1"
echo "The secind parameter was $2"
echo "The number of parameters pased $#"
echo "the list of parameters $*"
echo "The users home dir is $HOME"
exit 0
