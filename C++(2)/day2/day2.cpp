#include <iostream>
#include <ctime>
using namespace std;
float **CreateM(int lines, int rows)
{
    float **arry = new float *[lines];
    for (int i = 0; i < lines; i++)
    {
        arry[i] = new float[rows];
    } //创建
    for (int i = 0; i < lines; i++)
    {
        for (int c = 0; c < rows; c++)
        {
            int random = rand() % 20;
            arry[i][c] = random;
        }
    } //赋值随机数
    return arry;
}
//打印矩阵
void PrintMatrix(float **arry, int lines, int rows)
{
    for (int i = 0; i < lines; i++)
    {
        for (int c = 0; c < rows; c++)
        {
            cout << arry[i][c] << "\t";
        }
        cout << endl;
    }
}
//矩阵乘法
float **MultiplicationM(float **arry01, float **arry02, int arry01_lines, int arry01_rows, int arry02_rows)
{
    float **arry = new float *[arry01_lines];
    for (int i = 0; i < arry01_lines; i++)
    {
        arry[i] = new float[arry02_rows];
    } //创建矩阵
    for (int i = 0; i < arry01_lines; i++)
    {
        for (int c = 0; c < arry02_rows; c++)
        {
            float x = 0;
            for (int y = 0; y < arry01_rows; y++)
            {
                x += arry01[i][y] * arry02[y][c];
            }
            arry[i][c] = x;
        }
    }
    return arry;
}
//行最简式
float **RowSimplestM(float **arry_, int lines, int rows)
{
    float **arry = new float *[lines];
    for (int i = 0; i < lines; i++)
    {
        arry[i] = new float[rows];
    } //创建新函数
    for (int i = 0; i < lines; i++)
    {
        for (int c = 0; c < rows; c++)
        {
            arry[i][c] = arry_[i][c];
        }
    }          //赋值
    int x = 0; //多出的0的数量
    for (int i = 0; i < lines; i++)
    {
        if (arry[i][i + x] == 0)
            x++;
        else
        {
            for (int y = 0; y < lines; y++)
            {
                if (y != i)
                {
                    float k = arry[y][i + x] / arry[i][i + x]; //求k值
                    arry[y][i + x] = 0;
                    for (int z = x + i + 1; z < rows; z++)
                    {
                        arry[y][z] -= k * arry[i][z];
                    }
                }
            }
        }
    }
    //每行首个不为0的数化1
    for (int i = 0; i < lines; i++)
    {
        bool isK = true;
        float k = 0;
        for (int c = i; c < rows; c++)
        {
            if (arry[i][c] != 0)
            {
                if (isK)
                    k = arry[i][c];
                arry[i][c] /= k;
                isK = false;
            }
        }
    }
    return arry;
}
//行列式
int DeterminantM(float **arry, int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        if (n >= 3)
        {
            float **arry_ = new float *[n - 1];
            for (int i = 0; i < n - 1; i++)
            {
                arry_[i] = new float[n - 1];
            } //创建余子式
            for (int x = 0; x < n - 1; x++)
            {
                for (int y = 0; y < n - 1; y++)
                {
                    if (x < i)
                        arry_[x][y] = arry[x][y + 1];
                    else if (x >= i)
                        arry_[x][y] = arry[x + 1][y + 1];
                }
            }                                                                                                         //为余子式赋值
            total += i % 2 == 0 ? arry[i][0] * DeterminantM(arry_, n - 1) : -arry[i][0] * DeterminantM(arry_, n - 1); //计算
        }
        else if (n == 2)
        {
            total = arry[0][0] * arry[1][1] - arry[0][1] * arry[1][0];
        }
        else
            total = arry[0][0];
    }
    return total;
}
//矩阵的秩
int RankM(float **arry, int lines, int rows)
{
    arry = RowSimplestM(arry, lines, rows);
    int x = 0;
    int y = 0;
    for (int i = 0; i < lines; i++)
    {
        for (int c = 0; c < rows; c++)
        {
            if (arry[i][c] != 0)
            {
                x++;
                break;
            }
        }
    }
    for (int c = 0; c < rows; c++)
    {
        for (int i = 0; i < lines; i++)
        {
            if (arry[i][c] != 0)
            {
                y++;
                break;
            }
        }
    }
    return x < y ? x : y;
}
int main()
{
    srand((unsigned int)time(NULL));
    int m = 0;
    int l = 0;
    int n = 0;
STATE:
    cout << "输入m:" << endl;
    cin >> m;
    cout << "输入l:" << endl;
    cin >> l;
    cout << "输入n:" << endl;
    cin >> n;
    if (m < 1 || l < 1 || n < 1)
    {
        cout << "错误";
        goto STATE;
    }
    float **A1 = CreateM(m, l);
    float **B1 = CreateM(l, n);
    cout << "矩阵A1为" << endl;
    PrintMatrix(A1, m, l);
    cout << "矩阵B1为" << endl;
    PrintMatrix(B1, l, n);
    cout << "A1乘B1得矩阵：" << endl;
    PrintMatrix(MultiplicationM(A1, B1, m, l, n), m, n);
    cout << "矩阵A1的行最简型为：" << endl;
    PrintMatrix(RowSimplestM(A1, m, l), m, l);
    cout << "矩阵B1的行最简型为：" << endl;
    PrintMatrix(RowSimplestM(B1, l, n), l, n);
    if (m == l)
        cout << "矩阵A1的行列式为：" << DeterminantM(A1, m) << endl;
    if (l == n)
        cout << "矩阵B1的行列式为：" << DeterminantM(B1, l) << endl;

    cout << "矩阵A1的秩为：" << RankM(A1, m, l) << endl;
    cout << "矩阵B1的秩为：" << RankM(B1, l, n) << endl;
    system("pause");
}