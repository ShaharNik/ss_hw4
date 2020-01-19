#include "trie.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char* argv[])
{
	
	bool printInReverse = false;
	if (argc == 2 && strcmp(argv[1], "r") == 0)
		printInReverse = true;

	char str[50];//Assuming 50 it's enough for buffersize
	TrieNode* head = TrieNode_new();

	FILE * file = fopen("Sources/input.txt", "r");
	if (file)
	{
		while (fscanf(file, "%49s", str) == 1)
		{
			TrieNode_insert(head, str);
		}
		fclose(file);
	}

	str[0] = '\0';
	TrieNode_print(head, str, sizeof(str), printInReverse);

	TrieNode_delete(head);

	return 0;
}
