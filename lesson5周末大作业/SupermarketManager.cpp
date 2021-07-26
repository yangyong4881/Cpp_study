#include "SupermarketManager.h"

SupermarketManager::SupermarketManager() {
	//文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in); //先读入文件
	if (!ifs.is_open())
	{
		//初始化商品数和数组指针
		this->commodityNum = 0;
		this->commodityArray = NULL;
		this->commodityEmpty = true; 
		ifs.close();
		return;
	}

	//文件存在，但数据为空
	char ch;
	ifs >> ch;  
	if (ifs.eof()) //如果结果为true，表示文件已经读完，为空
	{
		this->commodityNum = 0;  
		this->commodityArray = NULL;
		this->commodityEmpty = true;
		ifs.close();
		return;
	}

	//当文件存在并且文件中记录数据
	int num = this->getCommodity();
	this->commodityNum = num;  //更新商品数
	//开辟空间，将文件中的数据存放到数组中
	this->commodityArray = new Commodity * [this->commodityNum];
	this->initCommodity();
}

SupermarketManager::~SupermarketManager() {
	if (this->commodityArray != NULL)
	{
		delete[] this->commodityArray;
		this->commodityArray = NULL;
	}
}

void SupermarketManager::addCommodity() {
	cout << ">>>>>>>>增加商品<<<<<<<<" << endl;
	string addType;
	string addName;
	double addPrice;
	int addCount;
	cout << "类型：";
	cin >> addType;
	cout << "名称：";
	cin >> addName;
	cout << "价格：";
	cin >> addPrice;
	cout << "数量：";
	cin >> addCount;
	cout << "..." << endl;
	//add程序
	//添加，先计算添加空间大小
	int newSize = this->commodityNum + 1;

	//开辟新空间newSpace,新空间的大小等于算得结果，本质就是新建数组指针
	Commodity** newSpace = new Commodity * [newSize];

	//将原来数组commodityArray中的数据，拷贝到新数组里面
	if (this->commodityArray != NULL)
	{
		for (int i = 0; i < this->commodityNum; i++)
		{
			newSpace[i] = this->commodityArray[i];
		}
	}
	Commodity* commodity = NULL;
	//
	if (addType == "Drinks"){
		commodity = new Drinks(addType, addName, addPrice, addCount);
	}
	if (addType == "Drinks") {
		commodity = new Drinks(addType, addName, addPrice, addCount);
	}
	newSpace[this->commodityNum] = commodity;
	delete[] this->commodityArray;
	this->commodityArray = newSpace;
	this->commodityNum = newSize;
	commodityEmpty = false;
	cout << "商品添加成功" << endl;
	this->saveCommodity();
	cout << "是否返回主菜单（y返回，n退出）：";
	char a; 
	do {
		cin >> a;
		switch (a)
		{
		case 'n':  exit(0);
		}
	} while (a != 'y');
}

void SupermarketManager::deleteCommodity() {
	cout << ">>>>>>>>删除商品<<<<<<<<" << endl;
	string delType;
	cout << "删除的商品类型：";
	cin >> delType;
	int index;
	for (int i = 0; i < this->commodityNum; i++) {
		if (this->commodityArray[i]->type == delType)
		{
			index = i;
			this->commodityArray[index]->myPrint();
		}
	}
	if (index != -1) {
		cout << "删除商品：";
		string delName; 
		cin >> delName ;
		for (int i = 0; i < this->commodityNum; i++) {
			if (this->commodityArray[i]->name == delName)
			{
				index = i;
				for (int i = index; i < this->commodityNum - 1; i++)  //这里要commodityNum-1的原因是之后要把i+1的元素移到i中来
				{
					this->commodityArray[i] = this->commodityArray[i + 1];
				}
			}
		}
		--this->commodityNum;  //更新文件
		this->saveCommodity(); //保存操作到文件中
		cout << "删除成功！！！" << endl;
	}
	else {
		cout << "无此商品！！" << endl;
	}
	cout << "是否返回主菜单（y返回，n退出）：";
	char a;
	do {
		cin >> a;
		switch (a)
		{
		case 'n':  exit(0);
		}
	} while (a != 'y');
}

