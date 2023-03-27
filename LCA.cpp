class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL|| root==p || root==q){
            return root;
        }//BASE CASE IF ROOT IS NULL OR IS EQUAL TO ONE OF THE TWO TARGETED NODES IN HERE FOR THE LCA 
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);//RECURSSIVE CALLS TO LEFT AND RIGHT 
        //RECURSSIVE CALL TO MOVE LEFT AND RIGHT OF THE TREE 
        if(left==NULL){
            return right;
        }//IF LEFT NULL PROCEED 
        if(right==NULL){
            return left;
        }//IF RIGHT NULL PROCEED 
        else{//BOTH LEFT AND RIGHT ARE NOT NULL SO WE RETURN THE RESULT WHICH IS THE LOWEST COMMON ANCESTOR WHICH RETURNS THE FIRST NODE WHICH CONTAINS IN ITS LEFT AND RIGHT CHILD THE TWO NODES WHOSE LCA IS TO BE FOUND (ROOT )
            return root;
        }
        
    }
    
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
