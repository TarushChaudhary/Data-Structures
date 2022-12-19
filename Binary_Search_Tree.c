#include<stdio.h>
#include<stdlib.h>
struct nodeType
{
	int val;
	
	struct nodeType * left; 	
	struct nodeType * right;	
};


typedef struct nodeType * nodeAddress;

nodeAddress search(nodeAddress root, int val){
	
	if (root == NULL) {return NULL;}
	
	if(val < root->val) {return search(root->left, val);} 
	
	else if (val > root->val) {return search(root->right, val);} 
	
	else {return root;}
}

nodeAddress search2(nodeAddress root, int val){
	if (root) {
				
		return root?((val==root->val)?root:((val < root->val)?search(root->left, val):search(root->right, val))):NULL;
	}
}

nodeAddress insert(nodeAddress root, int val){
	
	if (root == NULL) {return createNode(val);}
	
		if(val < root->val) { root->left = insert(root->left, val);} 
	else if (val > root->val) {root->right = insert(root->right, val);} 
	
	return root;
}

nodeAddress insert2(nodeAddress root, int val){
	if (root == NULL) {return createNode(val);}
	
	if(val < root->val){
		if(root->left){return insert(root->left, val);}
		else{root->left = createNode(val);
		return root->left;}
	}

	if(val > root->val){
		if(root->right){return insert(root->right, val);}
		else{root->right = createNode(val);
		return root->right;}
	}

	return root;
}

void inOrder(nodeAddress root){
	
	if(root->left){
		inOrder(root->left);
	}
	
	if(root){
		printf("%d",root->val);
	}
	if(root->right){
		inOrder(root->right);
	}
}