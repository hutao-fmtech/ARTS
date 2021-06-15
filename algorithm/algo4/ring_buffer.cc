#include <stdio.h>
#include <stdint.h>

#define BUF_SIZE 10

static int buf[BUF_SIZE] = {0};
static int head = 0;
static int tail = 0;

bool is_full()
{
    if (head == (tail + 1) % BUF_SIZE)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool is_empty()
{
    if (head == tail)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int push(int data)
{
    if (is_full())
    {
        printf("is full\n");
        return -1;
    }
    buf[tail] = data;
    tail = (tail + 1) % BUF_SIZE;
    return 0;
}

int pop(int *data)
{
    if (is_empty())
    {
        printf("is empty\n");
        return -1;
    }
    *data = buf[head];
    head = (head + 1) % BUF_SIZE;
    return 0;
}

int main()
{
    for (int i = 0; i < BUF_SIZE; i++)
    {
        push(i);
    }

    int data;
    for (int i = 0; i < BUF_SIZE; i++)
    {
        int ret = pop(&data);
        if (ret == 0)
        {

            printf("data = %d\n", data);
        }
    }
    return 0;
}