class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    set<int> numbers;
    SmallestInfiniteSet() {
        for(int i = 1; i <= 1000; i++){
            numbers.insert(i);
             minHeap.push(i);
        }
    }
    
    int popSmallest() {
        int ans = minHeap.top();
        minHeap.pop();
        numbers.erase(ans);
        return ans;
    }
    
    void addBack(int num) {
        if(numbers.find(num)== numbers.end()){
            minHeap.push(num);
            numbers.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */