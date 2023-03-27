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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> inmap;
        for(int i=0;i<inorder.size();i++){
            inmap[inorder[i]]=i;//HASHING TO STORE 
        }
        TreeNode* root=cTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inmap);
        
        return root;
        
    }
    
    TreeNode* cTree(vector<int>& preorder,int prestart,int preEnd,vector<int>& inorder,int instart,int inend,map<int,int> &inmap){
        if(prestart>preEnd || instart>inend) return NULL;//IF SOME PREORDER OR INORDER TRAVERSAL LEFT TO BE DONE:)
        TreeNode* root=new TreeNode(preorder[prestart]);//TAKING THE VERY FIRST ELNNT OF PREORDER AS THE ROOT(ROOT L R) THIS IS THE ROOT 
        
        int inroot=inmap[root->val];//LOCATING THAT ROOT IN THE INORDER TRAVERSAL WITH ITS INDEX
        int numleft=inroot-instart;//TO THE LEFT OF THE INORDER INDEX WE GET THE LEFT SUBTREE
        //PRESTART+1 AS FIRST NODE ROOT IS DONE AND PRESTART+NUMLEFT END OF PREORDER TRAVERS
    //LEFT SUBTREE AND INORDER M INSTART AND INROOT-1 THIS WILL BE THE LEFT SUBTREE
        //PRE:ROOT LEFT RIGHT INORDER::LEFT ROOT RIGHT 
        root->left=cTree(preorder,prestart+1,prestart+numleft,inorder,instart,inroot-1,inmap);
        //LEFT SUBTREE IS prestart++ bcz root already and end is+numleft till left inorder wale m instart se inroot -1 
        //INROOT IS ALREADY CONSIDERED IN TRAVERSAL AND INEND M END HOGA THE TRAVERSAL IN HERE 
        root->right=cTree(preorder,prestart+numleft+1,preEnd,inorder,inroot+1,inend,inmap);
        //remaining part of pre and inorder form the right subtree 
        return  root;        
    }
};

https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
