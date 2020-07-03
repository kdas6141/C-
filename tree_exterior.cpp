#include <iostream>
#include <vector>
#include <memory>
#include <stack>
#include <unordered_map>
#include <cassert>

using namespace std;

template <typename T>

struct TreeNode {
	T val;
	unique_ptr<TreeNode<T>> left, right;
};

//capture the nodes from the root to the leftmost leaf
void LeftBoundary(const unique_ptr<TreeNode<int>> &subtree,
	vector<const unique_ptr<TreeNode<int>> *> *exterior_ptr,
	vector<int> &valt) {
	if (subtree == nullptr ||
		(subtree->left == nullptr && subtree->right == nullptr))
		return;

	exterior_ptr->emplace_back(&subtree);
	valt.emplace_back(subtree->val);
	if (subtree->left != nullptr) {
		LeftBoundary(subtree->left, exterior_ptr, valt);
	} else {
		LeftBoundary(subtree->right, exterior_ptr, valt);
	}
}

//capture the nodes from rightmost leaf to the root
void RightBoundary(const unique_ptr<TreeNode<int>> &subtree,
	vector<const unique_ptr<TreeNode<int>> *> *exterior_ptr,
	vector<int> &valt) {

	if (subtree == nullptr ||
		(subtree->left == nullptr && subtree->right == nullptr))
		return;

	if (subtree->right != nullptr) {
		RightBoundary(subtree->right, exterior_ptr, valt);
	} else {
		RightBoundary(subtree->left, exterior_ptr, valt);
	}
	exterior_ptr->emplace_back(&subtree);
	valt.emplace_back(subtree->val);
}

//capture the nodes from left to the right
void Leaves(const unique_ptr<TreeNode<int>> &subtree,
	vector<const unique_ptr<TreeNode<int>> *> *exterior_ptr,
	vector<int> &valt) {

	if (subtree == nullptr)
		return;

	if (subtree->left == nullptr && subtree->right == nullptr){
		exterior_ptr->emplace_back(&subtree);
		valt.emplace_back(subtree->val);
		return;
	}

	Leaves(subtree->left, exterior_ptr, valt);
	Leaves(subtree->right, exterior_ptr, valt);
}

vector<const unique_ptr<TreeNode<int>> *> ExteriorBinaryTree(
	const unique_ptr<TreeNode<int>> &tree, vector<int> &valt) {

	if (tree == nullptr) {
		return {};
	}

	vector<const unique_ptr<TreeNode<int>> *> exterior{&tree};
	valt.emplace_back(tree->val);
	LeftBoundary(tree->left, &exterior, valt);
	Leaves(tree->left, &exterior, valt);
	Leaves(tree->right, &exterior, valt);
	RightBoundary(tree->right, &exterior, valt);
	return exterior;
} 

unique_ptr<TreeNode<int>> BTFromPreorderInorder(
	const vector<int> &preorder, size_t ps, size_t pe, size_t is, size_t ie,
	unordered_map<int, size_t> &node_to_inorder_idx) {

	if (pe<=ps || ie<=is) {
		return nullptr;
	}
	size_t root_inorder_idx = node_to_inorder_idx.at(preorder[ps]);
	size_t left_subtree_size = root_inorder_idx - is + 1;

	return make_unique<TreeNode<int>> (TreeNode<int> {
		preorder[ps],
		//left subtree
		BTFromPreorderInorder(preorder, ps+1, ps+left_subtree_size,
							is, root_inorder_idx, node_to_inorder_idx),
		//right subtree
		BTFromPreorderInorder(preorder, ps+left_subtree_size, pe,
							root_inorder_idx+1, ie, node_to_inorder_idx)});
}

unique_ptr<TreeNode<int>> BTFromPreorderInorder(
	const vector<int> &preorder, const vector<int> &inorder) {
	unordered_map<int, size_t> node_to_inorder_idx;
	for(size_t i=0; i<size(inorder); i++) {
		node_to_inorder_idx.emplace(inorder[i], i);
	}

	return BTFromPreorderInorder(preorder, 0, size(preorder), 0, 
								size(inorder), node_to_inorder_idx);
}

void BTFree(unique_ptr<TreeNode<int>> &root) {

	if (root == nullptr)
		return;
	if (root->left == nullptr && root->right == nullptr) {
		TreeNode<int> *temp = root.release();
		assert(root == nullptr);
		delete temp;
	}
	BTFree(root->left);
	BTFree(root->right);
}

void TreeTraversalPre(const unique_ptr<TreeNode<int>> &root) {
	if (root){
		//preorder
		cout << " " << root->val;
		TreeTraversalPre(root->left);
		TreeTraversalPre(root->right);
	}
}

void TreeTraversalIn(const unique_ptr<TreeNode<int>> &root) {
	if (root){
		TreeTraversalIn(root->left);
		//inorder
		cout << " " << root->val;
		TreeTraversalIn(root->right);
	}
}

void TreeTraversalPost(const unique_ptr<TreeNode<int>> &root) {
	if (root){
		TreeTraversalPost(root->left);
		TreeTraversalPost(root->right);
		//postorder
		cout << " " << root->val;
	}
}

int main(){
	const vector<int> inorder = {4, 3, 5, 2, 6, 8, 7, 1, 10, 12, 13, 11, 14, 9, 15, 16};
	const vector<int> preorder = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
	unique_ptr<TreeNode<int>> root =  BTFromPreorderInorder(preorder, inorder);
	vector<const unique_ptr<TreeNode<int>> *> ebt;
	vector<int> valt;
	cout << "PreOrder: ";
	TreeTraversalPre(root);
	cout << endl << "InOrder: ";
	TreeTraversalIn(root);
	cout << endl << "PostOrder: ";
	TreeTraversalPost(root);
	ebt = ExteriorBinaryTree(root, valt);
	cout << endl << "Exterior BT:";
	for (auto v: valt)
		cout << " " << v;
	BTFree(root);
}