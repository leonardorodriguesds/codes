package main

func minArraySum(nums []int) int64 {
	maxVal := 100000
	freq := make([]int, maxVal+1)
	present := make([]bool, maxVal+1)
	best := make([]int, maxVal+1)

	for _, x := range nums {
		freq[x]++
		present[x] = true
	}

	for d := 1; d <= maxVal; d++ {
		if !present[d] {
			continue
		}

		for m := d; m <= maxVal; m += d {
			if best[m] == 0 {
				best[m] = d
			}
		}
	}

	var soma int64
	for _, x := range freq {
		soma += int64(x * best[x])
	}

	return soma
}
