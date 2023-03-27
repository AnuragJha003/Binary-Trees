class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
  int isSumProperty(Node *root)
    {
     if(root==NULL || (root->left==NULL && root->right==NULL))
     return 1;
     
     int left_sum = 0, right_sum = 0;
     
     if(root->left) left_sum = root -> left -> data;
     
     if(root->right) right_sum = root -> right -> data;
     
if(root->data==right_sum+left_sum && isSumProperty(root->left)&& isSumProperty(root->right))
    return 1;

else
    return 0;

      }
};

https://practice.geeksforgeeks.org/problems/children-sum-parent/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=hildren-sum-parent
