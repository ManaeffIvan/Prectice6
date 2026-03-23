#include<iostream>

using namespace std;

void my_bubble_sort(int* beg, int k) {
	for (int i = 0; i < k - 1; i++) {
		for (int j = i + 1; j < k; j++) {
			if (*(beg + i) > *(beg + j)) {
				swap(*(beg + i), *(beg + j));
			}
			else {
				break;
			}
		}
	}
}

int main() {
	int n, k;

	cin >> n;

	int *a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cin >> k;

	for (int i = 0; i < n; i += k) {
		my_bubble_sort(&a[0] + i, min(n - i, k));
	}

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
		if (i % k == k - 1) {
			cout << endl;
		}
	}
	if (n % k != 0) {
		cout << endl;
	}

	delete[] a;
	return 0;
}