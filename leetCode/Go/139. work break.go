func wordBreak(s string, wordDict []string) bool {
    m := make(map[rune]int)

    for _, c := range s {
        m[c]++
    }

    for _, w := range wordDict {
        for _, r := range w {
            if m[r] > 0 {
                m[r]-- 
            } else {
                return false 
            }
        }
    }
    return true
}