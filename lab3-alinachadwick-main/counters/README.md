# CS50 Lab 3
## CS50 Spring 2021 Alina Chadwick

### counters
A counter set is a set of counters, each of which have an integer key. For each key, it tracks a counter, which is incremented every time counters_add is called. 
By calling counters_get, the user can retrieve the counter value.

### Usage
The *counters* module, defined in `counters.h` and implemented in `counters.c` exports the following functions:

```c
counters_t* counters_new(void);
int counters_add(counters_t* ctrs, const int key);
int counters_get(counters_t* ctrs, const int key);
bool counters_set(counters_t* ctrs, const int key, const int count);
void counters_print(counters_t* ctrs, FILE* fp);
void counters_iterate(counters_t* ctrs, void* arg, void (*itemfunc)(void* arg, const int key, const int count);
void counters_delete(counters_t* ctrs);
```

### Implementation
We implement this counter as a linked list.
The *counter* itself is represented as a `struct counters` containing a pointer to the head of the list; the head pointer is NULL when the set is empty.

Each node in the list is a `struct countersnode`, a type defined internally to the module.
Each node includes a pointer to the next node on the list.

To insert a new item in the counter we create a new countersnode and insert it at the head of the list.

To get an item, we must loop through and find the item based on its key and we return its value. We do not remove it. 

The `counters_print` method prints the pointers of the items we have in the list. This is useful to keep track of pointers and can be used for testing. 

The `counters_iterate` method calls the `itemfunc` function on each item by scanning the linked list.

The `counters_delete` method frees the memory from each node and redirects pointers accordingly.
It concludes by freeing the the counter.

### Assumptions
No assumptions beyond those that are clear from the spec.



Because of the semantics of a *counters*, we have great freedom in our implementation.
We add to the head of the linked list in this case, although that can be changed.

### Files

* `Makefile` - compilation procedure
* `counters.h` - the interface
* `counters.c` - the implementation
* `counterstest.c` - unit test driver
* `testing.out` - result of `make test &> testing.out`

### Compilation 
To compile, simply `make counters.o`.

### Testing
The `counterstest.c` program tests a few edge cases and functions.
This test is somewhat minimal, a lot more could be done!

To test, simply `make test`.
See `testing.out` for details of testing and an example test run.

Try testing with `MEMTEST` by editing Makefile to turn on that flag and then `make test`.
