#pragma once
#include<iostream>
#include<vector>

using namespace std;

template<typename T>
class KMatrix {
public:
	//构造
	KMatrix() {

	}
	KMatrix(int row,int col) :row_count(row), col_count(col) {
		Matrix.resize(row);
		for (int i = 0; i < row_count; i++) {
			Matrix[i].resize(col_count);
		}
	}
	//
	KMatrix(int row, int col,T value) : row_count(row), col_count(col) {
		Matrix.resize(row);
		for (int i = 0; i < row_count; i++) {
			Matrix[i].resize(col_count);
		}
		for (int i = 0; i < row_count; i++) {
			for (int j = 0; j < col_count; j++) {
				Matrix[i][j] = value;
			}
		}
	}

	//拷贝构造
	KMatrix(KMatrix<T>& k):row_count(k.row_count),col_count(k.col_count),Matrix(k.Matrix) {}
	
	//析构
	~KMatrix(){}

private:
	vector<vector<T>> Matrix;
	int row_count, col_count;

public:
	//init
	void init(int row, int col){
		row_count = row; col_count = col;
		Matrix.resize(row);
		for (int i = 0; i < row_count; i++) {
			Matrix[i].resize(col_count);
		}
		for (int i = 0; i < row_count; i++) {
			for (int j = 0; j < col_count; j++) {
				Matrix[i][j] = 0;
			}
		}
	}


	//KMatrix获取行列数的函数
	int getRows() const {
		return row_count;
	}
	int getCols() const {
		return col_count;
	}
	//数据修改
	void setData(int row,int col,T value) {
		Matrix[row][col] = value;
	}
	//获取函数
	T getData(int row, int col) const {
		return Matrix[row][col];
	}
	//删除行列的函数
	void delRows(int row) {
		/*KMatrix<T> tmp(row_count-1,col_count);
		for (int i = 0; i < row_count; i++) {
			for (int j = 0; j < col_count; j++) {
				if (i < row) {
					tmp.Matrix[i][j] = Matrix[i][j];
				}
				else if(i > row) {
					tmp.Matrix[i-1][j] = Matrix[i][j];
				}
			}
		}*/
		Matrix.erase(Matrix.begin() + row);
		row_count--;
	}
	void delCols(int col) {
		/*KMatrix<T> tmp(row_count, col_count - 1);
		for (int i = 0; i < row_count; i++) {
			for (int j = 0; j < col_count; j++) {
				if (j < col) {
					tmp.Matrix[i][j] = Matrix[i][j];
				}
				else if (j > col) {
					tmp.Matrix[i][j-1] = Matrix[i][j];
				}
			}
		}*/
		for (int i = 0; i < row_count; i++) {
			Matrix[i].erase(Matrix[i].begin() + col);
		}
		col_count--;
		
	}
	
	// =重载
	/*KMatrix<T>& operator=(const KMatrix<T>& k) {
		Matrix = new vector<vector<T>>;
		Matrix.resize(k.row_count);
		for (int i = 0; i < k.row_count; i++) {
			Matrix[i].resize(k.col_count);
		}
		for (int i = 0; i < k.row_count; i++) {
			for (int j = 0; j < k.col_count; j++) {
				Matrix[i][j] = k.Matrix[i][j];
			}
		}
		return *this;
	}*/

