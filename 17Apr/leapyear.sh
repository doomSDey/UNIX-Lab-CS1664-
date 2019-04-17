echo "enter the year"
read y

if [ $(($y % 4)) -eq 0 ]
then
	if [ $(($y % 100)) -eq 0 ]
	then
		if [ $(($y % 400)) -eq 0 ]
		then
			echo "it is a leap year"
		else
			echo "it is not a leap year"
		fi
	else
		echo "it is a leap year"
	fi
else
	echo "it is a leap year"
fi

