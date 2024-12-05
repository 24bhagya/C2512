#!/bin/bash
read -p "Number of Terms:" N

echo "Natural Numbers:"
for I in $(seq $N -1 1); do
    echo -n "$I "
done
echo
