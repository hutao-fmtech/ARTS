#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> two_way_merge(vector<int> &a, vector<int> &b)
{

    vector<int> ans;

    ans.resize(a.size() + b.size());

    int idx = 0;
    int i = 0;
    int j = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            ans[idx++] = a[i++];
        }
        else
        {
            ans[idx++] = b[j++];
        }
    }

    while (i < a.size())
    {
        ans[idx++] = a[i++];
    }

    while (j < b.size())
    {
        ans[idx++] = b[j++];
    }

    return ans;
}

vector<int> k_way_merge(vector<vector<int>> &x, int start, int end)
{
    if (start >= end)
    {
        return x[start];
    }
    int mid = start + (end - start) / 2;

    vector<int> left = k_way_merge(x, start, mid);
    vector<int> right = k_way_merge(x, mid + 1, end);

    return two_way_merge(left, right);
}
struct merge_node_t
{
    vector<int> *p_vector;
    int idx;
    bool operator<(const merge_node_t b) const
    {
        return p_vector->at(idx) > b.p_vector->at(b.idx);
    }
};

vector<int> k_way_merge_2(vector<vector<int>> &x)
{
    priority_queue<merge_node_t> pq;

    for (int i = 0; i < x.size(); i++)
    {
        merge_node_t node = {&x[i], 0};
        pq.push(node);
    }

    vector<int> ans;

    while (!pq.empty())
    {
        merge_node_t node = pq.top();
        pq.pop();
        ans.push_back(node.p_vector->at(node.idx));
        if (node.idx < node.p_vector->size() - 1)
        {
            node.idx++;
            pq.push(node);
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> test_case = {{2, 3, 7}, {0, 1, 8, 9}, {-1, 29, 30}};

    vector<int> ans = k_way_merge(test_case, 0, test_case.size() - 1);

    for (auto item : ans)
    {
        cout << item << " ";
    }
    cout << endl;

    vector<int> ans_2 = k_way_merge_2(test_case);

    for (auto item : ans_2)
    {
        cout << item << " ";
    }
    cout << endl;
    return 0;
}

class Solution
{
public:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

private:
    ListNode *merge_tow_lists(ListNode *left, ListNode *right)
    {
        if (left == nullptr)
        {
            return right;
        }

        if (right == nullptr)
        {
            return left;
        }
        ListNode *dummy_head = new ListNode();
        ListNode *cur_node = dummy_head;
        while (left != nullptr && right != nullptr)
        {
            if (left->val < right->val)
            {
                cur_node->next = left;
                left = left->next;
            }
            else
            {
                cur_node->next = right;
                right = right->next;
            }

            cur_node = cur_node->next;
        }

        // while (left != nullptr)
        // {
        //     cur_node->next = left;
        //     left = left->next;
        //     cur_node = cur_node->next;
        // }

        // while (right != nullptr)
        // {
        //     cur_node->next = right;
        //     right = right->next;
        //     cur_node = cur_node->next;
        // }

        if (left != nullptr)
        {
            cur_node->next = left;
        }
        else
        {
            cur_node->next = right;
        }

        return dummy_head->next;
    }
    ListNode *merge_k_lists(vector<ListNode *> &lists, int start, int end)
    {
        if (start >= end)
        {
            return lists[start];
        }

        int mid = start + (end - start) / 2;
        ListNode *left = merge_k_lists(lists, start, mid);
        ListNode *right = merge_k_lists(lists, mid + 1, end);
        return merge_tow_lists(left, right);
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
        {
            return nullptr;
        }
        return merge_k_lists(lists, 0, lists.size() - 1);
    }
};

class Solution2
{
private:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    struct node_info_t
    {
        ListNode *cur_list;
        bool operator<(node_info_t *const b) const
        {
            return cur_list->val > b->cur_list->val;
        }
    };

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
        {
            return nullptr;
        }
        priority_queue<node_info_t> pq;

        for (auto item : lists)
        {
            if (item != nullptr)
            {
                pq.push({item});
            }
        }

        ListNode *dummy_head = new ListNode();
        ListNode *cur_node = dummy_head;
        while (!pq.empty())
        {
            cur_node->next = pq.top().cur_list;
            pq.pop();
            cur_node = cur_node->next;
            if (cur_node->next != nullptr)
            {
                pq.push({cur_node->next});
            }
        }
        return dummy_head->next;
    }
};