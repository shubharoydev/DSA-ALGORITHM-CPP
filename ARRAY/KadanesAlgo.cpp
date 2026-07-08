#include <vector>
#include <algorithm>
using namespace std;

/*
===============================================================================
KADANE'S ALGORITHM (LONG LONG VERSION)
===============================================================================

KEY PATTERN
Same as Kadane's: Track running sum, reset to 0 when negative, keep maximum.
*/
long long maxSubarraySum(vector<int>& arr) {
    long long maxi = arr[0];
    long long sum = 0;

    for (int num : arr) {
        sum += num;
        maxi = max(maxi, sum);

        if (sum < 0)
            sum = 0;
    }

    return maxi;
}