package main

import "testing"

func TestIsValid(t *testing.T) {
	if !isValid("()") {
		t.Error("020 valid parentheses not work correctly.")
	}
	if !isValid("(){}[]") {
		t.Error("020 valid parentheses not work correctly.")
	}
	if isValid("(]") {
		t.Error("020 valid parentheses not work correctly.")
	}
	if isValid("([)]") {
		t.Error("020 valid parentheses not work correctly.")
	}
	if !isValid("{[]}") {
		t.Error("020 valid parentheses not work correctly.")
	}

}
