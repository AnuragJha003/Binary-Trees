class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;//STACK OF NODES OF TREE IS CREATED
        TreeNode* node=root;//NODE INITIALISED WITH ROOTS IN HERE
        vector<int> inorder;
        while(true){
            if(node!=NULL){//IN EVERY ITERATION WE R PUSHING BACK THE LEFT VALUE OF A NODE IF A NODE IS NOT NULL
                st.push(node);
                node=node->left;//INORDER IS LEFT ROOT RIGHT....
                //IF NODE VALUE POINTS TO NON EMPTY KEEP IT PUSHING INTO A STACK
            }//STACK IS BASICALLY STORING ALL THE LEFT VALUES OF THE TREE IN HERE AND THEN CHECKING RIGHT AND ROOT WITH IT
            else{//IF LEFT VALUE IS NULL
                if(st.empty()==true) break;//STACK HI EMPTY HOGYA MEANS VECTOR READY TO BE PRINTED
                node=st.top();//TOPMOST ELEMENT OF STACK WILL BE THE ELEEMNT GOING DOWN IN THE VECTOR
                st.pop();//WE R PRINTING OUT THE LEFT MOST VALUE BY PUSHING INTO THE VECTOR AND REMOVING IT FROM THE STACK
                inorder.push_back(node->val);//VALUE ASSOSCIATED WITH THE NODE GETS PUSHED BACK AS NODE IS A POINTER LEFT(root h types) now right 
                node=node->right;//FURTHER CHECKING OF THE NODE VALUE COMPLETELY ASSOCIATED WITH IT
            }
        }
        return inorder;
    }
};

//left print value right recurssive 

https://leetcode.com/problems/binary-tree-inorder-traversal/

