#pragma once
#include "Worker.h"
class Boss :
	public Worker
{
public:
	Boss(int id, string name, int DId);
	//显示个人信息
	virtual void showInfo();
	//获取岗位名称
	virtual string getDeptName();
};

