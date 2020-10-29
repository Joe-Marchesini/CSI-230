#!/bin/bash
# file hostlookup.sh
# brief  Takes file input with host names and checks if they are valid hosts. 
# author joeseph.marchesini
# lab 6.2
# date 10/15/2020

usage()
{
	echo "$0 usgae: [-f input filed]"
}

while getopts ":f:" options;
do
	f=${OPTARG}
	while read h;
	do
		out=$(host -W1 -t A $h)
		if [ $? -eq 0 ];then
			ip=$(echo $out | cut -d " " -f 4)
			echo ${h},$ip
		else
			echo "${h}, not found"
		fi
	done < $f
done
