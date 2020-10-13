#!/bin/bash
red='/033[0;31m'
green='/033[0;32m'
yellow='/033[0;33m'
blue='/033[0;34m'
magenta='/033[0;35m'
default='/033[0m'

read -p "What is your favorit color (red, green, blue, yellow or magenta)?" c
color=${color^^}
echo "${color} selected"
