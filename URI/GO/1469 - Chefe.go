package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

type Graph struct {
	adj  [][]int
	ages []int
	n    int
}

func NewGraph(n int) *Graph {
	return &Graph{
		adj:  make([][]int, n),
		ages: make([]int, n),
		n:    n,
	}
}

func (g *Graph) AddEdge(u, v int) {
	g.adj[u] = append(g.adj[u], v)
}

func (g *Graph) swap(u, v int) {
	g.adj[u], g.adj[v] = g.adj[v], g.adj[u]

	for i := 0; i < g.n; i++ {
		for j := 0; j < len(g.adj[i]); j++ {
			if g.adj[i][j] == u {
				g.adj[i][j] = v
			} else if g.adj[i][j] == v {
				g.adj[i][j] = u
			}
		}
	}

}

func (g *Graph) dfs(u int, visited []bool) int {
	var res int = math.MaxInt

	visited[u] = true

	for _, v := range g.adj[u] {
		if visited[v] {
			continue
		}

		res = min(min(res, g.ages[v]), g.dfs(v, visited))
	}

	return res
}

func main() {
	in := bufio.NewReader(os.Stdin)

	for {
		var n, m, l int
		if _, err := fmt.Fscan(in, &n, &m, &l); err != nil {
			break
		}

		graph := NewGraph(n)

		for i := 0; i < n; i++ {
			if _, err := fmt.Fscan(in, &graph.ages[i]); err != nil {
				return
			}
		}

		for i := 0; i < m; i++ {
			var x, y int
			if _, err := fmt.Fscan(in, &x, &y); err != nil {
				return
			}
			graph.AddEdge(y-1, x-1)
		}

		for i := 0; i < l; i++ {
			var op string
			fmt.Fscan(in, &op)

			if op == "T" {
				var x, y int
				fmt.Fscan(in, &x, &y)
				graph.swap(x-1, y-1)
			} else if op == "P" {
				var u int
				fmt.Fscan(in, &u)
				var age int = graph.dfs(u-1, make([]bool, graph.n))
				if age >= math.MaxInt {
					fmt.Println("*")
				} else {
					fmt.Println(age)
				}
			}
		}

		_ = graph
	}
}
