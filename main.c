/*
 * main.c
 *
 *  Created on: Feb 14, 2018
 *      Author: sheida
 */
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int key;
	struct node *left;
	struct node *right;
}node_t;

node_t *create_node(int);
int subtreecheck(node_t *,node_t *);
int identical(node_t *,node_t *);

int main(int argc,char argv[]){

	node_t *root1;
	node_t *root2;

	/*
	 * first tree construction
	 *       30
	 *     /     \
	 *   99       25
	 *   /  \
	 *  41  21
	 *  /  /
	 * 1  20
	 *
	 */

	root1=create_node(30);
	root1->left=create_node(99);
	root1->right=create_node(25);
	root1->left->left=create_node(41);
	root1->left->right=create_node(21);
	root1->left->left->left=create_node(1);
	root1->left->right->left=create_node(20);

	//second tree

	root2=create_node(99);
	root2->left=create_node(41);
	root2->right=create_node(21);
	root2->left->left=create_node(1);
	root2->right->left=create_node(20);
	if(subtreecheck(root1,root2)){
		printf("tree 2 is a subtree of tree 1!\n");

	}else
		printf("they're not subtree!\n");




	return 0;
}

node_t *create_node(int key){
	node_t *node;
	node=(node_t *)malloc(sizeof(node_t));
	if(node== NULL){
		printf("Allocation ERROR !");
		return 1;
	}
	node->key=key;
	node->right=NULL;
	node->left=NULL;

	return node;
}

int subtreecheck(node_t *r1,node_t *r2){

	if(r1==NULL && r2 == NULL){

		return 1;
	}
	if(r1==NULL || r2==NULL){
		return 0;
	}
	if(identical(r1,r2)){
		return 1;
	}
	return subtreecheck(r1->left,r2);
	return subtreecheck(r2->left,r2);
}
int identical(node_t *r1,node_t *r2){

	if(r1==NULL && r2 == NULL){

			return 1;
		}
		if(r1==NULL || r2==NULL){
			return 0;
		}
return(r1->key==r2->key && identical(r1->left,r2->left) && identical(r1->right,r2->right));

}

