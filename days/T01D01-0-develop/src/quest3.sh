#!/bin/bash

FILE=/src/door_management_files

if [ ! -d "$FILE" ]; then
  mv door_management_fi door_management_files

  cd door_management_files
  mkdir -p door_configuration
  mv *.conf door_configuration

  mkdir -p door_map
  mv door_map_1.1 door_map

  mkdir -p door_logs
  mv *.log door_logs

  cd ..
  chmod +x ai_door_control.sh
else
  echo "= = = = ="
  echo "a folder called (door_management_files) already exists!"
  echo "= = = = ="
fi