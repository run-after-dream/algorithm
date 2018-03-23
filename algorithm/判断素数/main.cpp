#include <iostream>
#include <cmath>
using namespace std;

int is_prime(int n);

int main()
{
    cout << is_prime(12001) << endl;
    return 0;
}

int is_prime(int n)
{
    double k = sqrt(n);
    for (int i = 2; i < k; ++i)
    {
        if(n%i == 0)
        {
            return i;
        }
    }
    return 0;
}