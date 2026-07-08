// Three Types of Sorting AlgorithmsHere are three classic sorting algorithms: Selection Sort, Bubble Sort, and Insertion Sort.
#include <vector>
#include <algorithm>
using namespace std;

/*
===============================================================================
1. SELECTION SORT
===============================================================================

1. DRY RUN (Most Important)
   Example: arr = [64, 25, 12, 22, 11]

   Pass 1 (i=0): Find minimum from index 0 to 4
   - Start: minIdx = 0 (value=64)
   - j=1: arr[1]=25 < 64, minIdx=1
   - j=2: arr[2]=12 < 25, minIdx=2
   - j=3: arr[3]=22 > 12, minIdx stays 2
   - j=4: arr[4]=11 < 12, minIdx=4
   - Swap arr[0] and arr[4]
   - After: [11, 25, 12, 22, 64]

   Pass 2 (i=1): Find minimum from index 1 to 4
   - Start: minIdx = 1 (value=25)
   - j=2: arr[2]=12 < 25, minIdx=2
   - j=3: arr[3]=22 > 12, minIdx stays 2
   - j=4: arr[4]=64 > 12, minIdx stays 2
   - Swap arr[1] and arr[2]
    - After: [11, 12, 25, 22, 64]

   Pass 3 (i=2): Find minimum from index 2 to 4
   - Start: minIdx = 2 (value=25)
   - j=3: arr[3]=22 < 25, minIdx=3
   - j=4: arr[4]=64 > 22, minIdx stays 3
   - Swap arr[2] and arr[3]
   - After: [11, 12, 22, 25, 64]

   Pass 4 (i=3): Find minimum from index 3 to 4
   - Start: minIdx = 3 (value=25)
   - j=4: arr[4]=64 > 25, minIdx stays 3
   - Swap arr[3] with itself (no change)
   - After: [11, 12, 22, 25, 64]

2. VISUALIZATION

   Initial: [64] [25] [12] [22] [11]
            ↓
   Pass 1:  Find min (11) and swap with first
            ↓
            [11] [25] [12] [22] [64]
            ↓
   Pass 2:  Find min from remaining (12) and swap with second
            ↓
            [11] [12] [25] [22] [64]
            ↓
   Pass 3:  Find min from remaining (22) and swap with third
            ↓
            [11] [12] [22] [25] [64]
            ↓
   Pass 4:  Last element already in place
            ↓
            [11] [12] [22] [25] [64] ✓

3. WHY IT WORKS
   After each pass i:
   - Elements from index 0 to i-1 are sorted and in their final positions
   - We find the smallest element in the unsorted portion (i to n-1)
   - By swapping it to position i, we place the correct element there
   - After n-1 passes, all elements are in their correct positions

4. TIME & SPACE COMPLEXITY
   - Time: O(n²) - Two nested loops, each iterating n times
   - Space: O(1) - Only uses a few variables (minIdx, i, j)

5. KEY PATTERN
   Find the minimum in the unsorted portion and swap it to the front.
*/
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}

