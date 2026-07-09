#include <string>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;
/*
===============================================================================
VALID PALINDROME (TWO POINTER)
===============================================================================

1. DRY RUN (Most Important)
   Example: s = "A man, a plan, a canal: Panama"

   Initial: left=0, right=18
   - left=0: s[0]='A' is alphanumeric, tolower='A'
     right=18: s[18]='a' is alphanumeric, tolower='a'
     'A' != 'a', return false? Wait, let me check: 'A' == 'a' after tolower
     Actually: tolower('A') = 'a', tolower('a') = 'a', they match!
     left++ → left=1, right-- → right=17
   - left=1: s[1]=' ' not alphanumeric, left++ → left=2
   - left=2: s[2]='m' is alphanumeric, tolower='m'
     right=17: s[17]='m' is alphanumeric, tolower='m'
     'm' == 'm', left++ → left=3, right-- → right=16
   - left=3: s[3]='a' is alphanumeric, tolower='a'
     right=16: s[16]='a' is alphanumeric, tolower='a'
     'a' == 'a', left++ → left=4, right-- → right=15
   - left=4: s[4]='n' is alphanumeric, tolower='n'
     right=15: s[15]='n' is alphanumeric, tolower='n'
     'n' == 'n', left++ → left=5, right-- → right=14
   - left=5: s[5]=',' not alphanumeric, left++ → left=6
   - left=6: s[6]=' ' not alphanumeric, left++ → left=7
   - left=7: s[7]='a' is alphanumeric, tolower='a'
     right=14: s[14]='a' is alphanumeric, tolower='a'
     'a' == 'a', left++ → left=8, right-- → right=13
   - ...continues until left >= right
   - Result: true

2. VISUALIZATION

   String: A  m  a  n  ,     a     p  l  a  n  :     P  a  n  a  m  a
           L                                      R
           ↓                                      ↓
   Step 1:  Compare 'A' and 'a' (both become 'a') ✓
           L                                   R
           ↓                                   ↓
   Step 2:  Skip non-alphanumeric from left
               L                               R
               ↓                               ↓
   Step 3:  Compare 'm' and 'm' ✓
                   L                           R
                   ↓                           ↓
   ...continues until pointers meet...

3. WHY IT WORKS
   - Two pointers from ends moving towards center
   - Skip non-alphanumeric characters
   - Compare characters after converting to lowercase
   - If all comparisons match, it's a palindrome
   - If any comparison fails, it's not a palindrome

4. TIME & SPACE COMPLEXITY
   - Time: O(n) - Each pointer moves at most n times
   - Space: O(1) - Only uses left and right pointers

5. KEY PATTERN
   Two pointers from ends, skip non-alphanumeric, compare lowercase characters.
*/
bool isPalindrome(string s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
        while (left < right && !isalnum(s[left])) left++;
        while (left < right && !isalnum(s[right])) right--;
        
        if (tolower(s[left]) != tolower(s[right])) return false;
        left++;
        right--;
    }
    return true;
}