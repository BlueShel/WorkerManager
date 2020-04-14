#include"WorkerManager.h"
#include<iostream>
#include"Worker.h"
#include"employee.h"
#include"Manager.h"
#include"Boss.h"
using namespace std;

int choice = 0;
int main() {
	
	WorkerManager wm;
	while (true)
	{
		wm.Show_Menu();
		cout << "请输入您的选择" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://退出
			wm.ExitSystem();
		case 1://增加职工信息
			wm.Add_Emp();
			break;
		case 2://显示职工信息
			wm.show_Emp();
			break;
		case 3://删除职工信息
			wm.Del_Emp();
			break;
		case 4://修改职工信息
			wm.modify();
			break;
		case 5://查找职工信息
			wm.Find();
			break;
		case 6://排序职工信息
			wm.sort_Emp();
			break;
		case 7://清空职工信息
			wm.clean_file();
			break;
		default:
			system("cls");
		}
	}
	return 0;
}