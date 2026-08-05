/* problem link - https://leetcode.com/problems/task-scheduler/description/*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>freq;
        for(auto ch : tasks){
            freq[ch]++;
        }
        priority_queue<int>pq;
        for(auto it:freq){
            pq.push(it.second);
        }
        int time =0;
        while(!pq.empty()){
            int cycle = n+1;
            vector<int> temp;
            while(cycle>0 && !pq.empty()){
                int cnt = pq.top();
                pq.pop();

                cnt--;

                if(cnt>0)
                temp.push_back(cnt);

                time++;
                cycle--;
            }
            for(auto x:temp){
                pq.push(x);
            }

            if(pq.empty())
            break;

            time+=cycle;
            
        }
        return time;
    }
};

/*Since a task cannot be executed again for the next n intervals, we schedule tasks in cycles of length n + 1.
In each cycle, we always execute the most frequent remaining tasks first, using a max heap, because they are the hardest to place later.
After executing a task, we temporarily keep its updated frequency aside (temp) so it cannot be chosen again in the same cycle.
Once the cycle ends, unfinished tasks are pushed back into the heap, and any unused slots in the cycle become idle if tasks are still remaining.
*/

/*Count the frequency of each task and store them in a max heap.
Execute tasks in cycles of n + 1, since the same task can only repeat after n intervals.
In each cycle, always pick the tasks with the highest remaining frequency, decrease their count, and temporarily store unfinished tasks.
After the cycle ends, push unfinished tasks back into the heap. If tasks are still left but the cycle isn't full, the remaining slots are counted as idle.
*/