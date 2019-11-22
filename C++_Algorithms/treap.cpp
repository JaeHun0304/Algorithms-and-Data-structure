// For this tree, keytype is int
typedef int KeyType;

// Implementation of binary search tree in TREAP method
struct Node{
	// Element in the Node
	KeyType key;
	// prioirty of this node and sub-tree of this Node as a root
	int priority, size;
	// pointer to two children on left and right
	Node *left, *right;

	// Node constructor
	// priority initialized with rand() and initialzie left and right pointer with NULL
	Node(const KeyType& _key) : key(_key), priority(rand()),
	  size(1), left(NULL), right(NULL) {
	  }
	void sefLeft(Node* newLeft) {left = newLeft; calcSize();}
	void setRight(Node* newRight) {right = newRight; calcSize();}
	// Recalculate the member "size"
	void calcSize(){
		size = 1;
		if(left) size += left->size;
		if(right) size += right->size;
	}
}

typedef pair<Node*,Node*> NodePair;
// separate tree based on the value of the key
// left treap is smaller than key and right treap is bigger than key after split()
NodePair split(Node* root, KeyType key){
	if(root == NULL) return NodePair<NULL, NULL>;
	// if root < key, split right subtree
	if(root->key < key){
		NodePair rs = split(root->right, key);
		root->setRight(rs.first);
		return NodePair(root, rs.second);
	}

	// if root > key, split left subtree
	NodePair ls = split(root->left, key);
	root -> setLeft(ls.second);
	return NodePair(ls.first, root);
}

Node* insert(Node* root, Node* node){
	if(root == NULL) return node;

	if(root->prioirty < node->prioirty){
		NodePair splitted = split(root, node->key);
		node->sefLeft(splitted.first);
		node->setRight(splitted.second);
		return node;
	}
	else if(node->key < root->key)
		root->setLeft(insert(root->left, node));
	else
		root->setRight(insert(root->right, node));
	return root;
}