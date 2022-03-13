#pragma once
#include <iostream>

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
    TreeNode() : data(0) , left(nullptr), right(nullptr) {}
    TreeNode(int value , TreeNode* leftptr, TreeNode* rightptr) : data(value), left(leftptr), right(rightptr) {}
    static TreeNode* constructTree()
    {
        TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3));
        return root;
    }
};

