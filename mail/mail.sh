#!/bin/bash
# file hostlookup.sh
# brief  Takes file input and creates users based on emails and gives them a one time use password
# author joeseph.marchesini
# Project 2
# date 10/22/2020

#Checks if the user is root and exits if the user isn't.
if [[ $EUID -ne 0 ]]; then
	echo "This script must be run as root user" 
	exit 1
fi

#Makes sure the file is being called properly with -f
usage()
{
	echo "$0 usgae: [-f input filed]"
	exit 1
}

#Gets file from -f
while getopts ":f:" options;
do
	#Sets file to f, and checks if its a vailid file, exits if it isn't.
	f=${OPTARG}
	if [ -f "$f" ]; then
		echo "${f}, file exists"
	else
		echo "${f}, invlaid file"
		exit 1
	fi

	#Loops through each line of file containing emails
	while read h
	do
		#Gets username from email address in file.
		username=$(echo $h | cut -d "@" -f 1)
		#Sets random password using openssl
		pass=$(openssl rand -base64 12)
		#Adding user and making it so they have to reset password in first login
		useradd -m -p $(openssl passwd -1 $pass) $username
		chage -d 0 $username
		#Satus output for each user created with password for tesing purpuses
		echo "User added from email... Pass: ${pass}"
	done < $f
done
