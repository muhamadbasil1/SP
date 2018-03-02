#!/bin/bash

names=(`cat file`)
echo ${names[*]}
echo ${#names[*]}
echo ${#names[3]}

