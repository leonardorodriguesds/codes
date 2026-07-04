package main

import (
	"fmt"
	"math"
)

func reverse(x int) int {
	res := 0
	sign := 1
	if x < 0 {
		sign = -1
		x = -x
	}

	for x > 0 {
		res = res*10 + x%10
		x /= 10
	}

	res *= sign
	if res < math.MinInt32 || res > math.MaxInt32 {
		return 0
	} else {
		return res
	}
}

func main() {
	var num int
	fmt.Scan(&num)
	fmt.Println("output:", reverse(num))
}
