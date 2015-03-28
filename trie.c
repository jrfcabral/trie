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

    trieNode_t* currNode = trieRoot;
    while( *word != 0){
        //cascade insert
        if (currNode->child == NULL){
            trieCascadeInsert(currNode, word, value);
            return;
        }
        //jump to child
        currNode = currNode->child;
        //go through all of this level's nodes, create one at the end if key not found
        while(currNode->key != *word){
            printf("searching for neighbour %c, am at key %c\n", *word, currNode->key);
            if (currNode->next == NULL){
                printf("end of this level's without finding %c\n", *word);

                if (!*(word+1))
                    currNode->next = createNode(*word, value);
                else
                    currNode->next = createNode(*word, NULL);
                currNode->previous = currNode;
            }
            else
                printf("key %c has neighbour with key %c\n", currNode->key, currNode->next->key);
            currNode = currNode->next;
        }
        
        word++;
        printf("advanced to %c\n", *word);
                             
        
    }   
    
}


static void trieCascadeInsert(trieNode_t* rootNode, char* word, void* val)
{
    assert(rootNode->child == NULL);

    if (!*word)
        return;        
    
    rootNode->child = createNode(*word, val);    
    rootNode->child->parent = rootNode;
    
    trieCascadeInsert(rootNode->child, ++word, val);     
}

static trieNode_t* createNode(char key, void* val)
{

    trieNode_t* newNode = calloc(1, sizeof(trieNode_t));
    if (newNode == NULL){
        fprintf(stderr, "Calloc error at createNode()");
        exit(-1);
    }
    
    printf("creating node with key %c\n", key);
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
    printf(message);
#endif
}*/
