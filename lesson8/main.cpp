#include<iostream>
#include"KMatrix.h"

using namespace std;

void test01() {
	int x, y;
	cout << "输入矩阵的行和列" << endl;
	cin >> x >> y;
	KMatrix<int> k(x, y);
	k.print();//打印初始矩阵
	cout <<"获取行数："<< k.getCols() << endl;//获取行数
	cout << "获取列数：" << k.getRows() << endl;//获取列数
	k.setData(2, 3, 5);//数据修改
	k.setData(2, 4, 10); k.setData(1, 2, 6);
	k.print();//打印初始矩阵
	cout << "获取函数2行3列的值：" << k.getData(2, 3) << endl;//与获取函数输出2行3列的值；
	k.delRows(4);//删除第5行
	k.delRows(0);//删除第5行
	k.delCols(0);//删除列
	cout << "矩阵转置前：" << endl;
	k.print();//打印矩阵
	KMatrix<int> k1;
	k1 = k.Transpose();
	cout << "矩阵转置后：" << endl;
	k1.print();//打印矩阵
	KMatrix<int> k2(k);
	cout << "拷贝构造：" << endl;
	k2.print();//打印矩阵
	//init
	cout << "init初始化：" << endl;
	k.init(3,3);
	k.print();//打印矩阵

	for (KMatrix<int>::myIter iter = k.begin();iter != k.end();++iter)
	{
			for(KMatrix<int>::myIter it = (*iter).begin();it != (*iter).end();++it){
				cout << (*it) << " ";
			}
			cout << endl;
	}

}


//加(+)、减(-)、叉乘(*)运算
void test02() {
	int n, m;
	cout << "输入矩阵的行和列" << endl;
	cin >> n >> m;
	KMatrix<int> k1(n, m, 10);
	KMatrix<int> k2(n, m, 2);
	KMatrix<int> k3(n, m, 0);
	
	cout << "输入需要+，-，*的数" << endl;
	int v; cin >> v;
	k1 += v;
	cout << "+运算:" << endl;
	k1.print();
	k1 -= v;
	cout << "-运算:：" << endl;
	k1.print();
	k1 *= v;
	cout << "*运算:：" << endl;
	k1.print();
	//矩阵计算
	cout << "矩阵计算" << endl;
	k3 = k1 + k2;
	cout << "+运算:" << endl;
	k3.print();
	k3 = k1 - k2;
	cout << "-运算:" << endl;
	k3.print();
	k3.dotMul(k2);
	cout << "dotMul运算:" << endl;
	k3.print();
	//叉乘
	cout << "矩阵叉乘：" << endl;
	cout << "输入矩阵的行i和列j" << endl;
	int i, j;
	cin >> i >> j;
	KMatrix<int> k4(i, j, 3);
	KMatrix<int> k5(n, j, 0);
	try {
		if (m != i)
			throw - 1;//抛出int型异常
		k5 = k1 * k4;
		k5.print();
	}
	catch (int) {
		cout << "叉乘的两个矩阵行列不符合条件" << endl;
	}
}



int main()
{
	test01();
	//test02();
	
	return 0;
}