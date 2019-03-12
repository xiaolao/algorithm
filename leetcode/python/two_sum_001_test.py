import unittest

from two_sum_001 import Solution


class TestSolution(unittest.TestCase):

    def setUp(self):
        self.solution = Solution()

    def test_twoSum(self):
        nums = [2, 7, 11, 15]
        self.assertEqual(self.solution.twoSum(nums, 9), [0, 1])
        self.assertFalse(self.solution.twoSum(nums, 14))
