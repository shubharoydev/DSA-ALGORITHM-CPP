#include <vector>
#include <algorithm>
using namespace std;
/*
===============================================================================
 SECOND LARGEST ELEMENT
===============================================================================

1. DRY RUN (Most Important)
   Example: arr = [3, 7, 2, 9, 1]

   Initial: largest = 3, slargest = -1
   - i=1: arr[1]=7 > 3, slargest = 3, largest = 7
   - i=2: arr[2]=2 < 7 and 2 > -1, slargest = 2
   - i=3: arr[3]=9 > 7, slargest = 7, largest = 9
   - i=4: arr[4]=1 < 9 and 1 > -1, but 1 < 7, slargest stays 7
   - Result: 7

2. VISUALIZATION

   Array: [3] [7] [2] [9] [1]
            ↓
   Start:  largest=3, slargest=-1
            ↓
   i=1:    7 > 3, slargest=3, largest=7
            ↓
   i=2:    2 < 7, 2 > -1, slargest=2
            ↓
   i=3:    9 > 7, slargest=7, largest=9
            ↓
   i=4:    1 < 9, 1 < 7, slargest=7
            ↓
   Result: slargest=7

3. WHY IT WORKS
   - Track both largest and second largest
   - When finding new largest, old largest becomes second largest
   - When element is between largest and slargest, update slargest
   - Element must be less than largest to be considered for slargest

4. TIME & SPACE COMPLEXITY
   - Time: O(n) - Single pass through array
   - Space: O(1) - Only uses largest and slargest

5. KEY PATTERN
   Track two variables: when finding new max, old max becomes second max.
*/
int findSecondLargest(vector<int>& arr) {
    int largest = arr[0];
    int slargest = -1; // Assuming array contains positive numbers, otherwise use INT_MIN
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > largest) {
            slargest = largest;
            largest = arr[i];
        } else if (arr[i] < largest && arr[i] > slargest) {
            slargest = arr[i];
        }
    }
    return slargest;
}