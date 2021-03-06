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
	int result = amount;
	int* p;
	for(int i=0; i<number; i++)
	{
		p = find(pAmount+i, pAmount+number, result);
		if (p != pAmount+number)
			return true;
	  	else
			result = result - pAmount[i];
	}
	
	return false;
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
	
	int sum=0;
	for(int i=0; i<number; ++i)
	{
		if(sum+1 < pAmount[i])
			break;
		
		sum += pAmount[i];
	}
	cout << sum+1 << endl;
	
	return 0;
}

