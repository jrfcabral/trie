//trie.h
//author:João Cabral (joaofigueiredocabral@gmail.com)
//date of creation: March 27th, 2015
#include <stdio.h>

typedef struct trieNode_t trieNode_t;
typedef struct trieNode_t Trie;

struct trieNode_t{
    trieNode_t* parent, *child, *next, *previous;
    char key;
    void* val;
};



void trieCreate(trieNode_t** trie);
void trieInsert(trieNode_t* trie, char* word, void* value);
void* trieRetrieve(trieNode_t* trie, char* word);
void trieSwap(trieNode_t* trie, char* word, void* value);
int  trieRemove(trieNode_t* trie, char* word);
void triefprint(FILE* stream, trieNode_t* trie);
void triesprint(char* string, trieNode_t* trie);
