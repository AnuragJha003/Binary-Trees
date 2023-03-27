/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    
    void mpp(TreeNode* root, unordered_map<TreeNode* , TreeNode* > &mp ,TreeNode* target){
        queue<TreeNode*> q;//QUEUE SRORING THE NODES
        q.push(root);//PUSHING ROOT
        while(!q.empty()){//WHEN IT IS EMPTY 
            TreeNode *c=q.front();q.pop();//Q.FRONT() STORED IN A VAR 
            if(c->left){//LEFT CHILDE PRESENT
                mp[c->left]=c;//THEN PARENT O
                q.push(c->left);
            }
            if(c->right){
                mp[c->right]=c;
                q.push(c->right);
            }
        }
        
    }//FOR PARENT POINTER MAP IS USED WHICH IS USED FOR POINTING A CHILDERN TO ITS PARENT USING MAP KEY VALUE PAIR 
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* , TreeNode* > mp;//NODE --> PARENT POINTER 
        mpp(root,mp,target);
        unordered_map<TreeNode*,bool>visi;//VISITED NODES STORING MAP
        queue<TreeNode*> q2;//queue to store the nodes in here 
        q2.push(target);//target pushed BFS started from the target 
        visi[target]=true;//STARTING UP AND DOWN MOTION FROM THE TARGET ELMNT FROM WHERE DIST IS TO BE COMPARED 
        int cl=0;//STORING DISTANCE
        while(!q2.empty()){
            int sz=q2.size();//size of queue 
            if(cl++==k) break;//DISTANCE FROM TARGET NODE EQUALS K THEN MATCH 
            for(int i=0;i<sz;i++){//checking for all elmnts present in the queue at the moment 
                TreeNode *cur=q2.front();q2.pop();//first node/front node
                if(cur->left && !visi[cur->left]){//can go to left and is not visited 
                    q2.push(cur->left);//push in queue and mark visited
                    visi[cur->left]=true;
                }
                if(cur->right && !visi[cur->right]){//same with right 
                    q2.push(cur->right);
                    visi[cur->right]=true;
                }
                //taking a node and moving radially outwards from the node s it has equal distance and mark nodes as visited in the hash array of visited 
                if(mp[cur] && !visi[mp[cur]]){//checking for parent and if it is not visited 
                    q2.push(mp[cur]);
                    visi[mp[cur]]=true;
                }
                
            }//check done for all nodes at that particular level oppp
        }
        //nodes currently at the queue data structure at the distance k in the queue 
        //nodes in the queue are at distance k 
        vector<int> ans;
        while(!q2.empty()){
            TreeNode* curr=q2.front();q2.pop();
            ans.push_back(curr->val);
        }
    return ans;
    };
};
https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

