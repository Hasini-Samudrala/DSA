/*problem link - https://leetcode.com/problems/hand-of-straights/*/

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize!=0)
        return false;

        map<int,int>freq;
        for(auto card:hand){
            freq[card]++;
        }

        auto it = freq.begin();

        while(it != freq.end()){
            if(it->second==0)
            {
                ++it;
                continue;
            }
            int start = it->first;
            int count = it->second;
            for(int i= 0;i<groupSize;i++){
                if(freq[start+i]<count) return false;
                freq[start+i] -= count;
            }
            ++it;
        }
        return true;
    }
};

/*
Check if total number of cards is divisible by groupSize; if not, return false.
Store the frequency of each card in a sorted data structure.
Iterate over the sorted keys (card values) from smallest to largest.
For each key, try to form a group of groupSize starting from that key.
If there are not enough cards to build a group, return false.
Decrement the counts for each card used in the group.
If all groups are successfully formed, return true.
*/