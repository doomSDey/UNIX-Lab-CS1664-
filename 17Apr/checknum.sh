echo "enter a number:"
read num

if [ $num -lt 0 ]
then
	echo "number is negative"
elif [ $num -gt 0 ]
then
	echo "positive"
else
	echo "neither positive nor negative"
fi
