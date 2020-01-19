#ifndef TRIE_H
#define TRIE_H
#include <stdbool.h>

typedef struct TrieNode TrieNode;

TrieNode* TrieNode_new();
void TrieNode_insert(TrieNode* head, const char* str);
unsigned long int TrieNode_search(const TrieNode* head, const char* str);
void TrieNode_delete(TrieNode* n);
void TrieNode_print(TrieNode* head, char prefix[], int prefixBufferSize, bool printInReverse);

#endif
