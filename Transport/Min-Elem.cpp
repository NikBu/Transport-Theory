#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> MinElem(vector<int> Stocks, int StocksAmount, vector<int> Needs, int NeedsAmount) {
    int i = 0, j = 0;
    vector<vector<int>>Answer(StocksAmount, vector <int>(NeedsAmount, 0));
	
	int min_val;
	for (int i(0); i < Stocks.size(); ++i)
	{
		for (int k(0); k < Needs.size(); ++k)
		{
			if (Needs[k] == 0) continue;

			min_val = std::min(Stocks[i], Needs[k]);
			Answer[i][k] = min_val;
			Stocks[i] -= min_val;
			Needs[k] -= min_val;

			if (Stocks[i] == 0) break;
		}
	}
    return(Answer);
}