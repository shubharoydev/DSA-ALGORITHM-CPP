/*
1. DRY RUN
Finding primes up to N = 10 using Sieve:
- Array of booleans [0..10] initialized to true. Set 0 and 1 to false.
- p=2: prime. Mark multiples (4, 6, 8, 10) as false.
- p=3: prime. Mark multiples (6, 9) as false.
- p=4: false (already marked).
- p=5: stop, because 5*5 = 25 > 10.
Primes remaining: 2, 3, 5, 7.

2. VISUALIZATION
[T, T, T, T, T, T, T, T, T, T, T] (Init)
[F, F, T, T, T, T, T, T, T, T, T] (0,1 false)
[F, F, T, T, F, T, F, T, F, T, F] (Multiples of 2)
[F, F, T, T, F, T, F, T, F, F, F] (Multiples of 3)

3. WHY IT WORKS
- Every composite number has at least one prime factor less than or equal to √N.
- Multiples of each prime are marked as non-prime.
- Multiples smaller than p² have already been marked by smaller prime factors.
- Therefore, marking starts from p² to avoid unnecessary work.
- After all multiples are removed, the remaining numbers are prime.

4. TIME & SPACE COMPLEXITY
- Time Complexity: O(N * log(log(N)))
- Space Complexity: O(N) for boolean array.

5. KEY PATTERN
- Sieve of Eratosthenes
- Crossing out multiples starting from p*p

6. cpp code
*/


#include <iostream>
#include <vector>
using namespace std;

vector<int> sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n + 1, true);

    if (n >= 0) isPrime[0] = false;
    if (n >= 1) isPrime[1] = false;

    for (int p = 2; p * p <= n; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }

    vector<int> primes;

    for (int p = 2; p <= n; p++) {
        if (isPrime[p]) {
            primes.push_back(p);
        }
    }

    return primes;
}

int main() {
    vector<int> primes = sieveOfEratosthenes(30);

    cout << "Primes up to 30: ";
    for (int p : primes) {
        cout << p << " ";
    }
    cout << endl;

    return 0;
}