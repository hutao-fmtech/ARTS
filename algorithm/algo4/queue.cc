#include <stack>
#include <vector>
#include <iostream>

using namespace std;
class MyQueue
{
private:
    /* data */
    stack<int> in_stk;
    stack<int> out_stk;

    void in2out()
    {
        while (!in_stk.empty())
        {
            out_stk.push(in_stk.top());
            in_stk.pop();
        }
    }

public:
    void push(int x)
    {
        in_stk.push(x);
    }

    int pop()
    {
        if (out_stk.empty())
        {
            in2out();
        }
        int ret = out_stk.top();
        out_stk.pop();
        return ret;
    }

    int peek()
    {
        while (out_stk.empty())
        {
            in2out();
        }
        return out_stk.top();
    }

    bool empty()
    {
        return in_stk.empty() && out_stk.empty();
    }
    MyQueue(/* args */);
    ~MyQueue();
};

MyQueue::MyQueue(/* args */)
{
}

MyQueue::~MyQueue()
{
}

int main()
{
    MyQueue q;

    vector<int> test = {1, 2, 3, 4};
    for (auto &x : test)
    {
        q.push(x);
    }

    for (int i = 0; i < test.size()+1; i++)
    {
        cout << q.pop() << endl;
    }
    return 0;
}
