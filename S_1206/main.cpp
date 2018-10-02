#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int calcFloor(int *floor, int position)
{
	int view = 0;
	int sub[5] = { 0 };
	
	for(int i=-2; i<=2; i++)
	{
		sub[i] = floor[position] - floor[i];
	}
	sort(sub, sub+5);
	if (sub[4] > 0)
		view = sub[4];
	
	return view;
}

int main()
{
	int number;
	
	int floor[1004] = { 0 };
	
	freopen("input.txt", "r", stdin);
	
	for(int test_case=0; test_case<10; test_case++)
	{
		cin >> number;
		for(int i=0; i<number; i++)
		{
			int top = 0;
			cin >> top;
			floor[i+2] = top;
		}
		
		int total = 0;
		for(int i=0; i<number; i++)
		{
			total += calcFloor(floor, i);
		}
		
	}
	
	return 0;
}