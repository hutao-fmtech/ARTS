
#include <iostream>

using namespace std;

int tail = 0;
int head = 0;

#define QUEUE_SIZE 10
int buf[QUEUE_SIZE];
inline bool empty()
{
    return tail == head ? true : false;
}

inline bool is_full()
{
    return head == (tail + 1) % QUEUE_SIZE ? true : false;
}

int push(int data)
{
    if (is_full())
    {
        return -1;
    }
    buf[tail] = data;

    tail = (tail + 1) % QUEUE_SIZE;
    cout << "tail = " << tail << endl;
    return 0;
}

int pop(int *p_out)
{
    if (empty())
    {
        return -1;
    }
    *p_out = buf[head];
    head = (head + 1) % QUEUE_SIZE;

    cout << "head = " << head << endl;
    return 0;
}

int main()
{
    for (int i = 0; i < QUEUE_SIZE; i++)
    {
        int ret = push(i);
        cout << "ret = " << ret << endl;
    }

    for (int i = 0; i < QUEUE_SIZE; i++)
    {
        int data;
        int ret = pop(&data);
        cout << "ret = " << data << endl;
    }
}