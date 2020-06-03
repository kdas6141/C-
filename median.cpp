#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<double> OnlineMedian(vector<int> &nums) {
	//min heap stores larger half seen so far
	priority_queue<int, vector<int>, greater<>> min_heap;
	//max heap stores smallest half seen so far
	priority_queue<int, vector<int>, less<>> max_heap;
	vector<double> res;

	for (auto n: nums) {
		min_heap.emplace(n);
		max_heap.emplace(min_heap.top());
		min_heap.pop();
		if (max_heap.size() > min_heap.size()) {
			min_heap.emplace(max_heap.top());
			max_heap.pop();
		}
		res.emplace_back(min_heap.size() == max_heap.size() ?
			0.5 *(min_heap.top() + max_heap.top()) : min_heap.top());
	}
	return res;
}

int main() {
	vector<int> nums = {1, 0, 3, 5, 2, 0, 1};
	vector<double> res;
	res = OnlineMedian(nums);
	for (auto d: res)
		cout << d << endl;
}