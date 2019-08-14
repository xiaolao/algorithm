package leetcode

import "testing"

func TestLRUCache(t *testing.T) {
	cache := Constructor(2)
	cache.Put(1, 1)
	cache.Put(2, 2)
	t.Log(cache.Get(1)) // returns 1
	cache.Put(3, 3)     // evicts key 2
	t.Log(cache.Get(2)) // returns -1 (not found)
	cache.Put(4, 4)     // evicts key 1
	t.Log(cache.Get(1)) // returns -1 (not found)
	t.Log(cache.Get(3)) // returns 3
	t.Log(cache.Get(4)) // returns 4
}
