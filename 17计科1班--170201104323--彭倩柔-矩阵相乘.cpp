#include<iostream>
#include<string.h>
 
using namespace std;
 
int a[1000];
int s[1000][1000];
 
int Matrix(int n){
	int **m = new int *[n];
	for(int i = 0; i < n; i++){
		m[i] = new int [n];
		memset(m[i], 0, sizeof(int) * n); //m[i][i]同时设置为0 
	}
	//跨度
	for(int i = 1; i < n - 1; i++){
		//第j行
		for(int j = 1; j < n; j++){
			if(j + i >= n) break;
			//每个合法元素为m[j][j + i]
			int min = 0, temp = 0;
			min = m[j + 1][j + i] + a[j - 1] * a[j] * a[j + i];
			s[j][j + i] = j;
			for(int k = j + 1; k < j + i; k++){
				temp = m[j][k] + m[k + 1][j + i] + a[j - 1] * a[k] * a[j + i];
				if(temp < min){
					min = temp;
					s[j][j + i] = k;
				}
			}
			m[j][j + i] = min;
		}
	}
	return m[1][n - 1];
}
 
 
void TraceBack(int i, int j){
	if(i == j){
		cout << 'A' << i;
		return ;
	}
	cout << "(";
	TraceBack(i, s[i][j]);
	TraceBack(s[i][j] + 1, j);
	cout << ")";
}
 
 
int main(){
	char ch = ' ';
	int M;
	cin >> M;
	getchar();
	for(int i = 0; i < M; i++){
		int n = 0, times = 0;
		memset(a, 0, sizeof(int) * 1000);
		for(int i = 0; i < 1000; i++) memset(s[i], 0, sizeof(int) * 1000);
		for(int i = 0; ch != '\n'; i++, n++){
			scanf("%d", &a[i]);
			ch = getchar();
		}
		times = Matrix(n);
		cout << times << endl;
		TraceBack(1, n - 1);
		ch = ' ';
	}
	return 0;
}
