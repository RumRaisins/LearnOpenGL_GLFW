#include<iostream>
#include<math.h>
using namespace std;
int main() {

	int sum;
	int n;
	while (cin >> n) {
		sum = 0;
		 for(int i=1;i<=n;i++){
		for (int j = 1; j <= i; j++)
		{
			sum += (int)(2 * pow(10, j-1));
		}
		 }
		cout<<sum<<endl;
	}

	return 0;
}
