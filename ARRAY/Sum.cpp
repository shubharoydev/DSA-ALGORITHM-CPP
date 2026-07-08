#include <vector>
#include <algorithm>
using namespace std;
/*
===============================================================================
TWO SUM (TWO POINTER)
===============================================================================

1. DRY RUN (Most Important)
   Example: nums = [2, 7, 11, 15], target = 9

   Initial: left=0, right=3
   - left=0, right=3: sum = 2 + 15 = 17 > 9, right-- → right=2
   - left=0, right=2: sum = 2 + 11 = 13 > 9, right-- → right=1
   - left=0, right=1: sum = 2 + 7 = 9 == target, FOUND!
   - Return {0, 1}

2. VISUALIZATION

   Array: [2] [7] [11] [15]
            L               R
            ↓               ↓
   Step 1:  2 + 15 = 17 > 9, move R left

            L           R
            ↓           ↓
   Step 2:  2 + 11 = 13 > 9, move R left

            L   R
            ↓   ↓
   Step 3:  2 + 7 = 9 == target, FOUND!

3. WHY IT WORKS
   - Array is sorted, so moving left increases sum, moving right decreases sum
   - If sum < target: need larger sum, move left pointer right
   - If sum > target: need smaller sum, move right pointer left
   - If sum == target: found the pair
   - Guaranteed to find solution if it exists

4. TIME & SPACE COMPLEXITY
   - Time: O(n) - Each pointer moves at most n times
   - Space: O(1) - Only uses left, right

5. KEY PATTERN
   Two pointers from ends: if sum too small, move left; if sum too large, move right.
*/
vector<int> twoSum(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) return {left, right};
        else if (sum < target) left++;
        else right--;
    }
    return {};
}

/*
===============================================================================
THREE SUM
===============================================================================

1. DRY RUN (Most Important)
   Example: nums = [-1, 0, 1, 2, -1, -4]
   After sorting: nums = [-4, -1, -1, 0, 1, 2]

   i=0 (value=-4):
   - j=1, k=5: sum = -4 + (-1) + 2 = -3 < 0, j++ → j=2
   - j=2, k=5: sum = -4 + (-1) + 2 = -3 < 0, j++ → j=3
   - j=3, k=5: sum = -4 + 0 + 2 = -2 < 0, j++ → j=4
   - j=4, k=5: sum = -4 + 1 + 2 = -1 < 0, j++ → j=5
   - j=5, k=5: j >= k, stop

   i=1 (value=-1):
   - j=2, k=5: sum = -1 + (-1) + 2 = 0 == target, FOUND!
     Add [-1, -1, 2], j++ → j=3, k-- → k=4
   - j=3, k=4: sum = -1 + 0 + 1 = 0 == target, FOUND!
     Add [-1, 0, 1], j++ → j=4, k-- → k=3
   - j=4, k=3: j >= k, stop

   i=2 (value=-1):
   - nums[2] == nums[1], skip to avoid duplicates

   i=3 (value=0):
   - j=4, k=5: sum = 0 + 1 + 2 = 3 > 0, k-- → k=4
   - j=4, k=4: j >= k, stop

   Result: [[-1, -1, 2], [-1, 0, 1]]

2. VISUALIZATION

   Sorted: [-4] [-1] [-1] [0] [1] [2]
            i    j           k

   i=0:    Try all pairs, no match

   i=1:    [-4] [-1] [-1] [0] [1] [2]
                i    j        k
           -1 + -1 + 2 = 0 ✓ Add [-1,-1,2]

                i        j    k
           -1 + 0 + 1 = 0 ✓ Add [-1,0,1]

3. WHY IT WORKS
   - Sort array to enable two-pointer technique
   - Fix first element, use two pointers for remaining two
   - Skip duplicates to avoid duplicate triplets
   - If sum < 0: need larger sum, move j right
   - If sum > 0: need smaller sum, move k left

4. TIME & SPACE COMPLEXITY
   - Time: O(n²) - Outer loop O(n), inner two-pointer O(n)
   - Space: O(1) excluding output (or O(log n) for sorting)

5. KEY PATTERN
   Sort + fix first element + two pointers for remaining, skip duplicates.
*/
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int j = i + 1, k = n - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum < 0) j++;
            else if (sum > 0) k--;
            else {
                res.push_back({nums[i], nums[j], nums[k]});
                j++; k--;
                while (j < k && nums[j] == nums[j - 1]) j++;
                while (j < k && nums[k] == nums[k + 1]) k--;
            }
        }
    }
    return res;
}

