echo "hello smit"
var1=10
var2=20
sum= expr $var1 + $var2
echo "10+20=" $sum


echo "enter first number"
read num1
echo "enter second number"
read num2

add= expr $num1 + $num2
sub= expr $num1 - $num2
mul= expr $num1 * $num2
div= expr $num1 / $num2
rem= expr $num1 % $num2

echo "addition=" $add
echo "subtraction=" $sub
echo "multiplication=" $mul
echo "division=" $div
echo "reaminder=" $rem

