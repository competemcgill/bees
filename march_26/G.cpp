#include <algorithm>
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int n, ct;
char c[9], d[9], mn[9];
string s;

bool eq()
{
	for (int i = 0; i < 8; i++)
		if (c[i] != d[i])
			return false;
	return true;
}

int numDays[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// 0,1 DD 2,3 MM 4,5,6,7 YYYY
bool isValidDate()
{
	int year = (c[4] - '0') * 1000 + (c[5] - '0') * 100 + (c[6] - '0') * 10 + c[7] - '0';
	int month = (c[2] - '0') * 10 + c[3] - '0';
	int day = (c[0] - '0') * 10 + c[1] - '0';

	if (month <= 0 or month > 12 or year < 2000 or day <= 0 or day > 31)
		return false;
	if (month == 2 and (year % 400 == 0 or (year % 4 == 0 and year % 100 != 0)))
	{
		// leap year and february
		return day <= 29;
	}
	return day <= numDays[month];
}

void assignMin()
{
	for (int i = 0; i < 8; i++)
		mn[i] = c[i];
}

void updateMin()
{
	if (mn[0] == '5')
	{
		assignMin();
		return;
	}
	int year = (c[4] - '0') * 1000 + (c[5] - '0') * 100 + (c[6] - '0') * 10 + (c[7] - '0');
	int month = (c[2] - '0') * 10 + c[3] - '0';
	int day = (c[0] - '0') * 10 + c[1] - '0';

	int yearMin = (mn[4] - '0') * 1000 + (mn[5] - '0') * 100 + (mn[6] - '0') * 10 + (mn[7] - '0');
	int monthMin = (mn[2] - '0') * 10 + mn[3] - '0';
	int dayMin = (mn[0] - '0') * 10 + mn[1] - '0';

	if (year < yearMin)
	{
		assignMin();
		return;
	}
	if (year > yearMin)
		return;

	if (month < monthMin)
	{
		assignMin();
		return;
	}
	if (month > monthMin)
		return;

	if (day < dayMin)
	{
		assignMin();
		return;
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	getchar();
	c[8] = d[8] = mn[8] = '\0';

	for (int i = 0; i < n; i++)
	{
		mn[0] = '5';
		// 04 11 2018
		for (int j = 0; j < 8; j++)
		{
			cin >> c[j];
			d[j] = c[j];
		}

		ct = 0;
		do
		{
			if (isValidDate())
			{
				ct++;
				updateMin();
			}
			next_permutation(c, c + 8);
		} while (!eq());

		cout << ct;
		if (ct)
		{
			assert(mn[0] != 5);
			cout << ' ';
			for (int i = 0; i < 8; i++)
			{
				cout << mn[i];
				if (i == 1 or i == 3)
					cout << ' ';
			}
		}
		cout << endl;
	}

	return 0;
}
