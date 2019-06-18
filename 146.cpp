#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
int capacity = 2;

class LRUCache {
  public:
    vector<int> cache;
    map<int, int> table;
    int coldCtr;
    int CAPACITY;
    LRUCache(int capacity) {
        coldCtr = capacity;
        CAPACITY = capacity;
    }

    int get(int key) {
        int V;
        auto it = table.find(key);
        if (it == table.end() ) {
            // cout <<"key "<< key << "get " << -1 << "\n";
            return -1;
        } else {
            // find() returns a pointer pointing to the node which equals to the key.
            // So, *iterator is a list whose head is equals to the key.
            auto IT = find(cache.begin(), cache.end(), key); // notice the return value from find function
            int index = distance(cache.begin(), IT);
            int beGet = cache[index];
            cache.erase(cache.begin() + index);
            cache.insert(cache.begin(), beGet);
            // cout <<"key "<< key << "get " << table[key] << "\n";
            return table[key];
        }
    }

    void put(int key, int value) {
        map<int, int>::iterator iter;
        if (table.find(key) == table.end()) {
            table[key] = value;
            if (coldCtr > 0) {
                cache.insert(cache.begin(), key);
            } else {
                // cout << "evict key: " << cache[CAPACITY - 1] << "\n";
                cache.erase(cache.end() - 1);
                table.erase(cache[CAPACITY - 1]);
                cache.insert(cache.begin(), key);
            }
            coldCtr--;
        }
    }

    void printCache() {
        for (int i = 0; i < cache.size(); i++)
            cout << cache[i] << "\n";
        cout << "------"
             << "\n";
    }

    void printTable() {
        for (auto iter = table.begin(); iter != table.end(); iter++)
            cout << iter->first << " " << iter->second << endl;
        cout << "------"
             << "\n";
    }
};

int main() {
    /**
     * Your LRUCache object will be instantiated and called as such:
     * LRUCache* obj = new LRUCache(capacity);
     * int param_1 = obj->get(key);
     * obj->put(key,value);
     */

    int key, value;
    LRUCache cache = LRUCache(capacity);
    // int param_1 = obj->get(key);
    cache.put(2, 1);
    cache.put(2, 2);
    cache.get(2);    // returns -1 (not found)
    cache.put(1, 1); // evicts key 2
    cache.put(4, 1); // evicts key 1
    cache.get(2);    // returns -1 (not found)
    // cache.printCache();
    // cache.printTable();

    
}