#include <iostream>

int main() {
	//秘書の配列(数値は秘書の能力, 大きいほど能力が高い=採用したい)
	int secretaries[]
		= { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };

	//採用した秘書の能力の合計値
	int secretarySum = 0;

	for (int i = 0; i < 1000; i++) {

		//現在採用中の秘書の能力
		int currentSecretary = 0;

		//オンライン雇用アルゴリズム

		secretarySum += currentSecretary;
	}

	//採用した秘書の能力の平均を表示
	std::cout << (float)secretarySum / 1000.0f << std::endl;
}
