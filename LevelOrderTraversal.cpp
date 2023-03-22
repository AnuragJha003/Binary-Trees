class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;//DATA STRUCTURE IMPLEMETED TO STORE LEVEL ELMNTS 
        if(root==NULL) return ans;//EDGE TC 
        q.push(root);//PUSH
        while(!q.empty()){//WHEN NOT EMPTY 
            int s=q.size();//THIS S WILL INDICATE THE NO OF NODES IN A PARTICUALR LEVEL AND WE WILL TRAVERSE IN THE QUEUE UPTO THIS S PUSHING ELMNTS FROM QUEU TO A VECTOR AND STROING IT IN THE VECTOR 
            vector<int> level;//VECTOR FRO LEVEL OF A NODE 
            for(int i=0;i<s;i++){//TRAVERSING NODES PRESENT IN A LVL
                TreeNode* node=q.front();//Q.FRONT WILL SEE NODE OF THE LEVEL
                q.pop();//REMOVE
                if(node->left!=NULL) q.push(node->left);//IF LEFT CHILD PUSH BACK IN QUEEU
                if(node->right!=NULL) q.push(node->right);//IF RIGHT CHILD PUSH BACK
                level.push_back(node->val);//NOW LEVEL VECTOR M INSERT NODE WHICH IS STRONG Q.FRONT WHIXH IS THE VALUE OF NODE AT THE PARTICULAR LEVEL
            }
            ans.push_back(level);//ANS 2D VECTOR M STROING THE LEVEL VECTRO 
        }
        
        
        return ans;
        
    }
};

https://leetcode.com/problems/binary-tree-level-order-traversal/
