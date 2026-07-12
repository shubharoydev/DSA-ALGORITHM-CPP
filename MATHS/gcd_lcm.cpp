/*
1. DRY RUN
Find GCD of 12 and 18:
- gcd(18, 12): b != 0, return gcd(12, 18 % 12) => gcd(12, 6)
- gcd(12, 6): b != 0, return gcd(6, 12 % 6) => gcd(6, 0)
- gcd(6, 0): b == 0, return a => 6.
Result GCD = 6.
LCM = (12 * 18) / 6 = 36.

2. VISUALIZATION
Euclidean Algorithm:
GCD(a, b) = GCD(b, a % b)
Imagine fitting a bxb square into an axb rectangle. The remainder is what's left. Repeat until it fits perfectly (remainder 0).

3. WHY IT WORKS
- The GCD of two numbers also divides their remainder.
- Each recursive call reduces the size of the problem.
- The process continues until the remainder becomes 0.
- The last non-zero value is the GCD.
- Once the GCD is known, the LCM is found using:
  - LCM(a, b) = (a / GCD(a, b)) × b
- Dividing before multiplying helps reduce the risk of integer overflow.

4. TIME & SPACE COMPLEXITY
- Time Complexity: O(log(min(a, b)))
- Space Complexity: O(log(min(a, b))) for recursion stack, or O(1) if written iteratively.

5. KEY PATTERN
- Euclidean Algorithm
- LCM(a, b) = (a * b) / GCD(a, b)

6. cpp code
*/

#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    int a = 12, b = 18;

    cout << "GCD of " << a << " and " << b << " is: " << gcd(a, b) << endl;
    cout << "LCM of " << a << " and " << b << " is: " << lcm(a, b) << endl;

    return 0;
}