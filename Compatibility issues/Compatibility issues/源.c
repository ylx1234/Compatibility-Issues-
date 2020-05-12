#include<stdio.h>

typedef struct {
	int s;
	int f;
}l;


int main()
{
	l list[100];
	int n;
	scanf("%d", &n);//活动个数
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &list[i].s, &list[i].f);//每个活动开始和结束时间
	}
	for (int i = 0; i < n - 1; i++)  //对活动结束时间从前到后排序
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			l temp;
			if (list[j].f > list[j + 1].f)
			{
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
	int k = 0;
	for (int i = 0; i < n; i++) //对于和前面的活动相容的活动输出
	{
		if (i > 0)
		{
			if (list[i].s > list[k].f)
			{
				k = i;
				printf("活动%d:%d->%d\n", i, list[i].s, list[i].f);
			}
		}
		else
		{
			printf("活动%d:%d->%d\n-", i, list[i].s, list[i].f);
		}
	}

}