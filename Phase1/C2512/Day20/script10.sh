#!/bin/bash
while getopts "f:s:t:" opt; do
    case $opt in
        f) num1=$OPTARG ;;
        s) num2=$OPTARG ;; 
        t) num3=$OPTARG ;;
        *) 
            echo "Invalid option"
            echo "Usage: $0 -f first_number -s second_number -t third_number"
            exit 1
        ;;
    esac
done

echo "num1: $num1"
echo "num2: $num2"
echo "num3: $num3"
result=$(( $num1 + $num2 + $num3 ))
echo "sum of $num1, $num2, and $num3 is $result"
