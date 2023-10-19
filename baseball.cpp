#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	while (true) {
		int low = 1;
		int high = 9;

		srand(time(0));
		int temp1 = rand();
		int temp2 = rand();
		int temp3 = rand();
		int num1 = 0;
		int num2 = 0;
		int num3 = 0;

		do {
			num1 = temp1 % (high - low + 1) + low;
			num2 = temp2 % (high - low + 1) + low;
			num3 = temp3 % (high - low + 1) + low;
		} while (num1 == num2 || num2 == num3 || num1 == num3);

		cout << num1 << " " << num2 << " " << num3 << "\n";

		int com[3] = { num1,num2,num3 };

		cout << "숫자 야구 게임을 시작합니다." << "\n";
		while (true) {
			cout << "숫자를 입력해주세요 : ";
			int f, s, t;
			cin >> f >> s >> t;
			try {
				if (f < 1 || f>9 || s < 1 || s>9 || t < 1 || t>9) {
					throw 0;
				}
			}
			catch (int x) {
				return 0;
			}
			
			int user[3] = { f,s,t };
			int strike = 0;
			int ball = 0;

			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (user[i] == com[j]) {
						if (i == j) strike++;
						else ball++;
					}
				}
			}
			
			if (strike == 3) {
				cout << "3스트라이크" << "\n";
				cout<<"3개의 숫자를 모두 맞히셨습니다! 게임 종료" << "\n";
				cout << "게임을 새로 시작하려면 1, 종료하려면 2를 입력하세요.";
				int end;
				try {
					cin >> end;
					if (end < 1 || end>2) {
						throw false;
					}

					if (end == 1) {
						continue;
					}
					else {
						return 0;
					}
				}
				catch (bool x) {
					return 0;
				}
			}
			else if (ball == 0 && strike == 0) {
				cout << "낫싱" << "\n";
			}
			else if (ball == 0) {
				cout << strike << "스트라이크"<<"\n";
			}
			else if (strike == 0) {
				cout << ball << "볼" << "\n";
			}
			else {
				cout << ball << "볼 " << strike << "스트라이크" << "\n";
			}
			
		
		}

	}

	return 0;
}