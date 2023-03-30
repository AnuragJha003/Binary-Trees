class NodeVal{
public:
    int minNode,maxNode,maxSize;
    bool isBst;
};

NodeVal BT(Node*root, int &ans) {
  if (root == NULL)
    return {INT_MAX, INT_MIN, 0,true};
  // do postorder
  auto left = BT(root->left,ans);
  auto right = BT(root->right,ans);
  NodeVal curr ; 
  curr.maxSize=  left.maxSize+right.maxSize+1; 
  curr.minNode= min(root->data,left.minNode);
  curr.maxNode= max(root->data,right.maxNode);
  if ((root->data>left.maxNode && root->data<right.minNode)&&(left.isBst &&right.isBst)){
  curr.isBst = true;
  }
  else
  curr.isBst = false;
  
if(curr.isBst)
    ans= max(curr.maxSize,ans);
    return curr;
}

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
        //Your code here
        int ans =0;
        NodeVal obj = BT(root,ans);
        return ans;
    }
};

https://practice.geeksforgeeks.org/problems/largest-bst/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=largest-bst
