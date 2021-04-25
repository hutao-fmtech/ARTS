#include <map>
#include <queue>

using namespace std;

map<int, int> visitied;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void bfs(TreeNode *root)
{

    if (root == NULL)
    {
        return;
    }
    map<int, int> visitied;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();

        if (visitied.count(root->val))
        {
            continue;
        }
        visitied[root->val] = 1;
        if (root->left)
        {
            q.push(root->left);
        }

        if (root->right)
        {
            q.push(root->right);
        }
    }
}
