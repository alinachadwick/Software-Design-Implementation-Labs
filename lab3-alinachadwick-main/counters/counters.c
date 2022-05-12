/*
* Alina Chadwick
* CS 50 Lab 3
* Professor Kotz
*
* counters.c provides a 'counters' module
* see counters.h for more information
* based on the 'bag' module provided in bag.c
*/

#ifndef __COUNTERS_H
#define __COUNTERS_H

#include <stdio.h>
#include <stdbool.h>
#include "mem.h"
#include <stdlib.h>

/**************** local types ****************/
typedef struct countersnode{
    int key;
    int count;
    struct countersnode *next;  //link to next node
} countersnode_t;

/**************** global types ****************/
typedef struct counters {
    struct countersnode *head;  //head of the list of items in the counter
}counters_t;

/**************** local functions ****************/
static countersnode_t *countersnode_new(int key);

/**************** counters_new() ****************/
/* see counters.h for description */
counters_t*
counters_new(void){
    counters_t* counter = mem_malloc(sizeof(counters_t));
    if (counter == NULL) {
    return NULL;                
    }
    else {
    counter->head = NULL;  //create counter structure
    return counter;
  }
}

/**************** countersnode_new() ****************/
/* see counters.h for description */
countersnode_t*
countersnode_new(int key){
    countersnode_t *node = malloc(sizeof(countersnode_t));
    if (node != NULL){   //allocate memory for the node
        node -> count = 1;
        node -> key = key;
        node -> next = NULL;  //initialize node and pointers
        return node;
    }
    return NULL;
    
}

/**************** counters_add() ****************/
/* see counters.h for description */
int 
counters_add(counters_t* ctrs, const int key){
  if (ctrs != NULL && key > 0){
      countersnode_t *new = countersnode_new(key);
      if (new != NULL){
        new -> next = ctrs -> head;  //add a new node to the head of the list
        ctrs -> head = new;
        return new -> count;
      }     
  }
  return -1;
}

/**************** counters_get() ****************/
/* see counters.h for description */
int 
counters_get(counters_t* ctrs, const int key){
    if (ctrs != NULL){

        //loops through counter and returns pointer of the node in question
        for (countersnode_t *node = ctrs -> head; node != NULL; node = node -> next){
            if (node ->key == key){   
                return node -> count;  
            }
        }
    }
    return 0;
}

/**************** counters_set() ****************/
/* see counters.h for description */
bool 
counters_set(counters_t* ctrs, const int key, const int count){
   if (ctrs != NULL && key >0 && count > 0){
       for (countersnode_t *node = ctrs -> head; node != NULL; node = node -> next){
           if (node ->key == key){    
               node -> count = count;  //updates count value
               return true;
           }
       }
   }
   return false; //fails
}

/**************** counters_print() ****************/
/* see counters.h for description */
void 
counters_print(counters_t* ctrs, FILE* fp){
    if(fp != NULL){
        if (ctrs != NULL){
            fputc('{', fp);
            for (countersnode_t *node = ctrs -> head; node != NULL; node = node -> next){
                fprintf(fp, "%d -> %d; ", node ->key, node -> count);  //prints out the pointers
            }
        }
        fputc('}', fp);
    }
    else{
        printf("Either the file or the counter is empty");
        return;
    }
}

/**************** counters_iterate() ****************/
/* see counters.h for description */
void 
counters_iterate(counters_t* ctrs, void* arg, void (*itemfunc)(void* arg, const int key, const int count)){
  if (ctrs != NULL && itemfunc != NULL){
      for (countersnode_t *node = ctrs -> head; node != NULL; node = node -> next){
          (*itemfunc)(node, node->key, node ->count);  //algorithm from bag module
      }
  }
}

/**************** counters_delete() ****************/
/* see counters.h for description */
void 
counters_delete(counters_t* ctrs){
    if (ctrs != NULL){
        for (countersnode_t *node = ctrs -> head; node != NULL; ){
            countersnode_t *next = node -> next;
            mem_free(node);  //frees memory when we delete a node
            node = next;  
        }
        mem_free(ctrs);  //frees memory of the counter
    }
}

#endif // __COUNTERS_H
