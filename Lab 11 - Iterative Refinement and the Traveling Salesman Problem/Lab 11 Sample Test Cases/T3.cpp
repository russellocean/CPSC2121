#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <ctime>
using namespace std;

double tspRefine();

int main()
{
    double best_len = 999999999;
    clock_t start, end;
    start = clock();
    best_len=tspRefine();
    end = clock();

    //ASSERT_NEAR(best_len, 169.478, 0.001);
    if (abs(best_len - 169.478) > 0.001)
    {
        cout << "expected/correct value for best_len is 169.478 (+/- 0.001), actual value when testing " << best_len << ".\n";
        return 1;
    }
    if ((end - start) / (double)CLOCKS_PER_SEC > 3.0)
    {
        cout << "tspRefine() must return a result in less than 3 seconds, runtime is " << (end - start) / (double)CLOCKS_PER_SEC << " seconds.\n";
        return 1;
    }
    cout << "Passed" << std::endl;
    return 0;
}