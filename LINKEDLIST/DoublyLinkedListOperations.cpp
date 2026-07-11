/*
===============================================================================
DOUBLY LINKED LIST OPERATIONS (INSERT & DELETE AT K-TH POSITION)
===============================================================================

1. DRY RUN
   List: 10 <=> 20 <=> 30, Delete k=2 (Node 20)
   - Traverse to index 2 (curr points to node 20).
   - Link isolation mapping adjustment:
     curr->prev->next (Node 10's next) = curr->next (Node 30)
     curr->next->prev (Node 30's prev) = curr->prev (Node 10)
   - Free memory block of node 20.

2. VISUALIZATION
   Before: [10] <===> [20] <===> [30]
   After:  [10] <======================> [30]  (Node 20 deleted)

3. WHY IT WORKS
   Having access to both `prev` and `next` pointers allows a node to be 
   excised or inserted at any position without maintaining a lagging 
   parent reference pointer during traversal.

4. TIME & SPACE COMPLEXITY
   - Time Complexity: O(K) where K represents index distance traversal limits.
   - Space Complexity: O(1) structural updates require no temporary copy allocations.

5. KEY PATTERN                              
   Bidirectional Pointer Stitching
*/

struct Node { 
    int data; 
    Node* next; 
    Node* prev; 
};                                           
Node* deleteNode(Node* head, int k) {                                               
    if (!head) return nullptr;                                                 
    Node* curr = head;                                               
    for (int i = 1; curr && i < k; i++) curr = curr->next;                                                 
    if (!curr) return head;                                                 
    if (curr == head) head = head->next;                                                 
    if (curr->next) curr->next->prev = curr->prev;                                                 
    if (curr->prev) curr->prev->next = curr->next;                                                   
    delete curr;                                                 
    return head;                                                
}
