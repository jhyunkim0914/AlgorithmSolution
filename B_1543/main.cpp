#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
	string main;
	string query;
	
	freopen("input.txt", "r", stdin);
	
	cin >> main;
	cin >> query;
	
	int result = 0;
	
	for(;main.find(query) != string::npos; result++) {
        main = main.substr(main.find(query) + query.length(), main.length());
    }
	cout << result << endl;
	
	return 0;
}