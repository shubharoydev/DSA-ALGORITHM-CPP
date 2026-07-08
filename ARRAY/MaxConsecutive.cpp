#include <vector>
#include <algorithm>
using namespace std;
/*
===============================================================================
MAX CONSECUTIVE ONES
===============================================================================

1. DRY RUN (Most Important)
   Example: nums = [1, 1, 0, 1, 1, 1, 0, 1]

   Initial: cnt = 0, maxCnt = 0
   - num=1: cnt = 1, maxCnt = max(0, 1) = 1
   - num=1: cnt = 2, maxCnt = max(1, 2) = 2
   - num=0: cnt = 0, maxCnt = max(2, 0) = 2
   - num=1: cnt = 1, maxCnt = max(2, 1) = 2
   - num=1: cnt = 2, maxCnt = max(2, 2) = 2
   - num=1: cnt = 3, maxCnt = max(2, 3) = 3
   - num=0: cnt = 0, maxCnt = max(3, 0) = 3
   - num=1: cnt = 1, maxCnt = max(3, 1) = 3
   - Result: 3

2. VISUALIZATION

   Array: [1] [1] [0] [1] [1] [1] [0] [1]
            ↓
   Start:  cnt=0, maxCnt=0
            ↓
   1:      cnt=1, maxCnt=1
            ↓
   1:      cnt=2, maxCnt=2
            ↓
   0:      cnt=0, maxCnt=2
            ↓
   1:      cnt=1, maxCnt=2
            ↓
   1:      cnt=2, maxCnt=2
            ↓
   1:      cnt=3, maxCnt=3 ← Best!
            ↓
   0:      cnt=0, maxCnt=3
            ↓
   1:      cnt=1, maxCnt=3
            ↓
   Result:  maxCnt=3

3. WHY IT WORKS
   - cnt tracks current consecutive 1s count
   - When we see 1, increment cnt
   - When we see 0, reset cnt to 0 (streak broken)
   - maxCnt keeps the best streak seen so far
   - After full scan, maxCnt is the answer

4. TIME & SPACE COMPLEXITY
   - Time: O(n) - Single pass through array
   - Space: O(1) - Only uses cnt and maxCnt

5. KEY PATTERN
   Count consecutive 1s, reset on 0, track maximum count.
*/
int findMaxConsecutiveOnes(vector<int>& nums) {
    int cnt = 0, maxCnt = 0;
    for (int num : nums) {
        if (num == 1) {
            cnt++;
            maxCnt = max(maxCnt, cnt);
        } else {
            cnt = 0;
        }
    }
    return maxCnt;
}