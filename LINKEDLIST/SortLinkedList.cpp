/*
===============================================================================
SORT A LINKED LIST (MERGE SORT)
===============================================================================

1. DRY RUN
   Input: 4 -> 2 -> 1 -> 3
   - Find Mid point: slow/fast locates node 2. Split list into: L1 = 4->2, L2 = 1->3
   - Recursive dividing phase boils lists down to distinct atom units.
   - Merging phase:
     Merge(4, 2) -> 2->4
     Merge(1, 3) -> 1->3
     Merge(2->4, 1->3) -> 1->2->3->4.

2. VISUALIZATION
          [4 -> 2 -> 1 -> 3]
             /          \
        [4 -> 2]      [1 -> 3]  (Split)
          |              |
        [2 -> 4]      [1 -> 3]  (Sort & Merge back)

3. WHY IT WORKS
   Merge sort works incredibly well on linked lists because we can easily find 
   the middle element using the tortoise and hare approach, and merge the sorted 
   halves in-place by updating pointers without using any extra memory.

4. TIME & SPACE COMPLEXITY
   - Time Complexity: O(N log N) from the divide and conquer merge steps.
   - Space Complexity: O(log N) runtime stack frames footprint from recursion calls.

5. KEY PATTERN                                  
   Divide & Conquer / Two-Pointer Split
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Helper function to merge two sorted lists
ListNode* merge(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

ListNode* sortList(ListNode* head) {                                               
    if (!head || !head->next) return head;                                               
    ListNode *slow = head, *fast = head, *prev = nullptr;
                                                    
    while (fast && fast->next) {                                                    
        prev = slow; 
        slow = slow->next; 
        fast = fast->next->next;
    }                                               
    prev->next = nullptr; // Split list into two halves                                                
    ListNode* l1 = sortList(head);                                                    
    ListNode* l2 = sortList(slow);                                           
    return merge(l1, l2); // Uses same merge logic from Q3                                                
}
