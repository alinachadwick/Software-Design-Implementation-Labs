/* 
 * Alina Chadwick
 * Lab 2 CS50
 * April 2021
 *
 * Reads a series of positive integers from stdin
 * Prints out a histogram with 16 bins
 * The range of bins depends on the highest input
 *
 */

#include <stdio.h>
#include <stdlib.h>

/* 
 * Function that creates histograms
 *
 */
int
main(int argc, char *argv[]){
    FILE *fp = stdin;
    const int num_inputs = 16; // number of inputs possible and number of bins
    int curr_input = 1;  //keeps track of what input it is

    int array[num_inputs];
    for (int i = 0; i < num_inputs; i++){
       array[i] = 0;      //initial array of 16 bins depends on number of inputs
    }

    while (!feof(fp)){  //reads through the user input until the EOF
        int input;
        scanf("%d", &input);
       
       //algorithm to create bins: https://stackoverflow.com/questions/3836987/how-to-plot-a-histogram-in-c  
       while (input >= curr_input*num_inputs){   
           int i = 0;
           int j = 0;
           while (i<num_inputs/2){ //creates bins
               array[i] = array [j];
               j++;
               array[i] += array[j];
               j++;
               i++;
           }
           while (i< num_inputs){
               array[i] = 0; //adds input value to array to keep track of the number of inputs
               i++;
           }
           curr_input = curr_input * 2; //updates the current input value

           printf("%d bins of size %d for range [0, %d)", num_inputs, curr_input, num_inputs * curr_input);
           printf("\n");
       }
       array[input/curr_input] = array[input/curr_input] + 1;
    }
   
    //creates the tracker part of the histogram with *s as visual markers
    for (int i = 0; i < num_inputs; i++){
        int track = array[i];
        printf("[%2d:%2d] ", i * curr_input, i*curr_input + (curr_input -1));
        
        for (int j = 0; j<track; j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
