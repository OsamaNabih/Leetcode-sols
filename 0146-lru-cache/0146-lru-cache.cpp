class LRUCache {
private:
    unordered_map<int, int> mp;
    unordered_map<int, pair<int,int>> umap;
    int capacity;
    int currCapacity;
    int oldestTime;
    int now;
    bool isKeyInMap(int key) {
        return umap.find(key) != umap.end();
    }

    bool isMaxCapacity() {
        return currCapacity == capacity;
    }

    void insertKey(int key, int value) {
        umap[key] = make_pair(value, now);
        mp[now++] = key;
        currCapacity++;
    }
public:
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->currCapacity = 0;
        this->now = 0;
        this->oldestTime = 0;
    }
    
    int get(int key) {
        if (!isKeyInMap(key)) return -1;
        // Key already exists
        // Get value and timestamp from umap
        auto [val, time] = umap[key];
        
        // Make new entry with current time
        mp[now] = mp[time];
        
        // Update time in umap
        umap[key].second = now;
        now++;
        return val;
    }
    
    void put(int key, int value) {
        // cout << "Putting: " << key << endl;
        // Check if key already in map
        // If it is, we just update it
        if (this->get(key) != -1) {
            umap[key].first = value;
            // cout << "Updated existing \n";
            return;
        }

        // Check if map is full
        if (!isMaxCapacity()) {
            // cout << "Happy insert\n";
            insertKey(key, value);
            return;
        }
        
        // cout << "Removal and insert new\n";
        // Key not in map, need to remove oldest

        while(mp.find(oldestTime) == mp.end() || umap[mp.find(oldestTime)->second].second != oldestTime) {
            oldestTime++;
        }
        int removedKey = mp[oldestTime];
        mp.erase(oldestTime);
        umap.erase(umap.find(removedKey));
        currCapacity--;
        insertKey(key, value);
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */