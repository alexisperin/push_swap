#!/bin/bash

declare -i min=0
declare -i max=0
declare -i i=1
declare -i moy=0
FILE=checker
FILEBASIC=checker_Mac
PROJECT=push_swap

if [ $# -le 1 ] || ! test -f "$PROJECT"
then
	if [ $# -le 1 ]
	then
		echo "Not enough arguments : Number of test, number of values."
	fi
	if ! test -f "$PROJECT"
	then
		echo "File Push_Swap does not exists."
	fi
	exit
fi
while [ $i -le $1 ]
do
	ARG=`ruby -e "puts (0..$2).to_a.shuffle.join(' ')"`
	NB=$(( `./push_swap $ARG | wc -l` ))

	if [ -e "$FILE" ]
	then
		res=`./push_swap $ARG | ./$FILE $ARG`
	fi
	if [ -e "$FILEBASIC" ]
	then
		res2=`./push_swap $ARG | ./$FILEBASIC $ARG`
	fi
	if [ $i -eq 1 ]
	then
		min=$NB
		max=$NB
	fi
	if [ $NB -lt $min ]
	then
		min=$NB
	elif [ $NB -gt $max ]
	then
		max=$NB
	fi
	moy=$(( moy + NB ))
	echo -e "Test $i :"
	if test -f "$FILE"
	then
		if [[ $res =~ "OK" ]]
		then
			echo -e "mine : \033[1;32m$res\033[0m"
		else
			echo -e "mine : \033[1;31m$res\033[0m"
		fi
	fi
	if test -f "$FILEBASIC"
	then
		if [[ $res2 =~ "OK" ]]
		then
			echo -e "Basic : \033[1;32m$res2\033[0m"
		else
			echo -e "Basic : \033[1;31m$res2\033[0m"
		fi
	fi
	echo -e	"(number of instructions : $NB)"
	i=$(( $i + 1 ))
done
moy=$(( $moy / $1 ))
echo -e "
Statistique :
	Min : $min
	Max : $max
	Moyenne : $moy"
