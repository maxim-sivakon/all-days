#!/bin/bash

echo 'Путь, текст замены, что заменить'
read startPath lineEdit replace

if [ ! -f "$FILE" ]; then
  sed -i '' "s/$lineEdit/$replace/g" $startPath

  hashFile=`shasum -a 256 $startPath | awk '{print $1}'`
  fileSize=`stat -f%z $startPath`
  dateNow=`date '+%Y-%m-%d %H:%M'`

  echo src/$startPath - $fileSize - $dateNow - $hashFile - sha256 >> files.log
else
  echo "= = = = ="
  echo "file not found"
  echo "= = = = ="
fi
