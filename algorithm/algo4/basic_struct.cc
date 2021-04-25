#include <iomanip>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <unordered_map>
#include <map>
#include <queue>
#include <vector>

using namespace std;

void heap_sort(vector<int> &a, int len)
{
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < len; i++)
    {
        q.push(a[i]);
    }
    for (int i = 0; i < len; i++)
    {
        a[i] = q.top();
        q.pop();
    }
}

int main()
{
    string s = "abcd";
    reverse(s.begin(), s.end());
    cout << s << endl;

    vector<int> a = {8, 9, 1, 3, 6};

    heap_sort(a, a.size());
    for (int i = 0; i < a.size(); i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    vector<int> test_case = {1, 2, 5, 8, 9, 4, 3, 9, 11, 12, 14, 13, 15};

    for (int i = 0; i < test_case.size(); i++)
    {
        vector<int> tmp = vector<int>(test_case.begin() + i, test_case.begin() + i + 5);
        sort(tmp.begin(), tmp.end());
        int k = 1;
        for (; k < tmp.size(); k++)
        {
            if (tmp[k] != tmp[k - 1] + 1)
            {
                break;
            }
        }
        if (k != tmp.size())
        {
            continue;
        }
        else
        {
            cout << "match" << endl;
            for (auto it : tmp)
            {
                cout << it << " ";
            }
            cout << endl;
            break;
        }
    }

    return 0;
}