class StockPrice {
public:
    map<int,int>mp;
    multiset<int> count;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
         if (mp.find(timestamp) != mp.end())
            count.erase(count.find(mp[timestamp]));
        count.insert(price);
        mp[timestamp]=price;
    }
    
    int current() {
        return mp.rbegin()->second;
    }
    
    int maximum() {
        return *count.rbegin();
    }
    
    int minimum() {
        return *count.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */