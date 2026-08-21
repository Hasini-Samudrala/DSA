//first appraoch
int f(int n, vector<int<&dp){
    if(n<=1) return n;
    if(dp[n]!=-1) return dp[n];

    return dp[n] = f(n-1,dp)+f(n-2,dp);
}

main(){
    int n;
    cin>>n;
    vector<int>dp(n,-1);
    cout<<f(n,dp);
    return;
}


//second approach
dp[0]=0;
dp[1]=1;
for(int i =2;i<=n;i++){
    dp[i]=dp[i-1]+dp[i-2];
}

//here the time complexity is O(N) and space complexity is also O(N) .. there is no recursion stack space unlike the first one 

//third approach 
//here we try not to use the dp array also 
int prev2=0;
int prev1=1;
for(int i=2;i<=n;i++){
    curi = prev2+prev1;
    prev2 = prev1;
    prev1 = curi;   
}
cout<<prev;