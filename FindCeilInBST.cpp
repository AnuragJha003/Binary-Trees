int findCeil(Node* root, int input) {
    //if (root == NULL) return -1;
    //if(root->data>=input)return root->data;
    //else if(root->data<input)findCeil(root->right,input);
    //else findCeil(root->left,input);
    
    if(root==NULL)return -1;
    int ceil=-1;
    while(root!=NULL){
        if(root->data<input){
            root=root->right;
        }//if root value smaller than what is expected then move right as larger elmnt milega wahan
        else{
            ceil=root->data;//else store as this value is = or greater 
            root=root->left;//and we move left as immediate greater chahiye so we search if a smaller elmnt satisfying these properties is there 
        }
    }
    //SAME TC AND SAME SC AS THE FLOOR QUESTION (o(n) and o(1)) 
    return ceil;
    // Your code here
}
https://practice.geeksforgeeks.org/problems/implementing-ceil-in-bst/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implementing-ceil-in-bst
