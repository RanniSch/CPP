#!/bin/bash

./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
echo

./PmergeMe 3 5 9 7 4
echo

./PmergeMe "-1" "2"
echo

./PmergeMe 3 5 9 7 4 2
echo

./PmergeMe 100 34 3 5 9 66 7 4 2 0
echo

./PmergeMe 9 3 -1 7 4 2