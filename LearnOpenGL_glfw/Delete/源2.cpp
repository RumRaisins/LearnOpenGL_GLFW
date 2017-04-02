#include<iostream>
#include<math.h>
using namespace std;

void sum(int* p,const int n) {
	int j = 0;
	for (int i = 0; i < n; i++) {
		*p +=2*(n-i)+j;
		j = *p / 10;
		*p++ %= 10;
		
	}
}
int main() {

	int n;
	int *p;
	while (cin >> n) {
		p = new int[n];
		for (int i = 0; i < n; i++)
		{
			*p++ = 0;
		}
		p = p - n;
		sum(p, n);
		p += n;
		for (int i = 0; i < n; i++)
		{
			
			cout<<*--p;
		}
		cout << endl;
		delete[]p;
	}
	
	return 0;
}