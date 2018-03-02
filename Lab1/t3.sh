#!/bin/bash

UNIX=(Debian "Red hat" Ubuntu Suse Fedora)
echo ${UNIX[*]}
echo ${#UNIX[*]}
echo ${#UNIX[2]}
echo ${UNIX[*]:3:2}
echo ${UNIX[*]/"Ubuntu"/"SCO Unix"}
UNIX=(${UNIX[*]} "AIX" "HP-UX")
echo ${UNIX[*]}
unset UNIX[2]
LINUX=(${UNIX[*]})
echo ${LINUX[*]}
BASH=(${LINUX[*]} ${UNIX[*]})
unset LINUX
unset UNIX
