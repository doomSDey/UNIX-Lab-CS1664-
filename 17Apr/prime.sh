#! /bin/bash
echo "Enter a number between 1 to 1000"
read x
num=2
while [ $num -le $x ]
do
	n=$(($num / 2))
	c=0
	i=2
	while [ $i -le $n ]
	do
		m=$(($num % $i))
		if [ $m -eq 0 ]
		then
			c=$(($c + 1))
		fi
		i=$(($i + 1))
	done
	if [ $c -eq 0 ]
	then
		echo $num
		echo "prime"
	fi
	num=$(($num + 1))
done
