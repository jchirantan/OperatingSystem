# Name: Chirantan Joshi.
# Div: G
# Batch: G1
# Roll No.: PG13
# MATHEMATICAL OPERATIONS WITH CONTROL STRUCTURES

#!/bin/bash
echo "Enter the 2 numbers"
read num1
read num2
function add()
{
	res=`expr $1 + $2`
	return $res
}
function sub()
{
	res=`expr $1 - $2`
	echo $res
}
function mul()
{
	res=`expr $1 \* $2`
	return $res
}
function div()
{
	echo "scale=5; $1 / $2" | bc
}
while :
do 
	echo -e "\n---MENU---\n1->Add\n2->Sub\n3->Mul\n4->Div\n5->Exit\n"
	echo "Enter Your Choice: "
	read ch
	case $ch in
	1) echo "Addition of two numbers is: "
	 add $num1 $num2
	 echo $res
	;;
	2) echo "Subtraction of two numbers is: " 
	sub $num1 $num2
	;;
	3) echo "Multiplication of two numbers is: "
	 mul $num1 $num2
	 echo $res
	;;
	4)echo "Division of two numbers is: "
	 div $num1 $num2
	;;
	5) exit
	;;
	*) echo "Wrong input!!"
	esac 
done

# OUTPUT:
# Enter the 2 numbers
#18
#6

#---MENU---
#1->Add
#2->Sub
#3->Mul
#4->Div
#5->Exit

#Enter Your Choice: 
#1
#Addition of two numbers is: 
#24

#---MENU---
#1->Add
#2->Sub
#3->Mul
#4->Div
#5->Exit

#Enter Your Choice: 
#2
#Subtraction of two numbers is: 
#12

#---MENU---
#1->Add
#2->Sub
#3->Mul
#4->Div
#5->Exit

#Enter Your Choice: 
#3
#Multiplication of two numbers is: 
#108

#---MENU---
#1->Add
#2->Sub
#3->Mul
#4->Div
#5->Exit

#Enter Your Choice: 
#4
#Division of two numbers is: 
#3.00000

#---MENU---
#1->Add
#2->Sub
#3->Mul
#4->Div
#5->Exit

#Enter Your Choice: 
#5

