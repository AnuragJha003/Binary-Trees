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
    int countNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }//edge test case/base if NULL return 0 
        //TIME COMPLEXITY IS HEGIHT(LOGN)* AT THE WORST CASE LOGN NODES WILL BE TRAVERSED ==(LOGN)2
        //SC IS O(LOGN) FOR THE RECURSSIVE STACK 
        int lh=findleft(root);
        int rh=findright(root);//find the heigh of the left and right subtree given a particular node
        if(lh==rh){
            return (1<<lh)-1;
        }//if left and right subtree height are equal then 2^lh -1 will be the answr
        return 1+countNodes(root->left)+countNodes(root->right);
//else increment count of nodes by 1 and call the recurssive function on the left and right subtrees of the given node         
        
        
    }
    int findleft(TreeNode* node){
        int hl=0;
        while(node){
            hl++;
            node=node->left;
        }
        return hl;
    }
     int findright(TreeNode* node){
        int hr=0;
        while(node){
            hr++;
            node=node->right;
        }
        return hr;
    }//left and right subtrees height found in O(N) TC
};

https://leetcode.com/problems/count-complete-tree-nodes/
