class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) {
            return NULL;
       }//IF NULL THEN RETURN 
        if (root->val == key) {
            return helper(root);
        }//IF EQUAL THEN HELPER FNC CALLED TO DELETE AND MAKE CHANGE IN CONNECTIONS 
        TreeNode *dummy = root; //DUMMY TAKEN FOR ROOT TRAVERSAL
        while (root != NULL) {
            if (root->val > key) { //IF ROOT VALUE GREATER THEN LEFT M H KEY 
                if (root->left != NULL && root->left->val == key) {//if left vala hi value h then 
                    //5->LEFT AND IN HELPER FUNCTION HELPER(3/5->LEFT)
                    root->left = helper(root->left);//HELPER FNC IS CALLED 
                    break;
                } else {
                    root = root->left;//MOVE LEFT IF NOT SO 
                }
            } else {//IG VAL IS SMALLER THEN RIGHT M H KEY
                if (root->right != NULL && root->right->val == key) {
                    //MODIFICATION MADE ON ROOT->RIGHT AND ON HELPER FNC ROOT->RIGHT WALA NODE IS CALLED (DELETION AND CONNECTION CHANGES ARE MADE)
                    root->right = helper(root->right);
                    break;
                } else {
                    root = root->right;//MOVE RIGHT IF NOT SO 
                }
            }
        }
        return dummy;//MODIFICAITON AND DELETION MADERETRUN THE DUMMY 
    }
    TreeNode* helper(TreeNode* root) {
            if (root->left == NULL) 
            {
                return root->right;//IF LEFT SUBTREE NULL THEN ROOT->RIGHT ONLY
            } 
            else if (root->right == NULL)
            {
                return root->left;//SAME WITH RIGHT TOO 
            } 
            TreeNode* rightChild = root->right;//IMMEDIATE OR FIRST RIGHT OF THE NODE 
            TreeNode* lastRight = findLastRight(root->left);//LAST RIGHT OF THE LEFT SUBTREE SEARCHED 
            lastRight->right = rightChild;//NOW LAST RIGHT NODE OF THE LEFT SUBTREE CONNECTED WITH THE FIRST RIGHT NODE OF THE 
            return root->left;//RETURNED ROOT->LEFT 
    }
    TreeNode* findLastRight(TreeNode* root) {
        if (root->right == NULL) {
            return root;
        }
        return findLastRight(root->right);//TRAVERSE THE ENTIRE BST AND WHEN ROOT RIGHT NULL LAST M THEN RETURN THAT ROOT RIGHT 
    }
};

https://leetcode.com/problems/delete-node-in-a-bst/
