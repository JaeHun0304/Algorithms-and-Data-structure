#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode{
	int data; // Stored data
	TreeNode* parent; // Pointer to parent node
	vector<TreeNode*> children; // Pointer to children nodes
};

void printLabels(TreeNode* root) {
	// When root is given, print all nodes
	cout << root->data << endl;
	// Call the all children nodes recursively
	for(int i = 0; i < root->children.size(); i++){
		printLabels(root->children[i]);
	}
}

int height(TreeNode* root){
	int h = 0;
	for(int i = 0; i < root->children.size(); i++)
		h = max(h, height(root->children[i]));
	return h;
}

int main(){

	TreeNode* sampleTree;
	TreeNode* children1; 
	TreeNode* children2;
	children1 -> data = 1;
	children2 -> data = 2;
	sampleTree -> data = 3;
	sampleTree -> children.push_back(children1);
	sampleTree -> children.push_back(children2);
	
	printLabels(sampleTree);
	cout << height(sampleTree) << endl;


	return 0;
}