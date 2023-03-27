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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }//root null 
        long long int ans=0;
        queue<pair<TreeNode*,long long int>>q;
        q.push({root,0});
        //root and the width for the particular level 
        while(!q.empty()){
            long long int s=q.size();//size of queue 
            long long int imin=q.front().second; //TO MAKE ID START FROM 0 this will be the min index in here for the lvel 
            long long int first,last;//first and last for caluclation of the width of the given level 
            for(long long int i=0;i<s;i++){//checking for all nodes at that level 
                long long int ci=q.front().second-imin;//current index (current one subtracted from the minimum index) subtracted in order to avoid overflow 
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0) first=ci;
                if(i==s-1) last=ci;//STORING THE FIRST GUY AND THE LAST GUY 
                //FIRST AND LAST INDEX OF ANY LEVEL IS THE ONE WHICH IS USED FOR THE CALCULATION OF THE WIDTH HENCE STORED IN HERE HAI NA 
                if(node->left){
                    q.push({node->left, ci*2+1});
                }
                if(node->right){
                    q.push({node->right,ci*2+2});
                }
            }//traversal for that level is done now 
            ans=max(ans,last-first+1);//WIDTH OF THE BT MAX WIDTH REQUIRED 
            
            //TC IS O(N) LEVEL ORDER TRAVERSAL SC IS O(N) FOR QUEUE 
        }
        return ans;
    }
};

https://leetcode.com/problems/maximum-width-of-binary-tree/
