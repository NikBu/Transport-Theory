#include <iostream>
#include <cstring>
#include "North-West.h"
using namespace std;

int main()
{
	vector<int> stocks = { 30,40,10,40 }, needs = { 10,20,30,20,40 };
	vector<vector<int>> shipments(stocks.size(), vector <int>(needs.size(), 0));
	setlocale(LC_ALL, "Russian");
	while (true) {
		cout << "Выберите действие: " << endl;
		cout << "1. Метод наименьшего элемента" << endl;
		cout << "2. Метод северо-запада" << endl;
		cout << "0. Выход" << endl;

		int a;
		cin >> a;

		switch (a) {
		case 1: {
			cout << endl;
			int min_val;
			for (int i(0); i < stocks.size(); ++i)
			{
				for (int k(0); k < needs.size(); ++k)
				{
					if (needs[k] == 0) continue;

					min_val = std::min(stocks[i], needs[k]);
					shipments[i][k] = min_val;
					stocks[i] -= min_val;
					needs[k] -= min_val;

					if (stocks[i] == 0) break;
				}
			}

			for (int i(0); i < stocks.size(); ++i)
			{
				for (int k(0); k < needs.size(); ++k)
				{
					cout << shipments[i][k] << "\t";
				}
				cout << endl;
			}
			cout << endl;
			break;
		}

		case 2: {
			cout << endl;
			vector<vector<int>> shipments2 = NorthWest(stocks, stocks.size(), needs, needs.size());
			for (int i(0); i < stocks.size(); ++i)
			{
				for (int k(0); k < needs.size(); ++k)
				{
					cout << shipments2[i][k] << "\t";
				}
				cout << endl;
			}
			break;
		}
		case 0: {
			cout << "Выход" << endl;
			return 0;
		}
		}
	}
}
