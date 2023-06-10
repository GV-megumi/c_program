/*操作系统：页面置换算法*/

#include <stdio.h>
#include <stdlib.h>

#define N 100
/*给数组赋值*/

void setarray(int arr[], int num, int val)
{
	int i;
	for (i = 0; i < num; ++i)
		arr[i] = val;
}

/*查找内存 mem 中是否存在页面 page*/
int findexist(int **mem,int k, int mnum, int page)
{
	int i;
	for (i = 0; i < mnum; i++)
	{
		if (mem[i][k] == page) return i;
	}
	return -1;
}
/*查找内存 mem 中是否存空的位置*/
int findempty(int **mem,int k, int mnum)
{
	int i;
	for (i = 0; i < mnum; i++)
	{
		if (mem[i][k] == -1) return i;
	}
	return -1;
}

void initarr(int** arr, int rnum, int cnum)
{
	int r, c;
	for (r = 0; r < rnum; ++r)
	{
		setarray(arr[r], cnum, -1);
			
	}
}



/*先进先出页面置换算法*/
int fifo(int req[], int rnum, int mnum, int** arr)
{
	int count;
	int i, j;
	int pos;
	int max;
	/*time 记录内存中每个页面进入的时间*/
	int* time = (int*)malloc(sizeof(int) * mnum);
	setarray(time, mnum, rnum);
	/*缺页率初始时为 0*/
	count = 0;
	for (i = 0; i < rnum; ++i)
	{
		/*发现页面请求是否存在内存中*/
		pos = findexist(arr,i, mnum, req[i]);
		/*如果内存中存在页面请求*/
		if (pos != -1) continue;
		/*如果内存中不存在缺页次数加一*/
		count++;
		/*内存中是否存在空位置可以存放新页面*/
		pos = findempty(arr,i, mnum);
		/*存在空位置，直接存入新页面，不做置换*/
		if (pos != -1)
		{
			for (j = i; j < rnum; j++)
				arr[pos][j] = req[i];
			time[pos] = i;
			continue;
		}
		/*不存在空位置，寻找要置换的页面，fifo*/

		pos = 0;
		for (j = 1; j < mnum; ++j)
		{
			if (time[j] < time[pos])
			{
				pos = j;
			}
		}
		for (j = i; j < rnum; j++)
			arr[pos][j] = req[i];
		time[pos] = i;

	}

	free(time);

	return count;
}



/*最近最久未使用页面置换算法*/
int lru(int req[], int rnum, int mnum, int** arr)
{
	int count;
	int i, j;
	int pos;
	int max;
	/*time 记录内存中每个页面最后访问的时间*/
	int* time = (int*)malloc(sizeof(int) * mnum);
	setarray(time, mnum, rnum);
	/*缺页率初始时为 0*/
	count = 0;
	for (i = 0; i < rnum; ++i)
	{
		/*发现页面请求是否存在内存中*/
		pos = findexist(arr, i, mnum, req[i]);
		/*如果内存中存在页面请求，此处与 fifo 有些许区别*/
		if (pos != -1)
		{
			time[pos] = i; /*此处 lru 记录的是最后一次的访问时间，而 fifo 中记录的是最
			先进入的时间*/
			continue;
		}
		/*如果内存中不存在缺页次数加一*/
		count++;
		/*内存中是否存在空位置可以存放新页面*/
		pos = findempty(arr, i, mnum);
		/*存在空位置，直接存入新页面，不做置换*/
		if (pos != -1)
		{
			for (j = i; j < rnum; j++)
				arr[pos][j] = req[i];
			time[pos] = i;
			continue;
		}
		/*不存在空位置，寻找要置换的页面，lru*/
		pos = 0;
		for (j = 1; j < mnum; ++j)
		{
			if (time[j] < time[pos])
			{
				pos = j;
			}
		}
		for (j = i; j < rnum; j++)
			arr[pos][j] = req[i];
		time[pos] = i;
	}
		free(time);
	
	return count;
}


/*最佳页面置换算法*/
int opt(int req[], int rnum, int mnum, int** arr)
{
	int count;
	int i, j;
	int pos;
	int max;
	/*time 记录内存中每个页面将来要访问的时间*/
	int* time = (int*)malloc(sizeof(int) * mnum);
	/*缺页率初始时为 0*/
	count = 0;
	for (i = 0; i < rnum; ++i)
	{
		/*发现页面请求是否存在内存中*/
		pos = findexist(arr,i, mnum, req[i]);
		/*如果内存中存在页面请求，此处与 fifo 相同*/
		if (pos != -1)
			continue;
		/*如果内存中不存在缺页次数加一*/
		count++;
		/*内存中是否存在空位置可以存放新页面*/
		pos = findempty(arr,i, mnum);
		/*存在空位置，直接存入新页面，不做置换*/
		if (pos != -1)
		{
			for (j = i; j < rnum; j++)
				arr[pos][j] = req[i];
			continue;
		}
		/*不存在空位置，寻找要置换的页面，opt*/
		setarray(time, mnum, rnum);
		int k;
		/*查找内存中每个页面在将来出现的最近时间*/

		for (j = 0; j < mnum; ++j)
		{
			for (k = i + 1; k < rnum; k++)
			{
				if (arr[j][i] == req[k])
				{
					time[j] = k;
					break;
				}
			}
		}
		pos = 0;
		for (j = 1; j < mnum; ++j)
		{
			if (time[j] > time[pos]) /*此处与 fifo 和 lru 有区别*/
			{
				pos = j;
			}
		}
		for (j = i; j < rnum; j++)
			arr[pos][j] = req[i];


	}
	free(time);
	return count;
}





void outarr(int** arr, int rnum, int cnum) {
	int r, c;
	for (r = 0; r < rnum; ++r)
	{
		for (c = 0; c < cnum; ++c)
			printf("%d\t", arr[r][c]);
		printf("\n");
	}
}
int main()
{
	int M=0;
	int request[N];
	int count;
	int n = 3;
/*
	ifstream pla;
	pla.open("a.txt", ios::in);
	while (pla.peek()!=EOF) {
		pla >> request[M];
		M++;
	}
	*/
	char c;
	FILE *fp = fopen("fifo.txt","r");
	while ((c = fgetc(fp))!=EOF) {
		if (c == ' ')
			continue;
		request[M] = (int)c-48;
		M++;
	}
	fclose(fp);

	int** arr = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
		arr[i] = (int*)malloc(sizeof(int) * M);
	initarr(arr, n, M);
	count = fifo(request, M, n, arr);
	printf("fifo: %d \n", count);
	printf("缺页率：%f\n", (double)count / M);
	outarr(arr, n, M);
	
	initarr(arr, n, M);
	count = lru(request, M, n, arr);
	printf("lru: %d \n", count);
	printf("缺页率：%f\n", (double)count / M);

	outarr(arr, n, M);
	
	initarr(arr, n, M);
	count = opt(request, M, n, arr);
	printf("opt: %d \n", count);
	printf("缺页率：%f\n", (double)count / M);
	outarr(arr, n, M);
	system("pause");
	return 0;
}