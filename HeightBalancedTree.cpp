class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfsheight(root)!=-1;
    }
    
    
    int dfsheight(TreeNode* root){
        if(root==NULL)return 0;
        int l=dfsheight(root->left);
        if(l==-1)return -1;
        int r=dfsheight(root->right);
        if(r==-1)return -1;
        
        if(abs(l-r)>1) return -1;
        return 1+max(l,r);
    }
};
https://leetcode.com/problems/balanced-binary-tree/
