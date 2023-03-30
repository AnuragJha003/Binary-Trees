int floor(Node* root, int x) {
    // Code here
    int f=-1;
    if(root==NULL)return -1;
    while(root){
        if(root->data>x){
            root=root->left;
        }//if greater we move left as we need a smaller value 
        else{
            f=root->data;//if smaller then store 
            root=root->right;// and we move right as we need the largest smaller value 
        }//TC IS O(N) TRAVERSAL OF ALL THE NODES PRESENT IN THE TREE IN THE WORST CASE 
        //SC IS O(1)
    }
    return f;
}
https://practice.geeksforgeeks.org/problems/floor-in-bst/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=floor-in-bst
