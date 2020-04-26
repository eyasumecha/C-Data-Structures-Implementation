# CS50 Lab 3
## Eyasu Lemma, CS50 Spring 2020

### hash

a hashtable is a number of slots that are a set data structure themseleves, and each set holds a key value pair

## usage
the hashtable module is defined in hashtable.h and implemented in hashtable.c, and exports the following functions from hashtable.h

```c
/*create a new hashtbale and return null if error.*/
hashtable_t *hashtable_new(const int num_slots);

/*insert a key and value pair into the hashtable, and return false if it already exists or if paramertic invalidity*/
bool hashtable_insert(hashtable_t *ht, const char *key, void *item);

/*find the value associated with the key and return that value, null if it doesnt exist or paramertic invalidity*/
void *hashtable_find(hashtable_t *ht, const char *key);

/*print each elements in the hashtable, print null if hashtable is null*/
void hashtable_print(hashtable_t *ht, FILE *fp, 
                     void (*itemprint)(FILE *fp, const char *key, void *item));

/*iterate through the set and return the count of key-value pairs*/
void hashtable_iterate(hashtable_t *ht, void *arg,
                       void (*itemfunc)(void *arg, const char *key, void *item) );

/*delete the hash and free allocated memories*/
void hashtable_delete(hashtable_t *ht, void (*itemdelete)(void *item) );


## implementation
we implemented the hashtable as a pointer to a specific number of sets that are implemented as linked list. 

## Assumptions 
No assumptions beyond these that are clear from the spec. 

## compilations 
to compile simply make hashtable.o

to test simply make test
See [TESTING](TESTING.md) for details of testing and an example test run.
