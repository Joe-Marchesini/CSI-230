#!/bin/bash
#...

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
