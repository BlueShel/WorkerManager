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
	//��¼ְ������
	int m_EmpNum;
	//ְ������ָ��
	Worker** m_EmpArray;
	//��ʾ�˵�
	void Show_Menu();
	//���ְ��
	void Add_Emp();
	//�˳�ϵͳ
	void ExitSystem();
	void save();
	//�ļ���־,�ж��ļ��Ƿ�Ϊ��
	bool m_FileEmpty;//trueΪ��
	int getNum();
	//��ʼ��ְ��
	void init_Emp();
	//��ʾ����ְ��
	void show_Emp();
	//�ж�ְ���Ƿ���ڣ������ڷ���-1��
	int IsExist(int Id);
	//ɾ��ְ��
	void Del_Emp();
	void Find();
	void sort_Emp();
	void modify();
	void clean_file();
};

