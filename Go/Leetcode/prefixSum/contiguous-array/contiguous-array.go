package main

import (
	"fmt"
	"math"
)

func findMaxLength(nums []int) int {
	cnt := 0
	size := len(nums)
	// 0 换为 -1
	for i := 0; i < size; i++ {
		if nums[i] == 0 {
			nums[i] = -1
		}
	}
	// 前缀和 -> 前缀和尾元素下标
	hmap := make(map[int]int)
	sum := 0
	for i := 0; i < size; i++ {
		sum += nums[i]
		if sum == 0 && i > cnt {
			cnt = i + 1
		}
		if _, ok := hmap[sum]; ok {
			cnt = int(math.Max(float64(i-hmap[sum]), float64(cnt)))
		} else {
			hmap[sum] = i
		}
	}
	return cnt
}

func main() {
	nums := []int{0, 1, 0, 0, 0, 1, 1, 1}
	fmt.Println(findMaxLength(nums))
}
