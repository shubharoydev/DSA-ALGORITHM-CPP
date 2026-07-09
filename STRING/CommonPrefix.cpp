#include <string>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

/*
===============================================================================
LONGEST COMMON PREFIX
===============================================================================

1. DRY RUN (Most Important)
   Example: strs = ["flower", "flow", "flight"]

   After sorting: strs = ["flight", "flow", "flower"]
   first = "flight", last = "flower"

   Initial: result = ""
   - i=0: first[0]='f' == last[0]='f', add 'f' → result="f"
   - i=1: first[1]='l' == last[1]='l', add 'l' → result="fl"
   - i=2: first[2]='i' != last[2]='o', break
   - Result: "fl"

2. VISUALIZATION

   Original: ["flower", "flow", "flight"]
            ↓
   Sort:    ["flight", "flow", "flower"]
            ↓
   Compare first and last:
   flight
   flower
   ↓↓↓
   f l i  ← mismatch at 'i' vs 'o'
   ↓↓↓
   Result: "fl"

3. WHY IT WORKS
   - After sorting, the strings with most difference will be at ends
   - Common prefix of all strings must be common to first and last
   - If first and last share a prefix, all strings in between share it too
   - Compare first and last character by character until mismatch

4. TIME & SPACE COMPLEXITY
   - Time: O(n log n) for sorting + O(m) for comparison = O(n log n + m)
   - Space: O(1) excluding output

5. KEY PATTERN
   Sort array, compare first and last strings character by character.
*/
string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    // Sort the strings; the common prefix must be shared between the lexicographically first and last string
    sort(strs.begin(), strs.end());
    string first = strs[0];
    string last = strs[strs.size() - 1];
    
    string result = "";
    for (int i = 0; i < min(first.length(), last.length()); i++) {
        if (first[i] != last[i]) break;
        result += first[i];
    }
    return result;
}