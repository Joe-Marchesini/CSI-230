#!/bin/bash

# file Project-Scripting1.sh
# brief  First scripting project with various function implementation
# author joe.marchesini
# Project - Scripting 1
# date 10/5/2020

#Functions

# brief Outputs system information
systemInfo()
{
  echo "<h2>System Information</h2>"
  echo "<pre>"
  uname -a
  echo "</pre>"
}

# brief Outputs what memory is free
freeMemory()
{
  echo "<h2>Free Space avalible</h2>"
  echo "<pre>"
  free -m
  echo "</pre>"
}

# brief Outputs avalible disks and disk space
diskInfo()
{
  echo "<h2>Disk Information</h2>"
  echo "<pre>"
  df
  echo "<pre>"
}

# brief Outputs all useres with a shell prompt
shellPromptUsers()
{
  echo "<h2>System Users</h2>"
  echo "<pre>"
  w
  echo "<pre>"
}

# brief Outputs system ip
systemIP()
{
  echo "<h2>System IP Address</h2>"
  echo "<pre>"
  hostname -I
  echo "<pre>"
}

# brief Outputs title, username, and timestamp
title()
{
  echo "<h3>Project Scripting 1 | " date
  echo " | " whoami
  echo "</h3>"
}

# brief Outputs system uptime, based on "Writing Shell Scripts" documentation
systemUpTime()
{
  echo "<h2>System Up Time</h2>"
  echo "<pre>"
  uptime
  echo "<pre>"
}

# brief Outputs all useres with a shell prompt
something()
{
  echo "<h2>Place Holder</h2>"
}

#HTML

cat > Project-ScriptingHTML.html <<- _EOF_
  <html>
  <head>
      <title>Project - Scripting 1</title>
  </head>

  <body>
      $(title)
      $(systemInfo)
      $(freeMemory)
      $(diskInfo)
      $(shellPromptUsers)
      $(systemIP)
      $(systemUpTime)
      $(something)
  </body>
  </html>
_EOF_
