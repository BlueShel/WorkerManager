#pragma once
#include"Worker.h"
#include<iostream>
using namespace std;

class employee :public Worker
{
public:
	employee(int id, string name, int DId);
	//��ʾ������Ϣ
	virtual void showInfo() ;
	//��ȡ��λ����
	virtual string getDeptName();
};

