/*
* Alina Chadwick
* CS50 Lab 3
* 
* hashtable.c provides a 'hashtable' module
* see hashtable.h for more information
* based on the 'bag' module provided in bag.c
*
* uses hash.c for the jenkins algorithm for hashing
*/

#ifndef __HASHTABLE_H
#define __HASHTABLE_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "set.h"
#include "hashtable.h"
#include "hash.h"

/**************** global types ****************/
typedef struct hashtable {
  set_t ** table;  //creates the array
  long count;
} hashtable_t;

/**************** hashtable_new() ****************/
/* see hashtable.h for description */
hashtable_t*
hashtable_new(const int num_slots){
  hashtable_t* ht = malloc(sizeof(hashtable_t));  //creates a hashtable
    if (ht != NULL){
        ht -> table = calloc(num_slots, sizeof(set_t*));  //allocates memory
        ht -> count = num_slots;
        for (int i = 0; i < num_slots; i++) {
            ht->table[i] = set_new();  //loops through and initializes each item in the array
        }
        return ht;
  }
  return NULL;
}

/**************** hashtable_insert() ****************/
/* see hashtable.h for description */
bool 
hashtable_insert(hashtable_t* ht, const char* key, void* item){
  if (ht != NULL && key != NULL && item != NULL){
      int hash = hash_jenkins(key, ht -> count);  //uses jenkins algorithm 
      return set_insert(ht -> table[hash], key, item); //calls upon set_insertion method
  }
  else{
      return false;
  }
}

/**************** hashtable_find() ****************/
/* see hashtable.h for description */
void*
hashtable_find(hashtable_t* ht, const char* key){
   if (ht != NULL && key != NULL){
       int hash = hash_jenkins(key, ht -> count); //uses jenkins algorithm
       return set_find(ht -> table[hash], key); //calls upon set_find method
   }
   else{
       return NULL;
   }
}

/**************** hashtable_print() ****************/
/* see hashtable.h for description */
void 
hashtable_print(hashtable_t* ht, FILE* fp, void (*itemprint)(FILE* fp, const char* key, void* item)){
    if (fp != NULL){
        if (ht != NULL){
            for (int i = 0; i < ht -> count; i++){
                if (itemprint != NULL){
                    set_print(ht -> table[i], fp, (*itemprint)); //uses set_print method from set
                }
            }
        }
    }
    return;
}

/**************** hashtable_iterate() ****************/
/* see hashtable.h for description */
void 
hashtable_iterate(hashtable_t* ht, void* arg, void (*itemfunc)(void* arg, const char* key, void* item) ){
    if (ht != NULL && itemfunc != NULL){
         for (int i = 0; i < ht -> count; i++){
             set_iterate(ht -> table[i], arg, (*itemfunc));  //uses set_iterate method from set
         }
    }
}

/**************** hashtable_delete() ****************/
/* see hashtable.h for description */
void hashtable_delete(hashtable_t* ht, void (*itemdelete)(void* item) ){
    if (ht != NULL){
        for (int i = 0; i < ht -> count; i++){
            if (itemdelete != NULL){
                set_delete(ht->table[i], (*itemdelete) );  //uses set_delete method from set
            }
        }
        free(ht -> table);  //frees memory for pointers and for the hashtable
        free (ht);
    }
}

#endif // __HASHTABLE_H