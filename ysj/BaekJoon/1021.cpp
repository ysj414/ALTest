#include<iostream>
#define LEFT	-1
#define RIGHT	 1
using namespace std;

int num[55];
int ans[55];
int N,M;
void rot(int arr[], int count, int dir,int len);
void Del_num(int arr[],int len);
void Print(int arr[],int len);
int main(void)
{

	cin>>N>>M;
	for(int i=0; i<N; i++)
		num[i]=i+1;
	for(int i=0; i<M; i++)
		cin>>ans[i];
//	cout<<"N arr:";
//	Print(num,N);
//	cout<<"M arr:";
//	Print(ans,M);

	int Len=N;
	int right,left;
	int cnt=0;
	for(int i=0; i<M; i++)
	{
		for(int j=0; j<Len; j++)
		{
			if(num[j] == ans[0])
			{
					right=j;
					left=Len-j;
					break;
			}
		}
		
		int cursor = (right<=left)? RIGHT : LEFT;
		if(right != 0 && left !=0)
		{
		if(cursor == RIGHT)
		{
//			cout<<"R\n";
			rot(num,right,cursor,Len);
			cnt+=right;
		}
		else if(cursor == LEFT)
		{	
//			cout<<"L\n";
			rot(num,left,cursor,Len);
			cnt+=left;
		}
		}
//		cout<<"1Step Result:";
//		Print(num,Len);
//		Print(ans,M);

		Del_num(num,Len);
		Del_num(ans,M-i);
		Len--;
//		cout<<"Del Result:";
//		Print(num,Len);
//		Print(ans,M-i);
	}
		cout<<cnt<<"\n";

	return 0;
}
void rot(int arr[], int count, int dir, int len)
{
	if(dir == RIGHT)
	{
		while(count--)
		{
			int temp=arr[0];
			for(int i=0;i<len-1;i++)
				arr[i]=arr[i+1];
			arr[len-1]=temp;
		}
	}
	else
	{
		while(count--)
		{
		    int temp=arr[len-1];
			for(int i=len-1;i>0;i--)
				arr[i]=arr[i-1];
			arr[0]=temp;
		}
	}
}
void Del_num(int arr[],int len)
{
	for(int i=0;i<len-1;i++)
		arr[i]=arr[i+1];
	arr[len-1]=0;
}
void Print(int arr[], int len)
{
	cout<<"[ ";
	for(int i=0;i<len;i++)
		cout<<arr[i]<<" ";
	cout<<"]\n";
}
