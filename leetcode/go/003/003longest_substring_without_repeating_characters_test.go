package main

import "testing"

func TestLengthoflongestsubstring1(t *testing.T) {
	a := "abcabcbb"
	b := "bbbbb"
	c := "pwwkew"
	d := " "
	if lengthoflongestsubstring1(a) != 3 {
		t.Errorf("003 longest substring without repeating characters not work correctly!")
	}
	if lengthoflongestsubstring1(b) != 1 {
		t.Errorf("003 longest substring without repeating characters not work correctly!")
	}
	if lengthoflongestsubstring1(c) != 3 {
		t.Errorf("003 longest substring without repeating characters not work correctly!")
	}
	if lengthoflongestsubstring1(d) != 1 {
		t.Errorf("003 longest substring without repeating characters not work correctly!")
	}

}
