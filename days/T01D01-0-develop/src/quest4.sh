#!/bin/bash

# находим все процессы с названием ai_door_control.sh и удялаем их
pgrep -f ai_door_control.sh | xargs kill
