#!/bin/bash
# file nukeusers.sh
# brief  Deletes added users for testing purpuses.
# author joeseph.marchesini
# Project 2
# date 10/22/2020

#for loop opens the email file and cuts the username which we use
for user in $(cat emails.txt | cut -d "@" -f 1);
do
	userdel -r $user;
done
