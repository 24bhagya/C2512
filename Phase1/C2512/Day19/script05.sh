#!/bin/bash
read -p "Number of Terms:" N

echo "Natural Numbers:"
I=1
while [ $I -le $N ]; do
    echo -n "$I "
    I=$(( I + 1 ))
done
echo 
