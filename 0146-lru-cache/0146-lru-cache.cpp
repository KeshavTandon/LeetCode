class LRUCache {
public:
    list<int>dll;
    unordered_map<int,pair<list<int>::iterator,int>>mp;
    int n;
    
    LRUCache(int capacity) {
        n=capacity;
    }
    
    void markRecentlyUsed(int key)
    {
        dll.erase(mp[key].first);
        
        dll.push_front(key);
        
        mp[key].first=dll.begin(); //it will give address
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
            return -1;
        else {
            int val=mp[key].second;
            markRecentlyUsed(key);
        }
        return mp[key].second;
    }
    
    void put(int key, int value) {
        if(mp.find(key)==mp.end())
        {
            dll.push_front(key);
            mp[key]={dll.begin(),value};
            n--;
        }
        else{
            mp[key].second=value;
            markRecentlyUsed(key);
        }
        if(n<0)
        {
            int keyToBeDeleted=dll.back();
            dll.erase(mp[keyToBeDeleted].first);
            mp.erase(keyToBeDeleted);
            n++;
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */