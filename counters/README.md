# CS50 Lab 3
## Eyasu Lemma, CS50 Spring 2020

### counter

A counter is a linked list implementation that collects a number of keys and counter, which is 
how many times those keys have occured.
It could be empty or contain hundreds of key-count pairs.


## usage
The 'counter' module, defined in 'counter.h' and implemented in 'counters.c', implements a counter of int keys and their count number is also in int form, and exports following functions from 'counters.h'

```c
/*create a new counter, return null if error. */
counters_t *counters_new(void);

/* add a key, if it exists then increment its count
if it doesnt exists, add and set counter to 1, if error
return NULL*/
int counters_add(counters_t *ctrs, const int key);

/*return the counter paired with the key, if key
doesnt exist, return 0, null if ctrs doesn't exist*/
int counters_get(counters_t *ctrs, const int key);

/*set the current key value to the given counter, return false if
key doesn't exist or invalid parameters, else if worked return true*/
bool counters_set(counters_t *ctrs, const int key, const int count);

/*print each key-count pair of the counter, write out null if
ctrs is null, ignore if ctrs is null*/
void counters_print(counters_t *ctrs, FILE *fp);

/*count the number of key-count pairs*/
void counters_iterate(counters_t *ctrs, void *arg, 
                      void (*itemfunc)(void *arg, 
                                       const int key, const int count));

/*delete and free every allocated memory*/
void counters_delete(counters_t *ctrs);

### Implementation
we implemented the counter as a linked list. The counter itself is represented by a struct with pointer to head,
which it self is a local struct that has key and count int variables and a pointer to the next such node

## Assumptions 
No assumptions beyond those that are clear from the spec.

## compilation 
to compile simply `make counters.o`

to test simply `make test`
See [TESTING](TESTING.md) for details of testing and an example test run.