#!/bin.bash
#
# summarize.sh - print a Markdown summary of the files taken in
# files passed in as parameters, use files ending in .sh, .c, or .h for best results
#
# usage: summarize.sh
#
# Alina Chadwick, 5 April 2021

#  loops through pathnames
for file in $@;
do
    # if the file is not readable, an error message is printed
    if ! [[ -r "$file" ]] ; then
      echo 1>&2 "Not readable"

     # check if the file ends in ".sh", ".c", or ".h"
     elif [[ "$file" == *".sh" || "$file" == *".c" || "$file" == *".h" ]]; then
      echo "##" $(basename "$file")     # prints a subheader
      # markdown notation for bash
      if [[ "$file" == *".sh" ]]; then
        echo "\`\`\` bash"
        while read line; do
        # reads the lines before the empty line but after the line that starts with '#!'
        if [[ $line != "" ]]; then
          if [[ $line != "#!"* ]]; then
               echo "$line"
           fi
        else
        break    # break
        fi
       done < $file
      echo "\`\`\`"
      fi

      # markdown notation for files in c
      elif [[ "$file" == *".c" || "$file" == *".h" ]]; then
          echo "\`\`\`c"
       while read line; do
       # reads the lines before the empty line but after the line that starts with '#!'
         if ["$line" != "" && $line != "#!" ]; then
         echo "$line"
         else                                                                                                                     break
          fi
        done < $file
      echo "\`\`\`"

      # error message for files not ending in ".sh", ".h", or ".c"
     else
        echo WRONG TYPE OF FILE
     fi
     done
