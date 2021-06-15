#include <ctype.h>
#include <unordered_map>
#include <algorithm>
#include <limits.h>
#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

#define START 0
#define SIGNED 1
#define IN_NUMBER 2
#define END 3

int const state_table[][4] = {{START, SIGNED, IN_NUMBER, END}, {END, END, IN_NUMBER, END}, {END, END, IN_NUMBER, END}, {END, END, END, END}};
class Automation
{
private:
	/* data */
	int state = START;
	int get_col(char c)
	{
		if (isspace(c))
		{
			return START;
		}

		if (c == '+' || c == '-')
		{
			return SIGNED;
		}

		if (isdigit(c))
		{
			return IN_NUMBER;
		}

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
		{
			sign = c == '+' ? 1 : -1;
		}
	}
};

class Solution
{
public:
	int myAtoi(string str)
	{
		Automation automation;
		for (char c : str)
		{
			automation.get(c);
		}
		return automation.sign * automation.ans;
	}
};

int main()
{
	unordered_map<string, int> test_case = {{"123", 123}, {"-123", -123}, {"   12+13", 12}};

	Solution *p_solution = new Solution();
	for (auto &item : test_case)
	{
		if (p_solution->myAtoi(item.first) == item.second)
		{
			printf("\t%s : pass\n",item.first.c_str());
		}
		else
		{
			printf("\t%s : fail\n",item.first.c_str());
		}
	}
}