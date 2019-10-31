#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

/* declare functions */
void inorder_print(BStree bst, int i);
int get_position ( int i, BStree bst, Key *key);


BStree bstree_ini(int size) 
{   
	BStree p;

	/* allocate memory for pointer, and pointer members */
	p = (BStree_struct*) malloc(sizeof(BStree_struct));
	p ->tree_nodes = (Node*) malloc((size+1)* sizeof(Node));
	p ->is_free = (unsigned char*)malloc ((size +1)* sizeof(unsigned char));
    	p -> size = size;
	int k = 0;
	for ( k; k < size+1 ; k++)
        	p ->is_free[k] = '1';     
	return p;
}
    

void bstree_insert(BStree bst, Key *key, int data) 
{  
    int pos = get_position( 1, bst, key);

    /*do nothing if key is already in tree*/
	 if (pos == -1);

	/* stop if array index id out of bounds */ 
    		else {
			if (pos == -2)
				printf("\nArray index out of bounds. The Entry : {(%s, %d) - %d}  not inserted.\n", (*key).name ,(*key).id,  data);
			else {
      				(bst-> tree_nodes[pos]).key = key;  
        			(bst-> tree_nodes[pos]).data = data;
				bst -> is_free[pos] = '0';
    			}
		}
}


/* helper function (recursive) */
int get_position ( int i, BStree bst, Key *key){
	int pos;   

	/* if position is out of bounds, throw error */    
	if (bst->size +1  < i){
		return -2;} 

    /* if node is empty, return position of the node */   
	if ((bst ->is_free[i])== '1'){
		return i;}
    
    /* if node is not empty */
	else{
    		if (bst ->is_free[i] == '0'){

        	/* compare key of node at i-th position with given key */
		int where = key_comp(*(bst->tree_nodes[i].key), *key);
       
		/* if keys are equal, return a negative value */
        	if (where == 0)
            		return -1;
        
        	/* if key at node is greater than parameter, go to left child */
        	if (where > 0)
            		pos = i*2;
        
        	/* if key at node is less than parameter, go to right child */
        	else {
            		if (where < 0)
            			pos = (i*2)+1;
       		 }
        
        	/* recursively call next position */
        	int q = get_position(pos, bst, key);
		return q;
    }}
}


void bstree_traversal(BStree bst) {

    	/* call helper function */
	inorder_print(bst, 1);
}

/* helper function (recursive) */
void inorder_print(BStree bst, int i){
    
	/* call left child if not empty*/
	if (bst-> is_free[(2*i)] == '0')
        	inorder_print(  bst, 2*i);
    
	/* print root*/	
    	print_node( bst->tree_nodes[i]);
    
	/* call right child if not empty */
	if (bst-> is_free[(2*i)+1] == '0')
 		inorder_print (bst, (2*i)+1);
}


void bstree_free(BStree bst) {
	
	/* free all key pointers */
	int i =1;
	for ( i; i < bst-> size+1 ; i++)
		free( bst->tree_nodes[i].key);
	
	/* free treeNodes */    
	free (bst->tree_nodes);

	/* free is free */
    	free(bst->is_free);

	/* free tree */
    	free(bst);  
}

	
