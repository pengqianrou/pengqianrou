#include <iostream> 
#include <fstream>  
#include <string> 
using namespace std; 
 
const int N = 5;
const int M = 1000;
ifstream fin("4d5.txt"); 
 
template<class Type>
void Dijkstra(int n,int v,Type dist[],int prev[],Type c[][N+1]);
void Traceback(int v,int i,int prev[]);//������·�� vԴ�㣬i�յ�
 
int main()
{
	int v = 1;//Դ��Ϊ1
	int dist[N+1],prev[N+1],c[N+1][N+1];
 
	cout<<"����ͼȨ�ľ���Ϊ��"<<endl;
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++)
		{
			fin>>c[i][j];    
            cout<<c[i][j]<<" ";  
		}
		cout<<endl;
	}
 
	Dijkstra(N,v,dist,prev,c);
 
	for(int i=2; i<=N; i++)
	{
		cout<<"Դ��1����"<<i<<"�����·������Ϊ:"<<dist[i]<<"����·��Ϊ";
		Traceback(1,i,prev);
		cout<<endl;
	}
 
	return 0;
}
 
 
template<class Type>
void Dijkstra(int n,int v,Type dist[],int prev[],Type c[][N+1])
{
	bool s[N+1];
	for(int i=1; i<=n; i++)
	{
		dist[i] = c[v][i];//dist[i]��ʾ��ǰ��Դ������i���������·������
		s[i] = false;
 
		if(dist[i] == M)
		{
			prev[i] = 0;//��¼��Դ������i�����·��i��ǰһ������
		}
		else
		{
			prev[i] = v;
		}
	}
 
	dist[v] = 0;
	s[v] = true;
 
	for(int i=1; i<n; i++)
	{
		int temp = M;
		int u = v;//��һ����
 
		//ȡ��V-S�о����������·�����ȵĶ���u
		for(int j=1; j<=n; j++)
		{
			if((!s[j]) && (dist[j]<temp))
			{
				u = j;
				temp = dist[j];
			}
		}
		s[u] = true;
 
		//����������̰��ѡ�����Distֵ
		for(int j=1; j<=n; j++)
		{
			if((!s[j]) && (c[u][j]<M))
			{
				Type newdist = dist[u] + c[u][j];
				if(newdist < dist[j])
				{
					dist[j] = newdist;
					prev[j] = u;
				}
			}
		}
	}
}
 
//������·�� vԴ�㣬i�յ�
void Traceback(int v,int i,int prev[])
{
	if(v == i)
	{
		cout<<i;
		return;
	}
	Traceback(v,prev[i],prev);
	cout<<"->"<<i;
}
