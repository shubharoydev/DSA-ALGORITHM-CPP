#include <string>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;
/*
===============================================================================
LARGEST ODD NUMBER IN STRING
===============================================================================

1. DRY RUN (Most Important)
   Example: num = "4206"

   Scan from right to left:
   - i=3: num[3]='6', 6 % 2 = 0 (even), continue
   - i=2: num[2]='0', 0 % 2 = 0 (even), continue
   - i=1: num[1]='2', 2 % 2 = 0 (even), continue
   - i=0: num[0]='4', 4 % 2 = 0 (even), continue
   - No odd digit found
   - Result: ""

   Example 2: num = "35427"
   Scan from right to left:
   - i=4: num[4]='7', 7 % 2 = 1 (odd), return num.substr(0, 5) = "35427"
   - Result: "35427"

   Example 3: num = "52"
   Scan from right to left:
   - i=1: num[1]='2', 2 % 2 = 0 (even), continue
   - i=0: num[0]='5', 5 % 2 = 1 (odd), return num.substr(0, 1) = "5"
   - Result: "5"

2. VISUALIZATION

   num = "35427"

   Scan from right:
   [3] [5] [4] [2] [7]
                    ↑
                  Found odd!

   Return prefix: "35427"

   num = "4206"

   Scan from right:
   [4] [2] [0] [6]
   ↑   ↑   ↑   ↑
   All even

   Return: ""

3. WHY IT WORKS
   - A number is odd if its last digit is odd
   - We want the largest odd prefix, so we scan from right
   - First odd digit from right gives the largest odd prefix
   - Everything to the left of that digit forms the prefix
   - If no odd digit, no odd prefix exists

4. TIME & SPACE COMPLEXITY
   - Time: O(n) - Single pass from right
   - Space: O(1) - Only uses loop variable

5. KEY PATTERN
   Scan from right, find first odd digit, return prefix up to that digit.
*/
string largestOddNumber(string num) {
    // Scan from right to left to find the first odd digit
    for (int i = num.length() - 1; i >= 0; i--) {
        if ((num[i] - '0') % 2 != 0) {
            return num.substr(0, i + 1);
        }
    }
    return "";
}