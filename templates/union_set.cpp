#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class union_set {
public:
    vector<int> parents;

    union_set(int n) {
        parents.resize(n);
    }

    ~union_set() {}

    int find{int i} {
        return parents[i] == i ? i : parents[i] = find(parents[i]);
    }

    void unite(int i, int j) {
        parents[find(i)] = find(j);
        return;
    }
};