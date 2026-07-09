#include <string>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;
/*
===============================================================================
REMOVE OUTERMOST PARENTHESES
===============================================================================

1. DRY RUN (Most Important)
   Example: s = "(()())(())"

   Initial: result = "", opened = 0
   - c='(': opened=0, condition (opened > 0) is false, don't add. opened++ → opened=1
   - c='(': opened=1, condition (opened > 0) is true, add '(' → result="(". opened++ → opened=2
   - c=')': opened-- → opened=1, condition (opened > 0) is true, add ')' → result="()"
   - c='(': opened=1, condition (opened > 0) is true, add '(' → result="()(". opened++ → opened=2
   - c=')': opened-- → opened=1, condition (opened > 0) is true, add ')' → result="()()"
   - c=')': opened-- → opened=0, condition (opened > 0) is false, don't add. result="()()"
   - c='(': opened=0, condition (opened > 0) is false, don't add. opened++ → opened=1
   - c='(': opened=1, condition (opened > 0) is true, add '(' → result="()()(". opened++ → opened=2
   - c=')': opened-- → opened=1, condition (opened > 0) is true, add ')' → result="()()()"
   - c=')': opened-- → opened=0, condition (opened > 0) is false, don't add. result="()()()"
   
   Result: "()()()" (Correct!)

2. VISUALIZATION

   Original String:  (  (  )  (  )  )  (  (  )  )
   Outermost Check:  X  |__|  |__|  X  X  |__|  X
                     ↓  └───┬───┘   ↓  ↓   └┬┘  ↓
   Stripped Result:     ( ) ( )           ( )   👉  "()()()"

3. WHY IT WORKS
   - The variable `opened` maintains the nesting depth of valid parentheses.
   - For an opening parenthesis `(`, it is an outer boundary ONLY if `opened == 0`. If `opened > 0`, it belongs to an inner primitive string, so we keep it.
   - For a closing parenthesis `)`, we decrement `opened` first. It is an outer boundary ONLY if it brings `opened` back to `0`. If `opened > 0`, it belongs to an inner primitive string, so we keep it.

4. TIME & SPACE COMPLEXITY
   - Time: O(n) where n is the length of the string (single pass traversal).
   - Space: O(1) auxiliary space as we only use a primitive counter (`opened`).

5. KEY PATTERN
   Track nesting depth with a counter; filter out characters where depth equals 0.
*/

string removeOuterParentheses(string s) {
    string result = "";
    int opened = 0;
    for (char c : s) {
        if (c == '(') {
            if (opened > 0) result += c;
            opened++;
        } else {
            opened--;
            if (opened > 0) result += c;
        }
    }
    return result;
}