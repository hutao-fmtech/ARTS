class Node
{
public:
	int val;
	Node *left;
	Node *right;

	Node() {}

	Node(int _val)
	{
		val = _val;
		left = nullptr;
		right = nullptr;
	}

	Node(int _val, Node *_left, Node *_right)
	{
		val = _val;
		left = _left;
		right = _right;
	}
};
class Solution
{
public:
	Node *treeToDoublyList(Node *root)
	{

		if (root == nullptr)
		{
			return nullptr;
		}
		dfs(root);

		head->left = prev;
		prev->right = head;
		return head;
	}

private:
	Node *head;
	Node *prev;
	void dfs(Node *cur)
	{
		if (cur == nullptr)
		{
			return;
		}
		dfs(cur->left);
		if (prev != nullptr)
		{
			prev->right = cur;
		}
		else
		{
			head = cur;
		}
		cur->left = prev;
		prev = cur;
		dfs(cur->right);
	}
};