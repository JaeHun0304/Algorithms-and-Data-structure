/* Print the nodes in postorder when the preorder and inorder BST (Binary Search Tree)
  Nodes traverse history are given */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> slice(const vector<int>& v, int a, int b){
	return vector<int>(v.begin() + a, v.begin() + b);
}

void printPostOrder(const vector<int>& preorder, const vector<int>& inorder){
	// N = Total number of nodes in the tree
	const int N = preorder.size();
	// Base condition for the recursion
	if(preorder.empty()) return;

	// preorder first search root
	const int root = preorder[0];
	// size of left subtree = number of nodes before root in inorder traverse
	const int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();
	// right subtree size = total - left subtree - root(1)
	const int R = N - 1 - L;

	printPostOrder(slice(preorder, 1, L+1), slice(inorder, 0, L));
	printPostOrder(slice(preorder, L+1, N), slice(inorder, L+1, N));
	//Print root as last since this is postorder traverse
	cout << root << " ";

}


int main(){

	vector<int> preorder = {27, 16, 9, 12, 54, 36, 72};
	vector<int> inorder = {9, 12, 16, 27, 36, 54, 72};
	
	printPostOrder(preorder, inorder);

	return 0;
}