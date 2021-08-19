//Complexity
//Space: O(h) where h is the height of the //tree, at worst this can be O(n) in case //of a skewed tree.
//Time: O(n). We use two pass DFS's which 
//are O(n) each


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : data(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
 * };
 */
static int mod = 1000000007;
class Solution {
public:
     long long totalTreeSum = 0, res = 0;
     int sumUnderTillNow(TreeNode* node){  //Get the totalSum under the node `root` including root.
         if(!node)
             return 0;
         long long currentSubtreeSum = node->val + sumUnderTillNow(node->left) + sumUnderTillNow(node->right);
         res = max(res, currentSubtreeSum*(totalTreeSum - currentSubtreeSum)); //Get the max product after making current subtree as a separate tree
         return currentSubtreeSum;
     }
     int maxProduct(TreeNode* node){
         totalTreeSum = sumUnderTillNow(node);
         sumUnderTillNow(node);
         return res%mod;
     }
};


//or

static int MOD=1e9+7;
class Solution {
public:
    long long totalTreeSum=0,result=0;
    void getTotalTreeSum(TreeNode* root)    //Get total sum of the tree.
    {
        if(!root)
            return;
        totalTreeSum+=root->val;
        getTotalTreeSum(root->left);
        getTotalTreeSum(root->right);
    }
    int SumUnder(TreeNode* root)             //Get the totalSum under the node `root` including root.
    {
       if(!root)
            return 0;
       int sumUnderLeft=SumUnder(root->left),sumUnderRight=SumUnder(root->right); //Get the sum of left and right subtree under node 'root'
       result=max({result,(totalTreeSum-sumUnderLeft)*sumUnderLeft,(totalTreeSum-sumUnderRight)*sumUnderRight});    //Get the max product after making left or right subtrees as seprarate tree.
       return sumUnderLeft+sumUnderRight+root->val;
    }
    int maxProduct(TreeNode* root) 
    {
        getTotalTreeSum(root);
        SumUnder(root);
        return result%MOD;
    }
};