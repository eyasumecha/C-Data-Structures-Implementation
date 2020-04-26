/* 
 * set.c - CS50 'set' module
 *
 * see set.h for more information.
 *
 * Eyasu Lemma, Spring 2020
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"
#include "memory.h"

/**************** local types ****************/
typedef struct setnode {           //defining local helper setnode for elements of the set
    void *item;                     //will have key and the unspecified item and 
    char *key;                      // pointer to next node
    struct setnode *next;
} setnode_t;


typedef struct set {                //the set structure will just have a head node
    struct setnode *head;
}set_t;


static setnode_t *setnode_new(char *key, void *item){        //prototype header for setnode creator and static

    setnode_t *node = count_malloc(sizeof(setnode_t));      //dynamically assign memory
    if(node == NULL){
        return NULL;            //return null if allocation erroe occured
    }
    else{
        node->key = calloc(1, strlen(key) +1);       //if allocation coorect then set key and item for node
        strcpy(node->key, key);
        node->item = item;
        return node;            //return node when done
    }
}  

set_t *set_new(void){
    set_t *set = count_malloc(sizeof(set_t));  //allocate enough size for the set

    if(set == NULL){
        return NULL; //error allocating set
    }
    else{
        set->head = NULL; //initalize head to null
        return set;
    }
}

bool set_insert(set_t *set, const char *key, void *item){      //insert method       

    if( set != NULL && key != NULL && item != NULL){
        for(setnode_t *node = set->head; node != NULL; node = node->next){
            if(strcmp(node->key, key) == 0){           //if key already exists return false, dont insert item
                printf("exists already \n");
                return false;
            }
        }
        setnode_t *new = setnode_new((char*)key, item);  //if key doesnt exist then create a new node
        printf("created\n");
        if(new != NULL){
            new->next = set->head;      //insert at the head of the set and return true
            set->head = new;
            return true;
        }
    }
    
    return false;       //if any of the parameters null, then return false
    
}

void *set_find(set_t *set, const char *key){        //find an item method given key
    if(set != NULL && key != NULL){         //if no paramteres null
        for(setnode_t *node = set->head; node != NULL; node = node->next){
            if(strcmp(node->key, key) == 0){       //iterate through each node, compare key 
                return node->item;      // and if it equals return item
            }
        }
    }
    
    return NULL;        //else just return null
    
}

void set_print(set_t *set, FILE *fp, void (*itemprint)(FILE *fp, const char *key, void *item)){
    if(fp != NULL){
        if(set != NULL){
            fprintf(fp, "{ ");
            for(setnode_t *node = set->head; node != NULL; node = node->next){
                if(itemprint != NULL) {     //iterate through each node if set isnt null
                    fprintf(fp, " ");       //then pprint the elements of the set
                    (*itemprint)(fp, node->key, node->item);
                }
            }
            fprintf(fp, " }\n");  //close the braces of the set elemments printed
        }
        else{
            fprintf(fp, "(null)");  //if set null just print null
        }
    }
}

void set_iterate(set_t *set, void *arg, void (*itemfunc)(void *arg, const char *key, void *item)){
    if(set != NULL && itemfunc != NULL) {
        for(setnode_t *node = set->head; node != NULL; node = node->next) {     //iterate through each set node
            (*itemfunc)(arg, node->key, node->item);                            //and find count
        }
    }
}

void set_delete(set_t *set, void (*itemdelete)(void *item)){
    if(set != NULL){
        for(setnode_t *node = set->head; node != NULL; ){       //iterate through each node
            count_free(node->key);                              // free key strings memory
            if(itemdelete != NULL) {                            //free the item memory 
                (*itemdelete)(node->item);
            }
            setnode_t *next = node->next;
            count_free(node);
            node = next;
        }
        count_free(set);            //then finally free the set memory 
    }
}








