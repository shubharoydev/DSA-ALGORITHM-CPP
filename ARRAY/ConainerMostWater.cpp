#include <vector>
#include <algorithm>
using namespace std;

/*
===============================================================================
 CONTAINER WITH MOST WATER (TWO POINTER)
===============================================================================

1. DRY RUN (Most Important)
   Example: height = [1, 8, 6, 2, 5, 4, 8, 3, 7]

   Initial: left=0, right=8, maxW=0
   - left=0, right=8: w=8-0=8, h=min(1,7)=1, area=8*1=8, maxW=8
     height[left]=1 < height[right]=7, so left++ → left=1
   - left=1, right=8: w=8-1=7, h=min(8,7)=7, area=7*7=49, maxW=49
     height[left]=8 > height[right]=7, so right-- → right=7
   - left=1, right=7: w=7-1=6, h=min(8,3)=3, area=6*3=18, maxW=49
     height[left]=8 > height[right]=3, so right-- → right=6
   - left=1, right=6: w=6-1=5, h=min(8,8)=8, area=5*8=40, maxW=49
     height[left]=8 == height[right]=8, so right-- → right=5
   - left=1, right=5: w=5-1=4, h=min(8,4)=4, area=4*4=16, maxW=49
     height[left]=8 > height[right]=4, so right-- → right=4
   - left=1, right=4: w=4-1=3, h=min(8,5)=5, area=3*5=15, maxW=49
     height[left]=8 > height[right]=5, so right-- → right=3
   - left=1, right=3: w=3-1=2, h=min(8,2)=2, area=2*2=4, maxW=49
     height[left]=8 > height[right]=2, so right-- → right=2
   - left=1, right=2: w=2-1=1, h=min(8,6)=6, area=1*6=6, maxW=49
     height[left]=8 > height[right]=6, so right-- → right=1
   - left=1, right=1: left >= right, stop
   - Result: 49

2. VISUALIZATION

   Heights: [1] [8] [6] [2] [5] [4] [8] [3] [7]
            L                       R
            ↓                       ↓
   Step 1:  Area = 8 * min(1,7) = 8
            Move L (1 is smaller)

                L                   R
                ↓                   ↓
   Step 2:  Area = 7 * min(8,7) = 49 ← Best!
            Move R (7 is smaller)

                L               R
                ↓               ↓
   Step 3:  Area = 6 * min(8,3) = 18
            Move R (3 is smaller)

   ...continues until pointers meet...

3. WHY IT WORKS
   - Start with widest container (max width)
   - Area is limited by the shorter line
   - Moving the shorter line might find a taller line to increase area
   - Moving the taller line can never increase area (width decreases, height limited by shorter)
   - Greedy approach: always move the pointer at shorter line

4. TIME & SPACE COMPLEXITY
   - Time: O(n) - Each pointer moves at most n times
   - Space: O(1) - Only uses left, right, maxW

5. KEY PATTERN
   Two pointers from ends, always move the pointer at the shorter line.
*/
int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int maxW = 0;
    while (left < right) {
        int w = right - left;
        int h = min(height[left], height[right]);
        maxW = max(maxW, w * h);
        if (height[left] < height[right]) left++;
        else right--;
    }
    return maxW;
}
