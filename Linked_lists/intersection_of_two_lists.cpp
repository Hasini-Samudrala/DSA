/*problem link - https://leetcode.com/problems/intersection-of-two-linked-lists/*/

class Solution{
    public:
    ListNode* getIntersectionNode(ListNode* headA , ListNode* headB){
        ListNode* a = headA;
        ListNode* b = headB;

        while(a!=b){
            a= (a==nullptr)?headB:a->next;
            b=(b==nullptr)?headA:b->next;
        }
        return a;
    }
};

/*intuution 
**Intuition — Intersection of Two Linked Lists (LeetCode 160)**

The core problem: two lists might have different lengths *before* they merge, so a plain two-pointer walk won't line up the 
intersection point — the longer list's pointer would reach the merge point "too late" or overshoot compared to the shorter one.

**The fix — equalize total distance by swapping tracks:**
Walk `a` down `listA` and `b` down `listB` simultaneously, one step each. When a pointer falls off the end of its own list (hits `null`),
 redirect it to the **head of the other list** and keep walking. By the time each pointer has walked through *both* lists once, it has covered
  exactly `lenA + lenB` steps — same total distance for both pointers, regardless of which list is longer. This automatically cancels out the length difference,
   since any "extra" length one list had gets absorbed into the total once both pointers have traversed both lists.

**Why they meet exactly at the intersection:**
Once both pointers have covered the same total distance, they're now "synced up" — from the intersection point onward, both lists share the exact same nodes, 
so the pointers land on the same node at the same step and the loop stops (`a != b` becomes false).

**Why it correctly returns `null` when there's no intersection:**
If the lists never actually share a node, both pointers still travel the same total distance (`lenA + lenB`), and both run out of nodes at the exact same
 step — landing on `null` simultaneously. Since `null == null`, the loop condition `a != b` still becomes false, and `return a` returns `nullptr` — no separate
  "no intersection" case needs to be coded, the same logic naturally handles it.

**One-line summary:** by making both pointers travel the combined length of both lists (via the head-swap trick), you force them to either meet exactly at the real 
intersection node, or hit `null` together if none exists — same code path handles both outcomes.*/