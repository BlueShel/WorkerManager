#pragma once
#include<iostream>
#include"Worker.h"
#include<fstream>
#define FILENAME "empFile.txt"
using namespace std;

class WorkerManager
{
public:
	WorkerManager();
	~WorkerManager();
	//记录职工人数
	int m_EmpNum;
	//职工数组指针
	Worker** m_EmpArray;
	//显示菜单
	void Show_Menu();
	//添加职工
	void Add_Emp();
	//退出系统
	void ExitSystem();
	void save();
	//文件标志,判断文件是否为空
	bool m_FileEmpty;//true为空
	int getNum();
	//初始化职工
	void init_Emp();
	//显示所有职工
	void show_Emp();
	//判断职工是否存在，不存在返回-1；
	int IsExist(int Id);
	//删除职工
	void Del_Emp();
	void Find();
	void sort_Emp();
	void modify();
	void clean_file();
};

