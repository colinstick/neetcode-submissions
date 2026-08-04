class TimeMap {
private:
    map<string, set<int>> times;
    map<pair<string,int>, string> mp;
public:

    TimeMap() {
        times.clear(); mp.clear();
    }
    
    void set(string key, string value, int timestamp) {
        if(!times.contains(key)) {
            times.insert({});
        }
        times[key].insert(timestamp);
        mp[{key,timestamp}] = value;
    }
    
    string get(string key, int timestamp) {
        if(!times.contains(key)) return "";
        auto it = times[key].upper_bound(timestamp);
        if(it==times[key].begin()) {
            // nothing
            return "";
        }
        it--; 
        return mp[{key,*it}];
    }
};
