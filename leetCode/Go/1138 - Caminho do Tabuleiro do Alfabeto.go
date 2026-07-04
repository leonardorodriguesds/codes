import "math"

func alphabetBoardPath(target string) string {
	board := map[rune][]int{
		'a': {0, 0},
		'b': {0, 1},
		'c': {0, 2},
		'd': {0, 3},
		'e': {0, 4},
		'f': {1, 0},
		'g': {1, 1},
		'h': {1, 2},
		'i': {1, 3},
		'j': {1, 4},
		'k': {2, 0},
		'l': {2, 1},
		'm': {2, 2},
		'n': {2, 3},
		'o': {2, 4},
		'p': {3, 0},
		'q': {3, 1},
		'r': {3, 2},
		's': {3, 3},
		't': {3, 4},
		'u': {4, 0},
		'v': {4, 1},
		'w': {4, 2},
		'x': {4, 3},
		'y': {4, 4},
		'z': {5, 0},
	}

	x, y := 0, 0
	c := 'a'
	res := ""

	for _, ch := range target {
		if c == 'z' && ch != 'z' {
			res += string('U')
			x, y = board['u'][0], board['u'][1]
		}

		dr, dc := board[ch][0]-x, board[ch][1]-y

		for y = 0; y < int(math.Abs(float64(dc))); y++ {
			if dc < 0 {
				res += string('L')
			} else {
				res += string('R')
			}
		}

		for y = 0; y < int(math.Abs(float64(dr))); y++ {
			if dr < 0 {
				res += string('U')
			} else {
				res += string('D')
			}
		}
		res += string('!')
		x, y = board[ch][0], board[ch][1]
		c = ch
	}

	return res
}