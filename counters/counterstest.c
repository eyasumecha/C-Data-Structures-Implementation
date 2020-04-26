/* 
 * counterstest.c - test program for CS50 counters module
 *
 * usage: read user names from stdin

 * CS50, Spring 2020                                                                                                                                                                                                                                                                                                                                                                            
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counters.h"
#include "readlinep.h"

static void itemcount(void *arg, const int key, const int count); //defined helper function

int main(){
    counters_t *counter;
    int namecount = 0;

    //create a new counter
    counter = counters_new();
    if(counter == NULL){
        fprintf(stderr, "counter creation failed\n");
        return 1;
    }

    printf("testing counters_add:\n");
    int i;
    while(fscanf(stdin, "%d", &i) != EOF){
         int o = counters_add(counter, i);
         if(o >=1){
             printf("new counter: %d\n", o);
         }
         else{
             fprintf(stderr, "error: pointer null or invalid key\n");
             return 1;
         }
    }

    printf("Count: ");
    counters_iterate(counter, &namecount, itemcount);
    printf("%d\n", namecount);


    //testing counters_set
    printf("testing counter set: input key and count\n");
    int y,z;
    while (fscanf(stdin, "%d %d", &y, &z) != EOF){
        bool test = counters_set(counter, y, z);
        if(test == true){
            printf("set\n");
        }
        else{
            fprintf(stderr, "error: pointer null or key invalid\n");
        }
    }
    


    //testing counters_get
    printf("testing counter get\n");
    int x;
    while(fscanf(stdin, "%d", &x) != EOF){
        
        if(counters_get(counter, x) == 0){
            fprintf(stderr, "error: pointer is null or key not found\n");
        }
        else{
            fprintf(stdout, "counter for key is %d\n", counters_get(counter, x) );
        }
    }

    //testing counters_print
    printf("printing bag: ");
    counters_print(counter, stdout);


    //testing deleting 
    printf("deleting counter\n");
    counters_delete(counter);
    counter = NULL;

    return 0;
}

/* count the non-null items in the bag.
 */
static void itemcount(void *arg, const int key, const int count)
{
  int *nitems = arg;

  if (nitems != NULL)
    (*nitems)++;
}


