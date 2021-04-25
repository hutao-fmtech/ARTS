#include <vector>
#include <iostream>

using namespace std;
class MyQuickSort
{
public:
    static void sort(vector<int> &x)
    {
        sort(x, 0, x.size() - 1);
    }

private:
    //   1.  使用左右指针（i，j），分别寻找大于，小于 pivot 的位置。
    //   2. 左指针的值小于等于 pivot 时，左指针++（i++），往右移动，直至值大于 pivot。
    //   3. 右指针的值大于 pivot 值时，右指针-- （j--），往左移动，直至值小于 pivot。
    //   4. 当出现 a[i] > pivot, a[j] < pivot 是时交换 i，j，此时依然满足 a[i] <= pivot , a[j] > pivot, 2，3 步骤继续。
    //   5. 当 j <= i 时，整个数组扫描完成，交换 j 值 和 pivot 值。

    //   6. 一定 return j 指针。此时分区为 [lo，j-1],[j],[j+1,hi]
    //   7. 再次 partition 区间，[lo，j-1] ,[j+1,hi]
    static int partition(vector<int> &nums, int lo, int hi)
    {
        int i = lo;
        int j = hi + 1;   // 处理技巧，方便下面循环是直接 --
        int v = nums[lo]; // 以 lo 为pivot

        for (;;)
        {
            // 1. 寻找左边大于 nums[pivot] 值
            for (;;)
            {
                i++;
                if (nums[i] > v || i >= hi)
                    break;
            }
            // 2. 寻找右边小于 nums[pivot] 值

            for (;;)
            {
                j--;
                if (nums[j] < v || j <= lo)
                    break;
            }

            // 4. 整个数组扫描完成，结束
            if (j <= i)
                break;
            // 3. 此时 i 找一个一个比 pivot 大的，j 找一个比 pivot 小的，两者交换
            // 注意：交换后，i 位置的数值比 pivot 小，而 j 位置的 数值又比 pivot 大，进而又可以开始第二轮寻宝。
            swap(nums[i], nums[j]);
        }
        // 把锚点，放到对应位置
        swap(nums[lo], nums[j]);
        return j;
    }

    static void sort(vector<int> &nums, int lo, int hi)
    {
        if (hi <= lo)
        {
            return;
        }
        int pivot = partition(nums, lo, hi);
        sort(nums, lo, pivot - 1);
        sort(nums, pivot + 1, hi);
    }
};

int main()
{
    vector<int> test_case = {1, 6, 9, 9, 8, 2, 1, -1, 0, 99};

    MyQuickSort::sort(test_case);

    for (auto &i : test_case)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}