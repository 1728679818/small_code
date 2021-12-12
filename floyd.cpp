#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int inf = 999999;
int mp[N][N], path[N][N];
int n, m;
void print(int a, int b)
{
    if (path[a][b] == -1)
        return;                  //��Ϊ��ʼ��ʼ��Ϊ-1������Ϳ��Ա������ڵ��ٴ����
    print(a, path[a][b]);        //ǰ�벿
    cout << path[a][b] << "-->"; //����õ�
    print(path[a][b], b);        //��벿
}
int main()
{
    cin >> n >> m;
    memset(path, -1, sizeof(path)); //��ʼ��-1
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i == j)
                mp[i][j] = 0;
            else
                mp[i][j] = inf;
    while (m -- ) {
    	int x, y, d; cin >> x >> y >> d;
    	mp[x][y] = mp[y][x] = min(mp[x][y], d);
	}
    //����ѭ��
    for (int k = 0; k < n; k++)
    {
        //��k��������ɳ�
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (mp[i][j] > mp[i][k] + mp[k][j]) //����ܹ����̾͸��¾���
                {
                    mp[i][j] = mp[i][k] + mp[k][j];
                    path[i][j] = k; //��¼���ɳڵĵ�
                }
    }
    while (1) {
    	cout << "���������" << endl;
		int a; cin >> a;
		cout << "�������յ�" << endl;
		int b; cin >> b; 
	    if (mp[a - 1][b - 1] == inf)
	    { //���߲�ͨ
	        cout << a << ' ' << b;
	        cout << " �������û��ͨ·\n\n";
	        continue;
	    }
	    cout << a << " �� " << b << " ���·������ " << mp[a - 1][b - 1] << endl;
	    cout << "������·��Ϊ\n";
	    cout << a << "-->";
	    print(a - 1, b - 1);
	    cout << b << ' ';
	    cout << endl << endl;
	}
    
}
