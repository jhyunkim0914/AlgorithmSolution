#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int number;
int pTime[1001];

int getCompleteTime(int number, int pTime[])
{
	long long totalTime = 0;
	
	for(int i=0; i<number; i++)
	{
		totalTime = totalTime + (pTime[i] * (number - i));
	}
	
	return totalTime;
}

int main()
{
	int number;
	
	freopen("input.txt", "r", stdin);
	
	cin >> number;
	for(int i=0; i<number; i++)
	{
		cin >> pTime[i];
	}
	
	sort(pTime, pTime+number);
	cout << getCompleteTime(number, pTime) << endl;
	
	return 0;
}

