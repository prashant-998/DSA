/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     bool twoSum(vector<int>& numbers, int target) 
    {
        int start=0,end=numbers.size()-1;
        while(start<end)
        {
            if(numbers [start] + numbers [end] > target)
            {
                end--;
            }
            else if(numbers [start] + numbers [end] <target)
            {
                start++;
            }
            else
            {
                return true;
            }
        }
        
        return false;
        
    }
    void inOrder(TreeNode *root, vector<int> &Inorder){
        if(root == NULL) return;
        inOrder(root->left,Inorder);
        Inorder.push_back(root->val);
        inOrder(root->right,Inorder);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        inOrder(root,ans);
        if(twoSum(ans,k)) return true;
        return false;
    }
};