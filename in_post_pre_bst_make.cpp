#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode (): val(0), left(nullptr), right(nullptr){}
	TreeNode(int x): val(x), left(nullptr), right(nullptr){}
	TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

class BT {
private:
	int preindex = 0;

	/* get the index of the target value in an inorder tree */
	int getInorderIndex(vector<int> &inorder, int target) {
		for (int i=0; i<inorder.size(); i++) {
			if (inorder[i] == target)
				return i;
		}
		return -1;
	}

	TreeNode *buildBT(vector<int> &inorder, vector<int> &postorder,
						int s, int e, int ps, int pe) {

		if (s>e || ps>pe)
			return NULL;
		TreeNode * root = new TreeNode(postorder[pe]);
		int ii = getInorderIndex(inorder, postorder[pe]);
		root->left = buildBT(inorder, postorder, s, ii-1, ps, ps + ii-1-s);
		root->right = buildBT(inorder, postorder, ii+1, e, ps + ii-s, pe-1);
		return root;
	}

	TreeNode *buildBT(vector<int> &inorder, vector<int> &preorder,
						int s, int e) {

		if (s>e)
			return NULL;
		TreeNode * root = new TreeNode(preorder[preindex]);
		int ii = getInorderIndex(inorder, preorder[preindex++]);
		root->left = buildBT(inorder, preorder, s, ii-1);
		root->right = buildBT(inorder, preorder, ii+1, e);
		return root;
	}

public:
	TreeNode *buildBT(vector<int> &inorder, vector<int> &preorder, vector<int> &postorder) {
		if (postorder.size() == 0)
			return buildBT(inorder, preorder, 0, preorder.size()-1);

		return buildBT(inorder, postorder, 0, postorder.size()-1, 0, postorder.size()-1);
	}

	/* delete a Tree in recursive method */
	void deleteBT(TreeNode *root) {

		if (!root)
			return;

		if (!root->left && !root->right) {
			delete root;
			root = NULL;
		} else {
			deleteBT(root->left);
			deleteBT(root->right);
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

	/* inorder tree traversal */
	void inOrderRecursiveTreeNodes(TreeNode * root) {

		if (!root)
			return;
		inOrderRecursiveTreeNodes(root->left);
		cout << root->val << " ";
		inOrderRecursiveTreeNodes(root->right);
	}

	/* postorder recursive tree traversal */
	void postOrderRecursiveTreeNodes(TreeNode * root) {

		if (!root)
			return;
		postOrderRecursiveTreeNodes(root->left);
		postOrderRecursiveTreeNodes(root->right);
		cout << root->val << " ";
	}
};

void displayVector(vector<int> &nums, string header) {

	cout << header;
	for (auto n: nums)
		cout << n << " ";
}

int main() {

	vector<int> preorder = {10, 7, 1, 5, 8, 14, 20};
	vector<int> inorder = {1, 5, 7, 8, 10, 14, 20};
	vector<int> postorder = {5, 1, 8, 7, 20, 14, 10};
	vector<int> dummy = {};

	displayVector(inorder, "\nInorder List: ");
	displayVector(preorder, "\nPreorder List: ");
	displayVector(postorder, "\nPostorder List: ");
	BT bt;
	TreeNode *root = bt.buildBT(inorder, preorder, dummy);
	cout << "\nInorder TreeTraversal: ";
	bt.inOrderRecursiveTreeNodes(root);
	cout << "\nPreorder TreeTraversal: ";
	bt.preOrderRecursiveTreeNodes(root);

	TreeNode *root2 = bt.buildBT(inorder, dummy, postorder);
	cout << "\nInorder TreeTraversal: ";
	bt.inOrderRecursiveTreeNodes(root2);
	cout << "\nPostorder TreeTraversal: ";
	bt.postOrderRecursiveTreeNodes(root2);

	bt.deleteBT(root);
	bt.deleteBT(root2);
}