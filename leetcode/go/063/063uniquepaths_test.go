package main

import "testing"

func TestUniquePathsWithObstacles(t *testing.T) {
	A := [][]int{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}}
	if uniquePathsWithObstacles(A) != 2 {
		t.Error("063 uniquePathsWithObstacles doesn't work correctly!")
	}
}
