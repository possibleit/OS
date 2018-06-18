#include "iostream"
#include "vector"
#include "algorithm"
#include "neicun.h"
#include "stdio.h"
#include <ctime> 
#define READY 1                         //就绪
#define RESERVE 0                       //后备
#define Hang_Up 2                       //挂起



class PCB{
public:
	int PID;
	int RunTime;
	int weight;
	int status;
	int start_add;
	int size;
	int state;
	PCB(int p, int r, int w, int s);
	PCB(int p, int r, int w, int s, int state);
	~PCB();
	std::string string_out();
};

PCB::PCB(int p, int r, int w, int s)
{
	PID = p;
	RunTime = r;
	weight = w;
	size = s;
	start_add = 0;

}
PCB::PCB(int p, int r, int w, int s, int state)
{
	PID = p;
	RunTime = r;
	weight = w;
	size = s;
	start_add = 0;
	this->state = state;
}
PCB::~PCB()
{
}
std::string PCB::string_out()
{
	std::string str;
	char ch[64];
	sprintf_s(ch, "PID = %d RunTime = %d weight = %d %s", this->PID, this->RunTime, this->weight, "\r\n");
	str = ch;
	return str;
}

void run(std::vector<PCB> &pcb_list, std::vector<PCB>::iterator it);
int PSA(std::vector<PCB> &pcb_list);
void print(std::vector<PCB> &pcb_list);
void hang_up(std::vector<PCB> &pcb_list, int m, std::vector<PCB> &hang_up_list);
void block(std::vector<PCB> &pcb_list, int m, std::vector<PCB> &block_list);
void reblock(std::vector<PCB> &pcb_list, int m, std::vector<PCB> &block_list);
void Reset_hang_up(std::vector<PCB> &pcb_list, int m, std::vector<PCB> &hang_up_list);
void add(std::vector<PCB> &pcb_list, int p, int r, int w, int a);
void init1(std::vector<PCB> &list);
void init2(std::vector<SUBAREA> &LIST);
void init(std::vector<PCB> &LIST);
std::string refresh(std::vector<PCB> &list);
std::string refresh2(std::vector<SUBAREA> &list);
void StringToWString(const std::string &str, std::wstring &wstr);
void select(std::vector<PCB> &list, std::vector<PCB> &list2);
void   Delay(int   time);
double randval(double low, double high);

std::vector<PCB> weight_list;             //优先权队列，执行队列，就绪队列
std::vector<PCB> hang_up_list;            //挂起队列
std::vector<PCB> reserve_list;             //后备队列
std::vector<SUBAREA> SUB_LIST;
std::vector<PCB> block_list;               //阻塞队列


int ss = 0;
	


bool weight_down(const PCB &p1, const PCB &p2){ return p1.weight > p2.weight; }
void init(PCB& pcb){ pcb.status = RESERVE; }
void set_hang_up(PCB &pcb){ pcb.status = Hang_Up; }
void reset_hang_up(PCB &pcb){ pcb.status = READY; }

int PSA(std::vector<PCB> &pcb_list)                                   //调度一次
{
	//if (!pcb_list.empty())
	if(!pcb_list.empty())
	{
		std::vector<PCB>::iterator it = pcb_list.begin();
		run(pcb_list, it);
		sort(pcb_list.begin(), pcb_list.end(), weight_down);
	}
	return 1;
}
void run(std::vector<PCB> &pcb_list, std::vector<PCB>::iterator it)
{
	if ((*it).RunTime > 1)
	{
		if ((*it).state == 0){
			set1((*it).start_add, (*it).size, SUB_LIST);
			(*it).state = 1;
		}
		(*it).RunTime--;
		//Sleep(5000);
		//Delay(5 * 1000);   //延时5秒 
		if ((*it).weight > 0)
			(*it).weight--;
		
	}
	else
	{
		free((*it).start_add, (*it).size, SUB_LIST);
		(*it).state = 0;
		pcb_list.erase(it);
	}
}

void print(std::vector<PCB> &pcb_list)
{
	std::vector<PCB>::iterator it;
	for (it = pcb_list.begin(); it != pcb_list.end(); it++)
	{
		std::cout << (*it).PID << " ";
	}
	//std::cout << endl;
}

void hang_up(std::vector<PCB> &pcb_list, int m, std::vector<PCB> &hang_up_list)
{
	//for_each(pcb_list.begin(), pcb_list.end(), set_hang_up);
	for (std::vector<PCB>::iterator it = pcb_list.begin();
		it != pcb_list.end(); it++)
	{
		if ((*it).PID == m)                 //...............................................................................
		{
			if ((*it).state == 1)
				free((*it).start_add, (*it).size, SUB_LIST);
			hang_up_list.push_back(*it);
			pcb_list.erase(it);
			return;
		}
	}
}

