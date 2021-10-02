class Solution {
public: 
  //Recursive TC = O(N) ie  T(n) = 2T(n/2)+1
  //SC = O(N) N = no of nodes
  //   void inorderTraversalHelp(TreeNode* root, vector<int> &ans) {
  //     if(root == NULL) {}
  //      else{
  //      if(root->left != NULL){
  //     inorderTraversalHelp(root->left, ans);
  //      }
  //      ans.push_back(root->val);
  //      if(root->right != NULL){
  //    inorderTraversalHelp(root->right, ans);
  //      }
  //  }
  //  }
    //iterative approach TC = O(N) SC = O(N)
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        //inorderTraversalHelp(root, ans);
        stack<TreeNode*> st;
        TreeNode* currNode = root;
        while(currNode != NULL || !st.empty()){
            while(currNode != NULL){
                st.push(currNode);
                currNode = currNode->left;
            }
            currNode = st.top();
            st.pop();
            ans.push_back(currNode->val);
            currNode = currNode->right;
        }
        return ans;
    }
};
