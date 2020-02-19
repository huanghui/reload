#include<stdio.h>
#include<iostream>
#include<vector>
#include<time.h>
//#include<algorithm.h>
#include <algorithm>
//#include <algorithm.h>
#include<exception>
using namespace std;


int cmpint(const void* a,const void* b) {
	if (a > b)
	{
		return 1;
	}
	else if(a<b)
	{
		return -1;
	}
	else
	{
		return 0;
	}	

}


int main()
{
	char a[16];
	int i=0;
	snprintf(a,9,"%1d",123323);
	//printf("a=%s,i=%d", a, i);
	cout << a << endl;
	cout << i << endl;

	/*cout << rand()% 100 << endl;
	cout << rand() % 100 << endl;
	cout << rand() % 100 << endl;
	cout << rand() % 100 << endl;
	cout << rand() % 100 << endl;
	cout << rand() % 100 << endl;*/ //随机数的产生实验函数。

	vector<int> List;//定义一个向量
	
	int len = 10000000;
	int target = 23456;
	time_t t_start,t_end,time; //定义时间

	t_start = clock();
	for (int i = 0; i < len; i++)
	{
		List.push_back(rand()%1000000);
	}
	t_end = clock();
	time= t_end - t_start;
	cout << "Time cost to push data into the vector "<< time<<" ms"<< endl;

	t_start=clock();
	auto Iter=::find(List.begin(),List.end(),target);
	t_end= clock();
	time =t_end - t_start;
	if (Iter != List.end())
	{
		cout << "target is "<<target << endl;
		cout << "find time ="<<time <<"ms"<< endl; 
	}
	
///////////////////快速排序///////////////////////////////////////	
	t_start = clock();
	//sort(List.begin(),List.end()); //采用stl提供的模板sort直接排序，用快速排序看看计算时间有多少。

	qsort(&List.front(),len,sizeof(int),&cmpint);//采用快速排序，但快速排序需要自己定义比较函数，在此次vector向量里面，需要自定义。
	t_end = clock();
	time = t_end - t_start;
	cout<<"qsort time cost "<< time<<" ms"<<endl;

//////////////////////////////////////////////////


	t_start = clock();
	//qsort(List,1000000,)
	try {
		//binary_search(List.begin(), List.end(), target);//二分查找法查找向量的数据，已经成功实现该功
		bsearch(&target,&List.front(),len,sizeof(int),&cmpint); //用bsearch查找，其实效果一样的，只是传入的参数有点奇怪
		cout << "sort find target time "<<target << endl; 
	}
	catch(exception& e){
		cout<< "target not found"<< endl;
	}
	t_end = clock();
	time = t_end - t_start;
	cout << "Find time =" << time << " ms" << endl;

	//cout<<value<<endl;
	
	/*char List[100000000];
	

	for (int i=0;i< 100000000;i++)
	{
		//cin >> rand() >> endl;
		List[i]=rand()%23456;
	}
	::find();*/
}