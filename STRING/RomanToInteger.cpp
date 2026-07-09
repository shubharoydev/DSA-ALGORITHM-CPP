#include <string>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

/*
===============================================================================
ROMAN TO INTEGER
===============================================================================

1. DRY RUN (Most Important)
   Example: s = "MCMXCIV"
   Map: I=1, V=5, X=10, L=50, C=100, D=500, M=1000

   Initial: ans = 0
   - i=0: s[0]='M', m['M']=1000
     i+1 < 4 and m['M']=1000 < m['C']=100? No
     ans += 1000 → ans = 1000
   - i=1: s[1]='C', m['C']=100
     i+1 < 4 and m['C']=100 < m['M']=1000? Yes
     ans -= 100 → ans = 900
   - i=2: s[2]='M', m['M']=1000
     i+1 < 4 and m['M']=1000 < m['X']=10? No
     ans += 1000 → ans = 1900
   - i=3: s[3]='X', m['X']=10
     i+1 < 4 and m['X']=10 < m['C']=100? Yes
     ans -= 10 → ans = 1890
   - i=4: s[4]='C', m['C']=100
     i+1 < 4 and m['C']=100 < m['I']=1? No
     ans += 100 → ans = 1990
   - i=5: s[5]='I', m['I']=1
     i+1 < 4 and m['I']=1 < m['V']=5? Yes
     ans -= 1 → ans = 1989
   - i=6: s[6]='V', m['V']=5
     i+1 < 7 is false
     ans += 5 → ans = 1994
   - Result: 1994

2. VISUALIZATION

   String: M  C  M  X  C  I  V
           ↓  ↓  ↓  ↓  ↓  ↓  ↓
   Value: 1000 100 1000 10 100 1 5

   Compare pairs:
   M < C? No → +1000
   C < M? Yes → -100
   M < X? No → +1000
   X < C? Yes → -10
   C < I? No → +100
   I < V? Yes → -1
   V (last) → +5

   Total: 1000 - 100 + 1000 - 10 + 100 - 1 + 5 = 1994

3. WHY IT WORKS
   - Roman numerals are usually written from largest to smallest left to right
   - When a smaller value appears before a larger value, it's subtracted (e.g., IV = 4)
   - By checking if current < next, we know to subtract instead of add
   - This handles all special cases: IV, IX, XL, XC, CD, CM

4. TIME & SPACE COMPLEXITY
   - Time: O(n) - Single pass through string
   - Space: O(1) - Fixed size map for 7 characters

5. KEY PATTERN
   If current value < next value, subtract; otherwise add.
*/
int romanToInt(string s) {
    unordered_map<char, int> m = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
        {'C', 100}, {'D', 500}, {'M', 1000}
    };
    
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
        // If current value is less than the next value, subtract it
        if (i + 1 < s.length() && m[s[i]] < m[s[i + 1]]) {
            ans -= m[s[i]];
        } else {
            ans += m[s[i]];
        }
    }
    return ans;
}