void SupermarketManager::alterCommodity() {
	cout << ">>>>>>>>修改商品<<<<<<<<" << endl;
	cout << "名称：";
	string aName; int ac;
	cin >> aName;

	int index = this->IsExist(aName);

	cout << "修改项(1=价格， 2=数量)：";
	cin >> ac;
	switch(ac)
	{
	case 1:{
		printf("价格:");
		string type =commodityArray[index]->type ;      //种类
		string name = commodityArray[index]->name;   //名称
		double alterprice;  //价格
		int count= commodityArray[index]->count;     //数量
		delete this->commodityArray[index];
		cin >> alterprice;
		Commodity* altercommodity = NULL;
		altercommodity = new Drinks(type, name, alterprice, count);
		this->commodityArray[index] = altercommodity;
		cout << "商品价格修改成功" << endl;
		break;
	}
	case 2: {
		printf("数量:");
		string type = commodityArray[index]->type;      //种类
		string name = commodityArray[index]->name;   //名称
		double price= commodityArray[index]->price;  //价格
		int altercount;     //数量
		delete this->commodityArray[index];
		cin >> altercount;
		Commodity* altercommodity = NULL;
		altercommodity = new Drinks(type, name, price, altercount);
		this->commodityArray[index] = altercommodity;
		cout << "商品数量修改成功" << endl;
		break;
	}
	default:
		printf("\n按键错误，请重新输入\n");
	}
	this->saveCommodity();
	cout << "是否返回主菜单（y返回，n退出）：";
	char a;
	do {
		cin >> a;
		switch (a)
		{
		case 'n':  exit(0);
		}
	} while (a != 'y');
}

void SupermarketManager::indexCommodity() {
	cout << ">>>>>>>>商品信息检索<<<<<<<<" << endl;
	cout << "类型：";
	string indexType;
	cin >> indexType;
	int index;
	//this->commodityArray[indexType];
	//打印类型信息
	for (int i = 0; i < this->commodityNum; i++) {
		if (this->commodityArray[i]->type == indexType)
		{
			index = i;
			this->commodityArray[index]->myPrint();
		}
	}
	cout << "是否返回主菜单（y返回，n退出）：";
	char a;
	do {
		cin >> a;
		switch (a)
		{
		case 'n':  exit(0);
		}
	} while (a != 'y');
}

void SupermarketManager::sortCommodity() {
	cout << ">>>>>>>>商品排序输出<<<<<<<<" << endl;
	cout << "排序类型（1=由高到低，2=由低到高）：";
	int sC;
	cin >> sC;
	for (int i = 0; i < this->commodityNum; i++)
	{
		int minOrmax = i;
		for (int j = i + 1; j < this->commodityNum; j++)
		{
			if (sC == 1)  //由高到低
			{
				if (this->commodityArray[minOrmax]->price < this->commodityArray[j]->price)
				{
					minOrmax = j;  //先找到最大值，把他排在第一个
				}
				
			}
			else  //由低到高
			{
				if (this->commodityArray[minOrmax]->price > this->commodityArray[j]->price)
				{
					minOrmax = j;  //先找到最小值，把他排在第一个
				}
			}
		}
		//j循环转一圈后，需要判断minOrmax是否与最初的相等，若不等交换i和minOrmax
		if (i != minOrmax)
		{
			Commodity* temp = this->commodityArray[i];
			this->commodityArray[i] = this->commodityArray[minOrmax];
			this->commodityArray[minOrmax] = temp;
		}
	}
	//打印类型信息
	cout << "排序成功，排序后的结果为： " << endl;
	this->printCommodity(sC);
	cout << "是否返回主菜单（y返回，n退出）：";
	char a;
	do {
		cin >> a;
		switch (a)
		{
		case 'n':  exit(0);
		}
	} while (a != 'y');
}

