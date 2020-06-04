#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
	struct Endpoint {
		bool is_closed;
		int val;
	};
	Endpoint left, right;
};

vector<Interval> UnionOfIntervals(vector<Interval> &intervals) {
	if (intervals.empty()) {
		return {};
	}

	//sort intervals according to left endpoints
	sort(begin(intervals), end(intervals),
		[](const Interval& a, const Interval& b) {
			if (a.left.val != b.left.val) {
				return a.left.val < b.left.val;
			}
			return a.left.is_closed && !b.left.is_closed;
		});

	vector<Interval> res;
	for(Interval i: intervals) {
		if (!res.empty() &&
			(i.left.val < res.back().right.val ||
				(i.left.val == res.back().right.val &&
					(i.left.is_closed || res.back().right.is_closed)
				)
			)
		) {
			if (i.right.val > res.back().right.val ||
				(i.right.val == res.back().right.val && i.right.is_closed)
			) {
				res.back().right = i.right;
			}
		} else {
			res.emplace_back(i);
		}
	}
	return res; 
}

int main() {
	vector<Interval> intervals = {
									{{false, 0}, {false, 3}},
									{{true, 1}, {true, 1}},
									{{true, 2}, {true, 4}},
									{{true, 3}, {false, 4}},
									{{true, 5}, {false, 7}},
									{{true, 7}, {false, 8}},
									{{true, 8}, {false, 11}},
									{{false, 9}, {true, 11}},
									{{true, 12}, {true, 14}},
									{{false, 12}, {true, 16}},
									{{false, 13}, {false, 15}},
									{{false, 16}, {false, 17}}
								};

	vector<Interval> res = UnionOfIntervals(intervals);
	for (Interval r: res) {
		cout << r.left.val << " "  << r.left.is_closed << " " << r.right.val << " " << r.right.is_closed;
	}
}