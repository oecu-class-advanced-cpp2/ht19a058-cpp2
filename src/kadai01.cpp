// kadai1.cpp
#include <iostream>
using namespace std;

int nth_prime(int a,int b,int n) {
	int flag = 0;
	int count=0;
	int e = a;
	while(e<100000){
		if (e == 1) {
			flag = 1;
		}
		for (int i = 2; i < e; i++) {
			if (e%i == 0) {
				flag = 1;
			}
		}
		if (flag == 0) {
			count++;
		}
		if (count == n) {
			break;
			cout << 0;
		}
		flag = 0;
		e += b;
	}
	return e;
}

int main()
{
	cout << nth_prime(271,37,39) << endl;

	cin.get();
    cin.get();
    return 0;
}
