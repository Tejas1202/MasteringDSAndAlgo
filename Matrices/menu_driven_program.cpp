// Menu driven program (used diagonal matrix here)
#include <iostream>
using namespace std;

int main()
{
	int* A, n, choice, x;
	cout << "Enter dimension: ";
	cin >> n;
	A = new int[n];
	int i, j;

	do
	{
		cout << endl;
		cout << "Enter your choice: " << endl;
		cout << "1. Create" << endl;
		cout << "2. Get" << endl;
		cout << "3. Set" << endl;
		cout << "4. Display" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			for (i = 1; i <= n; i++)
			{
				cin >> x;
				A[i - 1] = x;
			}
			break;
		case 2:
			cout << "Enter indices i and j: ";
			cin >> i >> j;
			if (i == j)
				cout << A[i - 1] << endl;
			else
				cout << "0" << endl;
			break;
		case 3:
			cout << "Enter row, column and element: ";
			cin >> i >> j >> x;
			if (i == j)
				A[i - 1] = x;
			break;
		case 4:
			for (i = 1; i <= n; i++)
			{
				for (j = 1; j <= n; j++)
				{
					if (i == j)
						cout << A[i - 1] << " ";
					else
						cout << "0 ";
				}
				cout << endl;
			}
			break;
		default:
			break;
		}
	} while (choice >= 1 && choice <= 4);
}