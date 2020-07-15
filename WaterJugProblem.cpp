#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include<math.h>
#include <conio.h>

int min(int a, int b);

using namespace std;

void pour(int fromCapacity, int toCapacity, int d)
{
	int temp;
	int from = fromCapacity, to = 0, step = 1;
	
	cout << "\nStep\tJug M\tJug N\n";
	cout << step << "\t" << from << "\t" << to << "\n";
	
	while (from != d && to != d)
	{
		temp = min(from, toCapacity - to);
		
		to += temp;
		from -= temp;
		step++;
		
		cout << step << "\t" << from << "\t" << to << "\n";
		
		if (from == d || to == d)
			break;
		
		if (to == toCapacity)
		{
			to = 0;
			step++;
			cout << step << "\t" << from << "\t" << to << "\n";
		}
		
		if (from == 0)
		{
			from = fromCapacity;
			step++;
			cout << step << "\t" << from << "\t" << to << "\n";

		}
	}
}

int min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

int gcd(int a, int b)
{
	while (a != b)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
}

int main()
{
	int m, n, d;
	
	cout << "WATER JUG PROBLEM\n";
	
	cout << "Enter value of m:\n";
	cin >> m;
	
	cout << "Enter value of n:\n";
	cin >> n;
	
	cout << "Enter value of d:\n";
	cin >> d;

	if (d % gcd(m, n) == 0 && m < n && d < n)
		pour(m, n, d);
	else
		cout << "Solution is not possible!";

	_getch();
	return 0;
}
