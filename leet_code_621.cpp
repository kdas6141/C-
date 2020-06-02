#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> umap;
        for (auto t: tasks)
            umap[t]++;
        priority_queue<int> pq;
        for (auto um: umap)
            pq.push(um.second);
        int intv = 0;
        while (!pq.empty()) {
            vector<int> count;
            for (int i=0; i<n+1; i++) {
                int t = pq.top(); pq.pop();
                count.push_back(t);
            }
            for (auto c: count) {
                //if (--c>0)
                    pq.push(c);
            }
            intv += pq.empty() ? count.size() : n+1;
        }
        return intv;
    }
};

int main() {
    vector<char> tasks = {'A', 'B', 'C'};
    int n = tasks.size();
    Solution s;
    cout << "Least Interval: " + s.leastInterval(tasks, n);
}