/*
===============================================================================
2. BUBBLE SORT
===============================================================================

1. DRY RUN (Most Important)
   Example: arr = [5, 1, 4, 2, 8]

   Pass 1 (i=0): Push largest to end
   - j=0: Compare 5 > 1, swap → [1, 5, 4, 2, 8]
   - j=1: Compare 5 > 4, swap → [1, 4, 5, 2, 8]
   - j=2: Compare 5 > 2, swap → [1, 4, 2, 5, 8]
   - j=3: Compare 5 < 8, no swap → [1, 4, 2, 5, 8]
   - After: [1, 4, 2, 5, 8] (8 is at correct position)

   Pass 2 (i=1): Push second largest to position n-2
   - j=0: Compare 1 < 4, no swap → [1, 4, 2, 5, 8]
   - j=1: Compare 4 > 2, swap → [1, 2, 4, 5, 8]
   - j=2: Compare 4 < 5, no swap → [1, 2, 4, 5, 8]
   - After: [1, 2, 4, 5, 8] (5, 8 are at correct positions)

   Pass 3 (i=2): Push third largest to position n-3
   - j=0: Compare 1 < 2, no swap → [1, 2, 4, 5, 8]
   - j=1: Compare 2 < 4, no swap → [1, 2, 4, 5, 8]
   - After: [1, 2, 4, 5, 8] (4, 5, 8 are at correct positions)

   Pass 4 (i=3): Push fourth largest to position n-4
   - j=0: Compare 1 < 2, no swap → [1, 2, 4, 5, 8]
   - After: [1, 2, 4, 5, 8] ✓

2. VISUALIZATION

   Initial: [5] [1] [4] [2] [8]
            ↓
   Pass 1:  Bubble largest to end
   [5] [1] [4] [2] [8]
    ↓    ↓    ↓    ↓
   [1] [4] [2] [5] [8]  ← 8 is now at correct position
            ↓
   Pass 2:  Bubble next largest
   [1] [4] [2] [5] [8]
        ↓    ↓
   [1] [2] [4] [5] [8]  ← 5, 8 are now correct
            ↓
   Pass 3:  Check remaining
   [1] [2] [4] [5] [8]  ← Already sorted
            ↓
   Final:   [1] [2] [4] [5] [8] ✓

3. WHY IT WORKS
   After each pass i:
   - The largest i elements "bubble up" to their correct positions at the end
   - Adjacent swaps ensure larger elements move right
   - After n-1 passes, all elements are in sorted order

4. TIME & SPACE COMPLEXITY
   - Time: O(n²) - Two nested loops
   - Space: O(1) - Only uses a few variables

5. KEY PATTERN
   Repeatedly swap adjacent elements if they're in wrong order, pushing largest to end.
*/
void bubbleSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

/*
===============================================================================
3. INSERTION SORT
===============================================================================

1. DRY RUN (Most Important)
   Example: arr = [12, 11, 13, 5, 6]

   i=1: key=11, insert into sorted portion [12]
   - Compare 11 < 12, shift 12 right → [12, 12, 13, 5, 6]
   - Place key at index 0 → [11, 12, 13, 5, 6]

   i=2: key=13, insert into sorted portion [11, 12]
   - Compare 13 > 12, no shift needed
   - Place key at index 2 (same position) → [11, 12, 13, 5, 6]

   i=3: key=5, insert into sorted portion [11, 12, 13]
   - Compare 5 < 13, shift 13 right → [11, 12, 13, 13, 6]
   - Compare 5 < 12, shift 12 right → [11, 12, 12, 13, 6]
   - Compare 5 < 11, shift 11 right → [11, 11, 12, 13, 6]
   - Place key at index 0 → [5, 11, 12, 13, 6]

   i=4: key=6, insert into sorted portion [5, 11, 12, 13]
   - Compare 6 < 13, shift 13 right → [5, 11, 12, 13, 13]
   - Compare 6 < 12, shift 12 right → [5, 11, 12, 12, 13]
   - Compare 6 < 11, shift 11 right → [5, 11, 11, 12, 13]
   - Compare 6 > 5, stop shifting
   - Place key at index 1 → [5, 6, 11, 12, 13]

2. VISUALIZATION

   Initial: [12] [11] [13] [5] [6]
            ↓
   i=1:     Insert 11 into [12]
            [12] [12] [13] [5] [6]  ← Shift 12
             ↓
            [11] [12] [13] [5] [6]  ← Place 11
            ↓
   i=2:     Insert 13 into [11,12]
            [11] [12] [13] [5] [6]  ← No shift needed
            ↓
   i=3:     Insert 5 into [11,12,13]
            [11] [11] [12] [13] [13]  ← Shift all
             ↓
            [5] [11] [12] [13] [6]  ← Place 5
            ↓
   i=4:     Insert 6 into [5,11,12,13]
            [5] [11] [11] [12] [13]  ← Shift 11,12,13
             ↓
            [5] [6] [11] [12] [13]  ← Place 6
            ↓
   Final:   [5] [6] [11] [12] [13] ✓

3. WHY IT WORKS
   After each iteration i:
   - Elements from index 0 to i are sorted
   - We take element at i and shift larger elements right to make space
   - We place the element in its correct position within the sorted portion
   - Like sorting playing cards in your hand

4. TIME & SPACE COMPLEXITY
   - Time: O(n²) worst case, O(n) best case (already sorted)
   - Space: O(1) - Only uses a few variables

5. KEY PATTERN
   Build sorted array one element at a time by inserting each element into its correct position.
*/
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}