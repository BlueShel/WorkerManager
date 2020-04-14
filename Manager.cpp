#include "Manager.h"

Manager::Manager(int id, string name, int DId)
{
	this->m_Id = id;
	this->m_name = name;
	this->m_DeptId = DId;
}


void Manager::showInfo()
{
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：完成老板交给的任务，并下发员工" << endl;
}

string Manager::getDeptName()
{
	return string("经理");
}
