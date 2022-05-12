/*
*
* Alina Chadwick
* CS50 Lab 3
* Professor Kotz

* set.c provides a 'set' module
* based on the 'bag' module provided in bag.c
* see set.h for more information
*/
 
#ifndef __SET_H
#define __SET_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"
#include <stdbool.h>
#include "mem.h"

typedef struct setnode {
  void* item;                 
  struct setnode *next;      // link to next node 
  char *key;
} setnode_t;

/**************** global types ****************/
typedef struct set {
  struct setnode *head;       // head of the list of items in bag
} set_t;

/**************** local functions ****************/
static setnode_t *setnode_new(void *item, const char *key);

/**************** set_new() ****************/
/* see set.h for description */
set_t*
set_new(void)
{
   set_t* set = malloc(sizeof(set_t));

   if (set == NULL) {
       return NULL;
   }
   else{
       set -> head = NULL;  // create set structure
       return set;
   }
}

/**************** setnode_new() ****************/
/* see set.h for description */
static setnode_t*  
setnode_new(void* item, const char* key)
{
  setnode_t* node = mem_malloc(sizeof(setnode_t)); //allocate memory

  if (node == NULL) {
    return NULL;  // error allocating memory for node; return error
  } else {
    node->item = item;
    node->next = NULL; //initialize node and pointers
    return node;
  }
}

/**************** set_insert() ****************/
/* see set.h for description */
bool
set_insert(set_t* set, const char* key, void* item){
    if (set != NULL && key != NULL && item != NULL){ 
        setnode_t *new = setnode_new(item, key);
    
            if (new != NULL){
                new -> next = set -> head;  // add a new node to the head
                set -> head = new; 
                return true;
            }
    
        }
    return false;

}

/**************** set_find() ****************/
/* see set.h for description */
void*
set_find(set_t* set, const char* key){
    if (set == NULL) {
        return NULL;
    }
    else if (key == NULL){
        return NULL;
    }
    else if (set -> head == NULL){
        return NULL;
    }
    else{
        //loops through counter and returns pointer of the node in question
        for (setnode_t* node = set -> head; node != NULL; node = node -> next){
        node = set -> head;   
        void* item = node -> item;   
        return item;
        }
    }
    return NULL;
}

/**************** set_print() ****************/
/* see set.h for description */
void
set_print(set_t* set, FILE* fp, void (*itemprint)(FILE* fp, const char* key, void* item))
{
    if (fp != NULL){
        if (set != NULL){
            fputc('{', fp);
            for (setnode_t* node = set -> head; node != NULL; node = node -> next){ //loops through set
                if (itemprint!= NULL){
                    (*itemprint)(fp, node->key, node -> item); //prints out items in set
                    fputc(',', fp);
                }
            }
            fputc('}', fp);
        }
        else{
            fputs("(null)", fp);
        }
    }
}

/**************** set_iterate() ****************/
/* see set.h for description */
void
set_iterate(set_t* set, void* arg, void (*itemfunc)(void* arg, const char* key, void* item)){
   if (set != NULL &&  itemfunc != NULL){
       for (setnode_t* node = set -> head; node != NULL; node = node -> next){
           (*itemfunc)(arg, node->key, node->item);  //algorithm from bag module
       }
   }
}

/**************** set_delete() ****************/
/* see set.h for description */
void
set_delete(set_t* set, void (*itemdelete)(void* item))   
{
    if (set == NULL){
        for (setnode_t* node = set -> head; node != NULL; node = node -> next){
            if (itemdelete != NULL){
                (*itemdelete)(node -> item);
            }
            setnode_t* next = node -> next;
            mem_free(node); //free memory when we delete a node
            node = next;
        }
        mem_free(set); //free memory of the whole set
    }
}
#endif