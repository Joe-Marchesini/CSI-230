#!/bin/bash
red='/033[0;31m'
green='/033[0;32m'
yellow='/033[0;33m'
blue='/033[0;34m'
magenta='/033[0;35m'
default='/033[0m'

read -p "What is your favorit color (red, green, blue, yellow or magenta)?" color
color=${color^^}

case ${color} in
  ${color} = "RED")
    selected_color=$red
    ;;

  ${color} = "BLUE")
    selected_color=$blue
    ;;

  ${color} = "GREEN")
    selected_color=$green
    ;;
    
  ${color} = "YELLOW")
    selected_color=$yellow
    ;;
    
  ${color} = "MAGENTA")
    selected_color=$magenta
    ;;

  *)
    echo "You didn't enter anything!"
    exit 1
    ;;
esac

echo "${selected_color}Your selected color is ${color}${default}"
