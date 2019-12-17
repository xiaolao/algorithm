package main

import "testing"

func TestMaxWidthRamp(t *testing.T) {
	A := []int{6, 0, 8, 2, 1, 5}
	if maxWidthRamp(A) != 4 {
		t.Error("962 maxWidthRamp doesn't work correctly.")
	}
	B := []int{9, 8, 1, 0, 1, 9, 4, 0, 4, 1}
	if maxWidthRamp(B) != 7 {
		t.Error("962 maxWidthRamp doesn't work correctly.")
	}
}
