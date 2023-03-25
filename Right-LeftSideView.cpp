class Solution {
public:
    void recurssion(TreeNode* root,int level,vector<int>& res){
        if(root==NULL){
            return;
        }//base case in here        
        if(res.size()==level){//for  each level u will get a single node only so the level will be equal to the no of nodes present in the left/right side view 
            res.push_back(root->val);//pushh back the values 
        }
        recurssion(root->right,level+1,res);//call recurssion on the right subtree increasing the lvel 
        recurssion(root->left,level+1,res);//.........................left............................
    }
    
    
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        recurssion(root,0,res);//call made on the root from the 0th level with the data strcuture sttoring it called in the reference mode 
        return res;
    }
};
https://leetcode.com/problems/binary-tree-right-side-view/
