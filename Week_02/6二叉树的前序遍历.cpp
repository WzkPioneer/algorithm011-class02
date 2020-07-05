/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)
        {
            return  ans;
        }
        stack<TreeNode*> stack;
        TreeNode* p=root;
        while(!stack.empty()||p)
        {
            while(p)
            {
                ans.push_back(p->val);
                stack.push(p);
                p=p->left;
            }
            p=stack.top();
            stack.pop();
            p=p->right;
        }
        return ans;
    }
};