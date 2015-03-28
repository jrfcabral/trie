//trie.c
//author:João Cabral (joaofigueiredocabral@gmail.com)
//date of creation: March 27th, 2015
//ideas of implementation taken from https://www.cs.bu.edu/teaching/c/tree/trie/
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "trie.h"

static trieNode_t* createNode(char key, void* val);
static void trieCascadeInsert(trieNode_t* rootNode, char* word, void* val);


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
        
        if (trieRoot->child == NULL){
            trieCascadeInsert(trieRoot, word, value);
            return;
        }
        
        trieRoot = trieRoot->child;
        
        while(trieRoot->key != *word){        
            if (trieRoot->next == NULL){ 
                if (!*(word+1))
                    trieRoot->next = createNode(*word, value);
                else
                    trieRoot->next = createNode(*word, NULL);
                trieRoot->previous = trieRoot;
            }
            else        
                trieRoot = trieRoot->next;
        }
        
        word++;
        
                             
        
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

void trieSwap(trieNode_t* trieRoot, char* word, void* value)
{
     if (trieRoot == NULL || word == NULL)
     return ;
     
     for(;*word;word++){
        if (trieRoot->child == NULL) 
            return;
        trieRoot = trieRoot->child;
        while(trieRoot->key != *word){
            if (trieRoot->next == NULL) 
                return;
            trieRoot = trieRoot->next;
        }            
     }
     if (trieRoot->val != NULL)
         trieRoot->val = value;
        
}

int  trieRemove(trieNode_t* trieRoot, char* word)
{
    if (trieRoot == NULL || word == NULL)
    return -2;
     
    for(;*word;word++){
       if (trieRoot->child == NULL) 
           return -1;
       trieRoot = trieRoot->child;
       while(trieRoot->key != *word){
           if (trieRoot->next == NULL) 
               return -1;
           trieRoot = trieRoot->next;
       }            
    }
     
    if (trieRoot->val != NULL)
       trieRoot->val = NULL;  
           
    while(trieRoot->child == NULL){
        if(trieRoot->next != NULL)
            trieRoot->parent->child = trieRoot->next;
        trieNode_t* temp = trieRoot->parent;
        free(trieRoot);
        trieRoot = temp;
    } 
    return 0;
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
    
    newNode->key = key;
    newNode->next = NULL;     
    newNode->previous = NULL;
    newNode->child = NULL;
    newNode->parent = NULL;
    newNode->val = val;

    return newNode;    
}

