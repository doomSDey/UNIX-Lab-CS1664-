#! /bin/bash
echo "enter a number:"
read num
m=$(($num % 2))
if [ $m -eq 0 ]
then
	echo "even"
else
	echo "odd"
fi
