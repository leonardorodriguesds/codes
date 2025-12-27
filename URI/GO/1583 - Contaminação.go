package main

import (
	"bufio"
	"fmt"
	"os"
)

func floodFill(grid [][]rune, x, y, n, m int) {
	if x < 0 || x >= n || y < 0 || y >= m {
		return
	}

	if grid[x][y] == 'A' {
		grid[x][y] = 'T'

		floodFill(grid, x-1, y, n, m)
		floodFill(grid, x+1, y, n, m)
		floodFill(grid, x, y-1, n, m)
		floodFill(grid, x, y+1, n, m)
	}
}

func main() {

	in := bufio.NewReader(os.Stdin)

	for {
		var n, m int
		if _, err := fmt.Fscan(in, &n, &m); err != nil || (n == 0 && m == 0) {
			break
		}

		grid := make([][]rune, n)
		for i := 0; i < n; i++ {
			grid[i] = make([]rune, m)
		}

		for i := 0; i < n; i++ {
			var line string
			fmt.Fscan(in, &line)

			for j, ch := range line {
				grid[i][j] = ch
			}
		}

		for i := 0; i < n; i++ {
			for j := 0; j < m; j++ {
				if grid[i][j] == 'T' {
					floodFill(grid, i-1, j, n, m)
					floodFill(grid, i+1, j, n, m)
					floodFill(grid, i, j-1, n, m)
					floodFill(grid, i, j+1, n, m)
				}
			}
		}

		for _, row := range grid {
			fmt.Println(string(row))
		}
		fmt.Println()
	}

}
