#!/bin/bash

chmod +x ai_help/keygen.sh
chmod +x ai_help/unifier.sh
./ai_help/keygen.sh
mv key ai_help
rm ai_help/key/file*
cd ai_help
./unifier.sh
