vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<vector<int>>ans;
    stack<pair<BinaryTreeNode<int>*,int>>st;
    //1 preorder 2 inorder 3 postorder 
    st.push({root, 1});
    vector<int> pre,ino,post;
    if(root==NULL)return ans;
    while(!st.empty()){
        auto it=st.top();st.pop();//pop out top elmnt 
        if(it.second==1){//if preorder wala elmnt root to be printed 
            pre.push_back(it.first->data);//push in preorder traversal
            it.second++;//change pre to inorder now 
            st.push(it);//push in stack the same elmnt but now to come in inorder
            if(it.first->left!=NULL){//ROOT LEFT RIGHT PREORDER SO CHECK FOR LEFT
                st.push({it.first->left,1});//PUSH IN STACK 
            }
        }
        else if(it.second==2){//now if inorder wala 
            ino.push_back(it.first->data);it.second++;//push in inorder and change inorder to postorder now 
            st.push(it);//push in stack the same elmnt now to be printed in inorder 
            if(it.first->right!=NULL){//Left root right inroder so now right side is checked in here 
                st.push({it.first->right,1});//right pushed in stack in preorder first time type
            }
        }
        else{
            post.push_back(it.first->data);//if postorder h just print in post order 
        }
    }
    ans.push_back(ino);
    ans.push_back(pre);
    ans.push_back(post);
    return ans;//finally return ur answer

}

https://www.codingninjas.com/codestudio/problems/tree-traversal_981269?leftPanelTab=0
