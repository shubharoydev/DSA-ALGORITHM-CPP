#include <vector>
#include <algorithm>
using namespace std;

/*
===============================================================================
 REMOVE DUPLICATES IN SORTED ARRAY
===============================================================================

1. DRY RUN (Most Important)
   Example: nums = [1, 1, 2, 2, 2, 3, 4, 4]

   Initial: i = 0
   - j=1: nums[1]=1 == nums[0]=1, skip
   - j=2: nums[2]=2 != nums[0]=1, i++ → i=1, nums[1]=2 → [1, 2, 2, 2, 2, 3, 4, 4]
   - j=3: nums[3]=2 == nums[1]=2, skip
   - j=4: nums[4]=2 == nums[1]=2, skip
   - j=5: nums[5]=3 != nums[1]=2, i++ → i=2, nums[2]=3 → [1, 2, 3, 2, 2, 3, 4, 4]
   - j=6: nums[6]=4 != nums[2]=3, i++ → i=3, nums[3]=4 → [1, 2, 3, 4, 2, 3, 4, 4]
   - j=7: nums[7]=4 == nums[3]=4, skip
   - Result: return i+1 = 4, array = [1, 2, 3, 4, ...]

2. VISUALIZATION

   Array: [1] [1] [2] [2] [2] [3] [4] [4]
            i   j
            ↓   ↓
   Start:  i=0, j=1
            ↓
   j=2:    2 != 1, i=1, place 2
            [1] [2] [2] [2] [2] [3] [4] [4]
                 i       j
            ↓
   j=5:    3 != 2, i=2, place 3
            [1] [2] [3] [2] [2] [3] [4] [4]
                     i           j
            ↓
   j=6:    4 != 3, i=3, place 4
            [1] [2] [3] [4] [2] [3] [4] [4]
                         i           j
            ↓
   Result:  First 4 elements are unique

3. WHY IT WORKS
   - i points to last unique element position
   - j scans ahead to find next unique element
   - When nums[j] != nums[i], we found a new unique element
   - Place it at i+1 and increment i
   - After scan, first i+1 elements are unique

4. TIME & SPACE COMPLEXITY
   - Time: O(n) - Single pass through array
   - Space: O(1) - Only uses i and j

5. KEY PATTERN
   Two pointers: i tracks unique position, j scans for next unique.
*/
int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    int i = 0;
    for (int j = 1; j < nums.size(); j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}