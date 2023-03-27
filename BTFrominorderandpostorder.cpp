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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size()){
            return NULL;
        }
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return buildTree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mp);
    }
    TreeNode* buildTree(vector<int>& inorder,int is,int ie, vector<int>& postorder,int ps,int pe,map<int,int> &mp){
        if(ps>pe || is>ie){
            return NULL;
        }
        TreeNode* root=new TreeNode(postorder[pe]);//HEAD OR ROOT OF THE TREE LAST ELMNT IS ROOT 
        int inroot=mp[postorder[pe]];//WHERE IS THE FIRST ROOT IN THE HASHMAP 
        int nleft=inroot-is;//LEFT SUBTREE REGION 
        
        root->left=buildTree(inorder,is,inroot-1,postorder,ps,ps+nleft-1,mp);//LEFT KE LIYE SUBTREE INDEX 
        root->right=buildTree(inorder,inroot+1,ie,postorder,ps+nleft,pe-1,mp);//RIGHT KE LIYE SUBTREE INDEX 
        
        return root;//ROOT OF THE TREE CONSTRUCTED 
    }
};

https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
