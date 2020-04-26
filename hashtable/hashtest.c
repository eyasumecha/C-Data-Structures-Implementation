/* 
 * settest.c - test program for CS50 set module
 *
 * usage: read user names from stdin

 * CS50, Spring 2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "memory.h"
#include "hashtable.h"

void nameprint(FILE *fp, const char *key, void *item);
void namedelete(void* item);
static void itemcount(void *arg, const char *key, void *item);

int main(){
    hashtable_t *hash;
    int namecount = 0;

    //create a hash
    hash = hashtable_new(6);
    if(hash == NULL){
        fprintf(stderr, "hashtable_new failed\n");
        return 1;
    }

    printf("testing hashtable_insert: \n");
    char *key = (char*) calloc(100, sizeof(char));
    int *item = count_malloc(sizeof(int));
    //read from stadin key and interger item
   
    while(fscanf(stdin, "%s %d", key, item) != EOF){
        printf("%s %d\n", key, *item);
        if(hashtable_insert(hash, key, item)){
            item = count_malloc(sizeof(int));
        }
        
    }
    free(key);
    free(item);

    printf("Count: ");
    hashtable_iterate(hash, &namecount, itemcount);
    printf("%d\n", namecount);

    //test with null hash, null item and null key
    printf("testing with null on insert method\n");
    bool test = hashtable_insert(NULL, NULL, NULL);
    if(test == false){
        printf("hashtable_insert has worked\n");
    }
    else {
        fprintf(stderr, "hashtable_insert has failed\n");
        return 1;
    }
    test = hashtable_insert(hash, NULL, NULL);
     if(test == false){
        printf("hashtable_insert has worked\n");
    }
    else {
        fprintf(stderr, "hashtable_insert has failed\n");
        return 1;
    }

    //testing hashtable_print
    printf("testing hashtable print\n");
    hashtable_print(hash, stdout, nameprint);
    printf("\n");

    //testing with null hash
    printf("testing with null hash\n");
    printf("testing the print\n");
    hashtable_print(NULL, stdout, nameprint);
    printf("\n");

    //testing hashtable_find with appropriate key
    printf("testing hashtable_find with appropriate key\n");
    int *n = hashtable_find(hash, "one");
    if( *n == 1){
        printf("hashtable_find works\n");
    }
    else{
        fprintf(stderr, "error: hashtable_find \n");
        return 1;
    }

    //testing hashtable_find with non - appropriate key
    printf("testing hashtable_find with appropriate key\n");
    if(hashtable_find(hash, "One hundred") == NULL){
        printf("hashtbale_find works\n");
    }
    else{
        fprintf(stderr, "error: hashtable_find \n");
        return 1;
    }

    printf("deleting the set...\n");
    hashtable_delete(hash, namedelete);
    printf("deleted\n");
    
    return 0;
}

//counts the items in a set
static void itemcount(void *arg, const char *key, void *item){
    int *nitems = arg;
    if(nitems != NULL && key != NULL && item != NULL)
        (*nitems)++;
}

//prints elements of the set
void nameprint(FILE *fp, const char *key, void *item){
    int *name = item;
    fprintf(fp, "{%s %d}", key, *name);
}

void namedelete(void *item){
    if(item != NULL){
        free(item);
    }
}


