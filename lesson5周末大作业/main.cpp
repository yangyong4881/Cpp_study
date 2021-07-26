#include<iostream>
#include"SupermarketManager.h"

using namespace std;

int main()
{
    SupermarketManager M;
    //M["Drinks"];
    char c;
    do {
        cout << "****超市商品模拟管理系统****" << endl;
        cout << " 1—新增商品信息" << endl;
        cout << " 2—删除商品信息" << endl;
        cout << " 3—修改商品信息" << endl;
        cout << " 4—商品信息检索" << endl;
        cout << " 5—商品按价格排序输出" << endl;
        cout << " 6—输出价格前五的商品" << endl;
        cout << " 0—退出!请选择功能(0-6):" << endl;
        cin >> c;
        switch (c)
        {
        case '1':M.addCommodity(); break;
        case '2':M.deleteCommodity();  break;
        case '3':M.alterCommodity(); break;
        case '4':M.indexCommodity(); break;
        case '5':M.sortCommodity(); break;
        case '6':M.T5Commodity(); break;
        }
    }
    while (c != '0');
    return 0;
}