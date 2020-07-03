#include <iostream>
#include <algorithm>

//1. repalce each 'a' with two 'd's
//3. delete each 'b' 
using namespace std;

void ReplaceAndRemove(vector<char> &s){
	int wi=0, ac=0;
	//forward
	for (int i=0; i<size(s); i++) {
		if (s[i] != 'b')
			s[wi++] = s[i];
		if (s[i] == 'a')
			++ac;
	}
	//backward
	int ci=wi-1;
	wi=wi+ac-1;
	s.resize(wi+1);
	while (ci>=0) {
		if (s[ci]=='a') {
			s[wi--] = 'd';
			s[wi--] = 'd';
		} else {
			s[wi--] = s[ci];
		}
		--ci;
	}
}

int main(){
	vector<char> s={'a', 'c', 'd', 'b', 'b', 'c', 'a'};
	 
	cout << "Before: " << endl;
	for (int i=0; i<size(s); i++)
		cout << s[i] << (i == size(s)-1 ? "" : ",");
	ReplaceAndRemove(s);
	cout << endl << "After: " << endl;
	for (int i=0; i<size(s); i++)
		cout << s[i] << (i == size(s)-1 ? "" : ",");
} 