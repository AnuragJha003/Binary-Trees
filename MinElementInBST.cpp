int minValue(Node* root) {
    // Code here
    //leftmost node in bst is the min elmnt 
    int mn=INT_MAX;
    while(root!=NULL){
        mn=min(mn,root->data);
        root=root->left;
    }
    if(mn!=INT_MAX)return mn;
    else return -1;
}

https://practice.geeksforgeeks.org/problems/minimum-element-in-bst/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-element-in-bst
