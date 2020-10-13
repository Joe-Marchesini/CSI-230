#!/bin/bash
red='/033[0;31m'
green='/033[0;32m'
yellow=
blue=
magenta=
default=

read -p "What is your favorit color (red, green, blue, yellow or magenta)?" c
color=${color^^}
echo "${color} selected"
