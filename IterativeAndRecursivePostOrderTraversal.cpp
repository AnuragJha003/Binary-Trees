class Solution {
public:
 void solve(TreeNode * root,vector<int>&ans){
           //base case 
           if(root == NULL){
               return ;
            }
            solve(root->left,ans);
            solve(root->right,ans);
            ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        //solve(root,ans);
        if(root==NULL)return ans;
        stack<TreeNode*>st1,st2;
        st1.push(root);
        //ST1 WILL STORE THE NODE ITS CORRESPONDING LEFT AND RIGHT CHILD IN THE STACK AND THEN 
        //SO ON UNTIL TRAVERAL IS DONE 
        //ALL POPPED ELMNTS FROM THE ST1 ARE PUSHED INTO THE ST2 
        while(!st1.empty()){
            root=st1.top();st1.pop();//top elmnt of the stack 
            st2.push(root);//popped from stack st1 and pushed into stack st2
            if(root->left!=NULL)st1.push(root->left);//left child pushed into the stack st1 
            if(root->right!=NULL)st1.push(root->right);//right child pushed into the stack st2 
        }
        while(!st2.empty()){//now after full traversal 
            ans.push_back(st2.top()->val);//push the values from the top nodes into the answer vector 
            st2.pop();
        }//this will be the post order left right root 
        return ans;
    }
};
https://leetcode.com/problems/binary-tree-postorder-traversal/
