#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

void mkpair(int step, int sum);
int mkclocknum(int i,int j, int k, int u);

vector<int> v;
int main(void)
{
	int a[4];
	int b[4];
	int num=10000;
	cin>>a[0]>>a[1]>>a[2]>>a[3];
	
	num=mkclocknum(a[0],a[1],a[2],a[3]);
//	cout<<"clnum:"<<num;
	
	mkpair(1,0);
	sort(v.begin(),v.end());

//	for(int i=0;i<100;i++)
//		cout<<v[i]<<" ";

	int count=0;
	while(1)
	{
		if(num == v[count])
		{
			count++;
			break;
		}
		count++;
	}
	cout<<count<<"\n";
	return 0;
}

int mkclocknum(int i, int j, int k, int u)
{
	int num=10000;
	int b[4];
	b[0]=i*1000+j*100+k*10+u;
	b[1]=j*1000+k*100+u*10+i;
	b[2]=k*1000+u*100+i*10+j;
	b[3]=u*1000+i*100+j*10+k;
	
	for(int i=0;i<4;i++)
		if(num>b[i])
			num=b[i];
	return num;

}
void mkpair(int step, int sum)
{
	for(int i=1;i<=9;i++)
	{
		for(int j=1;j<=9;j++)
		{
			for(int k=1;k<=9;k++)
			{
				for(int u=1;u<=9;u++)
				{
					int temp=i*1000+j*100+k*10+u;
					int tclock=mkclocknum(i,j,k,u);
					if(temp == tclock)
						v.push_back(temp);
				}
			}
		}
	}
}
