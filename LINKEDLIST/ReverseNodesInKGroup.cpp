/*
===============================================================================
REVERSE NODES IN K-GROUP
===============================================================================

1. DRY RUN
   Input: 1 -> 2 -> 3 -> 4 -> 5, k = 2
   - First Group [1->2]: Counts 2 elements. Reverses them to [2->1].
   - Connection: previous group tail (or dummy) links to 2. Next group link attempts 3.
   - Second Group [3->4]: Counts 2 elements. Reverses them to [4->3].
   - Connection: Node 1 links to 4.
   - Remainder [5]: Only 1 element left (< k). Stays unchanged. 1->4->3->5.

2. VISUALIZATION
   Before:  [1 -> 2] -> [3 -> 4] -> [5]
   After:   [2 -> 1] -> [4 -> 3] -> [5]

3. WHY IT WORKS
   We verify if a full segment of size `k` exists before doing anything. 
   If it does, we pass it to a standard reversal routing mechanism, link its 
   subsequent connections iteratively, and jump ahead to evaluate upcoming cells.

4. TIME & SPACE COMPLEXITY
   - Time Complexity: O(N) since each node is processed at most twice.
   - Space Complexity: O(1) because pointers are adjusted iteratively without recursion stack frames.

5. KEY PATTERN                                 
   Chunked Boundary Tracking Loops
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {                                               
    if (!head || k == 1) return head;                                             
    ListNode dummy(0); 
    dummy.next = head;                                              
    ListNode *curr = &dummy, *nex = &dummy, *pre = &dummy;                                            
    int count = 0;                                               
    while (curr->next) { 
        curr = curr->next; 
        count++; 
    }                                               
    while (count >= k) {                                                   
        curr = pre->next; 
        nex = curr->next;                                                  
        for (int i = 1; i < k; i++) {                                                       
            curr->next = nex->next;                                                     
            nex->next = pre->next;                                                        
            pre->next = nex;                                                        
            nex = curr->next;                                                   
        }                                               
        pre = curr; 
        count -= k;                                              
    }                                               
    return dummy.next;                                            
}
