#!/bin/bash

echo "Enter arithmetic operator(+, -, /, *):"
read operation
echo "Enter the first number:"
read num1
echo "Enter the second number:"
read num2


if [ "$operation" = "+" ]; then
    result=$((num1 + num2))
    echo "The sum is: $result"

elif [ "$operation" = "-" ]; then
    result=$((num1 - num2))
    echo "The difference is: $result"

elif [ "$operation" = "*" ]; then
    result=$((num1 * num2))
    echo "The product is: $result"

elif [ "$operation" = "/" ]; then
    if [ "$num2" -eq 0 ]; then
        echo "Error: Division by zero"
    else
        result=$((num1 / num2))
        echo "The quotient is: $result"
    fi

else
    echo "Invalid Operation"
fi
