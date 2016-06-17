/* 
 * Given two binary trees, write a function to check if they are 
 * equal or not.
 * Two binary trees are considered equal if they are structurally 
 * identical and the nodes have the same value.
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        
        if (NULL == p && NULL == q)
            return true;
        if (NULL == p || NULL == q)
            return false;
        if (p->val == q->val)
        {
            bool rs1, rs2;
            rs1 = isSameTree(p->left, q->left);
            rs2 = isSameTree(p->right, q->right);
            if (rs1 && rs2)
            	return true;
        }
        return false;    
    }
};
