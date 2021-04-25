#include <map>
#include <iostream>

using namespace std;

map<int, int> visited;

struct tree_node_t
{
    int val;
    tree_node_t *left;
    tree_node_t *right;
};

void dfs(tree_node_t *root)
{
    // 1. terminator
    if (root == NULL)
    {
        return;
    }

    // 2. process
    cout << root->val << endl;

    // 3. drill down

    dfs(root->left);
    dfs(root->right);

    return;
}