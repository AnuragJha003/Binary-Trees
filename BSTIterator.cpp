/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    
private:stack<TreeNode*> ms;//storing the iterative inorder traversal in the stack 
    //left left first then pick out stack(root) and then right 
    //hasnext if stack is not empty 
public:
    BSTIterator(TreeNode* root) {
        pushall(root);
    }//CONSTRUCTOR IN HERE 
    
    int next() {
        TreeNode* tmp=ms.top();
        ms.pop();//POPPED FIRST 
        pushall(tmp->right);//IF RIGHT EXISTS THEN OF THE RIGHT SUBTREE WE RETURN ALL THE LEFT SIDED PARTS OF THE RIGHT SUBTREE USING THE PUSHALL FUNCTION 
        return tmp->val;//TOP ELEMENT RETURNED RETURN THIS VALUE 
    }
    
    bool hasNext() {
        return !ms.empty();
    }//if stack is empty then no next else has next 
    
    private:
    void pushall(TreeNode* root){
        for(;root!=NULL;ms.push(root),root=root->left);//push all the nodes to the left of a given node in the stack 
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
 
 https://leetcode.com/problems/binary-search-tree-iterator/
