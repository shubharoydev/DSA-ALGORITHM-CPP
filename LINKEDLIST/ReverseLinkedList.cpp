/*
===============================================================================
REVERSE A LINKED LIST
===============================================================================

1. DRY RUN
   Input: 1 -> 2 -> 3 -> NULL
   - Initial: curr = 1, prev = NULL, nextNode = NULL
   - Iteration 1 (curr = 1):
     nextNode = 2
     curr->next = NULL (1 -> NULL)
     prev = 1, curr = 2
   - Iteration 2 (curr = 2):
     nextNode = 3
     curr->next = 1 (2 -> 1 -> NULL)
     prev = 2, curr = 3
   - Iteration 3 (curr = 3):
     nextNode = NULL
     curr->next = 2 (3 -> 2 -> 1 -> NULL)
     prev = 3, curr = NULL
   Loop Ends. Return prev (Head is now 3).

2. VISUALIZATION
   Before:  [1] -> [2] -> [3] -> NULL
   After:   NULL <- [1] <- [2] <- [3]  (prev points to 3)

3. WHY IT WORKS
   By tracking the 'nextNode' before breaking the link, we can safely point 
   the current node's next pointer backward ('curr->next = prev') without 
   losing the rest of the list. Moving 'prev' and 'curr' one step forward 
   shifts the window sequentially.

4. TIME & SPACE COMPLEXITY
   - Time Complexity: O(N) because we traverse the list exactly once.
   - Space Complexity: O(1) as we modify pointers in-place using 3 variable trackers.

5. KEY PATTERN                                  
   Three-Pointer Sliding Window  
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {              
    ListNode *prev = nullptr, *curr = head, *nextNode = nullptr;                                             
    while (curr != nullptr) {                                                 
        nextNode = curr->next;                                                 
        curr->next = prev;                                                 
        prev = curr;                                                 
        curr = nextNode;                                             
    }                                              
    return prev;                                         
}
