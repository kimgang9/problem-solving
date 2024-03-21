#include <iostream>
#include <fstream>
#include <string>
#include <vector>

long long plus_n(long long num) {
    int number = 0;
    while (num != 1) {
        if (num % 2 == 0)
            num /= 2;
        else
            num = (num * 3) + 1;
        number++;
    }
    return number;
}

int main() {
    std::ifstream file("3nplus1.inp"); // 파일 열기
    std::ofstream file2("3nplus1.out"); // 파일 출력
    if (!file) {
        std::cout << "파일 오류" << std::endl;
        return 1;
    }

    std::vector<std::pair<long long, long long>> inputValues;

    // 파일에서 입력값을 벡터에 저장
    long long num1, num2;
    while (file >> num1 >> num2) {
        inputValues.push_back(std::make_pair(num1, num2));
    }

    for (const auto& input : inputValues) {
        long long f1 = input.first;
        long long f2 = input.second;
        long long num1 = f1, num2 = f2;

        if (num1 > num2)
            std::swap(num1, num2); // 자리 정렬

        long long maxnumber1 = 0;

        for (long long i = num1; i <= num2; i++) // 높은값 저장
            maxnumber1 = std::max(maxnumber1, plus_n(i));

        file2 << f1 << " " << f2 << " " << maxnumber1 + 1 << std::endl;
        std::cout << f1 << " " << f2 << " " << maxnumber1 + 1 << std::endl;
    }

    file.close();
    file2.close();
    return 0;
}
