import unittest

from lru_cache_146 import LRUCache


class TestLRUCache(unittest.TestCase):

    def setUp(self):
        self.cache = LRUCache(2)

    def test_put_get(self):
        self.cache.put(1, 1)
        self.cache.put(2, 2)
        self.assertEqual(self.cache.get(1), 1)
        self.cache.put(3, 3)
        self.assertEqual(self.cache.get(2), -1)
        self.cache.put(4, 4)
        self.assertEqual(self.cache.get(1), -1)
        self.assertEqual(self.cache.get(3), 3)
        self.assertEqual(self.cache.get(4), 4)


if __name__ == "__mian__":
    unittest.main()
