#include <vector>
#include <algorithm>
using namespace std;
/*
===============================================================================
DUTCH NATIONAL FLAG ALGORITHM (0's, 1's, 2's)
===============================================================================

1. DRY RUN (Most Important)
   Example: nums = [0, 2, 1, 2, 0, 1, 1]

   Initial: low=0, mid=0, high=6
   - mid=0: nums[0]=0, swap(nums[0], nums[0]), low++ → low=1, mid++ → mid=1
     Array: [0, 2, 1, 2, 0, 1, 1]
   - mid=1: nums[1]=2, swap(nums[1], nums[6]), high-- → high=5
     Array: [0, 1, 1, 2, 0, 1, 2]
   - mid=1: nums[1]=1, mid++ → mid=2
     Array: [0, 1, 1, 2, 0, 1, 2]
   - mid=2: nums[2]=1, mid++ → mid=3
     Array: [0, 1, 1, 2, 0, 1, 2]
   - mid=3: nums[3]=2, swap(nums[3], nums[5]), high-- → high=4
     Array: [0, 1, 1, 1, 0, 2, 2]
   - mid=3: nums[3]=1, mid++ → mid=4
     Array: [0, 1, 1, 1, 0, 2, 2]
   - mid=4: nums[4]=0, swap(nums[4], nums[0]), low++ → low=1, mid++ → mid=5
     Array: [0, 1, 1, 1, 0, 2, 2] (no change, 0 at low=0)
     Actually: swap with nums[low=0] which is 0, so no real change
     Array: [0, 1, 1, 1, 0, 2, 2]
   - mid=5: nums[5]=2, swap(nums[5], nums[4]), high-- → high=3
     Array: [0, 1, 1, 1, 2, 0, 2]
   - mid=5 > high=3, stop
   - Result: [0, 1, 1, 1, 2, 0, 2] (not fully sorted, let me redo)

   Correct trace:
   Initial: [0, 2, 1, 2, 0, 1, 1], low=0, mid=0, high=6
   - mid=0: nums[0]=0, swap(0,0), low=1, mid=1 → [0, 2, 1, 2, 0, 1, 1]
   - mid=1: nums[1]=2, swap(1,6), high=5 → [0, 1, 1, 2, 0, 1, 2]
   - mid=1: nums[1]=1, mid=2 → [0, 1, 1, 2, 0, 1, 2]
   - mid=2: nums[2]=1, mid=3 → [0, 1, 1, 2, 0, 1, 2]
   - mid=3: nums[3]=2, swap(3,5), high=4 → [0, 1, 1, 1, 0, 2, 2]
   - mid=3: nums[3]=1, mid=4 → [0, 1, 1, 1, 0, 2, 2]
   - mid=4: nums[4]=0, swap(4,1), low=2, mid=5 → [0, 0, 1, 1, 1, 2, 2]
   - mid=5 > high=4, stop
   - Result: [0, 0, 1, 1, 1, 2, 2]

2. VISUALIZATION

   Array: [0] [2] [1] [2] [0] [1] [1]
           L   M               H
           ↓   ↓               ↓
   Start:  low=0, mid=0, high=6
           ↓
   Step 1:  nums[mid]=0, swap with low
           [0] [2] [1] [2] [0] [1] [1]
               L   M               H
           ↓
   Step 2:  nums[mid]=2, swap with high
           [0] [1] [1] [2] [0] [1] [2]
               L   M           H
           ↓
   Step 3:  nums[mid]=1, mid++
           [0] [1] [1] [2] [0] [1] [2]
               L       M       H
           ↓
   Step 4:  nums[mid]=1, mid++
           [0] [1] [1] [2] [0] [1] [2]
               L           M   H
           ↓
   Step 5:  nums[mid]=2, swap with high
           [0] [1] [1] [1] [0] [2] [2]
               L           M   H
           ↓
   Step 6:  nums[mid]=1, mid++
           [0] [1] [1] [1] [0] [2] [2]
               L               M H
           ↓
   Step 7:  nums[mid]=0, swap with low
           [0] [0] [1] [1] [1] [2] [2]
                   L               M H
           ↓
   mid > high, stop. Sorted!

3. WHY IT WORKS
   - low: boundary for 0s (everything before low is 0)
   - mid: current element being processed
   - high: boundary for 2s (everything after high is 2)
   - If nums[mid]=0: swap with low, both move right (0 placed correctly)
   - If nums[mid]=1: mid moves right (1 already in middle)
   - If nums[mid]=2: swap with high, high moves left (2 placed correctly)
   - When mid > high, all elements are partitioned

4. TIME & SPACE COMPLEXITY
   - Time: O(n) - Single pass through array
   - Space: O(1) - In-place sorting

5. KEY PATTERN
   Three-way partition: 0s to left, 1s in middle, 2s to right using three pointers.
*/
void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++; mid++;
        } else if (nums[mid] == 1) {
            mid++;
        } else { // nums[mid] == 2
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}