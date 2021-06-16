#include<stdio.h>


int main(void)
{

	int n,w,L;
	int truck[1001]={0,};
	int bridge[101]={0,};
	int i,j;
	int time=0;

	scanf("%d %d %d", &n,&w,&L);

	for(i=1; i<=n; i++)
		scanf("%d",&truck[i]);

	int num=1;
    int cur_weight;
    while(num<=n)
    {
        time++;
        cur_weight=0;

        for(i=w-1; i>0; i--)
            bridge[i]=bridge[i-1];
        bridge[0] = 0;

        for(i=0; i<w; i++)
            cur_weight+=bridge[i];

        if((cur_weight + truck[num]) <= L)
        {
            bridge[0]=truck[num];
            num++;
        }
//		printf("time:%d, current_weight:%d\n",time,cur_weight);
//		for(i=0; i<w; i++)
//			printf("bridge[%d]:%d\n",i,bridge[i]);
    }

    time+=w;
    printf("%d\n",time);

	 

	return 0;
}
