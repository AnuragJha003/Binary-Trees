class Solution {
public:

    
    bool isValid(TreeNode* node,long long l,long long r){
        
        if(!node) return true;
        
        if(node->val > l && node->val < r)//node has value greater than the left and smaller than the right 
            return isValid(node->left,l,node->val) && isValid(node->right,node->val,r);
        //call thw func on the left subtree and the l will be the lower range and node->val will be the upper range of the left subtree values as all on left <node->val 
        //vall the func on the right subtree and the node->val will be the smallest value and the upper range fro the right subteee will still be the r as al nodes on rigth >
        else
            return false;//else return false 
    
    }
    
    
    bool isValidBST(TreeNode* root) {
        return isValid(root,-(1LL<<31)-1,(1LL<<31));      
        //all node values will be from -2^31-1 to 2^31 issliye min and max ranges pass krdiya ismein 
    }
};

https://leetcode.com/problems/validate-binary-search-tree/
