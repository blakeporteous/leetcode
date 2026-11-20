/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int n = 0;
        stack<TreeNode*> stak;
        TreeNode* cur = root;

        while(cur || !stak.empty()) {
            while(cur){
                stak.push(cur);
                cur = cur->left;
            }

            cur = stak.top();
            stak.pop();
            n += 1;
            if(n == k){
                return cur->val;
            }

            cur = cur->right;
        }
        return -1;  
    }
};
