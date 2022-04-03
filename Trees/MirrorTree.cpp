#include <iostream>
#include "../Utils/BinaryTree.h"
#include <queue>

using namespace std;

void LevelOrderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        // print the first element and pop it
        TreeNode *node = q.front();
        cout << node->data << " ";
        q.pop();

        // push the respective left and right nodes into the queue
        if (node->left != nullptr)
            q.push(node->left);
        if (node->right != nullptr)
            q.push(node->right);
    }
}

void MirrorTree(TreeNode* root)
{
    TreeNode* temp;
    if(root)
    {
        //recursive call to left and right nodes
        MirrorTree(root->left);
        MirrorTree(root->right);
        // swap the left and right nodes
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    return;
}

int main()
{
    TreeNode* root = TreeNode::constructTree();
    cout << "Before " << endl;
    LevelOrderTraversal(root);
    MirrorTree(root);
    cout << endl<<  "After mirroring" << endl;
    LevelOrderTraversal(root);
}
