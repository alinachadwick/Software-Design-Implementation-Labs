/* 
 * counterstest.c - test program for CS50 counters module
 * Alina Chadwick Lab 3
 * CS50, April 2019, 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counters.h"
#include "file.h"



/* **************************************** */
int main() 
{
  //creates new counter
  counters_t *counter;
  counter = counters_new();

  //test for counters_new
  if (counter == NULL) {
    fprintf(stderr, "counters_new failed\n");
    return 1;
  }

  //tests for counters_add
  printf("testing counters_add...\n");
  counters_add(counter, 1); 
  printf("Counter has added 1 successfully\n");
  counters_add(counter, 20);
  printf("Counter has added 20 successfully\n");

  //testing counters_print 
  printf("testing print function \n");
  counters_print(counter, stdout);
  printf("\n");
  printf("pass. coolio \n");

  //testing counters_get
  printf("test with null counter, good item...%d\n ", counters_get(NULL, 7));
  printf("test with null item...%d\n ", counters_get(counter, 0));
  printf("test with null set, null item...%d\n ", counters_get(NULL, 0));

  //another print check
  printf("The counter:\n");
  counters_print(counter, stdout);
  printf("\n");

  //testing counters_delete
  printf("delete the set...\n");
  counters_delete(counter);
  printf("success! you're perfect");
  return 0;
}







