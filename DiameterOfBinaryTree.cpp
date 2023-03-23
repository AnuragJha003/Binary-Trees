class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int d=0;
        height(root,d);//d gets modified in here as passed ny reference 
        return d;//return the d
    }
    //TIME COMPLEXITY IS O(N) AS WE R TRAVERSING THE NODES OF THE TREE ONCE AND MAX IS MODIFIED IN ITSELF EVERTYTIME 
    private:
    int height(TreeNode* root,int& d){
        if(!root){
            return 0;
        }//base condition 
        int l=height(root->left,d);
        int r=height(root->right,d);
        //left and right subtree height called with the d variable 
        d=max(d,l+r);//d stores the max of l+r which is the longest path throught that node for each and every node possible
        return 1+max(l,r);//for the height of the node 1+max(left subtree,right subtree)
    }
};
https://leetcode.com/problems/diameter-of-binary-tree/
