/*
Problem link - https://leetcode.com/problems/sort-characters-by-frequency/description/
*/

//approach -1
//brute force 
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        for(int i =0;i<s.length();i++){
            freq[s[i]] ++;
        }

        priority_queue<pair<int, char>>pq; // this is imp here declaring the pair wise queues 
        for(int i=0;i<s.length();i++){
            pq.push({freq[s[i]],s[i]});
        }

        string result = "";
        int n = pq.size();
        while(n>0){
            result += pq.top().second; // this is imp here , liek accessing the elements when the queue is declared pair wise
            pq.pop();
            n--;
        }
        return result;
    }
};

//intution 
/*
it is just like we caluclted teh frequency of all tteh characters and used a priority queue to keep them in order andthen 
used quue function sto comclude to teh answer */

//optimised approach 

//CHECK THE OPTIMISED APPROACH LATER 