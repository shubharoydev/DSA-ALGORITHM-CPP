#include <vector>
#include <algorithm>
using namespace std;
/*
===============================================================================
PEAK INDEX IN MOUNTAIN ARRAY (BINARY SEARCH)
===============================================================================

1. DRY RUN (Most Important)
   Example: arr = [1, 3, 5, 7, 9, 8, 6, 4, 2]

   Initial: low=1, high=7
   - mid = 1 + (7-1)/2 = 4
     arr[mid]=7, arr[mid-1]=5, arr[mid+1]=9
     7 > 5 but 7 < 9, so climbing up, low = mid + 1 = 5
   - mid = 5 + (7-5)/2 = 6
     arr[mid]=6, arr[mid-1]=8, arr[mid+1]=4
     6 < 8, so climbing down, high = mid - 1 = 5
   - mid = 5 + (5-5)/2 = 5
     arr[mid]=8, arr[mid-1]=9, arr[mid+1]=6
     8 < 9, so climbing down, high = mid - 1 = 4
   - low=4, high=4, low <= high is true
   - mid = 4 + (4-4)/2 = 4
     arr[mid]=9, arr[mid-1]=7, arr[mid+1]=8
     9 > 7 and 9 > 8, PEAK FOUND!
   - Return 4

2. VISUALIZATION

   Array: [1] [3] [5] [7] [9] [8] [6] [4] [2]
                      ↑
                    PEAK

   Binary Search:
   low=1, high=7, mid=4 (value=7)
   7 < 9, climbing up → move low to 5

   low=5, high=7, mid=6 (value=6)
   6 < 8, climbing down → move high to 5

   low=5, high=5, mid=5 (value=8)
   8 < 9, climbing down → move high to 4

   low=4, high=4, mid=4 (value=9)
   9 > 7 and 9 > 8 → PEAK at index 4!

3. WHY IT WORKS
   - Mountain array: strictly increases then strictly decreases
   - If arr[mid] < arr[mid+1]: we're on the left slope, peak is to the right
   - If arr[mid] > arr[mid+1]: we're on the right slope, peak is to the left
   - Binary search narrows down to the peak in O(log n)

4. TIME & SPACE COMPLEXITY
   - Time: O(log n) - Binary search halves search space each iteration
   - Space: O(1) - Only uses low, high, mid

5. KEY PATTERN
   Binary search: if climbing up, go right; if climbing down, go left.
*/
int peakIndexInMountainArray(vector<int>& arr) {
    int low = 1, high = arr.size() - 2;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
            return mid;
        }
        if (arr[mid] > arr[mid - 1]) low = mid + 1; // Climbing up
        else high = mid - 1; // Climbing down
    }
    return -1;
}
