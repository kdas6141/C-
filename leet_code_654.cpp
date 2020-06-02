#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    
private:
    int mloc(vector<int>& nums, int l, int r) {
        int max_i = l;
        for (int i=l; i<r; i++) {
            if (nums[max_i] < nums[i])
                max_i = i;
        }
        return max_i;
    }
    
    TreeNode *construct(vector<int>& nums, int l, int r) {
        if (l == r)
            return NULL;
        int max_i=mloc(nums, l, r);
        TreeNode *root = new TreeNode(nums[max_i]);
        root->left = construct(nums, l, max_i);
        root->right = construct(nums, max_i+1, r);
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums, 0, nums.size());
    }
};

int main() {
	vector<int> nums;
	struct TreeNode *t = NULL;
	Solution s;
	t = s.constructMaximumBinaryTree(nums);
	cout << "Hello World\n";
}