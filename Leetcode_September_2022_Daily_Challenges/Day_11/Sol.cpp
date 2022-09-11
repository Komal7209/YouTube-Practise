// speed => max
// efficiency => min(of all engineers chosen)
/*

Time: O(NlogN + NlogK), NlogN for sorting n engineers by decreasing of their efficiency, NlogK to iterate all engineers, each time need to perform logK for heappush/heappop.

Space: O(N + K)

*/


class Solution {
public:
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k) {
        vector<pair<int, int>> engineers;
        for (int i = 0; i < n; ++i)
            engineers.emplace_back(efficiency[i], speed[i]);
        
        sort(rbegin(engineers), rend(engineers)); // Sort by decreasing order of efficiency
        long speedSum = 0, ans = 0;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto&[e, s] : engineers) {
            speedSum += s;
            minHeap.emplace(s);
            if (minHeap.size() > k) { // Over k engineers -> remove the lowest speed engineer
                speedSum -= minHeap.top();
                minHeap.pop();
            }
            ans = max(ans, speedSum * e);
        }
        return ans % (int) (1e9 + 7);
  