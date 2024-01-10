package main

import "fmt"

func lengthOfLongestSubstring(s string) int {
	var longest_substring, current_substring int
	var start_substring int
	characters_substring := map[byte]bool{}

	for i := 0; i < len(s); i++ {
		_, already_present := characters_substring[s[i]]

		if already_present {
			if current_substring > longest_substring {
				longest_substring = current_substring
			}

			clear(characters_substring)

			i = start_substring
			start_substring += 1
			current_substring = 0

			continue
		}

		characters_substring[s[i]] = true
		current_substring++
	}

	if current_substring > longest_substring {
		longest_substring = current_substring
	}

	return longest_substring
}

func main() {
	fmt.Println(lengthOfLongestSubstring("dedf"))
}
