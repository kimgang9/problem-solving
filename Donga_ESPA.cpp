#include <iostream>
#include <fstream>
#include <string>

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
    std::ifstream file("3nplus1.inp");
    if (!file) {
        std::cout << "파일 오류" << std::endl;
        return 1;
    }

    long long num1, num2, num3, num4;
    file >> num1 >> num2 >> num3 >> num4;
    long long f1 = num1; long long f2 = num2; long long f3 = num3; long long f4 = num4;
    if (num1 > num2)
        std::swap(num1, num2);

    if (num3 > num4)
        std::swap(num3, num4);

    long long maxnumber1 = 0;
    long long maxnumber2 = 0;

    for (long long i = num1; i <= num2; i++)
        maxnumber1 = std::max(maxnumber1, plus_n(i));

    for (long long i = num3; i <= num4; i++)
        maxnumber2 = std::max(maxnumber2, plus_n(i));

    std::ofstream file2("3nplus1.out");
    file2 << f1 << " " << f2 << " " << maxnumber1 + 1 << std::endl;
    file2 << f3 << " " << f4 << " " << maxnumber2 + 1 << std::endl;
    
    return 0;
}