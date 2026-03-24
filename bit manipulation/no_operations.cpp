//problem link - https://leetcode.com/problems/divide-two-integers/
// problem statemet in simple terms - divide two numbers without using multiplication , division and no mod 

class Solution {
public:
    int divide(int dividend, int divisor) {

        long long ans =0;
        long long divid = abs((long long) dividend);
        long long divis = abs((long long) divisor);
        while(divid>=divis){
            int i=0;
            while((divis<<(i+1)) < divid)
            {
                i++;
            }
            divid = divid-(divis<<i);
            ans += 1<<i;

            if ((dividend < 0) ^ (divisor < 0))
            ans = -ans;
        }
          return ans;
    }
};



// so here like im trynna subtract big chuncks instead of the dicisor itself at a single time
// like say there is 15 and i have 3 as divisor , which means im trynna subtract 3 from 15 , 5 times 
// instaead of subtracting 3 , 5 times indiviidually , i calculuate it to the powers of 2 ( bit shifting )
// so 15 - 3*2^2 + 3*2^0 ==> 2^2 + 2^0 is my solution - which is 5 
