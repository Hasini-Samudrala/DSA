/*problem link - https://leetcode.com/problems/count-good-numbers/*/

class Solution {
public:
    long long MOD = 1000000007;

     long long power(long long x, long long n) {
        long long ans = 1.0;
        long long nn = n;

        if(nn<0) nn= (-1) *nn;

        while(nn){
            if(nn%2==1){
                ans = (ans * x) % MOD;
                nn = nn-1;
            }
            else{
                x = (x * x) % MOD;
                nn = nn/2;
            }
        }
        // if(n<0) ans = (long long)1/ans;
        return ans;
    }

    int countGoodNumbers(long long n) {
        long long evenPositions = (n + 1) / 2;
        long long oddPositions = n / 2;

        long long evenWays = power(5, evenPositions);
        long long oddWays = power(4, oddPositions);

        return (evenWays * oddWays) % MOD;
    }
};

/*intution 

even indices - only even numbers - which means 0,2,4,6,8 
which is basically 5 choices 
whereas odd induces - only odd numbers - which means - 1,3,5,7 
which is basically 4 choices 
so accordingle we calculate 

*/