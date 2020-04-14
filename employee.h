#pragma once
#include"Worker.h"
#include<iostream>
using namespace std;

class employee :public Worker
{
public:
	employee(int id, string name, int DId);
	//显示个人信息
	virtual void showInfo() ;
	//获取岗位名称
	virtual string getDeptName();
};

