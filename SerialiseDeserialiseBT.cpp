/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
          if(!root) return "";//if root is null then return empty string 
        
        string s ="";
        queue<TreeNode*> q;//queue for all the  nodes 
        q.push(root);//push into the root 
        while(!q.empty()) {
           TreeNode* curNode = q.front();
           q.pop();//checking for each node 
           if(curNode==NULL) s.append("#,");//if current node is null we code it as # in our string 
           else s.append(to_string(curNode->val)+',');//else we add trh node val to the string as char 
           if(curNode != NULL){//if not null 
               q.push(curNode->left);
               q.push(curNode->right);       
               //then push back in the queue the left and right child as well if its null we will give it a hash in the encryption but push it in the queue 
           }
        }
        return s;//return s 
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL; 
        stringstream s(data);
        string str; 
        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode*> q; 
        q.push(root); 
        while(!q.empty()) {
            
            TreeNode *node = q.front(); 
            q.pop(); //front pointed node 
            
            getline(s, str, ',');
            if(str == "#") {//if str is hash
                node->left = NULL; //the left child null as left child comes firt in the char check 
            }
            else {//if left child not hash means value h 
                TreeNode* leftNode = new TreeNode(stoi(str));//construct a new node with val as si] 
                node->left = leftNode; //and join it to the left of the node 
                q.push(leftNode); //push back into the queue as not null
            }
            
            getline(s, str, ',');
            if(str == "#") {//for right chid now same thing 
                node->right = NULL; 
            }
            else {
                TreeNode* rightNode = new TreeNode(stoi(str)); 
                node->right = rightNode;
                q.push(rightNode); 
            }
            //construction of tree agar hasg h then null and if not hash means not null push back in the queue after joining to the left/right of the given node as tree is constructed respectively 
        }
        return root; //return the constructed tree 
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
