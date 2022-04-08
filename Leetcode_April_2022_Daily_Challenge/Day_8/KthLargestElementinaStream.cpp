class KthLargest {
private:
    // opposite behaviour to what we define
    priority_queue<int, vector<int>, greater<int>> pq;
    int size;
public:
    
    KthLargest(int k, vector<int> nums) {
        size=k;
        for(int i=0;i<nums.size();i++) {
            pq.push(nums[i]);
            
            if(pq.size()>k) pq.pop();//because of this kth largest element would be at top
            // k largest values are now in heap 
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>size) pq.pop();
        return pq.top();
    }
};
