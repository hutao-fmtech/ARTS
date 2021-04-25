#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

class MyMergeSort
{
private:
    static vector<int> *p_aux;

public:
    static void sort(vector<int> &a)
    {
        vector<int> aux = vector<int>(a.size());
        sort(a, 0, a.size() - 1, aux);
    }

private:
    static void sort(vector<int> &a, int lo, int hi, vector<int> &aux)
    {
        if (hi <= lo)
        {
            return;
        }
        int mid = lo + (hi - lo) / 2;
        sort(a, lo, mid, aux);
        sort(a, mid + 1, hi, aux);
        merge(a, lo, mid, hi, aux);
    }

    static void merge(vector<int> &a, int lo, int mid, int hi, vector<int> &aux)
    {

        int i = lo;
        int j = mid + 1;
        int k = lo;

        // 归并 while 3步曲
        while (i <= mid && j <= hi)
        {
            if (a[i] < a[j])
            {
                aux[k++] = a[i++];
            }
            else
            {
                aux[k++] = a[j++];
            }
        }

        while (i <= mid)
        {
            aux[k++] = a[i++];
        }

        while (j <= hi)
        {
            aux[k++] = a[j++];
        }
        // 把辅助数组接口更新到数组中去
        for (int k = lo; k <= hi; k++)
        {
            a[k] = aux[k];
        }
    }
};

int numDecodings(string s)
{

    if (s.size() == 0 || (s.size() == 1 && s[0] == '0'))
        return 0;

    if (s.size() == 1)
        return 1;

    int ans = 0;

    vector<int> dp(s.size() + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= s.size(); i++)
    {

        if (s[i] == '0')
        {
            dp[i] = 0;
        }
        else
        {
            dp[i] = dp[i - 1];
        }

        if (i > 1 && s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))
        {
            dp[i] += dp[i - 2];
        }
        if (dp[i] == 0)
            return 0;
    }
    return dp.back();
}

int main()
{
    vector<int> test_case = {1, 6, 9, 9, 8, 2, 1, -1, 0, 99};

    MyMergeSort::sort(test_case);

    for (auto &x : test_case)
    {
        cout << x << " ";
    }
    cout << endl;

    cout << numDecodings("12") << endl;
    return 0;
}