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
    bool check(TreeNode* lroot, TreeNode* rroot)
    {
        if(lroot==NULL && rroot==NULL)
            return true;
        else if(lroot==NULL && rroot!=NULL)
            return false;
        else if(lroot!=NULL && rroot==NULL)
            return false;
        else
        {
            if(lroot->val == rroot->val)
            {
                if(check(lroot->left, rroot->right) && check(lroot->right, rroot->left))
                    return true;
                else
                    return false;
            }
            else
                return false;
        }
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        else
            return check(root->left, root->right);
    }
};