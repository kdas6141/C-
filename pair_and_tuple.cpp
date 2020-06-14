#include <iostream>
#include <tuple>
#include <string>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pi;
typedef pair<pair<int, int>, int> adjlist_edge;

tuple<int, double, string>  func1() {
	tuple<int, double, string> res(7, 9.8, "Sample text");

	return res;
}

priority_queue<pair<int, int>> func2() {

	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(10, 200));
	pq.push(make_pair(20, 100));
	pq.push(make_pair(15, 400));

	return pq;
}

priority_queue<pi, vector<pi>, greater<pi>> func3() {

	priority_queue<pi, vector<pi>, greater<pi>> pq;
	pq.push(make_pair(10, 200));
	pq.push(make_pair(20, 100));
	pq.push(make_pair(15, 400));

	return pq;
}

int main() {
	tuple<int, double, string> r = func1();
	priority_queue<pair<int, int>> pqn = func2();
	priority_queue<pi, vector<pi>, greater<pi>> pqx = func3();

	cout << "tuple<0>: " << get<0> (r) << " tuple<1>: " << get<1> (r) << " tuple<2>: " << get<2> (r) << endl;
	cout << "Max heap - pair<0>: " << pqn.top().first << " pair<1>: " << pqn.top().second << endl;
	cout << "Min heap - pair<0>: " << pqx.top().first << " pair<1>: " << pqx.top().second << endl;

	auto comp = [](adjlist_edge a, adjlist_edge b) { return a.second > b.second;};
	priority_queue<adjlist_edge, vector<adjlist_edge>, decltype(comp)> adjlist_pq(comp);	
}