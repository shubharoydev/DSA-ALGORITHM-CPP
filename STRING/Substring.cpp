#include <string>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

/*
===============================================================================
COUNT SUBSTRINGS WITH EXACTLY K DISTINCT CHARACTERS
===============================================================================

1. DRY RUN (Most Important)
   Example: s = "aabacbebebe", k = 3

   First, calculate atMostKDistinct(s, 3):
   Initial: left=0, distinct=0, count=0, freq=[0]*26
   - right=0: s[0]='a', freq[0]=0→1, distinct=1, distinct<=3, count+=1-0+1=1
   - right=1: s[1]='a', freq[0]=1→2, distinct=1, count+=2-0+1=3
   - right=2: s[2]='b', freq[1]=0→1, distinct=2, count+=3-0+1=6
   - right=3: s[3]='a', freq[0]=2→3, distinct=2, count+=4-0+1=10
   - right=4: s[4]='c', freq[2]=0→1, distinct=3, count+=5-0+1=15
   - right=5: s[5]='b', freq[1]=1→2, distinct=3, count+=6-0-1=20
   - right=6: s[6]='e', freq[4]=0→1, distinct=4>3, shrink:
     left=0: freq[0]=3→2, distinct=4, left=1
     left=1: freq[0]=2→1, distinct=4, left=2
     left=2: freq[1]=2→1, distinct=4, left=3
     left=3: freq[0]=1→0, distinct=3, left=4
     count+=6-4+1=23
   - ...continues...
   atMostKDistinct(s, 3) = some value

   Then, calculate atMostKDistinct(s, 2):
   Similar process with k=2

   Result: atMostKDistinct(s, 3) - atMostKDistinct(s, 2)

2. VISUALIZATION

   String: a  a  b  a  c  b  e  b  e  b  e
           L  R
           ↓  ↓
   k=3:    distinct=1, count+=1
               L  R
               ↓  ↓
           distinct=1, count+=2
               L      R
               ↓      ↓
           distinct=2, count+=3
               L          R
               ↓          ↓
           distinct=3, count+=4
               L              R
               ↓              ↓
           distinct=4>3, shrink L until distinct<=3

3. WHY IT WORKS
   - atMostK(k) counts all substrings with ≤ k distinct characters
   - atMostK(k-1) counts all substrings with ≤ k-1 distinct characters
   - Their difference gives exactly k distinct characters
   - Sliding window with frequency array tracks distinct count
   - When distinct > k, shrink window from left

4. TIME & SPACE COMPLEXITY
   - Time: O(n) for each atMostK call, total O(n)
   - Space: O(26) = O(1) for frequency array

5. KEY PATTERN
   Count atMost(k) - atMost(k-1) using sliding window with frequency array.
*/
long long atMostKDistinct(string s, int k) {
    if (k < 0) return 0;
    int left = 0, distinct = 0;
    long long count = 0;
    vector<int> freq(26, 0);
    
    for (int right = 0; right < s.length(); right++) {
        if (freq[s[right] - 'a'] == 0) distinct++;
        freq[s[right] - 'a']++;
        
        while (distinct > k) {
            freq[s[left] - 'a']--;
            if (freq[s[left] - 'a'] == 0) distinct--;
            left++;
        }
        count += (right - left + 1);
    }
    return count;
}

long long countSubstringsWithKDistinct(string s, int k) {
    return atMostKDistinct(s, k) - atMostKDistinct(s, k - 1);
}
