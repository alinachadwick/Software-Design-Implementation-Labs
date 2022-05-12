# Alina Chadwick
# CS50 Lab 2
# Professor Kotz
# testing the histo.c code

# one argument, less than 16
echo 4 | ./histo

# one argument, higher than 16
echo 150 | ./histo

# negative number
echo -4 | ./histo

# one argument in a much larger range to show the changing intervals
echo 9999999 | ./histo

# arguments in different numerical categories
echo 3 8 9 7 20 50 44 92 | ./histo


