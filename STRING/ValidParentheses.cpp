#include <string>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

/*
===============================================================================
VALID PARENTHESES (STACK)
===============================================================================

1. DRY RUN (Most Important)
   Example: s = "()[]{}"

   Initial: st = empty stack
   - c='(': push '(' → st = ['(']
   - c=')': top='(', matches, pop → st = []
   - c='[': push '[' → st = ['[']
   - c=']': top='[', matches, pop → st = []
   - c='{': push '{' → st = ['{']
   - c='}': top='{', matches, pop → st = []
   - Result: st.empty() = true, return true

   Example 2: s = "([)]"
   - c='(': push '(' → st = ['(']
   - c='[': push '[' → st = ['(', '[']
   - c=')': top='[', doesn't match '(', return false

2. VISUALIZATION

   String: (  )  [  ]  {  }
           ↓  ↓  ↓  ↓  ↓  ↓
   Stack:  []
           ↓
   (:      ['(']
           ↓
   ):      []  ← pop (matches)
           ↓
   [:      ['[']
           ↓
   ):      []  ← pop (matches)
           ↓
   {:      ['{']
           ↓
   }:      []  ← pop (matches)
           ↓
   Result:  Empty stack = valid ✓

3. WHY IT WORKS
   - Push opening brackets onto stack
   - When we see a closing bracket, it must match the top of stack
   - If it matches, pop the opening bracket (they form a valid pair)
   - If it doesn't match or stack is empty, string is invalid
   - At end, stack must be empty (all brackets matched)

4. TIME & SPACE COMPLEXITY
   - Time: O(n) - Single pass through string
   - Space: O(n) - Stack can hold up to n/2 opening brackets

5. KEY PATTERN
   Use stack: push opening brackets, pop and match when seeing closing brackets.
*/
bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if (st.empty()) return false;
            char top = st.top();
            if ((c == ')' && top == '(') || 
                (c == '}' && top == '{') || 
                (c == ']' && top == '[')) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.empty();
}
