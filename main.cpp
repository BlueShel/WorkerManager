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
		cout << "����������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://�˳�
			wm.ExitSystem();
		case 1://����ְ����Ϣ
			wm.Add_Emp();
			break;
		case 2://��ʾְ����Ϣ
			wm.show_Emp();
			break;
		case 3://ɾ��ְ����Ϣ
			wm.Del_Emp();
			break;
		case 4://�޸�ְ����Ϣ
			wm.modify();
			break;
		case 5://����ְ����Ϣ
			wm.Find();
			break;
		case 6://����ְ����Ϣ
			wm.sort_Emp();
			break;
		case 7://���ְ����Ϣ
			wm.clean_file();
			break;
		default:
			system("cls");
		}
	}
	return 0;
}