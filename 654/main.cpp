#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    TreeNode* buildTree(const vector<int>& nums, int start, int end) {
        if (start >= end) {
            return nullptr;
        }

        int max_val = numeric_limits<int>::min();
        int max_index = -1;

        for (int i = start; i < end; ++i) {
            if (nums[i] > max_val) {
                max_val = nums[i];
                max_index = i;
            }
        }

        TreeNode* root = new TreeNode(max_val);
        root->left = buildTree(nums, start, max_index);
        root->right = buildTree(nums, max_index+1, end);

        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildTree(nums, 0, nums.size());
    }
};

int main() {
    Solution s;
    vector<int> inputs({3,2,1,6,0,5});
    s.constructMaximumBinaryTree(inputs);
    
    cout << "Test" << endl;
    return 0;
}
