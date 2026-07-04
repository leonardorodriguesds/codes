package main

import "sort"

func earliestTime(tasks [][]int) int {
	sort.Slice(tasks, func(i, j int) bool {
		return tasks[i][0]+tasks[i][1] < tasks[j][0]+tasks[j][1]
	})

	return tasks[0][0] + tasks[0][1]
}
