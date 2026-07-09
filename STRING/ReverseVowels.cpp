#include <string>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;
/*
===============================================================================
REVERSE VOWELS (TWO POINTER)
===============================================================================

1. DRY RUN (Most Important)
   Example: s = "hello"

   Initial: left=0, right=4
   - left=0: s[0]='h', not vowel, left++ → left=1
   - left=1: s[1]='e', is vowel
     right=4: s[4]='o', is vowel
     swap(s[1], s[4]) → s="holle"
     left++ → left=2, right-- → right=3
   - left=2: s[2]='l', not vowel, left++ → left=3
   - left=3: s[3]='l', not vowel, left++ → left=4
   - left=4 >= right=3, stop
   - Result: "holle"

   Example 2: s = "leetcode"
   Initial: left=0, right=7
   - left=0: s[0]='l', not vowel, left++ → left=1
   - left=1: s[1]='e', is vowel
     right=7: s[7]='e', is vowel
     swap(s[1], s[7]) → s="leotcede"
     left++ → left=2, right-- → right=6
   - left=2: s[2]='e', is vowel
     right=6: s[6]='d', not vowel, right-- → right=5
   - left=2: s[2]='e', is vowel
     right=5: s[5]='c', not vowel, right-- → right=4
   - left=2: s[2]='e', is vowel
     right=4: s[4]='t', not vowel, right-- → right=3
   - left=2: s[2]='e', is vowel
     right=3: s[3]='o', is vowel
     swap(s[2], s[3]) → s="leotcede" (no change, e and o)
     left++ → left=3, right-- → right=2
   - left=3 >= right=2, stop
   - Result: "leotcede"

2. VISUALIZATION

   s = "hello"
        L       R
        ↓       ↓
   [h] [e] [l] [l] [o]
        ↓       ↓
   Swap e and o:
   [h] [o] [l] [l] [e]

   Result: "holle"

3. WHY IT WORKS
   - Two pointers from ends moving towards center
   - Left pointer finds next vowel from left
   - Right pointer finds next vowel from right
   - Swap them to reverse their positions
   - Continue until pointers meet
   - Only vowels are moved, consonants stay in place

4. TIME & SPACE COMPLEXITY
   - Time: O(n) - Each pointer moves at most n times
   - Space: O(1) - Only uses left and right pointers

5. KEY PATTERN
   Two pointers from ends, find vowels, swap them.
*/
bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
string reverseVowels(string s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
        while (left < right && !isVowel(s[left])) left++;
        while (left < right && !isVowel(s[right])) right--;
        
        if (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
    return s;
}