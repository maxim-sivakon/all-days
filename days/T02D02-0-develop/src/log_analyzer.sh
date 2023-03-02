#!/bin/bash

echo 'give file'
read fileLog
if [ -f $fileLog ]; then
  var1=`sort $fileLog | awk '{print $1}' $fileLog | wc -l`
  var2=`sort $fileLog | awk '{print $1}' $fileLog | wc -l |uniq| wc -l`
  var3=`sort $fileLog | awk '{print $8}' $fileLog | wc -l |uniq| wc -l`
  echo $var1 $var2 $var3
else
  echo "= = = = ="
  echo "file not found"
  echo "= = = = ="
fi