class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>nodes;
        //vertical    for a lvl/vertical there can be multiple nodes and since we need them in a sorted order we can use a multiset(as we can hv repeated value
        //verticals and at each vertical there may be multiple level and for each levels there can be multiple nodes for that level 
        queue<pair<TreeNode*,pair<int,int>>>q;
        //stores the node the vertical and level 
        q.push({root,{0,0}});
        //initial push 
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            TreeNode* node=p.first;//node in the queue 
            int x=p.second.first;//x is the vertical 
            int y=p.second.second;//y is the level 
            nodes[x][y].insert(node->val);//insert in the node[x] map for that given vertical and now in this given map node[x] at its key y(level at the vertical)node[x][y] this will give us a multiset at that level for a given vertical and insert the node val at that value 
            if(node->left){
                q.push({node->left,{x-1,y+1}});
            }//left then insert 
            if(node->right){
                q.push({node->right,{x+1,y+1}});
            }//right then insert in queue
            
        }//LEVEL ORER TRAVERSAL WITH COORIDNATES WISE TRAVERSAL USED AND TAKEN 
        vector<vector<int>> ans;
        for(auto p:nodes){//TRAVERSING THE MAP
            vector<int> col;
            //for a given vertical 
            for(auto q:p.second){//P.SECOND MEANS THE MAP OF INT AND MULTISET ONE
                //for a given vertical checking all its level we insert the multiset corresponding to that level at the considered vertical 
                col.insert(col.end(),q.second.begin(),q.second.end());
            }//INSERTING THE ELMNTS PRESENT IN LEVEL WISE TRAVERSAL AND ALL 
            ans.push_back(col);//PUSHING IT BACK IN THE ANSWER 
        }
        return ans;//RETURNING THE ANSWER 
        
    }
};
https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
