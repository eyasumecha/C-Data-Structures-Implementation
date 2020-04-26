# CS50 Lab 3
## Eyasu Lemma, CS50 Spring 2020

### set

a set is linked list implementation that collects anumber of key and value pairs. It could be empty or contain hundreds of key-value pairs

## usage
The set module is defined in set.h and implemented in set.c, and exports the following functions from set.h

```c
/*create a new set, and return null if error. */
set_t *set_new(void);

/*inserts a key value pair but returns false if the key and value pair already exist*/
bool set_insert(set_t *set, const char *key, void *item);

/*finds the value associated with the given key and returns the value, but returns null if the value doesn't exist*/
void *set_find(set_t *set, const char *key);

/*prints the whole set, prints null if set is null*/
void set_print(set_t *set, FILE *fp, 
               void (*itemprint)(FILE *fp, const char *key, void *item) );

/*iterates through the set and counts the number of key value pairs*/
void set_iterate(set_t *set, void *arg,
                 void (*itemfunc)(void *arg, const char *key, void *item) );

/*deletes the set and frees all memory*/               
void set_delete(set_t *set, void (*itemdelete)(void *item) );

## implementation  
we implemented the set as a linked list. The set itself is represented by a struct with pointer to head, which it self is a local struct that has key and void variables and a pointer to next node

## Assumptions 
No assumptions beyond these that are clear from the spec. 

## compilations 
to compile simply 'make set.o'

to test simply 'make test'
See [TESTING](TESTING.md) for details of testing and an example test run.

