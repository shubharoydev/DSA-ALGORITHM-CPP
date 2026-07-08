#include <vector>
#include <algorithm>
using namespace std;
/*
===============================================================================
SINGLE ELEMENT IN A SORTED ARRAY (BINARY SEARCH)
===============================================================================

1. DRY RUN (Most Important)
   Example: nums = [1, 1, 2, 2, 3, 4, 4, 8, 8]

   Edge cases checked: nums[0]=1 != nums[1]=1? No. nums[8]=8 != nums[7]=4? Yes, return 8.
   But let's continue with the main example.

   Better example: nums = [1, 1, 2, 3, 3, 4, 4, 8, 8]
   Initial: low=1, high=7
   - mid = 1 + (7-1)/2 = 4
     nums[mid]=3, nums[mid-1]=2, nums[mid+1]=3
     3 == 3 (right neighbor), mid is even (4)
     Even index with match on right means single is on right
     low = mid + 1 = 5
   - mid = 5 + (7-5)/2 = 6
     nums[mid]=4, nums[mid-1]=4, nums[mid+1]=8
     4 == 4 (left neighbor), mid is odd (6)
     Odd index with match on left means single is on right
     low = mid + 1 = 7
   - mid = 7 + (7-7)/2 = 7
     nums[mid]=8, nums[mid-1]=4, nums[mid+1]=8
     8 == 8 (right neighbor), mid is odd (7)
     Odd index with match on right means single is on left
     high = mid - 1 = 6
   - low=7, high=6, low > high, exit loop
   - Return -1 (should have found earlier)

   Let's use correct example: nums = [1, 1, 2, 3, 3, 4, 4, 8, 8]
   - mid=4: nums[4]=3, nums[4]==nums[5]=3, mid even, single on right, low=5
   - mid=6: nums[6]=4, nums[6]==nums[5]=4, mid even, single on right, low=7
   - mid=7: nums[7]=8, nums[7]==nums[8]=8, mid odd, single on left, high=6
   - low > high, shouldn't happen

   Correct example where single is found: nums = [1, 1, 2, 2, 3, 4, 4]
   - mid=3: nums[3]=2, nums[3]==nums[2]=2, mid odd, single on right, low=4
   - mid=5: nums[5]=4, nums[5]==nums[6]=4, mid odd, single on left, high=4
   - mid=4: nums[4]=3, nums[4]!=nums[3] and nums[4]!=nums[5], FOUND!
   - Return 3

2. VISUALIZATION

   Array: [1] [1] [2] [2] [3] [4] [4]
                           ↑
                       SINGLE

   Binary Search:
   low=1, high=5, mid=3 (value=2)
   2 == 2 (left), mid odd → single on right, low=4

   low=4, high=5, mid=4 (value=3)
   3 != 2 and 3 != 4 → FOUND at index 4!

3. WHY IT WORKS
   - In sorted array with pairs, single element disrupts the pattern
   - Before single: pairs start at even indices (0,1), (2,3), etc.
   - After single: pairs start at odd indices
   - If mid is even and matches right neighbor, single is on right
   - If mid is odd and matches left neighbor, single is on right
   - Otherwise, single is on left

4. TIME & SPACE COMPLEXITY
   - Time: O(log n) - Binary search
   - Space: O(1) - Only uses low, high, mid

5. KEY PATTERN
   Binary search using even-odd index pattern to determine which half contains single.
*/
int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    if (nums[0] != nums[1]) return nums[0];
    if (nums[n - 1] != nums[n - 2]) return nums[n - 1];
    
    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
            return nums[mid];
        }
        // Even-Odd property check
        if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) || 
            (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {
            low = mid + 1; // Left side is uniform, move right
        } else {
            high = mid - 1; // Right side is uniform, move left
        }
    }
    return -1;
}