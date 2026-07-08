#include <vector>
#include <algorithm>
using namespace std;

/*
===============================================================================
LARGEST ELEMENT
===============================================================================

1. DRY RUN (Most Important)
   Example: arr = [3, 7, 2, 9, 1]

   Initial: largest = 3
   - i=1: arr[1]=7 > 3, largest = 7
   - i=2: arr[2]=2 < 7, largest stays 7
   - i=3: arr[3]=9 > 7, largest = 9
   - i=4: arr[4]=1 < 9, largest stays 9
   - Result: 9

2. VISUALIZATION

   Array: [3] [7] [2] [9] [1]
            ↓
   Start:  largest = 3
            ↓
   i=1:    7 > 3, largest = 7
            ↓
   i=2:    2 < 7, largest = 7
            ↓
   i=3:    9 > 7, largest = 9
            ↓
   i=4:    1 < 9, largest = 9
            ↓
   Result: 9

3. WHY IT WORKS
   - Initialize largest with first element
   - Compare each element with current largest
   - Update largest if current element is bigger
   - After checking all elements, largest holds the maximum

4. TIME & SPACE COMPLEXITY
   - Time: O(n) - Single pass through array
   - Space: O(1) - Only uses largest variable

5. KEY PATTERN
   Track maximum by comparing each element with current maximum.
*/
int findLargest(vector<int>& arr) {
    int largest = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > largest) largest = arr[i];
    }
    return largest;
}
