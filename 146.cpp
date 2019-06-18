#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
int capacity = 4;

class LRUCache {
  public:
    vector<int> cache;
    map<int, int> table;
    int coldCtr;
    LRUCache(int capacity) {
        coldCtr = capacity;
    }

    int get(int key) {
        return 0;
    }

    void put(int key, int value) {
        coldCtr--;
        map<int, int>::iterator iter;
        if (table.find(key) == table.end()) {
            table[key] = value;
            if (coldCtr >= 0) {
                cache.insert(cache.begin(), key);
            } else {
                cache.erase(cache.end() - 1);
                cache.insert(cache.begin(), key);
            }
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
    LRUCache *obj = new LRUCache(capacity);
    // int param_1 = obj->get(key);
    obj->put(1, 1);
    obj->put(2, 2);
    obj->put(3, 3);
    obj->printCache();
    obj->put(3, 2);
    obj->put(4, 6);
    obj->printCache();
    obj->put(7, 6);
    obj->printCache();
    obj->put(9, 6);
    obj->printCache();
    // obj->printTable();

}