class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> nq;
        //BFS OR LEVEL TRAVERSAL JUST WITH AN ADDITIONAL FLAG CHECKER 
        if(root==NULL){
            return res;
        }//EDGE TC
        nq.push(root);//PUSH IN THE QUEUE 
        bool l2r=true;//STARTING FROM LEFT TO RIGHT 
        while(nq.empty()!=true){
            int size=nq.size();//SIZE REFERS TO THE NO OF NODES IN THE LEVEL 
            vector<int> row(size);//LEVEL ORDER TRAVERSAL NODES
            for(int i=0;i<size;i++){
                TreeNode* n=nq.front();nq.pop();//FRONT NODE 
                int ind= (l2r)?i:(size-i-1);//IF L2R IS TRUE START INDEX IS I AND END INDEX IS SIZE-I-1 IF L2R IS FALSE MATLAB RIGHT SE LEFT TRAVERSAL H 
                row[ind]=n->val;//STORE IN THE LEVEL ORDER VECTOR INDEX IND THE VALUE OF THE NODE 
                if(n->left!=NULL){
                    nq.push(n->left);
                }//PUSH THE LEFT 
                if(n->right!=NULL){
                    nq.push(n->right);
                }//PUSH THE RIGHT NODES 
            }
                l2r=!l2r;//IF TRUE THEN FALSE AND FALSER THEN TRUE L TO R AUR NHI TOH R TO L 
                res.push_back(row);//PUSH THE LEVEL TRAVERSED 
            }
            return res;        
    }
};

https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
