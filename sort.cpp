#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &nums, int low, int high) {
	int pivot = nums[high];
	int i = (low-1);
	for (int j=low; j<=high; j++) {
		if (nums[j] < pivot) {
			i++;
			swap(nums[i], nums[j]);
		}
	}
	swap(nums[i+1], nums[high]);
	return i+1;
}

void quickSort(vector<int> &nums, int low, int high) {
	if (low < high) {
		int pi = partition(nums, low, high);
		quickSort(nums, low, pi-1);
		quickSort(nums, pi+1, high);
	}
}

void printNums(vector<int> &nums, string header) {
	cout << header;
	for (auto n: nums) {
		cout << n << " ";
	}
}

int main() {
	vector<int> nums = {10, 3, 7, 100, 2, 6, 8, 9, 5, 4, 3};

	printNums(nums, "\nNums before sort: ");
	quickSort(nums, 0, nums.size()-1);
	printNums(nums, "\nNums after sort: ");

	return 0;
}