void block(std::vector<PCB> &pcb_list, int m, std::vector<PCB> &block_list)
{
	for (std::vector<PCB>::iterator it = pcb_list.begin();
		it != pcb_list.end(); it++)
	{
		if ((*it).PID == m)
		{
			//free((*it).start_add, (*it).size, SUB_LIST);
			block_list.push_back(*it);
			pcb_list.erase(it);
			return;
		}
	}
}

void reblock(std::vector<PCB> &pcb_list, int m, std::vector<PCB> &block_list)
{
	for (std::vector<PCB>::iterator it = block_list.begin();
		it != block_list.end(); it++)
	{
		if ((*it).PID == m)
		{
			//free((*it).start_add, (*it).size, SUB_LIST);
			pcb_list.push_back(*it);
			block_list.erase(it);
			sort(pcb_list.begin(), pcb_list.end(), weight_down);
			return;
		}
	}
}

void Reset_hang_up(std::vector<PCB> &pcb_list, int m, std::vector<PCB> &hang_up_list)
{
	for (std::vector<PCB>::iterator it = hang_up_list.begin();
		it != hang_up_list.end(); it++)
	{
		if ((*it).PID == m)                                     //..............................
		{
			//free((*it).start_add, (*it).size, SUB_LIST);
			pcb_list.push_back(*it);
			hang_up_list.erase(it);
			sort(pcb_list.begin(), pcb_list.end(), weight_down);
			return;
		}
	}
}

void ready(std::vector<PCB> &pcb_list, std::vector<PCB>::iterator it)
{
	for_each(pcb_list.begin(), pcb_list.end(), reset_hang_up);
}


void init1(std::vector<PCB> &list)
{
	srand(time(NULL));
	for (int i = 0; i < 3; i++)
	{
		int i1, i2, i3, i4;
		i1 = randval(0, 10);
		i2 = randval(5, 10);
		i3 = randval(1, 10); 
		i4 = randval(1, 10);
		PCB pcb1(i1, i2, i3, i4, 0);
		list.push_back(pcb1);
	}
	/*PCB pcb1(1, 3, 4, 8, 0);
	PCB pcb2(2, 3, 5, 8, 0);
	PCB pcb3(3, 3, 6, 8, 0);
	list.push_back(pcb1);
	list.push_back(pcb2);
	list.push_back(pcb3);*/
	sort(list.begin(), list.end(), weight_down);

}

void add(std::vector<PCB> &pcb_list, int p, int r, int w, int s, int a)
{
	PCB newpcb(p, r, w, s, a);
	pcb_list.push_back(newpcb);
}


void init2(std::vector<SUBAREA> &LIST)
{
	SUBAREA s[3] = { { 14, 12, READY }, { 32, 96, READY }, { 128, 120, READY } };
	LIST.push_back(s[0]);
	LIST.push_back(s[1]);
	LIST.push_back(s[2]);
	sort(LIST.begin(), LIST.end(), up);
}

void init(std::vector<PCB> &LIST)
{
	PCB pcb1(4, 7, 7, 9, 0);
	PCB pcb2(5, 6, 4, 9, 0);
	PCB pcb3(6, 5, 8, 12, 0);
	LIST.push_back(pcb1);
	LIST.push_back(pcb2);
	LIST.push_back(pcb3);
	sort(LIST.begin(), LIST.end(), weight_down);
}

std::string refresh(std::vector<PCB> &list)
{
	std::string str;
	std::vector<PCB>::iterator it = list.begin();
	for (it = list.begin(); it != list.end(); it++)
	{
		str += (*it).string_out();
	}
	return str;
}

std::string refresh2(std::vector<SUBAREA> &list)
{
	std::string str2;
	std::vector<SUBAREA>::iterator it = list.begin();
	for (it = list.begin(); it != list.end(); it++)
	{
		str2 += (*it).string_out();
	}
	return str2;
}

void StringToWString(const std::string &str, std::wstring &wstr)
{
	int nLen = (int)str.length();
	wstr.resize(nLen, L' ');
	int nResult = MultiByteToWideChar(CP_ACP, 0, (LPCSTR)str.c_str(), nLen, (LPWSTR)wstr.c_str(), nLen);
}


void select(std::vector<PCB> &list, std::vector<PCB> &list2)
{
	//std::vector<PCB>::iterator it = list.begin();
	//copy(it, it + 3, std::inserter(list2));
	for (int i = 0; i < 3; i++)
	{
		std::vector<PCB>::iterator it = list.begin();
		list2.push_back((*it));
		list.erase(it);
	}
	sort(list2.begin(), list2.end(), weight_down);
}


void   Delay(int   time)//time*1000为秒数 
{
	clock_t   now = clock();

	while (clock() - now   <   time);
}

double randval(double low, double high)
{
	double val;
	val = ((double)(rand() % RAND_MAX) / (double)RAND_MAX)*(high - low) + low;
	return(val);
}