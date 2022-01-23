#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <functional>
using namespace std;

namespace cpp2 {
	/* --------------------------------------------------------------------- */
	/*
	mcxi

	mcxi 記法を解析するクラスです。
	*/
	/* --------------------------------------------------------------------- */
	class mcxi {
	public:
		/* ----------------------------------------------------------------- */
		/*
		mcxi

		指定された文字列を解析して、オブジェクトを初期化します。
		以下の場合には例外が創出されます。

		1. [2-9,m,c,x,i] 以外の文字が出現した場合
		2. 2 文字続けて数字 (2-9) が出現した場合
		3. m, c, x, i がこの順序で出現しなかった場合
		ただし、例えば mx のように、特定の文字をスキップする事は許容
		されます。
		*/
		/* ----------------------------------------------------------------- */
		mcxi(const std::string& s) : value_(0) {
			int num =0;
			int sum = 0;
			int u = 1;
			int m = 0; int c = 0; int x = 0; int i = 0;
			int mt = s.find('m'); int ct = s.find('c'); int xt = s.find('x'); int it = s.find('i');
			string p[4] = { "m","c","x","i" };
			for (char i:s) {
				if (i=='m') {
					m++;
				}
				else if (i == 'c') {
					c++;
				}
				else if (i == 'x') {
					x++;
				}
				else if (i == 'i') {
					i++;
				}
			}

			for (auto pos = s.begin(); pos != s.end(); ++pos) {
				
				if (*pos == '1' || *pos == '0' ||m>1 || c>1 || x>1 || i>1) {
					break;
				}
				if (*pos >= '2' && *pos <= '9') {
					num = *pos - '0';

				}
				else
				{
					
					u = unit(*pos);
					value_ += std::max(num, 1)*u;
					num = 0;
					//sum += num*u;
				}
			}
		}


		/* ----------------------------------------------------------------- */
		/*
		operator+

		2 つのオブジェクトの加算結果を取得します。
		*/
		/* ----------------------------------------------------------------- */
		mcxi operator+(const mcxi& rhs) {
			mcxi tc(rhs);
			tc.value_ = this->value_ + rhs.value_;
			return tc;
		}

		/* ----------------------------------------------------------------- */
		/*
		to_string

		現在の値を mcxi 記法に変換します。
		*/
		/* ----------------------------------------------------------------- */
		std::string to_string() const {
			std::string mcxi;
			int num1 = value_;
			string s[4] = { "m","c","x","i" };
			int kotei = 1000;
			for (int i = 0; i < 4; i++) {
				if (num1 / kotei >= 1) {
					if (num1 / kotei == 1) {
						mcxi += s[i];
						num1 = num1 - kotei;
					}
					else {
						mcxi += std::to_string(num1 / kotei) + s[i];
						num1 = num1 - ((num1 / kotei) * kotei);
					}
				};
				kotei = kotei / 10;
			}
			return mcxi;
		}

		void debug_mcxi() {
			std::cout << "value_: " << value_ << std::endl;
		}

	private:
		int unit(char s){
			switch (s) {
			case 'm':return 1000; break;
			case 'c':return 100; break;
			case 'x':return 10; break;
			case 'i':return 1; break;
			}
			return - 1;
		}

	private:
		int value_;
	};
}

bool hikaku(string num) {
	string list[9] = { "3x","x","6cx","5m9c9x9i","m","9m9c9x9i","mi","mx","9m9c9x9i" };
	for (int i = 0; i < 9; i++) {
		if (num == list[i]) {
			return true;
			break;
		}
	}
	return false;
}

int main() {

	cpp2::mcxi a0("xi");
	cpp2::mcxi b0("x9i");
	auto result0 = a0 + b0;
	cout << hikaku(result0.to_string()) << endl;


	cpp2::mcxi a1("i");
	cpp2::mcxi b1("9i");
	auto result1 = a1 + b1;
	cout << hikaku(result1.to_string()) << endl;

	cpp2::mcxi a2("c2x2i");
	cpp2::mcxi b2("4c8x8i");
	auto result2 = a2 + b2;
	cout << hikaku(result2.to_string()) << endl;

	cpp2::mcxi a3("m2ci");
	cpp2::mcxi b3("4m7c9x8i");
	auto result3 = a3 + b3;
	cout << hikaku(result3.to_string()) << endl;

	cpp2::mcxi a4("9c9x9i");
	cpp2::mcxi b4("i");
	auto result4 = a4 + b4;
	cout << hikaku(result4.to_string()) << endl;

	cpp2::mcxi a5("i");
	cpp2::mcxi b5("9m9c9x8i");
	auto result5 = a5 + b5;
	cout << hikaku(result5.to_string()) << endl;

	cpp2::mcxi a6("m");
	cpp2::mcxi b6("i");
	auto result6 = a6 + b6;
	cout << hikaku(result6.to_string()) << endl;

	cpp2::mcxi a7("i");
	cpp2::mcxi b7("m");
	auto result7 = a7 + b7;
	cout << hikaku(result7.to_string()) << endl;

	cpp2::mcxi a8("m9i");
	cpp2::mcxi b8("i");
	auto result8 = a8 + b8;
	cout << hikaku(result8.to_string()) << endl;

	cpp2::mcxi a9("9m8c7xi");
	cpp2::mcxi b9("c2x8i");
	auto result9 = a9 + b9;
	cout << hikaku(result9.to_string()) << endl;

	cin.get();
	cin.get();
}