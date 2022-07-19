#include "North-West.h"
#include "Min-Elem.h"
using namespace std;

int main()
{
	vector<int> stocks = { 30,40,10,40 }, needs = { 10,20,30,20,40 }; //Поставщики и заказчики
	setlocale(LC_ALL, "Russian"); //
	while (true) { //Меню выбора варианта
		cout << "Выберите действие: " << endl;
		cout << "1. Метод наименьшего" << endl;
		cout << "2. Метод северо-запада" << endl;
		cout << "0. Выход" << endl;

		int a;
		cin >> a;

		switch (a) { //Метод наименьшего
		case 1: {
			cout << endl;
			vector<vector<int>> shipments = MinElem(stocks, stocks.size(), needs, needs.size());
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

		case 2: { //Метод северо-запада
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
