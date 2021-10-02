//Preorder
//TC = O(n) SC = O(n) [n = number of nodes (worst case occurs in a skewed tree) 
class Solution {
public: //recursive
    void recur(TreeNode* root, vector<int> &res){
        if(root == NULL){}
        else{
            res.push_back(root->val);
            recur(root->left, res);
            recur(root->right, res);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        recur(root, res);
        return res;
    }
};

//or
class Solution {
public:
    vector<int> vec;
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==nullptr) return {};
        vec.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return vec;
    }
};

//Iterative solution
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        stack<TreeNode*> stack;
        if (root == NULL)
            return preorder;
        stack.push(root);
        while(!stack.empty()) {
            TreeNode* curr = stack.top();
            stack.pop();
            preorder.push_back(curr->val);
            if (curr->right != NULL)
                stack.push(curr->right);
            if (curr->left != NULL) //left is inserted at the last so that it appears before right node
                stack.push(curr->left);
        }
        return preorder;
    }
