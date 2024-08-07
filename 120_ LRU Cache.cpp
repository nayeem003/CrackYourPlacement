class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) {
            return -1;
        } else {
            // Move the accessed key-value pair to the front of the list
            usage.splice(usage.begin(), usage, it->second.second);
            return it->second.first;
        }
    }
    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            // Update the value and move to the front of the list
            it->second.first = value;
            usage.splice(usage.begin(), usage, it->second.second);
        } else {
            if (cache.size() >= capacity) {
                // Remove the least recently used element
                int lruKey = usage.back();
                usage.pop_back();
                cache.erase(lruKey);
            }
            // Insert the new key-value pair
            usage.push_front(key);
            cache[key] = {value, usage.begin()};
        }
    }
private:
    int capacity;
    std::list<int> usage; // Stores keys in order of usage
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> cache; // Stores key-value pairs and their usage list iterators
};
