package main

import (
	"fmt"
	// "strconv"
)

type void struct{}

var null void

func main() {
	s := "abcddfg"
	set := make(map[string]void)
	for _, i := range s {
		key := string(i)
		if _, exists := set[key]; exists {
			fmt.Println(key)
			return
		}
		set[key] = null

	}
}
