#include <stdio.h>
#include "bst.h"
#include <string.h>
#include <stdlib.h>

int main(void){
    
   /* declare all variables and struct types */
    char name[100], *token,  str_id[10],  str_data[10] ,  str[100];
    int id, data;

   /* initialize tree */ 
    BStree bst;
    bst = bstree_ini(10);

   /* get key and data pair from stdin */
    while(1){ 
    	printf ("Please enter key, data pair, or E to exit\n ");
    	fgets(str, 100, stdin);
	
	/* exit loop if enf of file or user exits with "E" */
	if ( feof(stdin) | str[0] == 'E')
                break;

	/* if not at the end, break str from stdin into tokens */
 	strcpy(name, strtok(str, ","));
	strcpy(str_id, strtok (NULL, ","));
	strcpy (str_data, strtok ( NULL, ","));

	/* convert string to integers */
	id =  atoi (str_id);
        data =  atoi (str_data);

	/* insert key, data pair into tree */ 
        bstree_insert(bst, key_construct(name, id), data);

    }
   printf("\n");

   /* transverse tree then free allocated memory */
   if (bst->is_free[1] == '0')
   bstree_traversal(bst);
   bstree_free(bst);

}
