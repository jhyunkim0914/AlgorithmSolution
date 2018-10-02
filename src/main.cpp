#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int number;
int pAmount[1001];

bool isPossible(int number, int pAmount[], int amount)
{
	//pAmount is already sorted
	bool isPossible = false;
	
	for(int i=0; i<=number; i++)
	{
		for(int j=i; j<number; j++)
		{
			amount -= pAmount[j];
			if (amount == 0)
			{
				isPossible = true;
				return isPossible;
			}
		}
	}
	
	return isPossible;
}

int main()
{
	int number;
	
	freopen("input.txt", "r", stdin);
	
	cin >> number;
	for(int i=0; i<number; i++)
	{
		cin >> pAmount[i];
	}
	
	sort(pAmount, pAmount+number);
	
	long long totalAmount = 0;
	for(int i=0; i<number; i++)
	{
		totalAmount += pAmount[i];
	}
	for(int i=1; i<=totalAmount; i++)
	{
		if(isPossible(number, pAmount, i) == false)
		{
			cout << i << endl;
			break;
		}
		if(i == totalAmount)
			cout << i << endl;
	}
	
	return 0;
}

