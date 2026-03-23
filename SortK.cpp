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











#include<bits/stdc++.h>

using namespace std;

string clean_str(string s) {
	string ans = "", s1 = "";
	int i = 0;
	while (i < s.length() && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')) {
		i++;
	}
	for (; i < s.length(); i++) {
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n') {
			s1 += s[i];
		}
		else {
			ans += s1 + s[i];
			s1 = "";
		}
	}
	return ans;
}

bool check_is_fp(string s) {
	s = clean_str(s);
	int cnt_sign = 0;
	bool is_end = false, first_simb = true, before_point = false, before_e = false;
	
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '.') {
			if (before_point) {
				return false;
			}
			before_point = true;
		}
		else if (s[i] == '+' || s[i] == '-') {
			cnt_sign++;
			if (!first_simb && s[i - 1] != 'e' && s[i - 1] != 'E') {
				return false;
			}
		}
		else if (s[i] == 'e' || s[i] == 'E') {
			if (first_simb || before_e) {
				return false;
			}
			before_e = true;
		}
		else if (int(s[i]) < int('0') || int(s[i]) > int('9')) {
			return false;
		}
		else {
			first_simb = false;
		}
		
	}
	
	return true;
}

int main() {
	string s;
	cin >> s;

	cout << s << endl;
	cout << (check_is_fp(s)? "" : "not ") << "a floating-point number" << endl;

	cout << endl;
	
    
	return 0;
}