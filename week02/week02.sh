#!/bin/bash

FILE='week02.c'
YN=1

echo -e "\n\033[33m\n< week02 Test>"
for NUM in {1..15}
do
	echo -en "."
	sleep 0.01
done
echo -e ".\n"
if test -e $FILE; then
	echo -e "\033[32mFind '$FILE'!\033[0m"
	echo -en "\033[35mNumber of tests: "
	read NUM
	echo -en "\033[32mYou have $NUM chances to test\033[0m"
	while [ $YN -le $NUM ]; do
		echo -e "\033[36m\n\n	[ $YN/$NUM ]\033[0m"
		gcc -Wall -Werror -Wextra $FILE -o week02
		./week02
		((YN++))
	done
else
	echo -e "\033[1;31mNo file!\033[0m"
fi
echo -e "\033[32m\n\nFinish testing!\033[0m"
