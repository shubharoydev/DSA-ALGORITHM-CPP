#include <vector>
#include <algorithm>
using namespace std;
/*
===============================================================================
UNION OF TWO SORTED ARRAYS
===============================================================================

1. DRY RUN (Most Important)
   Example: a = [1, 2, 3, 4, 5], b = [2, 3, 4, 4, 5, 6]

   Initial: i=0, j=0, unionArr=[]
   - a[0]=1 <= b[0]=2, add 1 → unionArr=[1], i++ → i=1
   - a[1]=2 <= b[0]=2, add 2 → unionArr=[1,2], i++ → i=2, j++ → j=1
   - a[2]=3 <= b[1]=3, add 3 → unionArr=[1,2,3], i++ → i=3, j++ → j=2
   - a[3]=4 <= b[2]=4, add 4 → unionArr=[1,2,3,4], i++ → i=4, j++ → j=3
   - a[4]=5 > b[3]=4, add 4 (duplicate, skip), j++ → j=4
   - a[4]=5 <= b[4]=5, add 5 → unionArr=[1,2,3,4,5], i++ → i=5, j++ → j=5
   - i=5 >= a.size(), exit first loop
   - Add remaining from b: b[5]=6 not in union, add 6 → unionArr=[1,2,3,4,5,6]
   - Result: [1, 2, 3, 4, 5, 6]

2. VISUALIZATION

   a: [1] [2] [3] [4] [5]
   b: [2] [3] [4] [4] [5] [6]
        i   j
        ↓   ↓
   Step 1:  1 <= 2, add 1, i++

            i   j
            ↓   ↓
   Step 2:  2 <= 2, add 2, i++, j++

            i       j
            ↓       ↓
   Step 3:  3 <= 3, add 3, i++, j++

   ...continues until i reaches end...

   Result: [1] [2] [3] [4] [5] [6]

3. WHY IT WORKS
   - Both arrays are sorted, so we can merge like merge sort
   - Compare elements from both arrays, add smaller one
   - If equal, add once and advance both pointers
   - Skip duplicates by checking against last added element
   - After one array exhausted, add remaining unique elements from other

4. TIME & SPACE COMPLEXITY
   - Time: O(n + m) - Single pass through both arrays
   - Space: O(n + m) - For result array

5. KEY PATTERN
   Merge like merge sort, skip duplicates by checking last added element.
*/
vector<int> findUnion(vector<int>& a, vector<int>& b) {
    int i = 0, j = 0;
    vector<int> unionArr;
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) {
            if (unionArr.empty() || unionArr.back() != a[i]) unionArr.push_back(a[i]);
            i++;
        } else {
            if (unionArr.empty() || unionArr.back() != b[j]) unionArr.push_back(b[j]);
            j++;
        }
    }
    while (i < a.size()) {
        if (unionArr.empty() || unionArr.back() != a[i]) unionArr.push_back(a[i]);
        i++;
    }
    while (j < b.size()) {
        if (unionArr.empty() || unionArr.back() != b[j]) unionArr.push_back(b[j]);
        j++;
    }
    return unionArr;
}
