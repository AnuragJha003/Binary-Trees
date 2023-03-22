class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            root=st.top();
            st.pop();//ROOT LEFT RIGHT 
            ans.push_back(root->val);
            if(root->right!=NULL){
                st.push(root->right);
            }
            if(root->left!=NULL){
                st.push(root->left);
            }//as stack is last in first out so as we need the left child first we r pushing it in the stack at the end/last 
        }
        return ans;
    }
};



/*
class Solution {
     vector<int> ret{};
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root)
        {
            ret.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
        return ret;
    }
};*/

https://leetcode.com/problems/binary-tree-preorder-traversal/
