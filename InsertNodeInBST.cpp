class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {        
        TreeNode* curr=root;//current node will be equal to root 
        if(root==NULL)return new TreeNode(val);//if root is null then create a new node with value val and finsih 
        while(root){
            if(curr->val<=val){//if curr or root node has value<= val to be inserted then we can move right for insertion if it is not null else insert it in the very right itself
                if(curr->right!=NULL)curr=curr->right;//move right if not null 
                else{
                    curr->right=new TreeNode(val);break;//else insert node in the tree at the right of the current node 
                }
            }
            else{//if smaller value h then move left if not null else insert at the very left
                if(curr->left!=NULL)curr=curr->left;//moving left if not null 
                else{
                    curr->left=new TreeNode(val);break;//else insert the node at the left 
                }
            }
        }
        return root;
        //TIME COMPLEXTIY IS O(H) IN THE WORST CASE INSERTION WIL BE MADE AFTER TRAVERSAL OF ALL THE NODES PRESENT IN ONE SIDE OF THE TREE SPACE COMPLEXITY IS O(1)
    }
};
