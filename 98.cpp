/*
 * @Author       : foregic
 * @Date         : 2021-08-02 00:12:28
 * @LastEditors  : foregic
 * @LastEditTime : 2021-08-02 00:15:38
 * @FilePath     : \leetcode\98.cpp
 * @Description  : leetcode98题看到一个非常棒的解决方法
 */

//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int *last = nullptr;
    bool isValidBST(TreeNode *root)
    {
        if (root)
        {
            if (!isValidBST(root->left))
                return false;
            if (last && *last >= root->val)
                return false;
            last = &root->val;
            if (!isValidBST(root->right))
                return false;
            return true;
        }
        else
            return true;
    };
};