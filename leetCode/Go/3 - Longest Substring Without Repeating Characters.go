func lengthOfLongestSubstring(s string) int {
    charIndexMap := make(map[rune]int)
	maxLen := 0
	start := 0 

	for i, char := range s {
		if lastIndex, ok := charIndexMap[char]; ok && lastIndex >= start {
			start = lastIndex + 1
		}
		if i-start+1 > maxLen {
			maxLen = i - start + 1
		}
		charIndexMap[char] = i
	}

	return maxLen
}