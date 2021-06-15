#include <ctype.h>
#include <algorithm>
#include <limits.h>
#include <string>
#include <iostream>
#include <unordered_map>
#include <iomanip>

// [8. 字符串转换整数 (atoi)](https://leetcode-cn.com/problems/string-to-integer-atoi/)
using namespace std;

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
        if (c == '+' || c == '-')
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
            ans = ans * 10 + (c - '0');
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

int main()
{
    unordered_map<string, int> test_case = {{"123", 123}, {"-123", -123}, {"dd", 0}, {"    123", 123}, {"    123   13", 123}};

    Solution *p = new Solution();

    for (auto &item : test_case)
    {
        if (p->myAtoi(item.first) == item.second)
        {
            cout << right << setw(16) << item.first << ": pass" << endl;
        }
        else
        {
            cout << right << setw(16) << item.first << ": fail" << endl;
        }
    }
}