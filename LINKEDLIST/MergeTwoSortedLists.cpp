/*
===============================================================================
MERGE TWO SORTED LINKED LISTS
===============================================================================

1. DRY RUN
   Input: L1 = 1->3, L2 = 2->4
   - Create dummy node. tail = dummy.
   - Compiling comparison loop:
     1 < 2 -> tail->next = L1 (1). L1 moves to 3. tail moves to 1.
     3 > 2 -> tail->next = L2 (2). L2 moves to 4. tail moves to 2.
     3 < 4 -> tail->next = L1 (3). L1 becomes null. tail moves to 3.
   - Append remnant: L1 is exhausted, connect tail->next = L2 (4).
   - Return dummy->next.

2. VISUALIZATION
   L1: [1] -> [3]
   L2: [2] -> [4]
   Merged via Dummy: [Dummy] -> [1] -> [2] -> [3] -> [4]

3. WHY IT WORKS
   By evaluating the front-most elements of both lists, we dynamically 
   stitch together the smaller element. A dummy tracking node eliminates 
   messy initialization conditionals for the new head pointer.

4. TIME & SPACE COMPLEXITY
   - Time Complexity: O(N + M) where N and M are lengths of the respective lists.
   - Space Complexity: O(1) because we rearrange existing node links without cloning.

5. KEY PATTERN                                  
   Dummy Node + Two-Pointer Merge
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {                                             
    ListNode dummy(0);                                             
    ListNode* tail = &dummy;                                             
    while (l1 && l2) {                                                
        if (l1->val <= l2->val) {                                                     
            tail->next = l1; l1 = l1->next;                                                
        } else {                                                     
            tail->next = l2; l2 = l2->next;                                                 
        }                                                 
        tail = tail->next;                                              
    }                                              
    tail->next = l1 ? l1 : l2;                                              
    return dummy.next;                                           
}
