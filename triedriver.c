//triedriver.c
//author:João Cabral (joaofigueiredocabral@gmail.com)
//date of creation: March 27th, 2015
#include <assert.h>
#include "trie.h"
int main(){
	int i = 2;
	int j = 3;
	trieNode_t* t = NULL;

	trieCreate(&t);
	assert (t != NULL);
	trieInsert(t, "anais", &i);	
	trieInsert(t, "berta", &i);
	trieInsert(t, "berto", &i);
	trieInsert(t, "fernando", &i);
	trieInsert(t, "fernanda", &i);
	trieInsert(t, "fernandina", &i);
	trieRemove(t, "berta");
	int *k = trieRetrieve(t, "berta");
	assert (k == NULL);

	return 0;
	
}

