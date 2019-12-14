package main

import "testing"

func TestMinimumTotal(t *testing.T) {
	A := [][]int{
		{2},
		{3, 4},
		{6, 5, 7},
		{4, 1, 8, 3},
	}

	if minimumTotal(A) != 11 {
		t.Error("120 triangle doesn't work correctly.")
	}
}
