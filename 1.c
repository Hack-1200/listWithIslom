#include <stdio.h>
#include <stdlib.h>
typedef int tInfo;
typedef struct Node{
	tInfo x;
	struct Node *next;
} node;

void *create(){
	node *root;
	root=(node*)malloc(sizeof(node));
	root->next=NULL;
	root->x=0;
	return root;
}


int main(){
	node *root=create();


}

