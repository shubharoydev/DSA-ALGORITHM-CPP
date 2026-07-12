/*
1. DRY RUN
Calculate 2^5:
- x=2, n=5, ans=1.
- n is odd: ans = 1 * 2 = 2. n = 4.
- n is even: x = 2 * 2 = 4. n = 2.
- n is even: x = 4 * 4 = 16. n = 1.
- n is odd: ans = 2 * 16 = 32. n = 0.
Result = 32.

2. VISUALIZATION
2^5 = 2 * 2^4
2^4 = (2^2)^2 = 4^2
4^2 = (4^2)^1 = 16^1
16^1 = 16 * 16^0 = 16 * 1 = 16
Final Ans = 2 * 16 = 32.
At each step, we either multiply ans by x (if power is odd) or square x and halve the power (if power is even).

3. WHY IT WORKS
- Binary exponentiation reduces the number of multiplications.
- For an even exponent:
  - x^n = (x²)^(n/2)
- For an odd exponent:
  - Multiply the answer by x, then reduce the exponent by 1.
- The exponent becomes smaller in every iteration.
- This allows us to compute the answer much faster than multiplying x by itself n t

4. TIME & SPACE COMPLEXITY
- Time Complexity: O(log N) because we halve the power at each step.
- Space Complexity: O(1) iterative space.

5. KEY PATTERN
- Binary Exponentiation / Fast Power
- Check for odd/even powers

6. cpp code
*/

#include <iostream>
using namespace std;

double myPow(double x, int n) {
    double ans = 1.0;
    long long nn = n; // Handle INT_MIN

    if (nn < 0)
        nn = -nn;

    while (nn > 0) {
        if (nn % 2 == 1) { // Odd exponent
            ans *= x;
            nn--;
        } else { // Even exponent
            x *= x;
            nn /= 2;
        }
    }

    if (n < 0)
        ans = 1.0 / ans;

    return ans;
}

int main() {
    cout << "2.0 ^ 5 = " << myPow(2.0, 5) << endl;
    cout << "2.0 ^ -2 = " << myPow(2.0, -2) << endl;

    return 0;
}