#include<iostream>
using namespace std;
int lyr(int yr)
{
	if(yr%4==0&&yr%100!=0)
        return 1;
	if(yr%400==0)
        return 1;
	else
        return 0;
}
class Date
{
	int dd;
	int mm;
	int yy;
	public:

		Date nextday()
		{
			Date D1;
			D1.dd=dd;
			D1.mm=mm;
			D1.yy=yy;
				if( dd==31 || (dd==30 && (mm==4 || mm==6 || mm==9 || mm==11)) ||( dd==29 && mm==2) || ( dd==28 && (mm==2 && lyr (yy)==0)))
				{
					D1.dd=1;
					if(mm!=12)
					{
						D1.mm=mm+1;
					}
					if(mm==12)
					{
						D1.mm=1;
						D1.yy=yy+1;
					}
				}

				else
				{
					D1.dd=dd+1;
				}
				return D1;
		}
		void Getdate()
		{
			cout<<"Enter the date, month and year in order: \n";
			cin>>dd>>mm>>yy;
		}
		void Printdate()
		{
			cout<<dd<<"/"<<mm<<"/"<<yy;
		}

};
int main()
{
	Date D2[365],D3;
	int i;

	cout<<"Enter the date to start from: \n";
	D3.Getdate();
	cout<<endl;
	D2[0]=D3.nextday();
	cout<<"\n The next day is:\n";
	D2[0].Printdate();
	cout<<endl;
	for(i=1;i<100;i++)
	{
		cout<<"The next day is: \n";
		D2[i]=D2[i-1].nextday();
		D2[i].Printdate();
		cout<<endl;
	}
}
