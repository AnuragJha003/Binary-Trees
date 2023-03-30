class Solution {
    private:
    TreeNode* first;//FOR FIRST VIOLATION IN THE TRAVERSAL
    TreeNode* prev;//previous /last elemnt in the INORDER TRAVERSAL 
    TreeNode* mid;//ADJACENT ELMNT
    TreeNode* last;//2ND/LAST VIOLATION 
private:
    void inorder(TreeNode* root){
        if(root==NULL)return;//BASE CASE 
        inorder(root->left);//LEFT 
        if(prev!=NULL && (root->val<prev->val)){//PREVIOUS ONE IS NOT NULL AND THE ROOTVAL IS LESS THAN PREVAL MEANS VIOLATION IN INORDER SORTED TOH NEXT ONE WILL BE GREATER ELSE VIOLATION H 
            if(first==NULL){
                //FIRST VIOLATION TIME
                first=prev;//FIRST IS TAKEN AS THE PREV WHICH IS THE VIOLATION ITSELF 
                mid=root;//MID IS TAKEN AS THE ELMNT WE R CURRENTLY PRESENT UPON AS BY ITERATION WE MOVE ONE AHEAD OF THE VIOLATION ELMNT 
            }
            else{//IF IT IS THE 2ND VIOLATION 
            last=root;//2ND VIOLATION IS EQUAL TO THE INDEX WE R UPON
            }
        }
        prev=root;//PREVIOUS POINTER MOVED AHEAD FOR FURTHER CHECKS 
        inorder(root->right);//RECURSIVE CALL FOR THE RIGHT SUBTREE
    }
    public:
    void recoverTree(TreeNode* root) {
        first=mid=last=NULL;//INITILASED WITH NULL 
        prev=new TreeNode(INT_MIN);//PREV INITIAKKY MADE A POINTER AT THE VERY BEGINNING OF THE ARRAY WITH INT_MIN
        inorder(root);//CALLING INORDER
        if(first && last) swap(first->val,last->val);//IF 2 VIOLATIONS R THERE THEN SWAP BOTH OF THEM  
        else if (first && mid) swap(first->val,mid->val);//ADJACENT ELMNTS ARE THE TWO TO BE SWAPPED 
    }
};

https://leetcode.com/problems/recover-binary-search-tree/
