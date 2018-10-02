#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int number;
int pAmount[] = {500, 100, 50, 10, 5, 1};

int main()
{
	
	freopen("input.txt", "r", stdin);
	
	cin >> number;
	int amount = 1000 - number;
	int result = 0;
	for(int i = 0; i<6; i++)
	{
		int count = (amount / pAmount[i]);
		result += count;
		amount -= pAmount[i] * count;
	}
	
	cout << result << endl;
	
	return 0;
}