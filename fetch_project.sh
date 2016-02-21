#!/bin/bash
set -x

filename="IT279"
filename+=`date +"_%m-%d-%Y_%H-%M-%S"`

# Remove old files
mv IT279 "$filename"

# Download the zip file
wget http://github.com/matheussampaio/IT279/archive/master.zip --quiet

# Unzip
unzip master

# Rename folder
mv IT279-master IT279

# Delete temp file
rm master
