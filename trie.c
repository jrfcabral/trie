//trie.c
//author:João Cabral (joaofigueiredocabral@gmail.com)
//date of creation: 26 of March, 2015
#include <stdlib.h>
#include "trie.h"

void trieCreate(trieNode_t* trie)
{
    if ( (trie = calloc(1, sizeof(trieNode_t)) == NULL ){
        fprintf(stderr, "Calloc error at trieCreate()\n";
        exit(-1);
    }
    
    trie->key = '0';
    trie->next = NULL;     
    trie->previous = NULL;
    trie->child = NULL;
    trie->parent = NULL;
    trie->val = NULL;    
}

