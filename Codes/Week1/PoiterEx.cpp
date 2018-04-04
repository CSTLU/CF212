#include <iostream>
#include <math.h>
using namespace std;
bool isPrime(const int &);
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int * ptr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>*(ptr+i);
		if(isPrime(*(ptr+i)))
			cout<<" "<<*(ptr+i);
	}
}

bool isPrime(const int &n)
{
	if (n < 0)
		return false;
	for (int i = 2; i <= sqrt(n); ++i)
	{
		if (n % i == 0)
			return false;
	}

	return true;
}