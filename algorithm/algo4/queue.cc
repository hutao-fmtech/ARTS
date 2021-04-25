#include <stack>

using namespace std;

class MyQueue
{
private:
    /* data */
    stack<int> in_stack;
    stack<int> out_stack;

    void in2out()
    {
        while (!in_stack.empty())
        {
            out_stack.push(in_stack.top());
            in_stack.pop();
        }
    }

public:
    MyQueue(/* args */);
    ~MyQueue();

    void push(int x)
    {
        in_stack.push(x);
    }

    int pop()
    {
        if (out_stack.empty())
        {
            in2out();
        }
        int ret = out_stack.top();
        out_stack.pop();
        return ret;
    }

    int peek()
    {
        if (out_stack.empty())
        {
            in2out();
        }
        return out_stack.top();
    }

    bool empty()
    {
        return in_stack.empty() && out_stack.empty();
    }
};