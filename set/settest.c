/* 
 * settest.c - test program for CS50 set module
 *
 * usage: read user names from stdin

 * CS50, Spring 2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"
#include "readlinep.h"
#include "memory.h"
#include <stdbool.h>

void nameprint(FILE *fp, const char *key, void *item);
void namedelete(void* item);
static void itemcount(void *arg, const char *key, void *item);

int main(){
    set_t *set;
    int namecount = 0;

    //create a set
    set = set_new();
    if (set == NULL){
        fprintf(stderr, "set_new failed\n");
        return 1;
    }

    printf("testing set_insert: \n");
    char *key = (char*) calloc(100, sizeof(char));
    int *item = count_malloc(sizeof(int));
    //read from stadin key and interger item
   
    while(fscanf(stdin, "%s %d", key, item) != EOF){
        printf("%s %d\n", key, *item);
        if(set_insert(set, key, item)){
            item = count_malloc(sizeof(int));
        }
        
    }
    free(key);
    free(item);

    printf("Count: ");
    set_iterate(set, &namecount, itemcount);
    printf("%d\n", namecount);

    // test with null set, null item and null key
    printf("test with null set, null item and null key\n");
    bool test = set_insert(NULL, NULL, NULL);
    if(test == false){
        printf("set has worked\n");
    }
    else{
        fprintf(stderr, "set_insert error\n");
        return 1;
    }
    test = set_insert(set, NULL, NULL);
    if(test == false){
        printf("set has worked\n");
    }
    else{
        fprintf(stderr, "set_insert error\n");
        return 1;
    }

   


    //testing set_print
    printf("testing the print\n");
    set_print(set, stdout, nameprint);
    printf("\n");

    //testing with null set
    printf("testing the print with null set\n");
    set_print(NULL, stdout, nameprint);
    printf("\n");

    //testing set_find with appropriate key
    printf("testing set_find with appropriate key\n");
    int *n = set_find(set, "one");
    if( *n == 1){
        printf("set works\n");
    }
    else{
        fprintf(stderr, "error: set_find \n");
        return 1;
    }
    
    //testing set_find with non - appropriate key
    printf("testing set_find with non - appropriate key\n");
    if(set_find(set, "One hundred") == NULL){
        printf("set works\n");
    }
    else{
        fprintf(stderr, "error: set_find \n");
        return 1;
    }

    printf("deleting the set...\n");
    set_delete(set, namedelete);

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