/*
===============================================================================
 FOUR SUM
===============================================================================

1. DRY RUN (Most Important)
   Example: nums = [1, 0, -1, 0, -2, 2], target = 0
   After sorting: nums = [-2, -1, 0, 0, 1, 2]

   i=0 (value=-2):
   j=1 (value=-1):
   - k=2, l=5: sum = -2 + (-1) + 0 + 2 = -1 < 0, k++ → k=3
   - k=3, l=5: sum = -2 + (-1) + 0 + 2 = -1 < 0, k++ → k=4
   - k=4, l=5: sum = -2 + (-1) + 1 + 2 = 0 == target, FOUND!
     Add [-2, -1, 1, 2], k++ → k=5, l-- → l=4
   - k=5, l=4: k >= l, stop
   j=2 (value=0):
   - k=3, l=5: sum = -2 + 0 + 0 + 2 = 0 == target, FOUND!
     Add [-2, 0, 0, 2], k++ → k=4, l-- → l=4
   - k=4, l=4: k >= l, stop
   j=3 (value=0):
   - nums[3] == nums[2], skip to avoid duplicates

   i=1 (value=-1):
   j=2 (value=0):
   - k=3, l=5: sum = -1 + 0 + 0 + 2 = 1 > 0, l-- → l=4
   - k=3, l=4: sum = -1 + 0 + 0 + 1 = 0 == target, FOUND!
     Add [-1, 0, 0, 1], k++ → k=4, l-- → l=3
   - k=4, l=3: k >= l, stop
   j=3 (value=0):
   - nums[3] == nums[2], skip

   i=2 (value=0):
   - nums[2] == nums[1], skip

   Result: [[-2, -1, 1, 2], [-2, 0, 0, 2], [-1, 0, 0, 1]]

2. VISUALIZATION

   Sorted: [-2] [-1] [0] [0] [1] [2]
            i    j    k        l

   i=0,j=1: -2 + -1 + 0 + 2 = -1 < 0, move k right

            i    j        k    l
           -2 + -1 + 1 + 2 = 0 ✓ Add [-2,-1,1,2]

            i    j    k    l
           -2 + 0 + 0 + 2 = 0 ✓ Add [-2,0,0,2]

3. WHY IT WORKS
   - Sort array to enable two-pointer technique
   - Fix first two elements, use two pointers for remaining two
   - Skip duplicates to avoid duplicate quadruplets
   - If sum < target: need larger sum, move k right
   - If sum > target: need smaller sum, move l left

4. TIME & SPACE COMPLEXITY
   - Time: O(n³) - Two outer loops O(n²), inner two-pointer O(n)
   - Space: O(1) excluding output (or O(log n) for sorting)

5. KEY PATTERN
   Sort + fix two elements + two pointers for remaining, skip duplicates.
*/
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < n; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            int k = j + 1, l = n - 1;
            while (k < l) {
                long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                if (sum < target) k++;
                else if (sum > target) l--;
                else {
                    res.push_back({nums[i], nums[j], nums[k], nums[l]});
                    k++; l--;
                    while (k < l && nums[k] == nums[k - 1]) k++;
                    while (k < l && nums[l] == nums[l + 1]) l--;
                }
            }
        }
    }
    return res;
}