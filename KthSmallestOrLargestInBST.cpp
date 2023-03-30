/*THIS IS TC O(N) AND SC IS O(N)
class Solution {
public:
    
    void inorder(TreeNode* root,vector<int>& v){
        if(root==NULL)return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        inorder(root,v);
        return v[k-1];
    }
    
    KTH LARGEST IS:(N-KTH)SMALLEST WHERE N IS THE NO OF NODES IN THE TREE JISKE LIYE ONE MORE TRAVERSAL OF THE TREE IS REQUIRED 
};*/
/*TC IS O(N) BUT FOR BETTER SC IT IS O(1) MORRIS TRAVERSAL */

class Solution {
public:
    int solve(TreeNode *root , int k , int &i){
        if(root == NULL)
            return -1;
        
        //left
        int leftAns = solve(root->left , k , i); //CALLING TO CHECK ON THE LEFT SUBTREE FOR THE KTH ELMNT 
        if(leftAns != -1)//IF NOT -1 MEANS KUCH VALUE H  THAT IS KTH ELMNT IS PRESENT 
            return leftAns;//RETRUN 
        
        //root
        i++;//WHEN ROOT IS THERE I++
        if(i == k)//IF I IS EQUAL TO K IT IS THE KTH ELMNT 
            return root->val;//RETURN THE VALUE 
        
        
        //right
        return solve(root->right , k , i);//ELSE GO TO RIGHT AND CALL THE SOLVE FUNCTION 
        
        //INORDER TRAVERASAL HI H JUST LEFT ROOT RIGHT WITH MODIFCATION OF COUNT DONE IN ITSLEF ONLY 
        //MORRIS TRAVERSAL O(N) TC AND O(1) SC 
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int i = 0;//COUNT FOR THE KTH ELMNT 
        int ans = solve(root , k , i);//CALL ON ROOT K AND I
        return ans;//RETURN THE ANSWER 
    }
};

https://leetcode.com/problems/kth-smallest-element-in-a-bst/
