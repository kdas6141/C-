#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<pair<int, int>, int> adjlist_edge;

int main() {
	auto comp = [](adjlist_edge a, adjlist_edge b) { return a.second > b.second;};
	priority_queue<adjlist_edge, vector<adjlist_edge>, decltype(comp)> adjlist_pq(comp);	
}