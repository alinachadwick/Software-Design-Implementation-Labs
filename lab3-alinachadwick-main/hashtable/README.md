# CS50 Lab 3
## CS50 Spring 2021 Alina Chadwick

### hashtable
A hashtable is essentially an array of sets. It works like a set, with more complex pointers that are adjusted accordingly. This is particularly important to use with larger collections and is a more complex model than we had in counters, set, or bag.

### Usage
The *hashtable* module, defined in `hashtable.h` and implemented in `hashtable.c` uses the hash_jenkins function dfined in `hash.h` exports the following functions:

```c
hashtable_t* hashtable_new(const int num_slots);
bool hashtable_insert(hashtable_t* ht, const char* key, void* item);
void* hashtable_find(hashtable_t* ht, const char* key);
void hashtable_print(hashtable_t* ht, FILE* fp, void (*itemprint)(FILE* fp, const char* key, void* item));
void hashtable_iterate(hashtable_t* ht, void* arg,void (*itemfunc)(void* arg, const char* key, void* item) );
void hashtable_delete(hashtable_t* ht, void (*itemdelete)(void* item) );
```

### Implementation
We implement this hashtable as an array of sets. We frequently call the set functions to preform similar tasks of deletion, insertion, and other functions.

The *hashtable* itself is represented as a `struct hashtable` containing an array (initially empty) and a float which will keep track of the items in the hashtable.

To insert, find, iterate, and delete, we need to call the specific set function (i.e. set_insert) on each set in the hashtable. This is an effective way to implement code that is already in place.

### Assumptions
No assumptions beyond those that are clear from the spec.

The set cannot be null because we must call on set functions in order to change or alter the empty hashtable in any way.


### Files

* `Makefile` - compilation procedure
* `hashtable.h` - the interface
* `hashtable.c` - the implementation
* `hash.h` - jenkins algorithm
* `hash.c` - implements jenkins algorithm
* `testing.out` - result of `make test &> testing.out`

### Compilation 
To compile, simply `make hashtable.o`.

### Testing
The `hashtabletest.c` program tests a few edge cases and functions.
This test is somewhat minimal, a lot more could be done!

To test, simply `make test`.
See `testing.out` for details of testing and an example test run.

Try testing with `MEMTEST` by editing Makefile to turn on that flag and then `make test`.