
**岗位：路由器高级软件工程师**

**时间：2020-10-16 20:00**

**方式：牛客网视频面试**

**题目：**

1. 实现atoi(const char * s)

**思路**
- 有限状态机。碰到问题，不要采用第一步的想到的方法傻写，能整理成有限状态机，能减少很多debug 的时间。
- 在小米面试路由器部门时碰到这个，当时采用的傻写，面试官问能否优化时，并没有想到状态机。
- 直接使用官方的题解，执行时间比较考后（20ms），主要是因为方便大家看懂用的map。改成const 状态表格，执行时间8ms，效率不比傻写判断分支差。
- leetcode 题目 [8. 字符串转换整数 (atoi)](https://leetcode-cn.com/problems/string-to-integer-atoi/)

**代码**
```c++

#define START 0
#define SIGNED 1
#define IN_NUMBER 2
#define END 3

int const state_table[][4] = {{START, SIGNED, IN_NUMBER, END}, {END, END, IN_NUMBER, END}, {END, END, IN_NUMBER, END}, {END, END, END, END}};

class Automaton
{

private:
    int state = START;
    int get_col(char c)
    {
        if (isspace(c))
            return START;
        if (c == '+' or c == '-')
            return SIGNED;
        if (isdigit(c))
            return IN_NUMBER;
        return END;
    }

public:
    int sign = 1;
    long long ans = 0;

    void get(char c)
    {
        state = state_table[state][get_col(c)];
        if (state == IN_NUMBER)
        {
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
        }
        else if (state == SIGNED)
            sign = c == '+' ? 1 : -1;
    }
};

class Solution
{
public:
    int myAtoi(string str)
    {
        Automaton automaton;
        for (char c : str)
            automaton.get(c);
        return automaton.sign * automaton.ans;
    }
};
```

2. 判断百万级别的数列中，是否有5个数据是相邻的，即这个5个数排序后，相邻两个数相差1，初始位置不一定相邻。
