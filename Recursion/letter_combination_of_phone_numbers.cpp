/*problem link - https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/*/

class Solution {
public:
    vector<string>result;
    string current;
    unordered_map<char,string>mapping={
        {'2',"abc"},{'3',"def"} ,{'4',"ghi"},{'5',"jkl"},
        {'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}
    };

    void backtrack(string digits,int index){
        if(current.length() == digits.size()){
            result.push_back(current);
            return;
        }
        string lala = mapping[digits[index]];
        for(int i =0;i<lala.size();i++){
            current.push_back(lala[i]);
            backtrack(digits,index+1);
            current.pop_back();
        }
        return ;
    }
    vector<string> letterCombinations(string digits) {
        backtrack(digits,0);
        return result;
    }
};

/*intution
**Intuition:**

This is a slightly different backtracking flavor — instead of choosing *whether* to
 include elements from one shared pool, here each **position** in the output string has its own
  independent set of choices (the letters mapped to that digit). So you backtrack **index by index
   through the input `digits`**, not through a candidates array, and at each index you branch over all 
   letters mapped to that digit, moving to the next index each time — no reuse or duplicate-skip concerns
   exist here since each digit position is handled exactly once.


**Dry run for digits="23"** (expected: `["ad","ae","af","bd","be","bf","cd","ce","cf"]`):

```
backtrack(index=0), current=""
digits[0]='2' → letters="abc"
├─ pick 'a' → current="a", backtrack(index=1)
│  digits[1]='3' → letters="def"
│  ├─ pick 'd' → current="ad", backtrack(index=2) → index==len → ADD "ad" ✅
│  ├─ pick 'e' → current="ae", backtrack(index=2) → ADD "ae" ✅
│  └─ pick 'f' → current="af", backtrack(index=2) → ADD "af" ✅
│  → pop, current="a"→""
├─ pick 'b' → current="b", backtrack(index=1)
│  ├─ 'd' → ADD "bd" ✅
│  ├─ 'e' → ADD "be" ✅
│  └─ 'f' → ADD "bf" ✅
├─ pick 'c' → current="c", backtrack(index=1)
│  ├─ 'd' → ADD "cd" ✅
│  ├─ 'e' → ADD "ce" ✅
│  └─ 'f' → ADD "cf" ✅
```

Result: `["ad","ae","af","bd","be","bf","cd","ce","cf"]` ✅ matches exactly.

**Why this is a different pattern from the earlier problems:** all the previous problems (Combination Sum, Subsets) picked a 
**subset** from one shared pool with a `start` index to avoid reordering/duplicates. This one instead has a
 **fixed-length output** where each **position** is independently decided from its own local set of options —
  closer to a Cartesian product than a subset-selection problem. There's no "skip" or "start index" logic needed because
   you're not avoiding duplicate combinations — every position must be filled with something, in order.



**Edge case handled:** empty `digits` input returns an empty vector immediately (per problem convention), rather than `[""]`.*/