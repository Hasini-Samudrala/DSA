/* [roblem link - https://leetcode.com/problems/first-bad-version/ ]*/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long int l=1;
        long long int r=n;
        long long int m,result=-1;
        while(l<=r)
        {
            m=(l+r)/2;
            if(isBadVersion(m))
            {
                result =m;
            r=m-1;
            }

            else
            l=m+1;
        }

        return result;
    }
};