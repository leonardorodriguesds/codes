package main

import (
	"sort"
)

type Pair struct {
	val int
	idx int
}

func twoSum(nums []int, target int) []int {
	pairs := []Pair{}
	for i, v := range nums {
		pairs = append(pairs, Pair{
			val: v,
			idx: i,
		})
	}

	sort.Slice(pairs, func(i, j int) bool {
		return pairs[i].val < pairs[j].val
	})

	var l, r = 0, len(nums) - 1

	for l < r {
		if pairs[l].val+pairs[r].val > target {
			r = r - 1
		} else if pairs[l].val+pairs[r].val < target {
			l = l + 1
		} else {
			break
		}
	}

	if pairs[l].val+pairs[r].val != target {
		return []int{}
	}

	return []int{pairs[l].idx, pairs[r].idx}
}
