# CS50 Lab 3
## CS50 Spring 2021 Alina Chadwick

### set
A set is an unordered collection of 'key, item' pairs where each item is distinguished by its key. The user can insert pairs as long as they have not been inserted yet. As well, the user can print the set, delete item pairs, but cannot change the 'key, item' pair itself.

### Usage
The *set* module, defined in `set.h` and implemented in `set.c` exports the following functions:

```c
set_t* set_new(void);
bool set_insert(set_t* set, const char* key, void* item);
void* set_find(set_t* set, const char* key);
void set_print(set_t* set, FILE* fp, void (*itemprint)(FILE* fp, const char* key, void* item) );
void set_iterate(set_t* set, void* arg,void (*itemfunc)(void* arg, const char* key, void* item) );
void set_delete(set_t* set, void (*itemdelete)(void* item) );
```

### Implementation
We implement this set using a linked list, adding items to the head of the list when we insert htem.

The *set* itself is represented as a `struct set` containing a pointer to the head.
Each node in the list is a `struct setnode`, a type defined internally to the module.
Each node includes a pointer to the next node on the list.

When inserting, we must check if that 'key, item' pair has not already been implemented. 

### Assumptions
No assumptions beyond those that are clear from the spec.
Our nodes cannot be null, and specifically nor the key nor the item can be null in order to be added to the set.

### Files

* `Makefile` - compilation procedure
* `set.h` - the interface
* `set.c` - the implementation
* `testing.out` - result of `make test &> testing.out`

### Compilation 
To compile, simply `make set.o`.

### Testing
The `settest.c` program tests a few edge cases and functions.
This test is somewhat minimal, a lot more could be done!

To test, simply `make test`.
See `testing.out` for details of testing and an example test run.

Try testing with `MEMTEST` by editing Makefile to turn on that flag and then `make test`.