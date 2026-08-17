/*problem link - https://leetcode.com/problems/powx-n/ */

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n;

        if(nn<0) nn= (-1) *nn;

        while(nn){
            if(nn%2==1){
                ans = ans*x;
                nn = nn-1;
            }
            else{
                x *= x;
                nn = nn/2;
            }
        }
        if(n<0) ans = (double)1/ans;
        return ans;
    }
};

/*
intution 
Initial state: ans = 1.0, nn = 10 (positive, so no sign flip needed), x = 2.0

Step	nn	nn even/odd?	Action	ans (after)	x (after)
1	10	even	x *= x → x=4, nn /= 2 → nn=5	1.0	4.0
2	5	odd	ans *= x → ans=4, nn -= 1 → nn=4	4.0	4.0
3	4	even	x *= x → x=16, nn /= 2 → nn=2	4.0	16.0
4	2	even	x *= x → x=256, nn /= 2 → nn=1	4.0	256.0
5	1	odd	ans *= x → ans=1024, nn -= 1 → nn=0	1024.0	256.0

Loop ends (nn == 0).

Since n = 10 is not negative, skip the reciprocal step.

Return ans = 1024.0 ✅ matches 2^10 = 1024.

Why it only took 5 steps instead of 10 multiplications: every even step just squares x (doubling what one multiplication represents)
 without touching ans, and only the odd steps actually fold that squared value into ans. That's the log(n) speedup in action
  — notice x jumped from 2 → 4 → 16 → 256 by repeated squaring, 
so by step 5 a single ans *= x was worth "256", covering a huge chunk of the exponent in one multiplication.

*/