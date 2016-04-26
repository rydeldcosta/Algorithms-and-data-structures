#include <iostream>

using namespace std;

int main()
{
	// Speed up cin
	std::ios_base::sync_with_stdio(false);

	int num_cases, divisor, count = 0;
	cin >> num_cases >> divisor;

	while (num_cases--)
	{
		int number;
		cin >> number;

		if (number % divisor == 0)
		{
			count += 1;
		}
	}

	cout << count;
	return 0;
}
