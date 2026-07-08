#include <vector>
#include <algorithm>
using namespace std;

/*
===============================================================================
 FIND THE NUMBER WHICH APPEARS ONCE
===============================================================================

Uses XOR to find the element
that appears once while all others appear twice.


KEY PATTERN
Same as Single Number: Use XOR to cancel out pairs.
*/
int getSingleElement(vector<int>& arr) {
    int xorr = 0;
    for (int num : arr) {
        xorr ^= num;
    }
    return xorr;
}
