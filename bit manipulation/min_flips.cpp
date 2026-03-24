/* problem link - https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/
*/


class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x=start^goal;
        int count =0;

        while(x){
            x = x&(x-1);
            count++;
        }
        return count;
    }
};

//so to get themin no of flips , by doing the xor , the 1's but in xor tells you that the bits are not same , so wht you do is
//do the xor and thencalculatr the number of 1's in that result....