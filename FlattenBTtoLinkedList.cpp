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
/*class Solution {
public:
    void flatten(TreeNode* root) {
        stack<TreeNode*>st;
        if(root==NULL || root->left==NULL && root->right==NULL)
            return;
        st.push(root);
        while(!st.empty()){
            TreeNode* curr=st.top();st.pop();
            if(curr->left!=NULL){
                st.push(curr->left);
            }
            if(curr->right!=NULL){
                st.push(curr->right);
            }
            if(!st.empty()){
                curr->right=st.top();
            }
            curr->left=NULL;
        }
        return;
    }
};*/
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
//    finding pre-order and storing it in an arr
    void solve(TreeNode *root,vector<int> &arr)
    {
//         base case
        if(root==NULL)
            return;
        
        arr.push_back(root->val);
        solve(root->left,arr);
        solve(root->right,arr);//PREORDER PUSHING BACK 
    }
    void flatten(TreeNode* root) {
//         base case
        if(root==NULL || root->left==NULL && root->right==NULL)
            return;
        
        vector<int> arr;
        solve(root,arr);
        
//      deleting existing tree
        root->left=NULL;
        root->right=NULL;
        
//         constructing 'root' tree from pre order array
        for(int i=1;i<arr.size();i++){
                TreeNode *newNode=new TreeNode(arr[i]);    
                root->right=newNode;   
                root=newNode;
            }
    }
};

//THIS IS THE MORRIS TRAVERSAL APPROACH 

//OTHJER IS A RECURRSIVE EASY TO UNDERSTAND APPROACH IN NOTES AND ALSO THERE IS A STACK APPROACH EASY TO UNDERSTAND IN THE NOTES

https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
