#include<iostream>
using namespace std;
int main()
{
	int p1,q1;
	cout<<"enter number of process\n";
	cin>>p1;
	cout<<"enter number of resources\n";
	cin>>q1;
	
	char p[p1],q[q1];
	int need[p1];
	int i;
		cout<<"enter resources name\n ";
	for(i=0;i<q1;i++)
	{
		cin>>q[i];
	}
	int sum=0;
	for(i=0;i<p1;i++)
	{
			cout<<"enter process name\n";
		cin>>p[i];
			cout<<"enter max need\n";
			cin>>need[i];
			if(need[i]>q1)
			{
				cout<<"deadlock occurred\n";
				break;
			}
			else
			{
				cout<<"allocated resources\n";
			}
			sum=sum+need[i];
	}
	if(sum>(p1+q1))
	{
		cout<<"deadlock occurred request to next process can not be given\n ";
	}
	else
	{
    	cout<<"resource can be allocated\n ";
	}



}

