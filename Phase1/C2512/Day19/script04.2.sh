#!/bin/bash
read -p "Number of Terms:" N

echo "Natural Numbers:"
for ((I = 1; I <= N; I++ )); do
    echo -n "$I "
done
echo 
