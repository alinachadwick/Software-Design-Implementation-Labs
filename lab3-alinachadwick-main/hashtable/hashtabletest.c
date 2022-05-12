/* 
 * hashtabletest.c - test program for CS50 hashtable module
 * Alina Chadwick Lab 3
 * CS50, April 2019, 2021
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "memory.h"

void delete(void *item);
void printer(FILE *fp, const char *node, void *item);

/* **************************************** */
int 
main(){
  //creates a hashtable
  hashtable_t *ht;
  ht = hashtable_new(7);
  // test case, allocates memory to test my name
  char* name = (char *) malloc(6*sizeof(char));
  strcpy(name, "Alina");

  //makes sure the hashtable was created effectively
  if (ht != NULL){
    printf("hash created. nice! \n");
  }

  // tests insertion
  if (hashtable_insert(ht, "test", name)){
     printf("insertion works!");
     hashtable_insert(ht, "test", name);
  }
  else{
    printf("cannot insert.");
  }

  //tests the print function
  printf("\n");
  hashtable_print(ht, stdout, printer);
  printf("\n");
  
  
}

/*helper function for printing*/
void 
printer(FILE *fp, const char *node, void *item)
{
  char *name = item; 
  if (name == NULL) {
    fprintf(fp, "(null)");
  }
  else {
    fprintf(fp, "%s -> %s", node, name); 
  }
}

/*helper function for deleting*/
void delete(void *item)
{
  if (item != NULL) {
    free(item);   
  }
}