#include <string>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;
/*
===============================================================================
ROTATE STRING
===============================================================================

1. DRY RUN (Most Important)
   Example: s = "abcde", goal = "cdeab"

   Check: s.length() = 5, goal.length() = 5, lengths equal, continue
   doubled = s + s = "abcdeabcde"
   Check if "cdeab" is substring of "abcdeabcde"
   - "abcdeabcde" contains "cdeab" starting at index 2
   - Result: true

   Example 2: s = "abcde", goal = "abced"
   Check: s.length() = 5, goal.length() = 5, lengths equal, continue
   doubled = "abcdeabcde"
   Check if "abced" is substring of "abcdeabcde"
   - "abcdeabcde" does NOT contain "abced"
   - Result: false

2. VISUALIZATION

   s = "abcde"
   goal = "cdeab"

   doubled = "abcdeabcde"
            ↓↓↓↓↓↓↓↓↓↓↓
   Check:  "cdeab" found at index 2
            abcdeabcde
                cdeab  ← match!

   Result: true ✓

3. WHY IT WORKS
   - Rotating s by k positions moves first k characters to end
   - All possible rotations of s are substrings of s + s
   - If goal is a rotation of s, it must be a substring of s + s
   - Length check ensures we don't get false positives from different lengths

4. TIME & SPACE COMPLEXITY
   - Time: O(n) - String concatenation O(n), substring search O(n)
   - Space: O(n) - For doubled string

5. KEY PATTERN
   If goal is a rotation of s, it must be a substring of s + s.
*/
bool rotateString(string s, string goal) {
    // If lengths are different, s can never match goal by shifting
    if (s.length() != goal.length()) return false;
    // If goal is a rotation of s, it must be a substring of (s + s)
    string doubled = s + s;
    return doubled.find(goal) != string::npos;
}
