#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;


void circularMove(int *arr)
{
	int temp[8];
	for (int i = 7; i >= 0; i--)
	{
		int index = (i - 1) % 8;
		if (index == -1)
			index += 8;
		temp[index] = arr[i];
	}
	for (int i = 7; i >= 0; i--)
	{
		arr[i] = temp[i];
	}
	return;
}

int main()
{
	int number = 0;
	int arr[8];
	
	freopen("input.txt", "r", stdin);
	
	// Read File
	for(int i=0; i<10; i++)
	{
		cin >> number;
		
		for(int j=0; j<8; j++)
		{
			cin >> arr[j];
		}

		//Solve Problem
		while (true)
		{
			for (int i = 1; i <= 5; i++)
			{
				arr[0] -= i;
				circularMove(arr);
				if (arr[7] <= 0) {
					break;
				}
			}
			if (arr[7] <= 0) {
				break;
			}
		}
		arr[7] = 0;
		cout << '#' << number << ' ';
		for (int j = 0; j<8; j++)
		{
			cout << arr[j] << ' ';
		}
		cout << endl;
	}
	
	return 0;
}