
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int left = 0;
		int right = arr.size() - 1;
		while (right - left >= k) {
			if ((arr[right] - x )>= (x- arr[left])) { // we are checking on the basis of difference
				right--;
			} else {
				left++;
			}
		}
		vector<int>result;
		for (int i = left; i <= right; i++) {
			result.push_back(arr[i]);
		}
		return result;
        
    }
};




/*
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    
    priority_queue<pair<int, int>>pq;
        
        for( int i =0; i<arr.size(); i++){
            
            pq.push({abs(arr[i]-x), arr[i]});
            if(pq.size() > k)
                pq.pop();
        }
        
        vector<int>result;
        while(pq.size() >0){
			result.push_back(pq.top().second);
            pq.pop();

        }
        sort(result.begin(), result.end());
    	return result;
    }
};

*/