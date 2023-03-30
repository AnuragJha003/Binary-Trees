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
    TreeNode* bstFromPreorder(vector<int>& A) {
        int i = 0;//i is the inde pointing to the preorder 
        return build(A, i, INT_MAX);//call the build function with initial upper bound as INT_MAX
    }

    TreeNode* build(vector<int>& A, int& i, int bound) {
        if (i == A.size() || A[i] > bound) return NULL;
        //if i has completed the preorder traversal or value in preorder has exceeded the given upper bound 
        TreeNode* root = new TreeNode(A[i++]);//new root consturcted with value at A[i++]
     //i is the index pointing to the preorder vector 
        root->left = build(A, i, root->val);//now building the left tree
        //build  preorder vector and i the index pointing to the preorder elmnt and upper bound for all the left subtree will be the root value 
        root->right = build(A, i, bound);
        //build  preorder vector and i the index pointing to the preorder elmnt and upper bound for all the right subtree will be the  bound only INT_MAX as rihgt subtee has vlue>root->val 
        return root;//retrun the root 
    }
};

https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
