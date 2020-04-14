#include "employee.h"
#include<iostream>
#include<string>

employee::employee(int id,string name,int DId) {
	this->m_Id = id;
	this->m_name = name;
	this->m_DeptId = DId;
}
void employee::showInfo()
{
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：完成经理交给的任务" << endl;
}

string employee::getDeptName()
{
	return string("员工");
}
