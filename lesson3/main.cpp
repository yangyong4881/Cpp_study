#include<iostream>
#include<vector>
#include<fstream>
using namespace std;


class readOFF
{
public:
    readOFF(string filename, vector<float>& position, vector<float>& points, vector<int>& myIndex)
    {
        string line;
        ifstream fin(filename);
        if (!fin.is_open())
        {
            cout << "文件 " << filename << " 打开失败" << endl;
            exit(-1);
        }
        fin >> line;    // OFF字符串
        // 读取顶点位置
        //int vertexNum, faceNum, edgeNum;
        fin >> vertexNum >> faceNum >> edgeNum;
        cout << "目标模型的顶点数为：" << vertexNum << "；目标模型的面片数为：" << faceNum << endl;
        for (int i = 0; i < vertexNum; i++)
        {
            float p1, p2, p3;
            fin >> p1 >> p2 >> p3;
            position.push_back(p1);
            position.push_back(p2);
            position.push_back(p3);
            //cout << "第" << i + 1 << "个顶点坐标为：" << p1 << p2 << p3 << endl;
        }
        // 根据面信息生成实际顶点
        for (int i = 0; i < faceNum; i++)
        {
            int n, index1, index2, index3;
            fin >> n >> index1 >> index2 >> index3;
            myIndex.push_back(index1);
            myIndex.push_back(index2);
            myIndex.push_back(index3);
            points.push_back(position[3 * index1 - 3]);
            points.push_back(position[3 * index1 - 2]);
            points.push_back(position[3 * index1 - 1]);
            points.push_back(position[3 * index2 - 3]);
            points.push_back(position[3 * index2 - 2]);
            points.push_back(position[3 * index2 - 1]);
            points.push_back(position[3 * index3 - 3]);
            points.push_back(position[3 * index3 - 2]);
            points.push_back(position[3 * index3 - 1]);
            //cout << "第" << i + 1 << "个面片的三个顶点坐标为：(" << index1 << ")的坐标：" << points[9 * i] << "," << points[9 * i + 1] << "," << points[9 * i + 2] << "   (" << index2 << ")的坐标：" << points[9 * i + 3] << "," << points[9 * i + 4] << "," << points[9 * i + 5] << "   (" << index3 << ")的坐标：" << points[9 * i + 6] << "," << points[9 * i + 7] << "," << points[9 * i + 8] << endl;
        }
        //cout << "第" << i + 1 << "个面片的三个顶点坐标为：(" << index1 << ")的坐标：" << points[myIndex[i]] << "," << points[myIndex[i] + 1] << "," << points[myIndex[i] + 2] << "   (" << index2 << ")的坐标：" << points[myIndex[i + 1]] << "," << points[myIndex[i + 1] + 1] << "," << points[myIndex[i + 1] + 2] << "   (" << index3 << ")的坐标：" << points[myIndex[i + 2]] << "," << points[myIndex[i + 2] + 1] << "," << points[myIndex[i + 2] + 2] << endl;
    }

    //打印0ff文件信息
    void myPrint(vector<float>& position, vector<float>& points, vector<int>& myIndex)
    {
        for (int i = 0; i < vertexNum; i++)
        {
            cout << "第" << i + 1 << "个顶点坐标为：" << position[3*i] << position[3 * i+1] << position[3 * i+2] << endl;
        }
        // 根据面信息生成实际顶点
        for (int i = 0; i < faceNum; i++)
        {
            cout << "第" << i + 1 << "个面片的三个顶点坐标为：(" << myIndex[3 * i] << ")的坐标：" << points[9 * i] << "," << points[9 * i + 1] << "," << points[9 * i + 2] << "   (" << myIndex[3 * i +1] << ")的坐标：" << points[9 * i + 3] << "," << points[9 * i + 4] << "," << points[9 * i + 5] << "   (" << myIndex[3 * i +2] << ")的坐标：" << points[9 * i + 6] << "," << points[9 * i + 7] << "," << points[9 * i + 8] << endl;
        }
    }

    //索引第n个顶点坐标
    void getPosition(vector<float>& position, int n)
    {
        cout << "第" << n << "个顶点坐标" << position[3 * n - 3] << position[3 * n - 2] << position[3 * n - 1] << endl;
    }
    //索引第n个面片三个坐标
    void getPoints(vector<float>& points, vector<int>& myIndex, int m)
    {

        //cout << "第" << n << "个面片的三个顶点坐标为：" << points[myIndex[9 * n - 9]] << points[myIndex[3 * n - 2]] << points[myIndex[3 * n - 1]] << endl;
        cout << "第" << m << "个面片的三个顶点坐标为：" << points[9 * m - 9] << "," << points[9 * m - 8] << "," << points[9 * m - 7] << "   " << points[9 * m - 6] << "," << points[9 * m - 5] << "," << points[9 * m - 4] << "   " << points[9 * m - 3] << "," << points[9 * m - 2] << "," << points[9 * m - 1] << endl;
    }

private:
    int vertexNum, faceNum, edgeNum;
    float position;
    float points;
    int myIndex;
};


int main()
{
    vector<float> position;
    vector<float> points;
    vector<int> myIndex;
    readOFF off1("m784.off", position, points, myIndex);
    off1.myPrint(position, points, myIndex);
    int n, m;
    cout << "请输入需要索引的顶点坐标：" << endl;
    cin >> n;
    off1.getPosition(position, n);
    cout << "请输入需要索引的面片的三个坐标：" << endl;
    cin >> m;
    off1.getPoints(points, myIndex, m);

    return 0;
}