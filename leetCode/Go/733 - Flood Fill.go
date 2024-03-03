type Pos struct {
    x, y int
}

func floodFill(image [][]int, sr int, sc int, color int) [][]int {
    m, n, c := len(image), len(image[0]), image[sr][sc]
    if c == color {
        return image
    }
    queue := []Pos{{x: sr, y: sc}}
    for len(queue) > 0 {
        p := queue[0]
        queue = queue[1:]
        x, y := p.x, p.y
        if image[x][y] == c {
            image[x][y] = color

            if x - 1 >= 0 && image[x-1][y] == c {
                queue = append(queue, Pos{x: x-1, y: y})
            }

            if x + 1 < m && image[x+1][y] == c {
                queue = append(queue, Pos{x: x+1, y: y})
            }

            if y - 1 >= 0 && image[x][y-1] == c {
                queue = append(queue, Pos{x: x, y: y-1})
            }

            if y + 1 < n && image[x][y+1] == c {
                queue = append(queue, Pos{x: x, y: y+1})
            }
        }
    }

    return image
}