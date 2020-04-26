/* 
 * counters.c - CS50 'bag' module
 *
 * see counters.h for more information.
 *
 * Eyasu Lemma, Spring 2020
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counters.h"
#include "memory.h"

/**************** file-local global variables ****************/
/* none */

/**************** local types ****************/

typedef struct node{
    int counter;           //each node which has a counter
    int key;          // and the key value
    struct node *next;

}node_t;

/**************** global types ****************/
typedef struct counters{
    struct node *head;  //head of the counter data structure 

}counters_t;

static node_t *new_node(const int key); //support local data type for the counter structure 

counters_t *counters_new(void){
    counters_t *counter = count_malloc(sizeof(counters_t)); 

    if(counter == NULL){
        return NULL;        //error allocating counter
    }
    else{
        counter->head = NULL;
        return counter;
    }
}

int counters_add(counters_t *ctrs, const int key){    //addd the counter of the key given
  
    if( ctrs != NULL && key >= 0){           //check if the key exists and if key non negative
        for(node_t *node = ctrs->head; node != NULL; node = node->next){
            if(node->key == key){    //find if the key exists, increment count and return
                node->counter += 1;
                return node->counter;
            }
        }
        node_t *new = new_node(key);   //if the key doesn't exist, create it
        if( new != NULL){               //increment count and return 
            new->next = ctrs->head;
            ctrs->head = new;
            return new->counter;
        }
    }
    
    return 0;
}

/**************** new_node ****************/
/* Allocate and initialize a counter node */
// the 'static' modifier means this function is not visible 
// outside this file

static node_t *new_node(const int key){

    node_t *node = count_malloc(sizeof(node_t));  //allocate memory dynamically for node
    if(node != NULL){
        node->counter = 1;      //set its counter to 1
        node->key = key;        //set its key to given parametric value
        node->next = NULL;      //set its next to NULL
        return node;
    }
    else{
        return NULL;        //error allocating node 
    }    
}





int counters_get(counters_t *ctrs, const int key){

    if( ctrs != NULL && key >= 0){           //check if the key exists and if key non negative
        for(node_t *node = ctrs->head; node != NULL; node = node->next){
            if(node->key == key){    //find if the key exists and return its counter
                return node->counter;
            }
        }
    }

    return 0;           //return 0 if key doesn't exist or counter null
}

bool counters_set(counters_t *ctrs, const int key, const int count){

   if( ctrs != NULL && key >= 0 && count >= 0){       //check if the key exists and if key non negative
       for(node_t *node = ctrs->head; node != NULL; node = node->next){
            if(node->key == key){       //find if the key exists, change its count and return true
                node->counter = count;
                return true;
            }
        }
        node_t *new = new_node(key);   //if the key doesn't exist, create it
        if( new != NULL){               //update count and return true
            new->next = ctrs->head;
            ctrs->head = new;
            new->counter = count;
            return true;
        }
    }
                            //if pointer null or key invalid return false
    return false;
}

void counters_print(counters_t *ctrs, FILE *fp){
    if(fp != NULL){      //check if the file is opened and pointer isnt null
        if(ctrs != NULL){
            fprintf(fp, "{ ");
            for(node_t *node = ctrs->head; node != NULL; node = node->next){   //iterate through each node 
                fprintf(fp, "{%d,%d} ", node->key, node->counter);  //print in to the file the values
            }
            fprintf(fp, "}\n");  //close the braces
        }
        else{
            fprintf(fp, "(null)");   // if pointer null, then just write null into the file.  
        }
    }
}

void counters_iterate(counters_t *ctrs, void *arg, void (*itemfunc)(void *arg, const int key, const int count)){

    if (ctrs != NULL && itemfunc != NULL) {
    // call itemfunc with arg, on each item
    for (node_t *node = ctrs->head; node != NULL; node = node->next) {
      (*itemfunc)(arg, node->key, node->counter); 
        }
    }
}

void counters_delete(counters_t *ctrs){
    
    if(ctrs != NULL){
        for(node_t *node = ctrs->head; node != NULL; ){
            node_t *next = node->next;
            count_free(node);
            node = next;
        }
        count_free(ctrs);   //free the counter pointer
    }

}






