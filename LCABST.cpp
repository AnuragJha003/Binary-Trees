class Solution {
public:
     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    /*if (p->val > q->val) return lowestCommonAncestor(root, q, p);
    while (1)
    {
        if (root->val >= p->val && root->val <= q->val)      return root; 
        else if (p->val < root->val && q->val < root->val)   root = root->left;
        else if (p->val > root->val && q->val > root->val)   root = root->right;
    }*/
        if(root==NULL)return NULL;
         int curr=root->val;
         if(curr<p->val && curr<q->val){
             return lowestCommonAncestor(root->right,p,q);
         }// if p and q are nodes with larger values we move to right 
         if(curr>p->val && curr>q->val){
             return lowestCommonAncestor(root->left,p,q);
         }//if p and q are nodes with smaller values we move to the left 
         return root;//else if p and q are on opposite ends of a particular node means ek larger h ek smaller h means this root itself is the LCA 
	}
};

https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
