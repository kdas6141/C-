#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void findmode(vector<int> &arr, vector<int> &r) {
	unordered_map<int, int> umap;
	int mmode = 0;
	for (auto a: arr) {
		umap[a]++;
		mmode = max(mmode, umap[a]);
	}
	
	for (auto u: umap) {
		if (mmode == u.second)
			r.push_back(u.first);
	}
}

int main() {
	vector<vector<int>> input_a = {{10, 9, 2, 11, 3, 3, 4, 16, 7, 2},
			   					   {11, 12, 5, 10, 9, 6, 5}};
	int i=0;
	for (auto a : input_a) {
		vector<int> res;
		findmode(a, res);
		cout << "Mode" << (res.size()>1 ? "s" : "") << " of array( " << i << " )is: ";
		for(auto r: res) {
			cout << r << " ";
		}
		cout << endl;
		i++;
	}

	return 0;
}