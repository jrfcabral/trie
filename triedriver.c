//triedriver.c
//author:João Cabral (joaofigueiredocabral@gmail.com)
//date of creation: 26 of March, 2015
#include <assert.h>
#include "trie.h"
int main(){
	int i = 1;
	trieNode_t* t = NULL;

	trieCreate(&t);
	assert (t != NULL);
	trieInsert(t, "ana", &i);	
	
}

