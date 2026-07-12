/*
1. DRY RUN
Calculate 5C2:
- ans = 1
- i=0: ans = (1 * (5-0)) / (0+1) = 5 / 1 = 5
- i=1: ans = (5 * (5-1)) / (1+1) = (5 * 4) / 2 = 10
Result = 10.

2. VISUALIZATION
nCr = n! / (r! * (n-r)!)
Instead of computing huge factorials, we compute it iteratively:
nCr = (n/1) * ((n-1)/2) * ((n-2)/3) ... * ((n-r+1)/r)
For 5C2: (5/1) * (4/2) = 10.

3. WHY IT WORKS
- The identity nCr = nC(n-r) lets us use the smaller of r and (n-r).
- Multiplication and division are performed together in each iteration.
- This prevents the large intermediate values that occur when using factorials.
- The result remains an integer at every step because combinations are always whole numbers.
- The algorithm efficiently computes the answer without calculating n!, r!, or (n-r)!.

4. TIME & SPACE COMPLEXITY
- Time Complexity: O(r)
- Space Complexity: O(1)

5. KEY PATTERN
- Combinatorics
- Iterative interleaved multiplication and division
- nCr = nC(n-r) optimization

6. cpp code
*/

#include <iostream>
using namespace std;

long long nCr(int n, int r) {
    if (r > n)
        return 0;

    if (r == 0 || r == n)
        return 1;

    // Use the smaller value of r
    if (r > n - r)
        r = n - r;

    long long res = 1;

    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }

    return res;
}

int main() {
    cout << "5C2 = " << nCr(5, 2) << endl;
    cout << "10C3 = " << nCr(10, 3) << endl;

    return 0;
}