class Solution {
public:
    unordered_map<int,TreeNode*> fa;
    unordered_map<int,bool> visited;


    void dfs(TreeNode* root)
    {
        if(root==NULL) return ;

        if(root->left)
        {
            fa[root->left->val]=root;
            dfs(root->left);
        }
        if(root->right)
        {
            fa[root->right->val]=root;
            dfs(root->right);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {

        fa[root->val]= nullptr;
        dfs(root);
        while(p!=nullptr)
        {
            visited[p->val]=true;
            p=fa[p->val];
        }
        while(q!= nullptr)
        {
            if(visited[q->val])
            {
                return  q;
            }
            q = fa[q->val];
        }
        return nullptr;
    }
};