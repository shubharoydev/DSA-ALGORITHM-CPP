/*
===============================================================================
DETECT & REMOVE CYCLE
===============================================================================

1. DRY RUN
   Input: 1 -> 2 -> 3 -> 4 -> 5 -> (loops back to 3)
   - Detection: 
     slow moves 1 step, fast moves 2 steps. They eventually meet at node 5.
   - Removal Point: 
     Reset slow to head (node 1). Keep fast at node 5.
     Move both 1 step at a time:
     Step 1: slow = 2, fast = 3
     Step 2: slow = 3, fast = 4
     Next steps match (slow->next is 3, fast->next is 3). Intersection discovered!
     Set fast->next = nullptr to break the loop.

2. VISUALIZATION
          [3] -> [4]
         ^         \
        /           v
   [1]->[2]        [5] -- (Loops back to 3) 
   After removal: [5]->nullptr

3. WHY IT WORKS
   Floyd's Cycle-Finding Algorithm dictates that the distance from the head 
   to the loop starting point is exactly equal to the distance from the 
   meeting point to the loop starting point (modulo loop length). 

4. TIME & SPACE COMPLEXITY
   - Time Complexity: O(N) as the traversal bounds are linear to the node count.
   - Space Complexity: O(1) because we rely exclusively on fast/slow pointer coordinates.

5. KEY PATTERN                                  
   Floyd's Tortoise and Hare (Two pointers traveling at 1x and 2x speeds)
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void removeCycle(ListNode* head) {
    ListNode *slow = head, *fast = head;
                                                
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
                                                    
        if (slow == fast) { // Cycle Detected
            slow = head;
                                                        
            if (slow == fast) { // Edge case: Loop at head
                while (fast->next != slow) fast = fast->next;
            } else {
                while (slow->next != fast->next) {
                    slow = slow->next;
                    fast = fast->next;
                }
            }
                                                        
            fast->next = nullptr; // Break loop
            return;
        }
    }
}
