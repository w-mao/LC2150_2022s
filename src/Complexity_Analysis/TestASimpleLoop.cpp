#include <iostream>
using namespace std;

int testASimpleLoop(){
	int a[5] = {0, 1, 2, 3, 4};

	// Case 1
	int sum1 = 0;
	for(int i = 0; i<5; i++){
		sum1 += a[i];
	}
	// cout << i; // Syntax error
	cout << "sum1 is " << sum1 << endl;


	// Case 2
	int ii;
	int sum2;

	for(ii = sum2 = 0; ii<5; ){
		sum2 += a[ii];
		ii++;
	}
	cout << "ii is " << ii << endl;
	cout << "sum2 is " << sum2 << endl;

	return 0;
}
