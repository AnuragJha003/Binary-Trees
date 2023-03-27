//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  Node* bfstostart(Node* root,map<Node*,Node*>& mp,int target){
      queue<Node*>q;
      q.push(root);
      Node* res;
      while(!q.empty()){
          Node* n=q.front();q.pop();
          if(n->data==target)res=n;
          if(n->left){ mp[n->left]=n; q.push(n->left);}
          if(n->right){ mp[n->right]=n;q.push(n->right); }
      }
      return res;
  }
  int findmin(map<Node*,Node*>& mp,Node* target){
      queue<Node*>q;
      q.push(target);//TO START BFS FROM NODE
      map<Node*,int> vis;//TO MARK THE NODES WHICH R BEING VISTED ONCE OR NODES WHIC R ALREADY BURNT
      int mx=0;vis[target]=1;//BURNT
      while(!q.empty()){
          int sz=q.size();
          int fl=0;
          for(int i=0;i<sz;i++){//CHECKING FOR ALL NODES CURRENTLY IN THE QUEUE
               auto it=q.front();q.pop();
               if(it->left && !vis[it->left]){
                   fl=1;vis[it->left]=1;
                   q.push(it->left);
               }
               if(it->right && !vis[it->right]){
                   fl=1;vis[it->right]=1;
                   q.push(it->right);
               }
               if(mp[it] && !vis[mp[it]]){
                   fl=1;vis[mp[it]]=1;
                   q.push(mp[it]);
               }
          }
          if(fl)mx++;//IF FL IS THERE MEANS SOME OR THE OTHER NODE WAS BURNT SO INCREMNT THE TIME VARIABLE
      }
      return mx;
  }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        map<Node*,Node*> mp;
        Node* tar=bfstostart(root,mp,target);
        //map stores the pointer from the children to its parent node and tar contains the target node from where burning will start
        int ans=findmin(mp,tar);
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends

https://practice.geeksforgeeks.org/problems/burning-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=burning-tree
