/*problem link - https://leetcode.com/problems/container-with-most-water/ */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0 ;
        int right = height.size()-1;
        int ans = 0;

        while(left<right){
            int area = min(height[left],height[right])*(right-left);
            ans = max(ans,area);

            if(height[left]<height[right])
            left++;

            else
            right--;
        }
        return ans;
    }
};

/*The area is determined by the smaller of the two heights and the distance between them. 
Since moving either pointer decreases the width, the only chance to increase the area is by 
finding a taller minimum height. Moving the taller line cannot increase the minimum height, 
so we always move the pointer with the smaller height.This guarantees that we explore all promising candidates in linear time.
*/