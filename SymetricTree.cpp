class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return root==NULL || ishelp(root->left,root->right);
    }
    
    bool ishelp(TreeNode* left,TreeNode* right){
        if(left==NULL || right==NULL){
            return left==right;
        }
        if(left->val!=right->val){
            return false;
        }
        return ishelp(left->left,right->right)&&ishelp(left->right,right->left);
    }
};

https://leetcode.com/problems/symmetric-tree/
