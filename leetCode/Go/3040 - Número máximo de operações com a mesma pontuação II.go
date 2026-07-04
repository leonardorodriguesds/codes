package main

import "fmt"

func fn(arr []int, l, r, target int, mem *[2000 + 1][2000 + 1]int) int {
	if r <= l {
		return 0
	}

	res := mem[l][r]
	if res == 0 {
		if arr[l]+arr[l+1] == target {
			res = fn(arr, l+2, r, target, mem) + 1
		}
		if arr[l]+arr[r] == target {
			res = max(res, fn(arr, l+1, r-1, target, mem)+1)
		}
		if arr[r]+arr[r-1] == target {
			res = max(res, fn(arr, l, r-2, target, mem)+1)
		}
	}

	mem[l][r] = res
	return res
}

func maxOperations(nums []int) int {
	var mem [2000 + 1][2000 + 1]int
	l, r := 0, len(nums)-1
	return max(
		fn(nums, l+2, r, nums[l]+nums[l+1], &mem),
		fn(nums, l+1, r-1, nums[l]+nums[r], &mem),
		fn(nums, l, r-2, nums[r]+nums[r-1], &mem),
	) + 1
}

func main() {
	nums := []int{13, 1, 11, 7, 15}
	result := maxOperations(nums)

	fmt.Println(result)
}
