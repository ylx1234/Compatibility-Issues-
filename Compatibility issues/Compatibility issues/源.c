#include<stdio.h>

typedef struct {
	int s;
	int f;
}l;


int main()
{
	l list[100];
	int n;
	scanf("%d", &n);//�����
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &list[i].s, &list[i].f);//ÿ�����ʼ�ͽ���ʱ��
	}
	for (int i = 0; i < n - 1; i++)  //�Ի����ʱ���ǰ��������
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
	for (int i = 0; i < n; i++) //���ں�ǰ��Ļ���ݵĻ���
	{
		if (i > 0)
		{
			if (list[i].s > list[k].f)
			{
				k = i;
				printf("�%d:%d->%d\n", i, list[i].s, list[i].f);
			}
		}
		else
		{
			printf("�%d:%d->%d\n-", i, list[i].s, list[i].f);
		}
	}

}