#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

vector<int> Multiply(vector<int> &n1, vector<int> &n2) {
	const int sign = (n1.front()<0) ^ (n2.front()<0) ? -1 : 1;
	n1.front() = abs(n1.front()), n2.front() = abs(n2.front());

	vector<int> r(size(n1) + size(n2), 0);
	//multiply two vectors
	for (int i=size(n1)-1; i>=0; i--) {
		for (int j=size(n2)-1; j>=0; j--) {
			r[i+j+1] += n1[i] * n2[j];
			r[i+j] += r[i+j+1] / 10;
			r[i+j+1] = r[i+j+1] % 10;
		} 
	}
	//remove the leading zeros
	r = {
		find_if_not(begin(r), end(r), [](int a){return a==0;}),
		end(r)};
	if (empty(r)){
		return {0};
	}
	r.front() *= sign;
	return r;
}

int main() {
	vector<int> n1 = {1, 2, 3};
	vector<int> n2 = {9, 8, 7};
	vector<int> r1 = Multiply(n1, n2);
	cout << "both positive: " << endl;
	for (int i=0; i<size(r1); i++)
		cout << r1[i] << " ";
	cout << endl;

	vector<int> n11 = {-1, 2, 3};
	vector<int> n21 = {9, 8, 7};
	vector<int> r11 = Multiply(n11, n21);
	cout << "one positive: " << endl;
	for (int i=0; i<size(r11); i++)
		cout << r11[i] << " ";
	cout << endl;

	vector<int> n12 = {-1, 2, 3};
	vector<int> n22 = {-9, 8, 7};
	vector<int> r12 = Multiply(n12, n22);
	cout << "both negative: " << endl;
	for (int i=0; i<size(r12); i++)
		cout << r12[i] << " ";
	cout << endl;

	vector<int> n13 = {0};
	vector<int> n23 = {-9, 8, 7};
	vector<int> r13 = Multiply(n13, n23);
	cout << "one zero: " << endl;
	for (int i=0; i<size(r13); i++)
		cout << r13[i] << " ";
	cout << endl;

	return 0;
}