//trie.c
//author:João Cabral (joaofigueiredocabral@gmail.com)
//date of creation: 26 of March, 2015
#include <stdlib.h>
#include <assert.h>
#include "trie.h"

static trieNode_t* createNode(char key, void* val);
static void trieCascadeInsert(trieNode_t* rootNode, char* word, void* val);
//static void printdebug(const char* message);


void trieCreate(trieNode_t** trie)
{

    *trie = createNode(0, NULL);   
    assert(*trie != NULL);

}


void trieInsert(trieNode_t* trieRoot, char* word, void* value)
{

    if (trieRoot == NULL || word == NULL || value == NULL)
        return;
    
    while( *word != 0){
        //cascade insert
        if (trieRoot->child == NULL){
            trieCascadeInsert(trieRoot, word, value);
            return;
        }
        //jump to child
        trieRoot = trieRoot->child;
        //go through all of this level's nodes, create one at the end if key not found
        while(trieRoot->key != *word){
            //printf("searching for neighbour %c, am at key %c\n", *word, trieRoot->key);
            if (trieRoot->next == NULL){
                //printf("end of this level's without finding %c\n", *word);

                if (!*(word+1))
                    trieRoot->next = createNode(*word, value);
                else
                    trieRoot->next = createNode(*word, NULL);
                trieRoot->previous = trieRoot;
            }
            else
                //printf("key %c has neighbour with key %c\n", trieRoot->key, trieRoot->next->key);
            trieRoot = trieRoot->next;
        }
        
        word++;
        //printf("advanced to %c\n", *word);
                             
        
    }   
    
}

void* trieRetrieve(trieNode_t* trieRoot, char* word)
{
     if (trieRoot == NULL || word == NULL)
        return NULL;
     
     for(;*word;word++){
        if (trieRoot->child == NULL) 
            return NULL;
        trieRoot = trieRoot->child;
        while(trieRoot->key != *word){
            if (trieRoot->next == NULL) 
                return NULL;
            trieRoot = trieRoot->next;
        }            
     }
     return trieRoot->val;
     
}


static void trieCascadeInsert(trieNode_t* rootNode, char* word, void* val)
{
    assert(rootNode->child == NULL);

    if (!*word)
        return;        
    if (!*(word+1))
        rootNode->child = createNode(*word, val);    
    else
        rootNode->child = createNode(*word, NULL);    
    rootNode->child->parent = rootNode;
    
    trieCascadeInsert(rootNode->child, ++word, val);     
}

static trieNode_t* createNode(char key, void* val)
{

    trieNode_t* newNode = calloc(1, sizeof(trieNode_t));
    if (newNode == NULL){
        //fprintf(stderr, "Calloc error at createNode()");
        exit(-1);
    }
    
    printf("creating node with key %c with val %d\n", key, val == NULL);
    newNode->key = key;
    newNode->next = NULL;     
    newNode->previous = NULL;
    newNode->child = NULL;
    newNode->parent = NULL;
    newNode->val = val;

    return newNode;    
}


/*static void printdebug(const char* message){
#ifndef NODEBUG
    //printf(message);
#endif
}*/
