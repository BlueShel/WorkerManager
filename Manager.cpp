#include "Manager.h"

Manager::Manager(int id, string name, int DId)
{
	this->m_Id = id;
	this->m_name = name;
	this->m_DeptId = DId;
}


void Manager::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ������ϰ彻�������񣬲��·�Ա��" << endl;
}

string Manager::getDeptName()
{
	return string("����");
}
