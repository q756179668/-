#include<iostream>
#include<string.h>
#include<math.h>

using namespace std;

long n, m, a[1100], b[1100];
long find_value(long pixel, long cow)//����pixel��,cow�е�����ֵ
{
	long i, t, max, sum = 0;
	max = (pixel - 1)*n + cow;
	for (i = 0; i<1100; i++)
	if (sum >= max)
	{
		t = i - 1; break;
	}
	else sum += b[i];
	return a[i - 1];
}
long get_biggest(long pixel, long cow)//����pixel��,cow�еĴ�������ֵ
{
	long i, j, max = -1, t;
	t = find_value(pixel, cow);
	if (m == 1 && n == 1)  return t;
	else if (m == 1)
	{
		if (cow == 1)
			return abs(find_value(1, 1) - find_value(1, 2));
		else if (cow == n)
			return abs(find_value(1, n - 1) - find_value(1, n));
		else
		{
			if (abs(find_value(pixel, cow - 1) - t)>max)  max = abs(find_value(pixel, cow - 1) - t);
			if (abs(find_value(pixel, cow + 1) - t)>max)  max = abs(find_value(pixel, cow + 1) - t);
		}
	}
	else if (n == 1)
	{
		if (pixel == 1)
			return abs(find_value(1, 1) - find_value(2, 1));
		else if (pixel == m)
			return abs(find_value(m - 1, 1) - find_value(m, 1));
		else
		{
			if (abs(find_value(pixel - 1, cow) - t)>max)  max = abs(find_value(pixel - 1, cow) - t);
			if (abs(find_value(pixel + 1, cow) - t)>max)  max = abs(find_value(pixel + 1, cow) - t);
		}
	}
	else if (pixel>1 && pixel<m&&cow>1 && cow<n)//�Ǳ߽�Ԫ��
	{
		for (i = pixel - 1, j = cow - 1; j <= cow + 1; j++)
		if (abs(find_value(i, j) - t)>max)
			max = abs(find_value(i, j) - t);
		if (abs(find_value(pixel, cow - 1) - t) >= max)  max = abs(find_value(pixel, cow - 1) - t);
		if (abs(find_value(pixel, cow + 1) - t) >= max)  max = abs(find_value(pixel, cow + 1) - t);
		for (i = pixel + 1, j = cow - 1; j <= cow + 1; j++)
		if (abs(find_value(i, j) - t)>max)
			max = abs(find_value(i, j) - t);
		return max;
	}
	else//�߽�Ԫ��
	{
		if (pixel == 1 && cow == 1)//meiyou
		{
			if (abs(find_value(1, 2) - t)>max) max = abs(find_value(1, 2) - t);
			if (abs(find_value(2, 2) - t)>max) max = abs(find_value(2, 2) - t);
			if (abs(find_value(2, 1) - t)>max) max = abs(find_value(2, 1) - t);
		}
		else if (pixel == 1 && cow == n)
		{
			if (abs(find_value(1, n - 1) - t)>max)  max = abs(find_value(1, n - 1) - t);
			if (abs(find_value(2, n - 1) - t)>max)  max = abs(find_value(2, m - 1) - t);
			if (abs(find_value(2, n) - t)>max)    max = abs(find_value(2, n) - t);
		}
		else if (pixel == m&&cow == 1)
		{
			if (abs(find_value(m - 1, 1) - t)>max) max = abs(find_value(m - 1, 1) - t);
			if (abs(find_value(m - 1, 2) - t)>max) max = abs(find_value(m - 1, 2) - t);
			if (abs(find_value(m, 2) - t)>max)   max = abs(find_value(m, 2) - t);
		}
		else if (pixel == m&&cow == n)
		{
			if (abs(find_value(m - 1, n) - t)>max)    max = abs(find_value(m - 1, n) - t);
			if (abs(find_value(m, n - 1) - t)>max)    max = abs(find_value(m, n - 1) - t);
			if (abs(find_value(m - 1, n - 1) - t)>max)  max = abs(find_value(m - 1, n - 1) - t);
		}
		else if (pixel == 1 && cow != 1 && cow != n)//��һ�зǵ�һ�к͵�n��
		{
			if (abs(find_value(1, cow - 1) - t)>max)  max = abs(find_value(1, cow - 1) - t);
			if (abs(find_value(1, cow + 1) - t)>max)  max = abs(find_value(1, cow + 1) - t);
			for (i = pixel + 1, j = cow - 1; j <= cow + 1; j++)
			if (abs(find_value(i, j) - t)>max)
				max = abs(find_value(i, j) - t);
		}
		else if (pixel == m&&cow != 1 && cow != n)//��m�зǵ�һ�к͵�n��
		{
			if (abs(find_value(m, cow - 1) - t)>max)  max = abs(find_value(m, cow - 1) - t);
			if (abs(find_value(m, cow + 1) - t)>max)  max = abs(find_value(m, cow + 1) - t);
			for (i = pixel - 1, j = cow - 1; j <= cow + 1; j++)
			if (abs(find_value(i, j) - t)>max)
				max = abs(find_value(i, j) - t);
		}
		else if (pixel != 1 && pixel != m&&cow == 1)//��һ�зǵ�һ�к͵�m��
		{
			if (abs(find_value(pixel - 1, 1) - t)>max)  max = abs(find_value(pixel - 1, 1) - t);
			if (abs(find_value(pixel + 1, 1) - t)>max)  max = abs(find_value(pixel + 1, 1) - t);
			for (i = pixel - 1, j = cow + 1; i <= pixel + 1; i++)
			if (abs(find_value(i, j) - t)>max)
				max = abs(find_value(i, j) - t);
		}
		else if (pixel != 1 && pixel != m&&cow == n)//��n�зǵ�һ�к͵�m��
		{
			if (abs(find_value(pixel - 1, n) - t)>max)  max = abs(find_value(pixel - 1, n) - t);
			if (abs(find_value(pixel + 1, n) - t)>max)  max = abs(find_value(pixel + 1, n) - t);
			for (i = pixel - 1, j = cow - 1; i <= pixel + 1; i++)
			if (abs(find_value(i, j) - t)>max)
				max = abs(find_value(i, j) - t);
		}
	}
	return max;
}
int main()
{
	long i, j, p, count, sum;

	while (scanf_s("%ld", &n) != EOF)
	{
		if (n == 0)   break;
		sum = 0; count = 1;
		for (i = 0;; i++)
		{
			scanf_s("%ld%ld", &a[i], &b[i]);
			sum += b[i];
			m = sum / n;
			if (a[i] == 0 && b[i] == 0)  break;
		}
		printf("%ld\n", n);
		if (i == 1)  printf("%ld %ld\n", 0, b[0]);
		else if (i == 2)
		{
			printf("%ld %ld\n", 0, b[0] - n);
			printf("%ld %ld\n", abs(a[0] - a[1]), 2 * n);
			printf("%ld %ld\n", 0, b[1] - n);
		}
		else
		{
			p = get_biggest(1, 1);
			for (i = 1; i <= m; i++)
			{
				if (i == 1)  j = 2;
				else j = 1;
				for (; j <= n; j++)
				{
					if (get_biggest(i, j) == p)
						count++;
					else
					{
						printf("%ld %ld\n", p, count);
						p = get_biggest(i, j);
						count = 1;
					}
				}
			}
			printf("%ld %ld\n", p, count);
		}
		printf("0 0\n");
	}
	printf("0\n");
	return 0;
}
