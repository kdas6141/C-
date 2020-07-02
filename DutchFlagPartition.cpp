#include <iostream>
#include <vector>
#include <iterator>

using namespace std;
typedef enum {kRed, kWhite, kBlue} Color;

void DutchFlagPartition(int pivot_index, vector<Color> *A_ptr) {
	vector<Color>& A = *A_ptr;
	Color pivot = A[pivot_index];
	/*
	 * bottom group: A[0, smaller-1]
	 * middle group: A[smaller, equal-1],
	 * unclassified group: A[equal, larger-1]
	 * top group: A[larger, size(A)-1]
	 */
	int smaller = 0, equal = 0, larger = size(A);
	while (equal < larger) {
		if (A[equal] < pivot) {
			swap(A[smaller++], A[equal++]);
		}
		else if (A[equal] == pivot) {
			++equal;
		} else { // A[equal] > pivot
			swap(A[equal], A[--larger]);
		}
	} 
}

int main(){
	vector<Color> A = {kRed, kWhite, kBlue, kRed, kBlue, kWhite, kWhite};
	int pivot_index = 3;
	DutchFlagPartition(pivot_index, &A);
	for (auto a : A) {
		cout << a << " ";
	}
	cout << endl;
}