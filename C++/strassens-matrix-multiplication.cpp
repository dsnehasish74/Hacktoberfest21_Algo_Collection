//Q1 iii) STRASSEN'S MATRIX MULTIPLICATION
//CODE BY JATIN DHALL 20BCE0832
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;

int nextpowerof2(int k)
{
    return pow(2, int(ceil(log2(k))));
}
void display(vector< vector<int>> &matrix, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j != 0)
            {
                cout << "\t";
            }
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

void add(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int size)
{
    int i, j;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void sub(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int size)
{
    int i, j;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void STRASSEN_algorithmA(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int size)
{
    //base case
    if (size == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    else
    {
        int new_size = size / 2;
        vector<int> z(new_size);
        vector<vector<int>>
            a11(new_size, z), a12(new_size, z), a21(new_size, z), a22(new_size, z),
            b11(new_size, z), b12(new_size, z), b21(new_size, z), b22(new_size, z),
            c11(new_size, z), c12(new_size, z), c21(new_size, z), c22(new_size, z),
            p1(new_size, z), p2(new_size, z), p3(new_size, z), p4(new_size, z),
            p5(new_size, z), p6(new_size, z), p7(new_size, z),
            aResult(new_size, z), bResult(new_size, z);

int i, j;

//dividing the matrices into sub-matrices:
for (i = 0; i < new_size; i++)
        {
            for (j = 0; j < new_size; j++)
            {
                a11[i][j] = A[i][j];
                a12[i][j] = A[i][j + new_size];
                a21[i][j] = A[i + new_size][j];
                a22[i][j] = A[i + new_size][j + new_size];

                b11[i][j] = B[i][j];
                b12[i][j] = B[i][j + new_size];
                b21[i][j] = B[i + new_size][j];
                b22[i][j] = B[i + new_size][j + new_size];
            }
}

// Calculating p1 to p7:

        add(a11, a22, aResult, new_size);     // a11 + a22
        add(b11, b22, bResult, new_size);    // b11 + b22
        STRASSEN_algorithmA(aResult, bResult, p1, new_size); 
        // p1 = (a11+a22) * (b11+b22)

        add(a21, a22, aResult, new_size); // a21 + a22
        STRASSEN_algorithmA(aResult, b11, p2, new_size);
        // p2 = (a21+a22) * (b11)

        sub(b12, b22, bResult, new_size);      // b12 - b22
        STRASSEN_algorithmA(a11, bResult, p3, new_size);
        // p3 = (a11) * (b12 - b22)

        sub(b21, b11, bResult, new_size);       // b21 - b11
        STRASSEN_algorithmA(a22, bResult, p4, new_size); 
        // p4 = (a22) * (b21 - b11)

        add(a11, a12, aResult, new_size);      // a11 + a12
        STRASSEN_algorithmA(aResult, b22, p5, new_size);
        // p5 = (a11+a12) * (b22)

        sub(a21, a11, aResult, new_size);      // a21 - a11
        add(b11, b12, bResult, new_size);               
        // b11 + b12
        STRASSEN_algorithmA(aResult, bResult, p6, new_size);
        // p6 = (a21-a11) * (b11+b12)

        sub(a12, a22, aResult, new_size);      // a12 - a22
        add(b21, b22, bResult, new_size);                
        // b21 + b22
        STRASSEN_algorithmA(aResult, bResult, p7, new_size);
        // p7 = (a12-a22) * (b21+b22)

        // calculating c21, c21, c11 e c22:

        add(p3, p5, c12, new_size); // c12 = p3 + p5
        add(p2, p4, c21, new_size); // c21 = p2 + p4

        add(p1, p4, aResult, new_size);       // p1 + p4
        add(aResult, p7, bResult, new_size);  // p1 + p4 + p7
        sub(bResult, p5, c11, new_size); // c11 = p1 + p4 - p5 + p7

        add(p1, p3, aResult, new_size);       // p1 + p3
        add(aResult, p6, bResult, new_size);  // p1 + p3 + p6
        sub(bResult, p2, c22, new_size); // c22 = p1 + p3 - p2 + p6

        // Grouping the results obtained in a single matrix:
        for (i = 0; i < new_size; i++)
        {
            for (j = 0; j < new_size; j++)
            {
                C[i][j] = c11[i][j];
                C[i][j + new_size] = c12[i][j];
                C[i + new_size][j] = c21[i][j];
                C[i + new_size][j + new_size] = c22[i][j];
            }
        }
    }
}
void STRASSEN_algorithm(vector<vector<int>> &A, vector<vector<int>> &B, int m, int n, int a, int b)
{  
/* Check to see if these matrices are already square and have dimensions of a power of 2. If not,
 * the matrices must be resized and padded with zeroes to meet this criteria. */
    int k = max({m, n, a, b});

    int s = nextpowerof2(k);

    vector<int> z(s);
    vector<vector<int>> Aa(s, z), Bb(s, z), Cc(s, z);

    for (unsigned int i = 0; i < m; i++)
    {
        for (unsigned int j = 0; j < n; j++)
        {
            Aa[i][j] = A[i][j];
        }
    }
    for (unsigned int i = 0; i < a; i++)
    {
        for (unsigned int j = 0; j < b; j++)
        {
            Bb[i][j] = B[i][j];
        }
    }
    STRASSEN_algorithmA(Aa, Bb, Cc, s);
    vector<int> temp1(b);
    vector<vector<int>> C(m, temp1);
    for (unsigned int i = 0; i < m; i++)
    {
        for (unsigned int j = 0; j < b; j++)
        {
            C[i][j] = Cc[i][j];
        }
    }
    display(C, m, b);
}

bool check(int n, int a)
{
    if (n == a)
        return true;
    else
        return false;
}

int main()
{
    int m, n, a, b;
    cout << "Matrix Multiplication using Strassen algorithm" << endl;
    cout << "Enter rows and columns of first matrix" << endl;
    cin >> m >> n;
    cout << "enter values into first matrix" << endl;
    vector<vector<int>> A;
    //first matrix input
    for (int i = 0; i < m; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            int i;
            cin >> i;
            temp.push_back(i);
        }
        A.push_back(temp);
    }
    cout << "Enter rows and columns of second matrix" << endl;
    cin >> a >> b;
    cout << "enter values into second matrix" << endl;
    vector<vector<int>> B;
    //second matrix input
    for (int i = 0; i < a; i++)
    {
        vector<int> temp;
        for (int j = 0; j < b; j++)
        {
            int i;
            cin >> i;
            temp.push_back(i);
        }
        B.push_back(temp);
    }


    auto start = high_resolution_clock::now();
    bool k = check(n, a);
    if (k)
    {
        STRASSEN_algorithm(A, B, m, n, a, b);
    }
    else
    {
        cout << "martrix multiplication not possible";
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
  
    // To get the value of duration use the count()
    // member function on the duration object
    cout << "Execution Time : "<<duration.count() <<" Microseconds"<< endl;
    return 0;
}