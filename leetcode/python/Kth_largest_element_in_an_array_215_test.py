import unittest

from Kth_largest_element_in_an_array_215 import Solution 


class TestSolution(unittest.TestCase):

    def setUp(self):
        self.solution = Solution()

    def test_findKthLargest(self):
        a = [6, 1, 3, 5, 7, 2, 4, 9, 11, 8]
        self.assertEqual(self.solution.findKthLargest(a, 3), 8)
