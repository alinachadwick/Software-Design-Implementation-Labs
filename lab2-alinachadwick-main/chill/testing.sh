## Alina Chadwick
## CS50 Lab 2
## simple bash script used to test chill.c

# zero arguments
./chill

#one argument
./chill 49

#two arguments
./chill 41.3 12

#temperature out of range - too high
./chill 9000

#temperature out of range - too low
./chill -10000

#velocity out of range
./chill 15 0

#arguments are not floats
./chill README.md


