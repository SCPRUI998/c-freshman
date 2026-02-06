#include<iostream>
#include <string>
#define MAX 100
using namespace std;
//1.显示通讯录的操作页面
void showmeun();
//2.添加联系人
struct Person
{
	string name;    // 姓名
	int age;       // 年龄
	string telenumber; // 电话号码
	string sex;      // 性别
	string address; // 住址
};
struct personaddr
{
	struct Person info;
};
int dengluperson(struct personaddr* stu, int count);
//3.显示联系人
void showperson(int count, struct personaddr* stu);
//4.修改联系人
int changeperson(struct personaddr* stu, int count);
//5.清空联系人
int cleanperson(struct personaddr* stu, int count);
//6.清空指定联系人
int cleanPointperson(struct personaddr* stu, int count);
int main()
{

	int count = 0;
	int flag = 0;
	int flag1 = 1;
	personaddr stu[MAX];
	showmeun();
	int select;
	while (true)
	{
		while (1)
		{
			cout << "请选择一种模式(0-6)" << endl;
			cin >> select;
			if (select > 5 || select < 0)
			{
				cout << "\t\t\t\t请重新输入" << endl;
			}
			else
			{
				break;
			}
		}
		switch (select)
		{
		case 0:
			cout << "\t\t\t\t欢迎您下次使用，系统即将退出" << endl;
			return 0;
		case 1:
			cout << "\t\t请填入以下信息" << endl;
			count = dengluperson(stu, count);
			cout << "\t       是否返回操作界面？(0-否[代表您即将退出系统],1-是)" << endl;
			break;
		case 2:
			showperson(count, stu);
			cout << "\t       是否返回操作界面？(0-否[代表您即将退出系统],1-是)" << endl;
			break;
		case 3:
			changeperson(stu, count);
			cout << "\t       您确定返回操作界面吗？(0-否[代表您即将退出系统],1-是)" << endl;
			break;
		case 4:
			count=cleanperson(stu, count);
			cout << "\t       是否返回操作界面？(0-否[代表您即将退出系统],1-是)" << endl;
			break;
		case 5:
			while (flag1)
			{
				count = cleanPointperson(stu, count);
				cout << "是否继续删除联系人？(0-否(若未添加联系人请输入‘0’)，1-是)" << endl;
				cin >> flag1;
				while (flag1 != 1 && flag1 != 0)
				{
					if (flag1 == 0 || flag1 == 1)
					{
						break;
					}
					cout << "\t\t\t\t请重新输入" << endl;;
					cin >> flag1;
				}
			}
			flag1 = 1;
			cout << "\t       是否返回操作界面？(0-否[代表您即将退出系统],1-是)" << endl;
			break;
		}
		cin >> flag;
		while (flag != 1&&flag!=0)
		{
			if (flag == 0||flag==1)
			{
					break;
			}
			cout << "\t\t\t\t请重新输入" << endl;;
			cin >> flag;
		}
		if (flag == 0)
		{
			select = 0;
			break;
		}
	}
	system("pause");
	return 0;
}
void showmeun()
{
	cout << "---\t1.添加联系人\t\t---" << endl;
	cout << "---\t2.显示联系人\t\t---" << endl;
	cout << "---\t3.修改联系人\t\t---" << endl;
	cout << "---\t4.清空联系人\t\t---" << endl;
	cout << "---\t5.删除特定联系人\t---" << endl;
	cout << "---\t0.退出通讯录\t\t---" << endl;
}
int dengluperson(struct personaddr* stu, int count)
{
	int flag = 1;
	int i = 0;
	for (; i < MAX; i++)
	{
		cout << "\t\t\t\t请输入姓名:" ;
		cin >> stu[count].info.name;
		cout << "\t\t\t\t请输入年龄:" ;
		cin >> stu[count].info.age;
		cout << "\t\t\t\t请输入电话号码:" ;
		cin >> stu[count].info.telenumber;
		cout << "\t\t\t\t请输入性别:" ;
		cin >> stu[count].info.sex;
		cout << "\t\t\t\t请输入住址:" ;
		cin >> stu[count].info.address;
		count++;
		cout << "\t是否停止添加(0为停止，1为继续)" << endl;
		cin >> flag;
		while (flag != 1 && flag != 0)
		{
			if (flag == 0 || flag == 1)
			{
				break;
			}
			cout << "\t\t\t\t请重新输入" << endl;;
			cin >> flag;
		}
		if (flag == 0)
		{
			break;
		}
	}
	if (i == MAX)
	{
		cout << "\t抱歉，您已经录入了100个人，此系统最多只能录入100个联系人，如需添加联系人，请清除或清空联系人" << endl;
	}
	return count;
}
void showperson(int count, struct personaddr* stu)
{
	if (count == 0)
	{
		cout << "\t\t\t\t您还未添加联系人" << endl;
	}
	for (int i = 0; i < count; i++)
	{
		cout << "\t\t\t\t-------------------------------------------------" << endl;
		cout << "\t\t\t\t|  " << "*******姓名:\t\t" << stu[i].info.name << "\t\t******\t|" << endl;
		cout << "\t\t\t\t|  " << "*******年龄:\t\t" << stu[i].info.age << "\t\t******\t|" << endl;
		cout << "\t\t\t\t|  " << "*******电话号码:\t" << stu[i].info.telenumber << "\t******\t|" << endl;
		cout << "\t\t\t\t|  " << "*******性别:\t\t" << stu[i].info.sex << "\t\t******\t|" << endl;
		cout << "\t\t\t\t|  " << "*******住址:\t\t" << stu[i].info.address << "\t\t******\t|" << endl;
		cout << "\t\t\t\t-------------------------------------------------" << endl;
	}
}
int changeperson(struct personaddr* stu, int count)
{
	if (count == 0)
	{
		cout << "\t\t\t\t您还未添加联系人" << endl;
		return 0;
	}
	for (int i = 0; i < count; i++)
	{
		cout << "\t\t\t\t---------------------------------------------------------" << endl;
		cout << "\t\t\t\t|  " << i << "." << "*******姓名:\t\t" << stu[i].info.name << "\t\t******\t|" << endl;
		cout << "\t\t\t\t---------------------------------------------------------" << endl;
	}
	while (1)
	{
		int select1;
		cout << "\t您想修改哪个联系人的信息?(输入-1可以退出至初始界面)" << endl;
		cin >> select1;
		if (select1 == -1)
		{
			break;
		}
		while (1)
		{
			if (select1 > count-1 || select1 < 0 && select1 != -1)
			{
				cout << "\t\t\t\t请重新输入" << endl;
			}
			else
			{
				break;
			}
		}
		while (1)
		{
			cout << "1.姓名" << endl;
			cout << "2.年龄" << endl;
			cout << "3.电话号码" << endl;
			cout << "4.性别" << endl;
			cout << "5.住址" << endl;
			cout << "0.退出" << endl;
			cout << "请选择您要修改的部分(请输入对应的序号):";
			int select2;
			cin >> select2;
			int flag = 0;
			if (select2 == 1)
			{
				cout << "\t\t\t\t请输入新的姓名：";
				cin >> stu[select1].info.name;
				cout << "\t\t\t\t====================" << endl;
				cout << "\t\t\t\t%%%%%操作成功!%%%%%" << endl;
				cout << "\t\t\t\t====================" << endl;
				cout << "\t请选择您要返回的界面0-[选择修改信息的界面],1-[选择联系人的界面{如果想退出此系统请先回到此界面后再退出}]？" << endl;
				cin >> flag;
				if (flag == 1)
				{
					break;
				}
			}
			else if (select2 == 2)
			{
				cout << "\t\t\t\t请输入新的年龄：";
				cin >> stu[select1].info.age;
				cout << "\t\t\t\t====================" << endl;
				cout << "\t\t\t\t%%%%%操作成功!%%%%%" << endl;
				cout << "\t\t\t\t====================" << endl;
				cout << "\t请选择您要返回的界面0-[选择修改信息的界面],1-[选择联系人的界面{如果想退出此系统请先回到此界面后再退出}]？" << endl;
				cin >> flag;
				if (flag == 1)
				{
					break;
				}
			}
			else if (select2 == 3)
			{
				cout << "\t\t\t\t请输入新的电话号码：";
				cin >> stu[select1].info.telenumber;
				cout << "\t\t\t\t====================" << endl;
				cout << "\t\t\t\t%%%%%操作成功!%%%%%" << endl;
				cout << "\t\t\t\t====================" << endl;
				cout << "\t请选择您要返回的界面0-[选择修改信息的界面],1-[选择联系人的界面{如果想退出此系统请先回到此界面后再退出}]？" << endl;
				cin >> flag;
				if (flag == 1)
				{
					break;
				}
			}
			else if (select2 == 4)
			{
				cout << "\t\t\t\t请输入新的性别：";
				cin >> stu[select1].info.sex;
				cout << "\t\t\t\t====================" << endl;
				cout << "\t\t\t\t%%%%%操作成功!%%%%%" << endl;
				cout << "\t\t\t\t====================" << endl;
				cout << "\t请选择您要返回的界面0-[选择修改信息的界面],1-[选择联系人的界面{如果想退出此系统请先回到此界面后再退出}]？" << endl;
				cin >> flag;
				if (flag == 1)
				{
					break;
				}
			}
			else if (select2 == 5)
			{
				cout << "\t\t\t\t请输入新的地址：";
				cin >> stu[select1].info.address;
				cout << "\t\t\t\t====================" << endl;
				cout << "\t\t\t\t%%%%%操作成功!%%%%%" << endl;
				cout << "\t\t\t\t====================" << endl;
				cout << "\t请选择您要返回的界面0-[选择修改信息的界面],1-[选择联系人的界面{如果想退出此系统请先回到此界面后再退出}]？" << endl;
				cin >> flag;
				if (flag == 1)
				{
					break;
				}
			}
			else if (select2 == 0)
			{
				break;
			}
			else
			{
				cout << "\t\t\t\t请重新输入" << endl;
			}
		}
	}
}
int cleanperson(struct personaddr* stu, int count)
{
	if (count == 0)
	{
		cout << "\t\t\t\t您还未添加联系人" << endl;
		return 0;
	}
	for (int i = 0; i < count; i++)
	{
		stu[i].info.address = '0';
		stu[i].info.age = NULL;
		stu[i].info.name = '0';
		stu[i].info.sex = '0';
		stu[i].info.telenumber = '0';
	}
	count = 0;
	cout << "\t\t\t\t====================" << endl;
	cout << "\t\t\t\t%%%%%操作成功!%%%%%" << endl;
	cout << "\t\t\t\t====================" << endl;
	return count;
}
int cleanPointperson(struct personaddr* stu,int count)
{
	if (count == 0)
	{
		cout << "\t\t\t\t您还未添加联系人" << endl;
		return 0;
	}
	for (int i = 0; i < count; i++)
	{
		cout << "\t\t\t\t---------------------------------------------------------" << endl;
		cout << "\t\t\t\t|  " << i+1 << "." << "*******姓名:\t\t" << stu[i].info.name << "\t\t******\t|" << endl;
		cout << "\t\t\t\t---------------------------------------------------------" << endl;
	}
	int select0;
	cout << "请输入序号以删除的联系人" << endl;
	cin >> select0;
	struct personaddr temp;
	int select3 = select0;
	for (int j = 1; j <= count - select0; j++)
	{
		
		temp.info = stu[select3-1].info;
		stu[select3 - 1].info.address = stu[select3].info.address;
		stu[select3 - 1].info.age = stu[select3].info.age;
		stu[select3 - 1].info.name = stu[select3].info.name;
		stu[select3 - 1].info.sex = stu[select3].info.sex;
		stu[select3 - 1].info.telenumber = stu[select3].info.telenumber;
		stu[select3].info.address = temp.info.address;
		stu[select3].info.age = temp.info.age;
		stu[select3].info.name = temp.info.name;
		stu[select3].info.sex = temp.info.sex;
		stu[select3].info .telenumber= temp.info.telenumber;
		select3++;
	}
	stu[count-1].info.address = '0';
	stu[count - 1].info.age = NULL;
	stu[count - 1].info.name = '0';
	stu[count - 1].info.sex = '0';
	stu[count - 1].info.telenumber = '0';
	count -= 1;
	cout << "\t\t\t\t====================" << endl;
	cout << "\t\t\t\t%%%%%操作成功!%%%%%" << endl;
	cout << "\t\t\t\t====================" << endl;
	return count;
}