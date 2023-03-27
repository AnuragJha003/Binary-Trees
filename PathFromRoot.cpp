 bool get(TreeNode* root, vector<int>& a,int B){
     if(root==NULL)return false;//if root is null then retrun false 
     a.push_back(root->val);//else we push bakc the current root value into the vecto 
     if(root->val==B)return true;//if the current root val matches the int target B return true
     if(get(root->right,a,B)|| get(root->left,a,B)){//call for the right and left subtrees 
         return true;//if anyone return true means node h then return true 
     }
     a.pop_back();//and pop back when completed once from left/right subtree so as to keep a proper track of the path 
     //backtrackking step 
    return false;
 }
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> a;//resultant vector 
     if(A==NULL){//if root is null 
         return a;
     }
     get(A,a,B);//call the function u r given the target in integer format 
     return a;
}
//PATH TO A GIVEN NODE WITH VALLUE B 
https://www.interviewbit.com/problems/path-to-given-node/


//PATH FRO ROOT TO LEAF NODES 
bool isLeaf(Node* root) {
    if(root == NULL)
        return false;
    return !root->left && !root->right;
}

void helper(Node* root, vector<vector<int>> &result, vector<int> &path) {
    
    if(root == NULL)
        return;//IF NULL RETURN 
    
    path.push_back(root->data);//PUSH BACK THE CURRENT ROOT DATA IN A POSSIBLE PATH 
    
    if(isLeaf(root)) {//IF NODE IS LEAF PUSH IN THE 2D VECTOR OF PATHS 
        result.push_back(path);
        path.pop_back();//DO THE POP BACK FROM THE PARTICULAR PATH TO KEEP PROPER TRACK OF MULTIPLE SUCH PATHS 
        return;
    }

    helper(root->left, result, path);
    helper(root->right, result, path);
    //CALLING IT ON THE LEFT AND RIGHT SUBTREES 
    path.pop_back();//SAME POP BACK OR BACKTRACKING DONE TO KEEP PROPER TRACK OF THE PATH 
    
}

vector<vector<int>> Paths(Node* root)
{
    // Code here
    vector<vector<int>> result;//STORES RESULTANT PATHS
    vector<int> path;//A POSSIBEL PATH 
    helper(root, result, path);
    
    return result;
}
https://practice.geeksforgeeks.org/problems/root-to-leaf-paths/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=root-to-leaf-paths
