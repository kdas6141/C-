#include <iostream>
#include <string>
#include <numeric>

using namespace std;

string IntToString(int x) {
	bool is_negative = false;
	if (x < 0) {
		is_negative = true;
	}

	x = abs(x);
	string s;
	do {
		s += '0' + (x % 10);
		x /= 10;
	} while (x);

	s += is_negative ? "-" : "";

	return {rbegin(s), rend(s)};
}

int StringToInt(const string& s) {
	return (s[0] == '-' ? -1 : 1) * accumulate(begin(s) + (s[0] == '-'), end(s), 0,
		[](int running_sum, char c) { return running_sum * 10 + c - '0';});
}

int main() {
	cout << "IntToString of 345: " << IntToString(345) << endl;
	cout << "IntToString of -345: " << IntToString(-345) << endl;
	cout << "StringToInt of \"345\": " << StringToInt("345") << endl;
	cout << "StringToInt of \"-345\": " << StringToInt("-345") << endl;

}
