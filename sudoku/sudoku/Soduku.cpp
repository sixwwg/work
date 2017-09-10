// Soduku.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "cstdlib"
#include "time.h"
#include "algorithm"
#include "iostream"
#include "fstream"
#include "cstdio"
#pragma warning(disable:4996)
using namespace std;
int sodu[10][10];
int N,i,j;
int number, num=(3+1)%9+1;
bool judge(int i, int j)
{
	if (i > 9 || j > 9)
		return true;
	for (int count = 1; count <= 9; count++)
	{
		int k = rand() % 9 + 1;
		bool can = true;
		for (int m = 1; m < i; ++m)
			if (sodu[m][j] == k)
			{
				can = false;
				break;
			}
		if (can)
		{
			for (int n = 1; n < j; ++n)
				if (sodu[i][n] == k)
				{
					can = false;
					break;
				}
		}
		if (can)
		{
			int x = (i / 3) * 3 + 3;
			int y = (j / 3) * 3 + 3;
			if (i % 3 == 0)
			{
				x = i;
			}
			if (j % 3 == 0)
			{
				y = j;

			}
			for (int p = x - 2; p <= x; ++p)  // 检查在3×3的小方格中是否出现了同一个数字
			{
				if (can == false)   //跳出外层循环 
					break;
				for (int q = y - 2; q <= y; ++q)
					if (sodu[p][q] == k)
					{
						can = false;
						break;
					}
			}
		}
		if (can)
		{
			sodu[i][j] = k;
			if (j < 9)
			{
				if (judge(i, j + 1))  //到同一行的下一位置开始搜索 
					return true;
			}
			else
			{
				if (i < 9)
				{
					if (judge(i + 1, 1))   // 到下一行的第一个空格开始搜索
						return true;
				}
				else
					return true;  //i >= 9  && j >= 9  , 搜索结束 

			}
			sodu[i][j] = 0;   //关键这一步：找不到解就要回复原状，否则会对下面的搜索造成影响 
		}
}
		return false;  //1到9都尝试过都不行，则返回递归的上一步 
	

}
void init(void)
{
	for (i = 1; i < 10; i++)
	{
		for ( j = 1; j < 10; j++)
			sodu[i][j] = 0;
		
		
	}                                  // 初始化
	for (int i = 1; i <= 9; i++)
	{
		sodu[1][i] = i;

	}
	sodu[1][1] = num;
	sodu[1][num] = 1;
	random_shuffle(&(sodu[1][2]), &(sodu[1][10]));   //第一个数固定，后八位随机排列
	
	judge(2, 1);
}

int main()
{
	freopen("soduku.txt", "w", stdout);
	N = 100000;
	for (int w = 0; w < N; w++)
	{
		init();
	    for (int i = 1; i <= 9; i++)
	    {
		      for (int j = 1; j <= 9; j++)
			  printf("%d ",sodu[i][j]);
			  putchar('\n');
		}

		putchar('\n');
    }
	//fout << flush;
	//fout.close();

	return 0;

}
