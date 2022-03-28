#include <iostream>
#include "../Utils/BinaryTree.h"
#include <queue>
#include <stack>
using namespace std;

// root, left , right
void PreOrderTraversal(TreeNode *node)
{
    if (node == nullptr)
        return;
    cout << node->data << " ";
    PreOrderTraversal(node->left);
    PreOrderTraversal(node->right);
}
// left, root, right
void InOrderTraversal(TreeNode *node)
{
    if (node == nullptr)
        return;
    InOrderTraversal(node->left);
    cout << node->data << " ";
    InOrderTraversal(node->right);
}
// left, right, root
void PostOrderTraversal(TreeNode *node)
{
    if (node == nullptr)
        return;
    PostOrderTraversal(node->left);
    PostOrderTraversal(node->right);
    cout << node->data << " ";
}
// non recursive implementations
void PreOrderStackTraversal(TreeNode *root)
{
    if (root == nullptr)
        return;
    stack<TreeNode *> s;
    while (1)
    {
        // collect left nodes
        while (root)
        {
            // output the data while collecting the left nodes
            cout << root->data << " ";
            s.push(root);
            root = root->left;
        }
        // pop the last node and continue this for the right node
        if (!s.empty())
        {
            root = s.top();
            root = root->right;
            s.pop();
        }
        else
            break; // break if there is nothing left to push
    }
}
void InOrderStackTraversal(TreeNode *root)
{
    if (root == nullptr)
        return;
    stack<TreeNode *> s;
    while (1)
    {
        // collect left nodes
        while (root)
        {
            s.push(root);
            root = root->left;
        }
        // pop the last node and continue this for the right node
        if (!s.empty())
        {
            root = s.top();
            cout << root->data << " ";
            root = root->right;
            s.pop();
        }
        else
            break; // break if there is nothing left to push
    }
}
void PostOrderStackTraversal(TreeNode *root)
{
    if (root == nullptr)
        return;
    stack<TreeNode *> s;
    TreeNode *previous = nullptr;
    do
    {
        // collect left nodes
        while (root)
        {
            s.push(root);
            root = root->left;
        }
        while (root == nullptr && !s.empty())
        {
            root = s.top();
            //print the right node and track back to the parent node
            // use nullptr to prevent revisits
            if (root->right == nullptr || root->right == previous)
            {
                cout << root->data << " ";
                s.pop();
                previous = root;
                root = nullptr;
            }
            else
            {
                root = root->right;
            }
        }
    } while (!s.empty());
}
// BFS
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
int main()
{
    TreeNode *root = TreeNode::constructTree();
    cout << "Preorder" << endl;
    PreOrderTraversal(root);
    cout << endl;
    PreOrderStackTraversal(root);
    cout << endl;
    cout << "Inorder" << endl;
    InOrderStackTraversal(root);
    cout << endl;
    InOrderTraversal(root);
    cout << endl;
    cout << "Postorder" << endl;
    PostOrderTraversal(root);
    cout << endl;
    PostOrderStackTraversal(root);
    cout << endl;
    cout << "Level Order BFS" << endl;
    LevelOrderTraversal(root);
    cout << endl;
    return 0;
}
