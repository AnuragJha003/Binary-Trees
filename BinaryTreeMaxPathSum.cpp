class Solution {
public:
    
   int findMaxPathSum(TreeNode * root, int & maxi) {
  if (root == NULL) return 0;

  int leftMaxPath = max(0, findMaxPathSum(root -> left, maxi));//taking max path sum from the left subtree 
  int rightMaxPath = max(0, findMaxPathSum(root -> right, maxi));//takign max path sum from the right subtree
  int val = root -> val;
  maxi = max(maxi, (leftMaxPath + rightMaxPath) + val);//storing in this variable at every instance the possible max path sum from all possibilities 
  return max(leftMaxPath, rightMaxPath) + val;//for a given node add its value to the max of left and right path sum in there 
       //-ve path sums are not considered if encounterd consider it as 0 as negative path sum will decrease the path sum initilly and hence would not contribute towards the max path sum 
}

int maxPathSum(TreeNode * root) {
  int maxi = INT_MIN;
  findMaxPathSum(root, maxi);
  return maxi;

}

};

https://leetcode.com/problems/binary-tree-maximum-path-sum/
