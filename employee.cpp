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
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ����ɾ�����������" << endl;
}

string employee::getDeptName()
{
	return string("Ա��");
}
