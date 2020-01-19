#include "trie.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NUM_LETTERS (26)

typedef struct TrieNode {
	long unsigned int count;
	struct TrieNode* children[NUM_LETTERS];
} TrieNode;

TrieNode* TrieNode_new()
{
	TrieNode* n = (TrieNode*)malloc(sizeof(TrieNode));
	n->count = 0;
	int i;
	for(i=0; i < NUM_LETTERS; i++)
	{
		n->children[i] = NULL; //initiallize children
	}
	return n;
}

bool isUpper(char ch)
{
	if(ch>='A'&&ch<='Z')
		return true;
	return false;//the character isn't between 'A' to 'Z'
}
bool isLower(char ch)
{
	if(ch>='a'&&ch<='z')
		return true;
	return false;//the character isn't between 'a' to 'z'
}

void TrieNode_insert (TrieNode* head, const char* str)
{
	// make sure input pointers are pointing to initialized memory
	if (head == NULL || str == NULL)
		return;

	TrieNode* n = head;
	char currChar = *str;
	int index;
	while(*str++)
	{
		if (isUpper(currChar))
			currChar = currChar-'A'+'a';
		else if (!isLower(currChar))
		{
			currChar = *str;
			continue;
		}
		index = currChar - 'a';
		if(n->children[index] == NULL)	
			n->children[index] = TrieNode_new();
		n = n->children[index];
		currChar = *str;
	}
	n->count++;
}

unsigned long int TrieNode_search (const TrieNode* head, const char* str)
{
	// make sure input pointers are pointing to initialized memory
	if (head == NULL || str == NULL)
		return 0;

	TrieNode const * n = head;
	char currChar = *str;
	int index;
	while(*str++)
	{
		if (isUpper(currChar))
			currChar = currChar-'A'+'a';
		else if (!isLower(currChar))
		{
			currChar = *str;
			continue;
		}
		index = currChar - 'a';
		if(n->children[index] == NULL)	
			return 0;
		n = n->children[index];
		currChar = *str;
	}
	return n->count;
}

void TrieNode_delete (TrieNode* n)
{
	if (n == NULL)
		return;

	for (int i = 0; i < NUM_LETTERS; ++i)
	{
		TrieNode_delete(n->children[i]);
	}

	free(n);
}

void TrieNode_print(TrieNode* head, char prefix[], int prefixBufferSize, bool printInReverse)
{
	// if head points to NULL then there's nothing to print
	if (head == NULL || prefix == NULL)
		return;

	if (!printInReverse)
	{
		// if current node has a non-zero count, then it should be printed
		if (head->count > 0)
			printf("%s\t%ld\n",prefix, head->count);
	}

	int prefixLength = strlen(prefix);
	if (prefixLength < prefixBufferSize - 1)
	{
		int letterIdx;
		for (int i = 0; i < NUM_LETTERS; ++i)
		{
			if (printInReverse)
				letterIdx = NUM_LETTERS - i - 1;
			else
				letterIdx = i;
			prefix[prefixLength] = 'a' + letterIdx;
			prefix[prefixLength + 1] = '\0';
			TrieNode_print(head->children[letterIdx], prefix, prefixBufferSize, printInReverse);
		}
		prefix[prefixLength] = '\0';
	}

	if (printInReverse)
	{
		// if current node has a non-zero count, then it should be printed
		if (head->count > 0)
			printf("%s\t%ld\n",prefix, head->count);
	}
}