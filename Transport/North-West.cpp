#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> NorthWest(vector<int> Stocks,int StocksAmount, vector<int> Needs,int NeedsAmount) {
	int i = 0, j = 0;
    vector<vector<int>>Answer(StocksAmount, vector <int>(NeedsAmount, 0));
    while (true)
    {
        if (!(i < StocksAmount and j < NeedsAmount))
            break;
        if (Stocks[i] >= Needs[j])//Запасов хватает
        {
            Answer[i][j] = Needs[j];
            Stocks[i] -= Needs[j];//Остаток
            Needs[j] = 0;//Заказчик удовлетворён
            j++;//Следующий заказчик
            continue;
        }
        else//Запасов не хватит
        {
            Answer[i][j] = Stocks[i];//Отдадим остаток поставщика
            Needs[j] -= Stocks[i];//Остаток заказа
            Stocks[i] = 0;//Поставщик пуст
            i++;//Следующий поставщик
        }

    }
    return(Answer);
}