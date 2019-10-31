#include <stdio.h>
#include <string.h>
#include "data.h"
#include <stdlib.h>

Key *key_construct(char *in_name, int in_id) 
{
	/*allocate memory for Key pointer*/ 
    	Key *p;
    	p = (Key*) malloc (sizeof(Key));

    	/*initialize Key*/
	(*p).name = strdup(in_name);
	(*p).id = in_id;

	/*return key pinter*/
    	return p;
}

int key_comp(Key key1, Key key2)
{
	/* compare name of keys */
	int x = strcmp( key1.name, key2.name);
	
	/* if key names  are equal, compare ids */
    	if (x==0)
    	{
        	if (key1.id > key2.id)
            		return 1;
        	if (key1.id < key2.id)
            		return -1;
   	 }
        return x;
}

void print_key(Key *key)
{
	printf("(");
	printf("%-15s", key ->name);
    	printf("%11d )", key ->id);
}

void print_node(Node node)
{
	print_key(node.key);
	printf("\t %d \n", node.data);
}
