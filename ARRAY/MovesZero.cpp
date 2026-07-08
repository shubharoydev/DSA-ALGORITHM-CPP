#include <vector>
#include <algorithm>
using namespace std;

/*
===============================================================================
MOVE ZEROS TO THE END
===============================================================================

1. DRY RUN (Most Important)
   Example: nums = [0, 1, 0, 3, 12]

   Initial: i = 0
   - j=0: nums[0]=0, skip
   - j=1: nums[1]=1 != 0, swap(nums[0], nums[1]) → [1, 0, 0, 3, 12], i++ → i=1
   - j=2: nums[2]=0, skip
   - j=3: nums[3]=3 != 0, swap(nums[1], nums[3]) → [1, 3, 0, 0, 12], i++ → i=2
   - j=4: nums[4]=12 != 0, swap(nums[2], nums[4]) → [1, 3, 12, 0, 0], i++ → i=3
   - Result: [1, 3, 12, 0, 0]

2. VISUALIZATION

   Array: [0] [1] [0] [3] [12]
            i   j
            ↓   ↓
   Start:  i=0, j=0
            ↓
   j=1:    1 != 0, swap with i=0
            [1] [0] [0] [3] [12]
                i   j
            ↓
   j=3:    3 != 0, swap with i=1
            [1] [3] [0] [0] [12]
                    i   j
            ↓
   j=4:    12 != 0, swap with i=2
            [1] [3] [12] [0] [0]
                        i   j
            ↓
   Result:  Zeros moved to end

3. WHY IT WORKS
   - i points to position where next non-zero should go
   - j scans through array
   - When nums[j] is non-zero, swap it to position i
   - This pushes all non-zeros to front in their original order
   - Zeros naturally end up at the end

4. TIME & SPACE COMPLEXITY
   - Time: O(n) - Single pass through array
   - Space: O(1) - Only uses i and j

5. KEY PATTERN
   Two pointers: i tracks non-zero position, j scans for non-zeros to swap.
*/
void moveZeroes(vector<int>& nums) {
    int i = 0; 
    for (int j = 0; j < nums.size(); j++) {
        if (nums[j] != 0) {
            swap(nums[i], nums[j]);
            i++;
        }
    }
}
