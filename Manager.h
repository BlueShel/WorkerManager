#pragma once
#include "Worker.h"
class Manager :
	public Worker
{
public:
	Manager(int id, string name, int DId);
	//��ʾ������Ϣ
	virtual void showInfo();
	//��ȡ��λ����
	virtual string getDeptName();
};