	//+=常数
	void operator+=(const T& value) {
		for (int i = 0; i < row_count; i++) {
			for (int j = 0; j < col_count; j++) {
				Matrix[i][j] = Matrix[i][j] + value;
			}
		}
	}
	//+=矩阵
	void operator+=(KMatrix<T>& k1) {
		for (int i = 0; i < row_count; i++) {
			for (int j = 0; j < col_count; j++) {
				Matrix[i][j] = Matrix[i][j] + k1.Matrix[i][j];
			}
		}
	}
	//+常数
	KMatrix<T> operator+ (const T& value) {
		KMatrix<T> tmp(row_count, col_count);
		for (int i = 0; i < row_count; i++) {
			for (int j = 0; j < col_count; j++) {
				tmp.Matrix[i][j] = Matrix[i][j] + value;
			}
		}
		return tmp;
	}
	//+矩阵
	KMatrix<T> operator+ ( KMatrix<T>& k1) {
		KMatrix<T> tmp(row_count, col_count);
		for (int i = 0; i < row_count; i++) {
			for (int j = 0; j < col_count; j++) {
				tmp.Matrix[i][j] = Matrix[i][j] + k1.Matrix[i][j];
			}
		}
		return tmp;
	}
	//-=常数
	void operator-=(const T& value) {
		for (int i = 0; i < row_count; i++) {
			for (int j = 0; j < col_count; j++) {
				Matrix[i][j] = Matrix[i][j] - value;
			}
		}
	}
	//-=矩阵
	void operator-=(KMatrix<T>& k1) {
		for (int i = 0; i < row_count; i++) {
			for (int j = 0; j < col_count; j++) {
				Matrix[i][j] = Matrix[i][j] - k1.Matrix[i][j];
			}
		}
	}
	//-常数
	KMatrix<T> operator- (const T& value) {
		KMatrix<T> tmp(row_count, col_count);
		for (int i = 0; i < row_count; i++) {
			for (int j = 0; j < col_count; j++) {
				tmp.Matrix[i][j] = Matrix[i][j] - value;
			}
		}
		return tmp;
	}
	//-矩阵
	KMatrix<T> operator- (KMatrix<T>& k1) {
		KMatrix<T> tmp(row_count, col_count);
		for (int i = 0; i < row_count; i++) {
			for (int j = 0; j < col_count; j++) {
				tmp.Matrix[i][j] = Matrix[i][j] - k1.Matrix[i][j];
			}
		}
		return tmp;
	}
	//*=常数
	void operator*=(const T& value) {
		for (int i = 0; i < row_count; i++) {
			for (int j = 0; j < col_count; j++) {
				Matrix[i][j] = Matrix[i][j] * value;
			}
		}
	}
	//*常数
	KMatrix<T> operator* (const T& value) {
		KMatrix<T> tmp(row_count, col_count);
		for (int i = 0; i < row_count; i++) {
			for (int j = 0; j < col_count; j++) {
				tmp.Matrix[i][j] = Matrix[i][j] * value;
			}
		}
		return tmp;
	}
	//叉乘
	KMatrix<T> operator* (KMatrix<T>& k1) {
		KMatrix<T> tmp(row_count, k1.col_count);
		for (int m = 0; m < row_count; m++) {
			for (int n = 0; n < k1.col_count; n++) {
				for (int j = 0; j < col_count; j++) {
					//T num;
					//num = Matrix[m][j] * k1.Matrix[j][n];
					//tmp[m][n] = tmp[m][n] + num;
					tmp.Matrix[m][n] += Matrix[m][j] * k1.Matrix[j][n];
				}
			}
		}
		return tmp;
	}
	//点乘
	KMatrix<T> dotMul(const KMatrix& k1) {
		KMatrix<T> tmp(row_count, col_count);
		for (int i = 0; i < row_count; i++) {
			for (int j = 0; j < col_count; j++) {
				tmp.Matrix[i][j] = Matrix[i][j] * k1.Matrix[i][j];
			}
		}
		return tmp;
	}

	//转置
	KMatrix<T> Transpose() const {
		KMatrix<T> tmp(col_count, row_count);
		for (int i = 0; i < row_count; i++)
		{
			for (int j = 0; j < col_count; j++)
			{
				tmp.Matrix[j][i] = Matrix[i][j];
			}
		}
		return tmp;
	}
	//打印输出
	void print() const {
		for (int i = 0; i < row_count; i++) {
			for (int j = 0; j < col_count; j++) {
				cout<<Matrix[i][j]<<" ";
			}
			cout << endl;
		}
	}

	////
	class myIter {
	public:
		myIter(int* pos) :_pos(pos) {

		}
		//前++
		myIter& operator++() {
			++_pos;
			return *this;
		}
		//后++
		myIter operator++(int) {
			int* tmp = _pos;
			++_pos;
			return tmp;
		}
		//前--
		myIter& operator--() {
			--_pos;
			return *this;
		}
		//后--
		myIter operator--(int) {
			int* tmp = _pos;
			--_pos;
			return tmp;
		}
		int* operator->() {
			return _pos;
		}
		int& operator*() {
			return *_pos;
		}
		bool operator==(myIter iter)
		{
			return _pos == iter._pos;
		}
		bool operator!=(myIter iter)
		{
			return !operator==(iter);
		}

	public:
		int* _pos = nullptr;
	};

public:
	myIter begin() {
		return myIter(this,0);
	}
	myIter end() {
		return myIter(NULL,row_count);
	}

};