void SupermarketManager::T5Commodity() {
	cout << ">>>>>>>>价格前五商品<<<<<<<<" << endl;
	//打印价格前五商品信息
	for (int i = 0; i < this->commodityNum; i++)
	{
		int minOrmax = i;
		for (int j = i + 1; j < this->commodityNum; j++)
		{
			if (this->commodityArray[minOrmax]->price < this->commodityArray[j]->price)
			{
				minOrmax = j; 
			}
		}
		if (i != minOrmax)
		{
			Commodity* temp = this->commodityArray[i];
			this->commodityArray[i] = this->commodityArray[minOrmax];
			this->commodityArray[minOrmax] = temp;
		}
	}
	cout << "价格前五商品为： " << endl;
		for (int i = 0; i < 5; i++) {
			this->commodityArray[i]->myPrint();
			cout << ">";
		}
		cout << "是否返回主菜单（y返回，n退出）：";
		char a;
		do {
			cin >> a;
			switch (a)
			{
			case 'n':  exit(0);
			}
		} while (a != 'y');
}
void SupermarketManager::saveCommodity() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);  //用输出的方式打开文件 == 写文件

	//将每个人数据写入文件中
	for (int i = 0; i < this->commodityNum; i++)
	{
		ofs << this->commodityArray[i]->type << setw(15)
			<< this->commodityArray[i]->name  << setw(10)
			<< this->commodityArray[i]->price  << setw(10)
			<< this->commodityArray[i]->count << endl;
	}
	//关闭文件
	ofs.close();
}

int SupermarketManager::getCommodity() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);  //打开文件，读的方式

	string type;
	string name;
	double price;
	int count;

	int num = 0;
	while (ifs >> type && ifs >> name && ifs >> price && ifs >> count)  //利用ifs将当前文件中的全部数据都读进来
	{
		num++;
	}
	return num;
}

void SupermarketManager::initCommodity() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	string type;
	string name;
	double price;
	int count;

	int index = 0;

	while (ifs >> type && ifs >> name && ifs >> price && ifs >> count)
	{
		Commodity* commodity = NULL;  //创建commodity，并初始为空
		if (type == "Drinks")
		{
			commodity = new Drinks(type, name, price, count);  //创建Drinks
		}

		this->commodityArray[index++] = commodity;  //把commodity中存储的内容放到数组指针中，依次index++
	}
	ifs.close();
}

void SupermarketManager::printCommodity(int sC) {
	if (sC == 1) {
		for (int i = 0; i < this->commodityNum; i++)
		{
			//利用多态调用程序接口
			this->commodityArray[i]->myPrint();
			cout << ">";
		}
	}
	else if (sC == 2) {
		for (int i = 0; i < this->commodityNum; i++)
		{
			//利用多态调用程序接口
			this->commodityArray[i]->myPrint();
			cout << "<";
		}
	}
}
int SupermarketManager::IsExist(string type) {
	int index = -1;
	for (int i = 0; i < this->commodityNum; i++) {
		if (this->commodityArray[i]->type == type)
		{
			index = i;
			break;
		}
	}
	return index;
}
//int SupermarketManager::IsExist(string name) {
//	int index = -1;
//	for (int i = 0; i < this->commodityNum; i++) {
//		if (this->commodityArray[i]->name == name)
//		{
//			index = i;
//			break;
//		}
//	}
//	return index;
//}

void SupermarketManager::operator[](string indexCommodity) {
	int index;
	//打印类型信息
	for (int i = 0; i < this->commodityNum; i++) {
		if (this->commodityArray[i]->type == indexCommodity)
		{
			index = i;
			this->commodityArray[index]->myPrint();
		}
	}
}