/* 
 * settest.c - test program for CS50 set module
 *
 * usage: read lines from stdin
 *
 * CS50, April 2019, 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"
#include "set.c"
#include "file.h"

static void nameprint(FILE *fp, const char *node, void *item);
static void namedelete(void *item);
static void itemcount(void *arg, const char *node, void *item);

/* **************************************** */
int main() 
{
  set_t *set;
  int namecount = 0;

  // create a set, testing set_new
  set = set_new();
  if (set == NULL) {
    fprintf(stderr, "set_new failed\n");
    return 1;
  }
 
  // test set_iterate
  printf("Count (should be zero): ");
  set_iterate(set, &namecount, itemcount);
  printf("%d\n", namecount);  

  // test set_insert
  printf("testing set_insert...\n");
  namecount = 0;
  while (!feof(stdin)) {  // read lines from stdin
    char *name = file_readLine(stdin);
    if (name != NULL) {
      set_insert(set, name, name);
      namecount++;
    }
  }

  printf("Count (should be %d): ", namecount);  // checks if the namecount is accurate
  printf("%d\n", namecount);  

  // edge cases
  printf("test with null set, good item...\n");
  set_insert(NULL, "Dartmouth", NULL);  
  printf("test with null item...\n");
  set_insert(set, NULL, NULL); 
  printf("test with null set, null item...\n");
  set_insert(NULL, NULL, NULL);
 
  // test set_print
  printf("The set:\n");
  set_print(set, stdout, nameprint);
  printf("\n");

  // test set_delete
  printf("delete the set...\n");
  set_delete(set, namedelete);

  return 0;
}


// helper function, counts the non-null items in the set
static void itemcount(void *arg, const char *node, void *item)
{
  int *nitems = arg;

  if (nitems != NULL && item != NULL)
    (*nitems)++;
}

// helper function, prints a name in quotes
void nameprint(FILE *fp, const char *node, void *item)
{
  char *name = item; 
  if (name == NULL) {
    fprintf(fp, "(null)");
  }
  else {
    fprintf(fp, "\"%s\"", name); 
  }
}

// helper function, deletes a name 
void namedelete(void *item)
{
  if (item != NULL) {
    free(item);   
  }
}
