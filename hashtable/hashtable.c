/* 
 * hashtable.c - CS50 'hashtable' module
 *
 * see hashtable.h for more information.
 *
 * Eyasu Lemma, Spring 2020
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "memory.h"
#include "../set/set.h"
#include "jhash.h"

typedef struct hashtable{   //a struct for hashtable with mod for slots and 
    int mod;                //an array of set pointers 
    set_t **set;
} hashtable_t;

hashtable_t *hashtable_new(const int num_slots){  //initalize the sets 
    if(num_slots > 0){
        hashtable_t *hash = count_malloc(sizeof(hashtable_t));   //allocate memory for hash
        if(hash == NULL){
            return NULL;
        }
        hash->set = calloc(num_slots, sizeof(set_t*));
        for( int i = 0; i < num_slots; i++){
            hash->set[i] = set_new();       //allocate memory for each slot
        }
        hash->mod = num_slots;   //assign the mod to num_slots 
        return hash;
    }
    
    return NULL;
}

bool hashtable_insert(hashtable_t *ht, const char *key, void *item){
    if(ht != NULL && key != NULL && item != NULL){
        int x = (int)JenkinsHash(key, (unsigned long)ht->mod);  //insert in this slot 
        return (set_insert(ht->set[x], key, item));             // and call insert on it
    }
    return false;    

}

void *hashtable_find(hashtable_t *ht, const char *key){
    if(ht != NULL && key != NULL){
        int x = (int)JenkinsHash(key, (unsigned long)ht->mod); //find in this slot
        return set_find(ht->set[x], key);  //returned the found result 
    }
    return NULL;
}

void hashtable_print(hashtable_t *ht, FILE *fp, void (*itemprint)(FILE *fp, const char *key, void *item)){
    if(fp != NULL){
        if(ht != NULL){
            for(int i = 0; i < ht->mod; i++){
                if(itemprint != NULL){
                    set_print(ht->set[i], fp, (*itemprint)); //call set print on each set and print the elements 
                }
            }
        }
    } else {
        fputs("(null)", fp);
    }
}



void hashtable_iterate(hashtable_t *ht, void *arg, void (*itemfunc)(void *arg, const char *key, void *item) ){
    if(ht != NULL && itemfunc != NULL) {
        for(int i = 0; i < ht->mod; i++){
            if(itemfunc != NULL){
                set_iterate(ht->set[i], arg, (*itemfunc));   //iterate each set and return the count 
            }
        }
    }
} 

void hashtable_delete(hashtable_t *ht, void (*itemdelete)(void *item) ){
    if(ht != NULL){
        for(int i = 0; i < ht->mod; i++){  //delete the hash memory and every slot accounted 
            set_delete(ht->set[i], (*itemdelete)); //also delete the set by calling delete on every slot
        }
        count_free(ht->set);
        count_free(ht);
    }    
}





