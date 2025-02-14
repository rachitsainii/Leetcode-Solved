class ProductOfNumbers {
public:
    vector<int> n;
    ProductOfNumbers() {
        n.clear();
    }
    
    void add(int num) {
        n.push_back(num);
    }
    
    int getProduct(int k) {
        int product = 1;
        int length = n.size();
        for(int i = length - k; i < length; i++){
            product *= n[i];
        }

        return product;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */