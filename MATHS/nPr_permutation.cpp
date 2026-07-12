/*
1. DRY RUN
Calculate 5P2:
- n = 5, r = 2
- res = 1
- Iteration 1: res = 1 * 5 = 5
- Iteration 2: res = 5 * 4 = 20
Result = 20.

2. VISUALIZATION
nPr = n! / (n-r)!
We just need to multiply 'r' numbers starting from 'n' going downwards.
For 5P2: 5 * 4 = 20.

3. WHY IT WORKS
- The first position can be filled in n ways.
- The second position can be filled in (n - 1) ways.
- The third position can be filled in (n - 2) ways.
- This continues until r positions are filled.
- Multiplying these choices gives the total number of permutations.
- This directly computes:
  - nPr = n! / (n - r)!

4. TIME & SPACE COMPLEXITY
- Time Complexity: O(r)
- Space Complexity: O(1)

5. KEY PATTERN
- Combinatorics
- Decreasing multiplication loop

6. cpp code
*/

#include <iostream>
using namespace std;

long long nPr(int n, int r) {
    if (r > n)
        return 0;

    long long res = 1;

    for (int i = 0; i < r; i++) {
        res *= (n - i);
    }

    return res;
}

int main() {
    cout << "5P2 = " << nPr(5, 2) << endl;
    cout << "10P3 = " << nPr(10, 3) << endl;

    return 0;
}