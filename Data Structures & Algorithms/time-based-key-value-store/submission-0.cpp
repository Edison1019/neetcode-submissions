class TimeMap {
public:
    unordered_map<string, map<int, string>> um;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        um[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = um[key].upper_bound(timestamp);
        return it == um[key].begin() ? "" : prev(it)->second;
    }
};
