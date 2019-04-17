#! /bin/bash
echo "Hello SMIT"
echo "Enter num1"
read num1
echo "Enter num2"
read num2
echo "Greater no is"
if [ $num1 -gt $num2 ]
then
	echo $num1
else
	echo $num2
fi
