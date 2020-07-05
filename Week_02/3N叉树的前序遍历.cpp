
class Solution {
public:
    vector<int> ans;
    vector<int> preorder(Node* root) {
        if(root)
        {
            ans.push_back(root->val);
            for(int i=0;i<root->children.size();i++)
            {
                ans=preorder(root->children[i]);  
            }  
        }
        return ans;
    }
};