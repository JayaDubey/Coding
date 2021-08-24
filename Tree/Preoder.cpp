//Preorder
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
            if (curr->left != NULL)
                stack.push(curr->left);
        }
        return preorder;
    }
