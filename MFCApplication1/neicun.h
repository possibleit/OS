#include "iostream"
#include "vector"
#include "algorithm"


#define READY 1                  //���з���
#define BLANK 0                  //�ձ�Ŀ



class SUBAREA{
public:
	int start_add;
	int size;
	int state;
	SUBAREA(int s1, int s2, int s3);
	~SUBAREA();
	std::string string_out();
};

SUBAREA::SUBAREA(int s1, int s2, int s3)
{
	start_add = s1;
	size = s2;
	state = s3;
}

SUBAREA::~SUBAREA(){};

std::string SUBAREA::string_out()
{
	std::string str;
	char ch[64];
	sprintf_s(ch, "START_ADD = %d SIZE = %d STATE = %d %s", this->start_add, this->size, this->state, "\r\n");
	str = ch;
	return str;
}

int set1(int &start, int size, std::vector<SUBAREA> &list);
int free(int &start, int size, std::vector<SUBAREA> &list);
void print(std::vector<SUBAREA> &list);


bool up(SUBAREA &s1, SUBAREA &s2){ return s1.start_add < s2.start_add; }


int set1(int &start, int size, std::vector<SUBAREA> &list)
{
	int flag = 0;             //flagΪ0���ʾ��δ�ҵ����ʷ���
	for (std::vector<SUBAREA>::iterator iter = list.begin();
		iter != list.end(); iter++)
	{
		if ((*iter).state == READY && size <= (*iter).size)
		{
			start = (*iter).start_add;
			(*iter).start_add = (*iter).start_add + size;
			(*iter).size = (*iter).size - size;
			(*iter).state = 1;
			flag = 1;
			return 1;
		}

	}
	if (flag == 0)
		return 0;
	return 1;
}

int free(int &start, int size, std::vector<SUBAREA> &list)
{
	for (std::vector<SUBAREA>::iterator iter = list.begin();
		iter != list.end(); iter++)
	{
		if ((*iter).start_add + (*iter).size == start && (*iter).state == READY)                  //����Ƿ������ڿ���
		{
			//����Ƿ�������
			if (start + size == (*(iter + 1)).start_add && (*iter).state == READY)
			{//�ϲ������ڿ�����
				size = size + (*(iter + 1)).size;
				start = 0;
				(*iter).size = (*iter).size + size;
				(*iter).state = 0;
				list.erase(iter + 1);   //ɾ������Ǹ�����
				return 1;
			}
			else{//�ϲ����������
				start = 0;
				(*iter).size = (*iter).size + size;
				(*iter).state = 0;
				return 1;
			}
		}
		else
		{
			//����Ƿ�������
			if (start + size == (*(iter)).start_add && (*iter).state == READY)
			{//�ϲ�����
				(*iter).start_add = start;
				(*iter).size = (*iter).size + size;
				(*iter).state = 0;
				return 1;
			}
		}
	}
	//if ((*iter).state == 1)
	{//�����¿�����
		SUBAREA s(start, size, READY);
		list.push_back(s);
		sort(list.begin(), list.end(), up);
		return 1;
	}
}

void print(std::vector<SUBAREA> &list)
{
	std::vector<SUBAREA>::iterator it;
	for (it = list.begin(); it != list.end(); it++)
	{
		std::cout << (*it).start_add << " " << (*it).size << " " << (*it).state;
	}
}
