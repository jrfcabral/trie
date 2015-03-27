//trie.h
//author:João Cabral (joaofigueiredocabral@gmail.com)
//date of creation: 26 of March, 2015


typedef struct {
    trieNode_t* parent, child, next, previous;
    char key;
    void* val;
}trieNode_t;

void trieCreate(trieNode_t* trie);
void trieInsert(trieNode_t* trie, char* word, void* value);
void* trieRetrieve(trieNode_t* trie, char* word);
void trieSwap(trieNode_t* trie, char* word, void* value, int force = 0);
int  trieRemove(trieNode_t* trie, char* word);
void triefprint(FILE* stream, trieNode_t* trie);
void triesprint(char* string, trieNode_t* trie);
