// Given a non-negative integer x, compute and return the square root of x.

// Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.

//  

// Example 1:

// Input: x = 4
// Output: 2
// Example 2:

// Input: x = 8
// Output: 2
// Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.
//  

// Constraints:

// 0 <= x <= 231 - 1

/**
 * 牛顿迭代法
 * 令y = f(x) = x ^^ 2 - C  则f(x)在xi处的一阶泰勒展开为 f(x) ~ f(xi) + f(xi)`(x - xi)
 */

#include <cmath>

using std::log;
using std::exp;
using std::fabs;

class Solution {
public:

    // 牛顿迭代法
    int mySqrt(int x) {
        if (x == 0) return 0;
        double C = x, x0 = x, xi = 0.0;
        while (true) {
            xi = 0.5 * (x0 + C / x0);
            if (fabs(xi - x0) < 1e-7) break;
            x0 = xi;
        }
        return int(x0);
    }

    // 二分查找法
    int mySqrt1(int x) {
        int l = 0, r = x, ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if ((long long) mid * mid <= x) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }

    // 袖珍计算器算法
    int mySqrt2(int x) {
        if (x == 0) return 0;
        int ans = exp(0.5 * log(x));
        return (long long) (ans + 1) * (ans + 1) <= x ? ans + 1 : ans;
    }
};
