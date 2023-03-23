class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;//BASE CONDITION STOPS AT THE LOWERMOST LEAF NODE
        return 1+max(maxDepth(root->left),maxDepth(root->right));//RECURSSION USED TO CALCULATE HEIGHT OF THE CHILDREN AND ONE ADDED BCZ OF THE MAIN ROOT INCLUSION
    }
};
https://leetcode.com/problems/maximum-depth-of-binary-tree/
