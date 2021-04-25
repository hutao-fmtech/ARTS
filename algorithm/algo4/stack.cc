#include <queue>

using namespace std;

class MyStack
{
public:
    queue<int> q1;
    queue<int> q2;

    MyStack()
    {
    }

    void push(int x)
    {
        q2.push(x);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop()
    {
        int ret = q1.front();
        q1.pop();
        return ret;
    }

    int top()
    {
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};

class MyStack2
{
public:
    queue<int> q;
    MyStack2()
    {
    }

    void push(int x)
    {
        int size = q.size();
        q.push(x);
        for (int i = 0; i < size; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        int ret = q.front();
        q.pop();
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};
