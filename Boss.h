#pragma once
#include "Worker.h"
class Boss :
	public Worker
{
public:
	Boss(int id, string name, int DId);
	//��ʾ������Ϣ
	virtual void showInfo();
	//��ȡ��λ����
	virtual string getDeptName();
};

