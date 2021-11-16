// kadai1.cpp
#define CPP2_PRIME_UPPER_LIMIT 1000000
#include <iostream>
using namespace std;

/* --------------------------------------------------------------- */
/*
* is_prime
*
* 与えられた正整数numが素数ならtrueそれ以外ならfalseを返す
*
*/
/* -------------------------------------------------------------- */

bool is_prime(int num) {
    if(num == 1){
        return false;
    }
	for (int i = 2; i < num; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

/* --------------------------------------------------------------- */
/*
* nth_prime
*
* 与えられた正整数 a と d と n に対して、この等差数列に含まれる n 番目の
* 素数を返す。
*
* TODO: この nth_prime 関数を実装せよ。必要であれば他に関数や
* ファイルを作成せよ。
*/
/* -------------------------------------------------------------- */
int nth_prime(int a, int b, int n) {
    
	int count = 0;
	int e = a;
	while (e < CPP2_PRIME_UPPER_LIMIT) {
		
		if (is_prime(e)) {
			//printf("%dは素数です\n", e);
			count++;
		}
		if (count == n) {
			break;
			cout << 0;
		}

		e += b;
	}
	return e;
}

int main()
{
	cout << nth_prime(259, 170, 40) << " " << "22699" << endl;
    cout << nth_prime(367, 186, 151) << " " << "92809" << endl;
    cout << nth_prime(179, 10, 203) << " " << "6709" << endl;
    cout << nth_prime(271, 37, 39) << " " << "12037" << endl;
    cout << nth_prime(103, 230, 1) << " " << "103" << endl;
    cout << nth_prime(27, 104, 185) << " " << "93523" << endl;
    cout << nth_prime(253, 50, 85) << " " << "14503" << endl;
    cout << nth_prime(1, 1, 1) << " " << "2" << endl;
    cout << nth_prime(9075, 337, 210) << " " << "899429" << endl;
    cout << nth_prime(307, 24, 79) << " " << "5107" << endl;
    cout << nth_prime(331, 221, 177) << " " << "412717" << endl;
    cout << nth_prime(269, 58, 102) << " " << "25673" << endl;

	cin.get();
	cin.get();
	return 0;
}
