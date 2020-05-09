// Method 1
// Time complexity: O(n^2logn)
// Space complexity: O(1)
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {        
        while(stones.size() > 1){ // O(n/2)
            sort(stones.begin(), stones.end()); // O(nlogn)
            int len = stones.size();
            int tmp = abs(stones[len-1] - stones[len-2]);
            stones.pop_back(); 
            stones.pop_back();
            if(tmp != 0){
                stones.push_back(tmp);
            }
        }
        if(stones.size() == 1){
            return stones[0];
        }
        return 0;
    }
};

// Method 2: Using priority_queue
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end()); // O(n)
        
        while(pq.size() > 1){ // O(n)
            int firstHeaviest = pq.top(); // O(1)
            pq.pop(); // O(logn)
            int secondHeaviest = pq.top();
            pq.pop();
            
            int diff = firstHeaviest - secondHeaviest;
            if(diff != 0) {
                pq.push(diff);
            }
        }
        return pq.empty() ? 0 : pq.top();
    }
};
