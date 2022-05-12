/* 
 * Program that calculates "wind chill" based on the current temperature and wind speed. 
 * Used in degrees Fahrenheit, when the temperature is between -99 and 50 
 *
 * Alina Chadwick
 * CS50, Lab 2 - Professor Kotz
 *
 * This program can take in no arguments, one argument, or two arguments. It does not run from stdin or files
 */

#include <stdio.h>  // without this, my printf statement gets warnings
#include <math.h> 
#include <stdlib.h> // without this, my formula function was not called, learned from stack overflow

/* 
 * function that uses the standard formula for calculating windchill
 */
float 
formula ( float t, float v ){
    float windchill;
        windchill = (35.74 + (0.6215 * t) - (35.75 * (pow (v, 0.16 ))) + (( 0.4275 * t )*(pow (v, 0.16))));
        return windchill;
}


/*
 * main method, provides a table of windchill values based on user input
 * user can input up to two arguments
 * cases handle number of user arguments in different ways
 *
 * looked up additional information on how to interpret arguments at the following link
 * https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/
 */
int
main ( int argc, char *argv[] ){
    float temperature;
    float velocity;

   switch ( ( argc - 1) ) {

       /* 
        *  no arguments are given
        *  produces a table of temperatures and wind speeds
        */
       case 0:
         printf("Temperature   Wind    Chill" );
         printf("\n");
         printf("-----        -----      -----");
         printf("\n");
        for (temperature = -10; temperature <= 40; temperature +=10) {  //table from -10 degrees to 40 degrees in increments of 10.
           for (velocity = 5; velocity <= 15; velocity +=5){   //velocity values from 5 to 15 degrees in increments of 5.
             float windchill = formula(temperature, velocity);  
             printf("%0.1f,     %0.1f,      %0.1f" , temperature, velocity, windchill);
             printf("\n");
           }
        }
    break;

      /*
       *  only one argument is presented
       *   a table is produced calculating wind chill based on three velocities on that temperature given as the argument
       */
       case 1:
           if ((sscanf(argv[1], "%f", &temperature)) == 0){  //if the argument presented is not a number
               printf("Enter a number to test the wind chill");
               printf("\n");
               break;
           }
           if (temperature > 50 || temperature < -99){ //handles temperatures out of range
               printf("This formula only works with temperatures more than -99 and  less than 50 degrees Fahrenheit.");
               printf("\n");
               break;
           } 
           else {
               printf("Temperature   Wind    Chill " );
               printf("\n");
               printf("-----        -----      ----- ");
               printf("\n");
               for (velocity = 5; velocity <=15; velocity +=5){  //provides wind chill at that temperature for velocities of 5, 10, and 15
                   float windchill = formula(temperature, velocity);
                   printf("%0.1f,    %0.1f,      %0.1f" , temperature, velocity, windchill);
                   printf("\n");
               }
           }
           break;
   
           /*
            * user provides two arguments of temperature and velocity
            * calculates the wind chill for that temperature and velocity only
            */
       case 2:
           if ((sscanf(argv[1], "%f", &temperature)) == 0){  //argument presented for temperature is not a number
              printf("Enter a number to test the wind chill");
              printf("\n");
              break;
            }
           if ((sscanf(argv[2], "%f", &velocity)) == 0){
               printf("Enter a velocity to test the wind chill"); //argument presented for velocity is not a number
               printf("\n");
               break;
           }
           if (temperature > 50 || temperature < -99){  //handles temperatures out of range
               printf("This formula only works with temperatures more than -99 and less than 50 degrees Fahrenheit.");
               printf("\n");
              break;
           }
           if (velocity < 0.5 ){ //handles velocities out of range
               printf("Not enough wind!");
               printf("\n");
               break;
           }
           else{
               printf("Temperature   Wind    Chill " );
               printf("\n");
               printf("-----        -----      ----- ");
               printf("\n");
               float windchill = formula(temperature, velocity);
               printf("%0.1f,     %0.1f,      %0.1f", temperature, velocity, windchill);
               break;
           }


 default:
    return -1;
}
}


