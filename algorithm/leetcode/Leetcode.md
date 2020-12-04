198. 打家劫舍

```go
func rob(nums []int) int {
    dpI2 := 0
    dpI1 :=0
    dpI :=0

    for i := len(nums) -1 ; i>=0; i-- {
        if dpI1 > nums[i] + dpI2 {
            dpI = dpI1
        }else {
            dpI = nums[i] + dpI2
        }
        dpI2 = dpI1
        dpI1 = dpI
    }
    return dpI
}
```