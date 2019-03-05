#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): val(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(int start, int end) {
        if (end - start == 0) {
            return nullptr;
        }

        int mid = (start+end) / 2;
        TreeNode* root = new TreeNode(mid);
        root->left = buildTree(start, mid);
        root->right = buildTree(mid+1, end);

        return root;
    }
    int travelTo(TreeNode* root, int target) {
        int pay = 0;
        while (true) {
            if (root->val == target) {
                break;
            }
            else {
                pay += root->val;
                if (root->val > target) {
                    root = root->left;
                }
                else {
                    root = root->right;
                }
            }
        }

        return pay;
    }
    int getMoneyAmount(int n) {
        TreeNode* root = buildTree(0, n);
        std::cout << travelTo(root, 8-1) << std::endl;
        //for (int i = 1; i <= n; ++i) {
            //std::cout << travelTo(root, i) << std::endl;
        //}
    }
};

int main() {
    Solution s;

    s.getMoneyAmount(10);
    cout << "Test" << endl;
    return 0;
}
