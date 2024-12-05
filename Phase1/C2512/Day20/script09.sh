#!/bin/bash
if [ $# -ne 3 ]; then
    echo "Usage: $0 a b c"
    echo " Here a is first number"
    echo "      b is second number"
    echo "      c is second number"
    echo "Process ID: $$"
    exit 1
fi
s=$(( $1 + $2 + $3))
echo "Sum of $1 $2 $3 is $s"
echo "Process ID: $$" 
