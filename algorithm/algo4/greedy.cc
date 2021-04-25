#include <algorithm>
#include <iostream>

using namespace std;

int get_max_money(int d, int p, int g, int m, int c)
{
    for (int i = 0; i < d; i++)
    {
        cout << "--- day " << i << " ---" << endl;
        // 1. 雇佣
        int works = m / c;

        int m1 = (d - i) * (p + works) * g - works * c + m;

        // 2. 不雇佣
        int m2 = (d - i) * p * g + m;

        if (m1 > m2)
        {
            cout << "雇佣" << endl;
            m = (p + works) * g - works * c + m;
            p += works;
        }
        else
        {
            cout << "不雇佣" << endl;
            m = p * g + m;
        }
        cout << "money: " << m << endl;
    }

    return m;
}

int main()
{
    int d = 3;
    int p = 3;
    int g = 30;
    int m = 10;
    int c = 50;
    int ans = get_max_money(d, p, g, m, c);

    cout << ans << endl;
}