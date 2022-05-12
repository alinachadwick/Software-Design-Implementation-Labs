/* 
 * Alina Chadwick
 * Lab 2, CS50
 * Professor Kotz
 *
 * Program that breaks its input into a series of words, one per line
 * Can take input from stdin or from files whose names are listed as arguments
 *
 * Usage: words [filename]...
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * String comparator, used to test if a filename is "-" later in the lab
 * Used https://www.tutorialspoint.com/c_standard_library/c_function_strcmp.htm to learn how to do so
 *
 */
int 
strcmp (const char* part, const char* string);


/* 
 * Function that reads through the file 
 * Splits the words on separate lines
 *
 */
void 
parse (FILE *fp){

    while (!feof(fp)){
      char ch = fgetc(fp);  //read through the file until it is EOF

      if (ch == ' '){
        printf("\n"); //replace the spaces with new lines
      }

      else{
      printf("%c", ch); //keeps words together
      }
    }
    
}

/*
 * Handles the file or input accordingly
 * Calls the parse function to split the words
 *
 */
int
main (int argc, char *argv[] ){  
  FILE *fp;   
   /*
   * when no filenames are given on the command line, it reads from stdin
   *
   */
  if (argc ==1){
      fp = stdin;
      parse(fp);
      fclose(fp);
   }

  /* 
   * when filenames are given, it reads from each file
   * if the filename given is '-', stdin is read
   *
   */
   else if (argc > 1) {
      for (int i = 1; i < argc; i++){

         if (strcmp("-", argv[i]) == 0){
          fp = stdin; //reads from stdin
         }
          else{
           fp = fopen(argv[i], "r");
             if (fp == NULL){  //handles an empty file
              fprintf(stderr, "%s empty file try again '%s' \n", argv[0], argv[1]);
              exit(1);
          }
       }
      parse(fp);
      fclose(fp);     
      if (strcmp("-", argv[i]) == 0){
          printf("no more stdin");  //prints a message once the user is done inputing text
      }
     }
 }
 return 0;
}
    
