#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

/* insert a node in a Tree in recursive method */
TreeNode *insertTreeNode(TreeNode *root, int val) {

	if (!root) {
		return new TreeNode(val);
	} 
	if (val <= root->val)
		root->left = insertTreeNode(root->left, val);
	else
		root->right = insertTreeNode(root->right, val);
	
	return root;
}

/* create a Tree in recursive method */
TreeNode *createTreeNodes(vector<int> nums) {

	TreeNode *root = NULL;

	for (auto n: nums)
		root = insertTreeNode(root, n);

	return root;
}

/* create a tree using level order traversal */
TreeNode* createLevelOrderTreeNodes(vector<int> &nums, TreeNode* root, 
                       				int i, int n) 
{ 
    // Base case for recursion 
    if (i < n)
    { 
        root =  new TreeNode(nums[i]);
  
        // insert left child 
        root->left = createLevelOrderTreeNodes(nums,
                   								root->left, 2 * i + 1, n); 
  
        // insert right child 
        root->right = createLevelOrderTreeNodes(nums,
                  								root->right, 2 * i + 2, n); 
    }

    return root; 
} 

/* create a Tree in recursive method */
void deleteTreeNodes(TreeNode *root) {

	if (!root)
		return;

	if (!root->left && !root->right) {
		delete root;
		root = NULL;
	} else {
		deleteTreeNodes(root->left);
		deleteTreeNodes(root->right);
	}
}

/* preorder recursive tree traversal */
void preOrderRecursiveTreeNodes(TreeNode * root) {
	if (!root)
		return;
	cout << root->val << " ";
	preOrderRecursiveTreeNodes(root->left);
	preOrderRecursiveTreeNodes(root->right);
}

/* preorder iterative tree traversal */
void preOrderIterativeTreeNodes(TreeNode * root) {
	stack<TreeNode*> st;

	if (!root)
		return;
	while (1) {
		while (root) {
			cout << root->val << " ";
			st.push(root);
			root = root->left;
		}
		if (st.empty())
			break;
		root = st.top(); st.pop();
		root = root->right;
	}
}

/* inorder tree traversal */
void inOrderRecursiveTreeNodes(TreeNode * root) {
	if (!root)
		return;
	inOrderRecursiveTreeNodes(root->left);
	cout << root->val << " ";
	inOrderRecursiveTreeNodes(root->right);
}

/* inorder iterative tree traversal */
void inOrderIterativeTreeNodes(TreeNode * root) {
	stack<TreeNode*> st;

	if (!root)
		return;
	while (1) {
		while (root) {
			st.push(root);
			root = root->left;
		}
		if (st.empty())
			break;
		root = st.top(); st.pop();
		cout << root->val << " ";
		root = root->right;
	}
}

/* postorder recursive tree traversal */
void postOrderRecursiveTreeNodes(TreeNode * root) {
	if (!root)
		return;
	postOrderRecursiveTreeNodes(root->left);
	postOrderRecursiveTreeNodes(root->right);
	cout << root->val << " ";
}

/* postorder iterative tree traversal */
void postOrderIterativeTreeNodes(TreeNode * root) {
	if (!root)
		return;
	stack<TreeNode *> st1, st2;
	TreeNode *t;

	st1.push(root);

	while(!st1.empty()) {
		t = st1.top(); st1.pop();
		st2.push(t);

		if (t->left)
			st1.push(t->left);
		if (t->right)
			st1.push(t->right);
	}

	while (!st2.empty()) {
		t = st2.top(); st2.pop();
		cout << t->val << " ";
	}
}

/* levelorder tree traversal */
void levelOrderIterativeTreeNodes(TreeNode * root) {
	queue<TreeNode *> q;
	if (!root)
		return;
	q.push(root);
	while(!q.empty()) {
		TreeNode* t = q.front(); q.pop();
		cout << t->val << " ";
		if (t->left)
			q.push(t->left);
		if (t->right)
			q.push(t->right);
	}
}

int main() {
	vector <int> nums = {10, 7, 14, 20, 1, 5, 8};
	TreeNode *root = createTreeNodes(nums);

	cout << "\nTree Node Values: ";
	for (auto n: nums)
		cout << n << " ";
	cout << "\nPreOrderRecursive Traversal: ";
	preOrderRecursiveTreeNodes(root);
	cout << "\nPreOrderIterative Traversal: ";
	preOrderIterativeTreeNodes(root);
	cout << "\nInOrderRecursive Traversal: ";
	inOrderRecursiveTreeNodes(root);
	cout << "\nInOrderIterative Traversal: ";
	inOrderIterativeTreeNodes(root);
	cout << "\nPostOrderRecursive Traversal: ";
	postOrderRecursiveTreeNodes(root);
	cout << "\nPostOrderIterative Traversal: ";
	postOrderIterativeTreeNodes(root);
	cout << "\nLevelOrderIterative Traversal: ";
	levelOrderIterativeTreeNodes(root);
	deleteTreeNodes(root);

	vector<int> nums2 = { 1, 2, 3, 4, 5, 6, 6, 6, 6 };
    TreeNode* root2 = createLevelOrderTreeNodes(nums2, NULL, 0, nums2.size());

    cout << "\n\nTree2 Node Values: ";
	for (auto n: nums2)
		cout << n << " ";
	cout << "\nPreOrderRecursive Traversal: ";
	preOrderRecursiveTreeNodes(root2);
	cout << "\nInOrderRecursive Traversal: ";
	inOrderRecursiveTreeNodes(root2);
	cout << "\nInOrderIterative Traversal: ";
	inOrderIterativeTreeNodes(root2);
	cout << "\nPostOrderRecursive Traversal: ";
	postOrderRecursiveTreeNodes(root2);
	cout << "\nPostOrderIterative Traversal: ";
	postOrderIterativeTreeNodes(root2);
	cout << "\nLevelOrderIterative Traversal: ";
	levelOrderIterativeTreeNodes(root2);
	deleteTreeNodes(root2);
}