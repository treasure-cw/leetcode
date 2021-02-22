/*
如果正整数可以被 A 或 B 整除，那么它是神奇的。
返回第 N 个神奇数字。由于答案可能非常大，返回它模 10^9 + 7 的结果。

示例 1：
输入：N = 1, A = 2, B = 3
输出：2
示例 2：
输入：N = 4, A = 2, B = 3
输出：6
示例 3：
输入：N = 5, A = 2, B = 4
输出：10
示例 4：
输入：N = 3, A = 6, B = 4
输出：8
 
提示：
1 <= N <= 10^9
2 <= A <= 40000
2 <= B <= 40000
*/
/*
二分查找
*/
class Solution {
public:
    int nthMagicalNumber(int N, int A, int B) {
        int MOD = 1e9 + 7;
        int L = A / gcd(A, B) * B;
        long lo = 0;
        long hi = (long) 1e15;
        while (lo < hi) {
            long mi = lo + (hi - lo) / 2;
            if (mi / A + mi / B - mi / L < N)
                lo = mi + 1;
            else
                hi = mi;
        }
        return (int) (lo % MOD);
    }

    int gcd(int x, int y) {
        if (x == 0) return y;
        return gcd(y % x, x);
    }
};
