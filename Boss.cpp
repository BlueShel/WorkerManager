#include "Boss.h"

Boss::Boss(int id, string name, int DId)
{
	this->m_Id = id;
	this->m_name = name;
	this->m_DeptId = DId;
}

void Boss::showInfo()
{
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：管理全公司" << endl;
}

string Boss::getDeptName()
{
	return string("老板");
}
