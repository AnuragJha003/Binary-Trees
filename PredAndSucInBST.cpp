void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

 pre = NULL;
 suc = NULL;
 Node *tmp=root;
 while(tmp){//while not null
     if(tmp->key>key){//if value jyada h 
         suc = tmp;//store in successor 
         tmp=tmp->left;//and move left to get a smallr value 
     }
     else{
          tmp=tmp->right;//else move right for a greater value 
     }
 }
 
 tmp=root;//reinitlaise
 
 while(tmp){
     if(tmp->key<key){//is smaller value h 
         pre=tmp;//store in pred 
         tmp=tmp->right;//move right to get a larger small vlaue 
     }
     else
     tmp=tmp->left;//ekse greater h so move left for a small value 
 }

}

https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1
