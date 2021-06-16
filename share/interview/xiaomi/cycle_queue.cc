#include <stdio.h>

#define BUFF_SIZE 10

static int __buf[BUFF_SIZE] = {0};

static int head = 0;
static int tail = 0;

static bool is_full()
{
	if (head == (tail + 1) % BUFF_SIZE)
	{
		return true;
	}
	return false;
}

static bool is_empty()
{
	if (head == tail)
	{
		return true;
	}
	return false;
}

int pop(int *p_out)
{
	if (p_out == nullptr)
	{
		printf("error:para is null\n");
		return -1;
	}
	if (is_empty())
	{
		printf("error:is empty\n");
		return -2;
	}
	*p_out = __buf[head];
	head = (head + 1) % BUFF_SIZE;
	return 0;
}

int push(int data)
{
	if (is_full())
	{
		printf("error:is full\n");
		return -1;
	}
	__buf[tail] = data;
	tail = (tail + 1) % BUFF_SIZE;
	return 0;
}

int main()
{
	for (int i = 0; i < BUFF_SIZE; i++)
	{
		push(i + 5);
	}
	for (int i = 0; i < BUFF_SIZE; i++)
	{
		int data;
		int ret = pop(&data);
		if (ret == 0)
		{
			printf("data = %d\n", data);
		}
	}

	return 0;
}