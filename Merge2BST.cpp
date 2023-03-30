class Solution
{
    public:
      void inorder(Node* root,vector<int>&v)

    {

        if(root==NULL)

        return;
        
        inorder(root->left,v);

        v.push_back(root->data);

        inorder(root->right,v);

    }
    
    vector<int> merge(Node *root1, Node *root2)
    {
      vector<int>v1,v2;

      inorder(root1,v1);

      inorder(root2,v2);

      vector<int>v;
      
      int i=0,j=0;
      
      while(i<v1.size() && j<v2.size()){

           if(v1[i]<v2[j]){

               v.push_back(v1[i]);

               i++;

           }

           else{

               v.push_back(v2[j]);

               j++;

           }

       }

       

       while(i<v1.size()){

           v.push_back(v1[i]);

           i++;

       }

       while(j<v2.size()){

           v.push_back(v2[j]);

           j++;

       }

 

        sort(v.begin(),v.end());

        

        return v;
//tc is o(m+n) and sc is o(hm+hn+ m+n) as all nodes can be stored in there 
     

    }
};

https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=merge-two-bst-s
