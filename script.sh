#!/bin/bash
find . -name "*.cpp" | xargs g++ -std=c++17 -o app
echo "Скомпилировано: app"
echo "Today is $(date). Запускаю app..."
./app
