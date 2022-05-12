#!/bin/bash
#
# top 10.sh - print a markdown file that presents the top 10 regions in the United States
# based on the number of vaccines each region distributed.

# usage:
#  top10.sh, vaccine_data_us.csv
#
# ouput:
#  top10.md
#
# Alina Chadwick, 2021

# check if the file is readable
if [[ -r $1 ]]; then
        echo "| Area | Doses Administered |"
            echo "| :-------- | --------: |"

                # creates the top 10 in the correct format from the file
                    grep "All" $1 | cut -d "," -f2,10 | sort -nk2,2 -rt ','| head -10 | tr \, \|| sed -e 's/$/\|/' -e 's/^/\|/'

                    # if not readable, an error message is printed and the exit code is non-zero
                else
                        echo 1>&2 "Error";

                    fi
