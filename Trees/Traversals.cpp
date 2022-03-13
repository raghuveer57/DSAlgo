#include <iostream>
#include "../Utils/BinaryTree.h"
#include <queue>
using namespace std;

// root, left , right
void PreOrderTraversal(TreeNode* node)
{
    if(node == nullptr)
        return;
    cout << node->data << " ";
    PreOrderTraversal(node->left);
    PreOrderTraversal(node->right);
}
//left, root, right
void InOrderTraversal(TreeNode* node)
{
    if(node == nullptr)
        return;
    InOrderTraversal(node->left);
    cout << node->data << " ";
    InOrderTraversal(node->right);
}
// left, right, root
void PostOrderTraversal(TreeNode* node)
{
    if(node == nullptr)
        return;
    PostOrderTraversal(node->left);
    PostOrderTraversal(node->right);
    cout << node->data << " ";
}

//BFS
void LevelOrderTraversal( TreeNode* root)
{
    if ( root == nullptr)
        return;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty())
    {
        // print the first element and pop it
        TreeNode* node = q.front();
        cout << node->data << " ";
        q.pop();

        // push the respective left and right nodes into the queue
        if( node->left != nullptr)
            q.push(node->left);
        if(node->right != nullptr)
            q.push(node->right);
    } 
}
int main()
{
    TreeNode* root = TreeNode::constructTree();
    PreOrderTraversal(root);
    cout << endl;
    InOrderTraversal(root);
    cout << endl;
    PostOrderTraversal(root);
    cout << endl;
    LevelOrderTraversal(root);
    cout << endl;
    return 0;
}
