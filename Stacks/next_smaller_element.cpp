vector<int> nse;
stack<int>st;
int n = nums.size();

for(int i=0;i<n;i++){
    while(!st.empty() && st.top()>=arr[i])
    st.pop();

    nse[i]= st.empty()?(-1) : st.top();
    st.push(nums[i];)
}
return nse;

// this is the code for the nearest smaller element ( previous ) so yes opposite condition for next greater element thats all