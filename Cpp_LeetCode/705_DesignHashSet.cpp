#include <vector>
using namespace std;

class MyHashSet {
private:
	vector<vector<int>> hash;
	int p;
public:
    MyHashSet() {
		p = 1009;
		hash.resize(p);
    }

    void add(int key) {
		int index = key % p;

		if (hash[index].empty()){
			hash[index].push_back(key);
		} else {
			for (int i = 0; i < hash[index].size(); i++){
				if (hash[index][i] == key){
					return;
				}
			}
			hash[index].push_back(key);
		}
    }

    void remove(int key) {
        int index = key % p;
		if (hash[index].empty()){
			return;
		} else {
			for (int i = 0; i < hash[index].size(); i++){
				if (hash[index][i] == key){
					hash[index].erase(hash[index].begin() + i);
					return;
				}
			}
		}
    }

    bool contains(int key) {
		int index =	key % p;
		if (hash[index].empty()){
			return false;
		} else {
			for (int i = 0; i < hash[index].size(); i++){
				if (hash[index][i] == key){
					return true;
				}
			}
			return false;
		}
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
