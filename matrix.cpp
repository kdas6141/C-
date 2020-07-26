#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

//build matrix
void create_matrix(vector<vector<int>>& matrix, int n, int m) {
	srand (time(NULL));
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			matrix[i][j] = rand() % 10;
		}
	}
}

//print matrix
void print_matrix(vector<vector<int>>& matrix, int n, int m) {

	cout << "Output of matrix: " << endl;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cout << matrix[i][j] << (j==m-1 ? "" : " ");
		}
		cout << endl;
	}
}

//print diagonal matrix
void print_diagonal_matrix(vector<vector<int>>& matrix, int n, int m) {
	int l = n < m ? n : m;

	cout << "Output of diagonal matrix: " << endl;
	for (int i=0; i<l; i++) {
		cout << matrix[i][i] << (i==l-1 ? "" : " ");
	}
	cout << endl;
}

//print reverse diagonal matrix
void print_reverse_diagonal_matrix(vector<vector<int>>& matrix, int n, int m) {
	int l = n < m ? n : m;

	cout << "Output of reverse diagonal matrix: " << endl;
	for (int i=l-1; i>=0; i--) {
		cout << matrix[i][i] << (i==0 ? "" : " ");
	}
	cout << endl;
}

//reverse diagonal element of matrix
void reverse_diagonal_position_matrix(vector<vector<int>>& matrix, int n, int m) {
	int l = n < m ? n : m;

	for (int i=0, j=l-1; i<j; i++, j--) {
		swap(matrix[i][i], matrix[j][j]);
	}
}

int main() {
	int n=9, m=9;
	vector<vector<int>> matrix(n, vector<int> (m, 0));
	create_matrix(matrix, n, m);
	print_matrix(matrix, n, m);
	print_diagonal_matrix(matrix, n, m);
	print_reverse_diagonal_matrix(matrix, n, m);
	reverse_diagonal_position_matrix(matrix, n, m);
	print_diagonal_matrix(matrix, n, m);
	print_reverse_diagonal_matrix(matrix, n, m);
	print_matrix(matrix, n, m);
}