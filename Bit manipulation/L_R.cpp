/*
problem link - https://takeuforward.org/data-structure/find-xor-of-numbers-from-l-to-r
*/

class Solution{
    public:

    int XORUpto(int n){
        if(n%4==0) return n;
        if(n%4==1) return 1;
        if(n%4==2) return n+1;
        return 0;
    }

    int commputeXORFromLtoR(int L,int R){
        return XORUpto(R) ^ XORUpto(L-1);
    }
};

/*
Instead of doing range directly, we use:

XOR(L → R) = XOR(0 → R) ^ XOR(0 → L-1)

🔹 Why this works?

Because XOR cancels:

(0 ^ 1 ^ 2 ^ ... ^ L-1 ^ L ^ ... ^ R)
^
(0 ^ 1 ^ 2 ^ ... ^ L-1)
-----------------------------------
= L ^ (L+1) ^ ... ^ R

👉 Everything before L cancels out

🔥 Now main problem becomes:

Find XOR from 0 → n

🔹 Pattern of XOR(0 → n)
    n % 4	Result
    0	n
    1	1
    2	n + 1
    3	0     */