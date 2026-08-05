unordered_map<int,int> hashMap;
for(int i =  0;i< nums.size();i++){
    if(hashMap.find(target-num) != hashMap.end()){
        return ({hashMap[target-num],i})
    }
    else
    hashMpa[nums[i]]=i;
}



product of array excpet self 
// so here we tryu to maintain two array 
one is prefic one and other is suffix one 

vector<int> ans
int prefix   =1 ;
int suffox = 1 ;
for(int i = 0;i<n ;i++){
    ans[i] = prefix;
    prefix *= nums[i];
}

for(int i = n-1;i>=0;i++){
    asn[i] *= suffix;
    suffix *= nums[i];
}



maximum sum subarray question 
// basically teh kaden's algo

for(int i = 0;i<nums.size();i++){
    currentSum += nums[i];
    maxSum = max(maxSum, currentSum);
    if(currentSum<0) currentSum = 0;
}
return maxSum;


//merge intervals 
while(i<intervals.size()){
    if(large<intervals[i][0]){
        ans.push_back({small,large});
        large = intervals[i][0];
        large = intervals[i][1];
    }
    else{
        if(large<intervals[i][1])
        large = intrvals[i][1]

        else if(small>intervals[i][0])
        small = initervals[i][0];
    }
}
ans.push_back({small,large});
return ans;



//majjoruty elemenet 
int count = 0;
int candidate = 0;
for(auto num :nums){
    if(count ==0)
    candidate = num;

    if(num == candidate)
    count++;

    else
    count--;
}
return candidate;


//longest consecuotev sequebce 
int longest ;
unordered_set<int> st(nums.begin(),nums.end())
for(auto num : nums){
    if(st.find(num-1)==st.end()){
        count=0;
        length=0
        current = num;
        while(st.find(current+1)!=st.end())
        {
            current++;
            legth++;
        }
        maximum = max(ength,maximum);
    }
    return maximum;
}


//three sum 
sort(nums.bein(),nums.end())
for(int i =0;i<n-2;i++){
    if(i>0 && nums[i]==nums[i-1])
    i++;

    left = i+1;
    right = n-1;

    while(left<right){
        int sum = nums[i]+nums[left]+nums[right];
        if(sum>0)
        right++;
    else if(sum<0)
    left++;
        else
        ans.push_back({nums[i],nums[left],nums[right]});
    left++
    right--;

    while(left<=right && nums[left]== nums[left+1])
    left++;

    while(left<=right && nums[right]==nums[right-1])
    right--;
    }
    return ans;
}