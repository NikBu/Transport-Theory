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
        if (Stocks[i] >= Needs[j])//������� �������
        {
            Answer[i][j] = Needs[j];
            Stocks[i] -= Needs[j];//�������
            Needs[j] = 0;//�������� �����������
            j++;//��������� ��������
            continue;
        }
        else//������� �� ������
        {
            Answer[i][j] = Stocks[i];//������� ������� ����������
            Needs[j] -= Stocks[i];//������� ������
            Stocks[i] = 0;//��������� ����
            i++;//��������� ���������
        }

    }
    return(Answer);
}