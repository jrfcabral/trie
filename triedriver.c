//triedriver.c
//author:João Cabral (joaofigueiredocabral@gmail.com)
//date of creation: 26 of March, 2015
#include <assert.h>
#include "trie.h"
int main(){
	int i = 2;
	trieNode_t* t = NULL;

	trieCreate(&t);
	assert (t != NULL);
	trieInsert(t, "anais", &i);	
	trieInsert(t, "berta", &i);
	trieInsert(t, "berto", &i);
	trieInsert(t, "fernando", &i);
	trieInsert(t, "fernanda", &i);
	trieInsert(t, "fernandina", &i);
	int *j = trieRetrieve(t, "anais");
	assert (*j == 2);

	return 0;
	
}

