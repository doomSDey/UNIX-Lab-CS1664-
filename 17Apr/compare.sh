echo "enter first number"
read num1
echo "enter second number"
read num2

if [ $num1 -gt $num2 ]
then
	echo "greater number is:"$num1
else
	echo "greater number is:"$num2
fi
