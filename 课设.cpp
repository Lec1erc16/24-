#include <iostream>
#include<cstdio>

using namespace std;

typedef struct LinkList0	//植物信息链表
{
	int num;			//编号
	char name[20];		//植物名
	char type[20];		//种属
	char huaqi[16];		//花期
	char location[20];	//栽种地点
	char guanshang[10];	//观赏性
	char maintain[200];	//维护
	char yaoyong[1000];	//药用价值
	char meaning[100];	//历史意义或纪念意义
	LinkList0* next;
}LNode0, * L0;


typedef struct LinkList1 // 管理员/用户账号密码链表
{
	int state;			// 用户身份 1为管理员 2为用户
	char name[10];
	char key[100];
	LinkList1* next;
}LNode1, * L1;

typedef struct LinkList2	//观赏路线信息链表
{
	int num;				//编号
	char name[20];			//地点名
	L0 plant;
	LinkList2* next;
}LNode2, * L2;


void InitL0(L0& L);										//初始化L0
void InitL1(L1& L);										//初始化L1
void InitL2(L2& L);										//初始化L2
void CreateL0(int n, L0& Plant);						//创建带头结点的植物信息链表
void Createyonghu(L1& L);								//创建带头结点的用户信息链表
void CreateVisit(int num,L2& L);						//创建带头结点的游览路线信息链表
void PrintLNode0(L0 p);									//输出L0结点
void PrintLNode2(L2 p);									//输出L2结点
bool LoadFile_Plant(FILE* PlantFilePoi, L0& Plant);		//加载PLant文件中的数据
bool LoadFile_User(FILE* UserFilePoi, L1& User);		//加载User文件中的数据
bool LoadFile_Visit(FILE* fp, L2& Visit);				//加载Visit文件中的数据
void Fprint_Plant(L0 Plant);							//将新Plant写入文件中
void Fprint_User(L1 User);								//将新User写入文件中
void Fprint_Visit(L2 Visit);							//将新Visit写入文件中
L0 Plant_chaxun(L0 Plant);								//查询植物信息
L0 Plant_chaxun_num(int num, L0 Plant);					//使用编号查询植物信息
L0 Plant_chaxun_name(char name[], L0 Plant);			//使用名称查询植物信息
L2 Visit_chaxun(L2 Visit);								//查询游览路线
L2 Visit_chaxun_num(int num, L2 Visit);					//使用编号查询游览路线
L2 Visit_chaxun_name(char name[], L2 Visit);			//使用名称查询游览路线
bool Plant_delete(L0& Plant);							//删除植物信息
void Plant_delete_num(int num, L0& Plant);				//使用编号删除植物信息
void Plant_delete_name(char name[], L0& Plant);			//使用名称删除植物信息
void Visit_delete(L2& Visit);							//删除游览路线
void Visit_delete_num(int num, L2& Visit);				//使用编号删除游览路线
void Visit_delete_name(char name[], L2& Visit);			//使用名称删除游览路线
void Plant_xiugai(L0& Plant);							//修改植物信息
void Plant_xiugai_num(int num, L0& Plant);				//使用编号修改植物信息
void Plant_xiugai_name(char name[], L0& Plant);			//使用名称修改植物信息
void Visit_xiugai(L2& Visit);							//修改游览路线
void Visit_xiugai_num(int num, L2& Visit);				//使用编号修改游览路线
void Visit_xiugai_name(char name[], L2& Visit);			//使用名称修改游览路线
void Plant_bianli(L0 Plant);							//遍历植物信息
bool Plant_star(L0 p);									//收藏植物信息
void Visit_star(L2 p);									//收藏游览路线
void Visit_bianli(L2 Visit);							//遍历游览路线
void Share();											//分享功能
void LogInMenu();										//登录界面
void tuichujiemian();									//退出界面
void admin_caozuojiemian(LNode1 e);						//管理员操作界面
void user_caozuojiemian(LNode1 e);						//用户操作界面
bool Login_admin(L1 User, LNode1& e);					//管理员登录
bool Login_user(L1 User, LNode1& e);					//用户登录

int main()
{
	FILE* fp = NULL;
	L0 Plant;
	L1 User;
	L2 Visit;
	InitL0(Plant);
	InitL1(User);
	InitL2(Visit);
	if (!LoadFile_Plant(fp, Plant)) return 0;
	if (!LoadFile_User(fp, User)) return 0;
	if (!LoadFile_Visit(fp, Visit)) return 0;
	cout << "------------------------------------------------------***********----------------------------------------------------" << endl;
	cout << "|WW          WW           WW   EEEEEEEE    LL          CCCCCC      OOOOOOO          MMM         MMM         EEEEEEE |" << endl;
	cout << "| WW       WW  WW        WW    EE          LL         CC          OO     OO        MM MM       MM MM        EE      |" << endl;
	cout << "|  WW      WW   WW      WW     EE          LL        CC          OO       OO      MM   MM     MM   MM       EE      |" << endl;
	cout << "|   WW    WW     WW    WW      EEEEEEEE    LL       CC          OO         OO    MM     MM   MM     MM      EEEEEEE |" << endl;
	cout << "|    WW  WW       WW  WW       EE          LL        CC          OO       OO    MM       MM MM       MM     EE      |" << endl;
	cout << "|     W W          W W         EE          LL         CC          OO     OO    MM         M M         MM    EE      |" << endl;
	cout << "|      W            W          EEEEEEEEE   LLLLLLLL    CCCCCC      OOOOOOO    MM           M           MM   EEEEEEE |" << endl;
	cout << "|                                             欢迎使用华南农业大学植物观赏系统                                      |" << endl;
	cout << "|------------------------------------------------------***********--------------------------------------------------|" << endl;
	cout << endl;
	cout << "                                                  登 录（Y or N）" << endl;

	//登录模块
	char denglu[10];
	int state = 1, times = 5;
	int glycz = 1, yhcz = 1;	//管理员操作 用户操作
	LNode1 e;
	cin >> denglu;
	while ((denglu[0] != 'n' || denglu[0] != 'N') && state != 0)
	{
		while (state != 0)
		{
			LogInMenu();
			cin >> state;
			switch (state)
			{
			case 0:
				break;
			case(1):
			{
				while (1)
				{
					char temp = 0;
					if (Login_admin(User, e))
					{
						glycz = 1;
						while (glycz)
						{
							admin_caozuojiemian(e);
							printf("\n\n");
							cout << "请输入所选择的序号" << endl;
							cin >> glycz;
							switch (glycz)
							{

							case 1://查询植物信息
							{
								LoadFile_Plant(fp, Plant);
								if (Plant == NULL)
								{
									cout << "植物信息为空，请先录入数据！" << endl;
									system("pause");
									break;
								}
								else
								{
									Plant_chaxun(Plant);
									system("pause");
									break;
								}
							}
							case 2: //查询游览路线信息
							{
								LoadFile_Visit(fp, Visit);
								if (Visit == NULL)
								{
									cout << "游览路线信息为空，请先录入数据！" << endl;
									system("pause");
									break;
								}
								else
								{
									Visit_chaxun(Visit);
									system("pause");
								}
								break;
							}

							case 3: //创建植物信息
							{
								LoadFile_Plant(fp, Plant);
								int n = 0;
								cout << "请输入要创建植物的个数" << endl;
								cin >> n;
								CreateL0(n, Plant);
								Fprint_Plant(Plant);
								system("pause");
								break;

							}

							case 4: //创建游览路线
							{
								LoadFile_Visit(fp, Visit);
								if (Visit == NULL)
								{
									cout << "游览路线信息为空，请先录入数据！" << endl;
									system("pause");
									break;
								}
								else
								{
									int n = 0;
									cout << "请输入要创建游览路线的个数" << endl;
									cin >> n;
									CreateVisit(n, Visit);
									Fprint_Visit(Visit);
									system("pause");
									break;
								}
							}
							case 5: //删除植物信息
							{
								LoadFile_Plant(fp, Plant);
								if (Plant == NULL)
								{
									cout << "植物信息为空，请先录入数据！" << endl;
									system("pause");
									break;
								}
								else
								{
									if (Plant_delete(Plant)) Fprint_Plant(Plant);
									system("pause");
									break;
								}
							}

							case 6://删除游览路线
							{
								LoadFile_Visit(fp, Visit);
								if (Visit == NULL)
								{
									cout << "游览路线为空，请先录入数据！" << endl;
									system("pause");
									break;
								}
								else
								{
									Visit_delete(Visit);
									Fprint_Visit(Visit);
									system("pause");
									break;
								}
							}
							case 7://修改植物信息
							{
								LoadFile_Plant(fp, Plant);
								if (Plant == NULL)
								{
									cout << "植物信息为空，请先录入数据！" << endl;
									system("pause");
									break;
								}
								else
								{
									Plant_xiugai(Plant);
									Fprint_Plant(Plant);
									system("pause");
									break;
								}

							}
							case 8://修改游览路线
							{
								LoadFile_Visit(fp, Visit);
								if (Visit == NULL)
								{
									cout << "游览路线为空，请先录入数据！" << endl;
									system("pause");
									break;
								}
								else
								{
									Visit_xiugai(Visit);
									Fprint_Visit(Visit);
									system("pause");
									break;
								}
							}
							case 9://遍历植物信息
							{
								LoadFile_Plant(fp, Plant);
								if (Plant == NULL)
								{
									cout << "植物信息为空，请先录入数据！" << endl;
									system("pause");
									break;
								}
								else
								{
									Plant_bianli(Plant);
									system("pause");
								}
								break;
							}
							case 10:
							{
								LoadFile_Visit(fp, Visit);
								if (Visit == NULL)
								{
									cout << "游览路线信息为空，请先录入数据！" << endl;
									system("pause");
									break;
								}
								else
								{
									Visit_bianli(Visit);
									system("pause");
								}
								break;
							}
							case 0:
								break;
							default:
								cout << "您输入的有误，请重新输入！" << endl;
								system("pause");
								break;
							}
						}
						if (glycz == 0) break;
					}
					cout << "退出登录请输入 N" << endl;
					cin >> temp;
					if (temp == 'n' || temp == 'N') break;
				}
				break;
			}

			case(2):
			{
				while (1)
				{
					char temp = 0;
					if (Login_user(User, e))
					{
						yhcz = 1;
						while (yhcz)
						{
							user_caozuojiemian(e);
							printf("\n\n");
							cout << "请输入所选择的序号" << endl;
							cin >> yhcz;
							switch (yhcz)
							{
							case 0:
								break;
							case 1://查询植物信息
							{
								LoadFile_Plant(fp, Plant);
								if (Plant == NULL)
								{
									cout << "植物信息为空，请先录入数据！" << endl;
									system("pause");
									break;
								}
								else
								{
									int flag = 1;
									while (flag)
									{
										L0 tmp = NULL;
										tmp = Plant_chaxun(Plant);
										Plant_star(tmp);
										Share();
										system("pause");
										cout << "是否继续查询？ 是（1） 否（0）";
										cin >> flag;
										if (flag == 0) break;
									}
								}

								break;
							}
							case 2: //查询游览路线信息
							{
								LoadFile_Visit(fp, Visit);
								if (Visit == NULL)
								{
									cout << "游览路线信息为空，请先录入数据！" << endl;
									system("pause");
									break;
								}
								else
								{
									int flag = 1;
									while (flag)
									{
										L2 tmp = NULL;
										tmp = Visit_chaxun(Visit);
										Visit_star(tmp);
										Share();
										system("pause");
										cout << "是否继续查询？ 是（1） 否（0）";
										cin >> flag;
										if (flag == 0) break;
									}
								}
								break;
							}
							case 3://遍历植物信息
							{
								LoadFile_Visit(fp, Visit);
								if (Visit == NULL)
								{
									cout << "游览路线信息为空，请先录入数据！" << endl;
									system("pause");
									break;
								}
								else
								{
									Plant_bianli(Plant);
									system("pause");
								}
								break;
							}
							case 4: //遍历游览路线
							{
								LoadFile_Visit(fp, Visit);
								if (Visit == NULL)
								{
									cout << "游览路线信息为空，请先录入数据！" << endl;
									system("pause");
									break;
								}
								else
								{
									Visit_bianli(Visit);
									system("pause");
									break;
								}
							}
							default:
								printf("您的输入有误,请重新输入!\n");
								system("pause");
								break;

							}
						}
						if (yhcz == 0) break;
					}
					cout << "退出登录请输入 N" << endl;
					cin >> temp;
					if (temp == 'n' || temp == 'N') break;
				}
				break;
			}
			case(3):
				Createyonghu(User);
				Fprint_User(User);
				break;
			case(4):
				cout << "*******************************************************************************************************************" << endl;
				cout << "|                                      如遇问题 请电话联系：13825773655                                           |" << endl;
				cout << "*******************************************************************************************************************" << endl;
				system("pause");
				break;
			default:
				printf("您的输入有误!\n");
				system("pause");
				break;
			}
		}
	}
	tuichujiemian();
	return 0;
}

void InitL0(L0& L)		//初始化L0
{
	L0 p = new LNode0[1];
	p->next = NULL;
	L = p;
}

void InitL1(L1& L)		//初始化L1
{
	L1 p = new LNode1[1];
	p->next = NULL;
	L = p;
}

void InitL2(L2& L)		//初始化L2
{
	L2 p = new LNode2[1];
	L0 q;
	InitL0(q);
	p->next = NULL;
	p->plant = q;
	L = p;
}

void CreateL0(int n, L0& Plant)	//创建植物信息
{
	if (Plant == NULL)
	{
		Plant = new LNode0;
		Plant->next = NULL;
	}
	L0 p = Plant;
	while (p->next != NULL) p = p->next;
	for (int i = 0; i < n; i++)
	{
			L0 tmp = new LNode0[1];
			tmp->next = NULL;
			while (p->next != NULL) p = p->next;
			cout << "请输入植物的编号：";
			cin >> tmp->num;
			cout << "请输入植物的名称：";
			cin >> tmp->name;
			cout << "请输入植物的种属：";
			cin >> tmp->type;
			cout << "请输入植物的花期：";
			cin >> tmp->huaqi;
			cout << "请输入植物的栽种地点：";
			cin >> tmp->location;
			cout << "请输入植物的观赏性：";
			cin >> tmp->guanshang;
			cout << "请输入植物的维护信息：";
			cin >> tmp->maintain;
			cout << "请输入植物的药用价值：";
			cin >> tmp->yaoyong;
			cout << "请输入植物的历史意义或纪念意义：";
			cin >> tmp->meaning;
			p->next = tmp;
			p = tmp;
			
	}
}

void  CreateVisitL0(int n, L0& L)	//创建游览地点的植物信息
{
	L0 p = L;
	for (int i = 0; i < n; i++)
	{
		L0 tmp = new LNode0[1];
		cout << "请输入植物的编号：";
		cin >> tmp->num;
		cout << "请输入植物的名称：";
		cin >> tmp->name;
		cout << "请输入植物的种属：";
		cin >> tmp->type;
		cout << "请输入植物的花期：";
		cin >> tmp->huaqi;
		cout << "请输入植物的栽种地点：";
		cin >> tmp->location;
		cout << "请输入植物的观赏性：";
		cin >> tmp->guanshang;
		cout << "请输入植物的维护信息：";
		cin >> tmp->maintain;
		cout << "请输入植物的药用价值：";
		cin >> tmp->yaoyong;
		cout << "请输入植物的历史意义或纪念意义：";
		cin >> tmp->meaning;
		tmp->next = NULL;
		if (p == NULL) p = tmp;
		else  p = p->next;
		p->next = tmp;
	}
}

void Createyonghu(L1& User)			//创建用户信息
{
	L1 tmp = new LNode1[1];
	tmp->next = NULL;
	cout << "请输入用户名称（名称不多于10个字）：";
	cin >> tmp->name;
	cout << "请输入用户密码（密码不多于20个字符）：";
	cin >> tmp->key;
	tmp->state = 2;
	L1 p = User;
	if (p == NULL) p = tmp;
	else while (p->next != NULL) p = p->next;
	p->next = tmp;
}

void CreateVisit(int num,L2& Visit) //创建浏览路线
{
	L2 p = Visit;
	for (int i = 0; i < num; i++)
	{
		L2 tmp = new LNode2[1];
		tmp->next = NULL;
		L0 q = new LNode0[1];
		q->next = NULL;
		int n = 0;
		tmp->plant = q;
		cout << "请输入游览路线的编号" << endl;
		cin >> tmp->num;
		cout << "请输入游览路线的名称" << endl;
		cin >> tmp->name;
		cout << "请输入游览路线中出现的植物总数" << endl;
		cin >> n;
		CreateVisitL0(n, q);
		if (p == NULL) p = tmp;
		else while (p->next != NULL) p = p->next;
		p->next = tmp;
	}
}

bool LoadFile_Plant(FILE* fp, L0& Plant)	//加载PLant文件中的数据
{
	fp = fopen("Plant.txt", "r");
	if (fp == NULL)
	{
		cout << "Plant.txt文件打开错误" << endl;	
		cout << "请检查系统所需的Plant.txt文件是否受损" << endl;
		return false;		
	}
	L0 p = NULL;
	L0 q = Plant;	
	char ch = fgetc(fp);
	if (ch == EOF)
	{ 
		cout << "当前Plant.txt文件为空" << endl;
		cout << "请检查系统所需的Plant.txt文件是否受损" << endl;
		Plant = NULL;
		return true;
	}
		rewind(fp);
		while (!feof(fp))
		{
			p = new LNode0[1];
			p->next = NULL;
			fscanf(fp, "%d%s%s%s%s%s%s%s%s\n", &p->num, p->name, p->type, p->huaqi, p->location, p->guanshang,p->maintain, p->yaoyong, p->meaning);
			if (q == NULL) q = p;
			else q->next = p;
			q = p;
		}
		q->next = NULL;
		fclose(fp);
		return true;
}

bool LoadFile_User(FILE* fp, L1& User)		//加载User文件中的数据
{
	if ((fp = fopen("User.txt", "r")) == NULL)
	{
		cout << "User.txt文件打开错误" << endl;
		cout << "请检查系统所需的Plant.txt文件是否受损" << endl;
		return false;
	}
	char ch = fgetc(fp);
	if (ch == EOF)
	{
		cout << "当前User.txt文件为空" << endl;
		cout << "请检查系统所需的Plant.txt文件是否受损" << endl;
		User = NULL;
		return false;
	}
	rewind(fp);
	L1 p = NULL;
	L1 q = User;
	while (!feof(fp))
	{
		p = new LNode1[1];
		p->next = NULL;
		fscanf(fp, "%d%s%s", &p->state, p->name, p->key);
		if (User == NULL) User = p;
		else q->next = p;
		q = p;
	}
	fclose(fp);
	return true;
}

bool LoadFile_Visit(FILE* fp, L2& Visit)//加载Visit文件
{
	fp = fopen("Visit.txt", "r");
	if (fp == NULL)
	{
		cout << "VIsit.txt文件打开错误" << endl;
		cout << "请检查系统所需的Plant.txt文件是否受损" << endl;
		return false;
	}
	char ch = fgetc(fp);
	if (ch == EOF)
	{
		cout << "当前VIsit.txt文件为空" << endl;
		cout << "请检查系统所需的VIsit.txt文件是否受损" << endl;
		Visit = NULL;
		return false;
	}
	rewind(fp);
	L2 p2 = NULL;
	L2 q2 = Visit;
	L0 p0 = NULL;
	L0 q0 = Visit->plant;
	while (!feof(fp))
	{
		p2 = new LNode2[1];
		fscanf(fp, "%d%s", &p2->num, p2->name);
		p2->next = NULL;
		p0 = new LNode0[1];
		p0->next = NULL;
		p2->plant = p0;
		fscanf(fp, "%d%s%s%s%s%s%s%s%s", &p0->num, p0->name,p0->type, p0->huaqi, p0->location, p0->guanshang, p0->maintain,p0->yaoyong, p0->meaning);
		if (q2 == NULL) q2 = p2;
		else q2->next = p2;
		q2 = p2;
		if (q0 == NULL) q0 = p0;
		else q0->next = p0;
		q0 = p0;
	}
	fclose(fp);
	return true;
}

void Fprint_Plant(L0 Plant)
{
	FILE* fp;
	if ((fp = fopen("Plant.txt", "w")) == NULL)
	{
		cout << "Plant.txt文件打开错误，请检查文件是否受损";
		exit(0);
	}
	L0 p = Plant->next;
	for (; p != NULL;p=p->next)
	{
		fprintf(fp, "%d\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",p->num,p->name,p->type,p->huaqi,p->location,p->guanshang,p->maintain,p->yaoyong,p->meaning);
	}
	cout << "写入文件成功" << endl;
	fclose(fp);
}

void Fprint_Visit(L2 Visit)
{
	FILE* fp1;
	if ((fp1 = fopen("Visit.txt", "w")) == NULL)
	{
		cout << "Visit.txt文件打开错误，请检查文件是否受损";
		exit(0);
	}
	L2 p = Visit->next;
	for (; p != NULL; p = p->next)
	{
		fprintf(fp1, "%d\n%s\n", p->num, p->name);
		Fprint_Plant(p->plant);
	}
	cout << "写入文件成功" << endl;
	fclose(fp1);
}

void Fprint_User(L1 User) 
{
	FILE* fp;
	if ((fp = fopen("User.txt", "w")) == NULL)
	{
		cout << "User.txt文件打开错误，请检查文件是否受损";
		exit(0);
	}
	L1 p = User->next;
	for (; p != NULL; p = p->next)
	{
		fprintf(fp, "%d\n%s\n%s\n", p->state, p->name, p->key);
	}
	cout << "写入文件成功" << endl;
	fclose(fp);
}

bool Login_admin(L1 User,LNode1& e) //管理员登录
{
	L1 p = User;
	if (p == NULL)
	{
		cout << "User文件为空，请检查是否受损!" << endl;
		return false;
	}
	int flag = 1;
		char name[10], key[100];
		cout << "请输入管理员账号" << endl;
		cin >> name;
		while(p!=NULL)
		{
			if ((strcmp(name, p->name) == 0) && p->state == 1)
			{
				cout << "请输入密码" << endl;
				scanf("%s", &key);
				if (strcmp(key, p->key) == 0)
				{
					e = *p;
					return true;
				}
				else cout << "账号或密码错误" << endl;
			}
			else p = p->next;
		}
		cout << "输入的账户不存在" << endl;
		return false;
}

bool Login_user(L1 User,  LNode1& e) //用户登录
{
	L1 p = User;
	if (p == NULL)
	{
		cout << "User文件为空，请检查是否受损!" << endl;
		return false;
	}
	int flag = 1;
	char name[10], key[100];
	cout << "请输入您的账号" << endl;
	cin >> name;
	while (p != NULL)
	{
		if ((strcmp(name, p->name) == 0) && p->state == 2)
		{
			cout << "请输入密码" << endl;
			scanf("%s", &key);
			if (strcmp(key, p->key) == 0)
			{
				e = *p;
				return true;
			}
			else cout << "账号或密码错误" << endl;
		}
		else p = p->next;
	}
	cout << "输入的账户不存在" << endl;
	return false;
}

void PrintLNode0(L0 p)
{
	if (p == NULL)
	{
		cout << "植物信息为空" << endl;
		exit(0);
	}
	cout << " ======================================" << endl;
	cout << " |             植物信息如下           |" << endl;
	cout << " ======================================" << endl;
	cout << " |              编号                  |" << endl;
	printf("                 %d               \n", p->num);
	cout << " ======================================" << endl;
	cout << " |              名称                  |" << endl;
	printf("                 %s               \n", p->name);
	cout << " ======================================" << endl;
	cout << " |              种属                  |" << endl;
	printf("               %s               \n", p->type);
	cout << " ======================================" << endl;
	cout << " |              花期                  |" << endl;
	printf("                 %s               \n", p->huaqi);
	cout << " ======================================" << endl;
	cout << " |            栽种地点                |" << endl;
	printf("              %s               \n", p->location);
	cout << " ======================================" << endl;
	cout << " |            观赏性                  |" << endl;
	printf("              %s               \n", p->guanshang);
	cout << " ======================================" << endl;
	cout << " |            植物维护                |" << endl;
	printf("   %s\n", p->maintain);
	cout << " ======================================" << endl;
	cout << " |            药用价值                |" << endl;
	printf(   "%s\n", p->yaoyong);
	cout << " ======================================" << endl;
	cout << " |             历史意义               |" << endl;
	printf("   %s               \n", p->meaning);
	cout << " ======================================" << endl;
	printf("\n");
}

void PrintLNode2(L2 p)
{
	if (p == NULL)
	{
		cout << "游览路线信息为空" << endl;
		exit(0);
	}
	L0 q = p->plant;
	cout << "            游览信息如下       " << endl;
	cout << " ======================================" << endl;
	cout << "                编号              " << endl;
	printf("                 %d               \n", p->num);
	cout << " ======================================" << endl;
	cout << "              路线名称              " << endl;
	printf("                 %s               \n", p->name);
	cout << " ======================================" << endl;
	while (q != NULL)
	{
		if (q == NULL)
		{
			cout << "植物信息为空" << endl;
			exit(0);
		}
		cout << "               植物信息如下       " << endl;
		cout << " ======================================" << endl;
		cout << " |              编号                  |" << endl;
		cout << "              " << q->num << endl;
		cout << " ======================================" << endl;
		cout << " |              名称                  |" << endl;
		cout << "                 " << q->name << endl;;
		cout << " ======================================" << endl;
		cout << " |              种类                  |" << endl;
		printf("                  %s               \n", q->type);
		cout << " ======================================" << endl;
		cout << " |              花期                  |" << endl;
		printf("                  %s               \n", q->huaqi);
		cout << " ======================================" << endl;
		cout << " |            栽种地点                |" << endl;
		printf("                  %s               \n", q->location);
		cout << " ======================================" << endl;
		cout << " |             观赏性                 | " << endl;
		printf("                  %s               \n", q->guanshang);
		cout << " ======================================" << endl;
		cout << " |            植物维护                |" << endl;
		printf("              %s               \n", q->maintain);
		cout << " ======================================" << endl;
		cout << " |            药用价值                |" << endl;
		printf( "                 %s                  \n", q->yaoyong);
		cout << " ======================================" << endl;
		cout << " |            历史意义                |" << endl;
		printf("                  %s               \n", q->meaning);
		cout << " ======================================" << endl;
		q = q->next;
	}
}

L0 Plant_chaxun(L0 Plant)	//查询植物信息
{

	L0 tmp = NULL;
	char state = 0;
	cout << "*******************************************************************************************************************" << endl;
	cout << "|                    1 按植物编号进行查询       2 按植物名称进行查询    0  退出查询                               |" << endl;
	cout << "*******************************************************************************************************************" << endl;
	cin >> state;
	if (state == '0') return NULL;
	switch (state - '0')
	{
	case(1):
		int cha_num;
		cout << "请输入植物编号" << endl;
		cin >> cha_num;
		tmp=Plant_chaxun_num(cha_num, Plant);
		if (tmp != NULL)
		{
			return tmp;
			break;
		}
		printf("您的输入有误!\n");
		break;
	case(2):
		char cha_name[20];
		cout << "请输入植物名称" << endl;
		cin >> cha_name;
		tmp = Plant_chaxun_name(cha_name, Plant);
		if (tmp != NULL)
		{
			return tmp;
			break;
		}
		printf("您的输入有误!\n");
		break;
	default:
		printf("您的输入有误!\n");
		break;
	}
	return NULL;
}

L0 Plant_chaxun_num(int num, L0 Plant)	//使用编号查询植物信息
{
	if (Plant == NULL)
	{
		cout << "当前植物信息为空" << endl;
	}
	L0 p = Plant->next;
	while (p != NULL)
	{

		if (p->num == num)
		{
			PrintLNode0(p);
			return p;
		}
		else p = p->next;
	}
	cout << "输入的植物信息不存在" << endl;
	return NULL;
}

L0 Plant_chaxun_name(char name[], L0 Plant)	//使用名称查询植物信息
{
	if (Plant == NULL)
	{
		cout << "当前植物信息为空" << endl;
	}
	L0 p = Plant->next;
	while (p != NULL)
	{

		if (strcmp(name, p->name) == 0)
		{
			PrintLNode0(p);
			return p;
		}
		else p = p->next;
	}
	cout << "输入的植物信息不存在" << endl;
	return NULL;
}

bool Plant_delete(L0& Plant)
{
	L0 head = Plant;
	char state = 0;
	L0 tmp = NULL;
	cout << "*******************************************************************************************************************" << endl;
	cout << "|                    1 按植物编号进行删除       2 按植物名称进行删除    0  退出删除                               |" << endl;
	cout << "*******************************************************************************************************************" << endl;
	cin >> state;
	if (state == '0') return false;
	switch (state - '0')
	{
	case(1):
		int del_num;
		cout << "请输入植物编号" << endl;
		cin >> del_num;
		Plant_delete_num(del_num, Plant);
		break;
	case(2):
		char del_name[20];
		cout << "请输入植物名称" << endl;
		cin >> del_name;
		Plant_delete_name(del_name, Plant);
		break;
	}
	return true;
}

void Plant_delete_num(int num, L0& Plant)	//使用编号查询植物信息
{
	if (Plant == NULL)
	{
		cout << "当前植物信息为空" << endl;
		return;
	}
	else {
		L0 prev = Plant, curr = Plant->next;
		while (curr) {
			if (curr->num == num) {
				prev->next = curr->next;
				delete curr;
				return;
			}
			prev = curr;
			curr = curr->next;
		}

		cout << "输入的植物信息不存在" << endl;
	}
}

void Plant_delete_name(char name[], L0& Plant)	//使用名称删除询植物信息
{
	if (Plant == NULL)
	{
		cout << "当前植物信息为空" << endl;
		return;
	}
	L0 p = Plant->next, q = Plant;
	while (p != NULL)
	{
		if (strcmp(name, p->name) == 0)
		{
			q->next = p->next; 
			delete p;
			cout << "植物信息删除成功" << endl;
			return;
		}
		else
		{
			q = p; 
			p = p->next; 
		}
	}
	}
	cout << "输入的植物信息不存在" << endl;
}

void Plant_bianli(L0 Plant)
{
	L0 q = Plant->next;
	while (q != NULL)
	{
		PrintLNode0(q);
		q = q->next;
	}
}

void Plant_xiugai(L0& Plant)
{
	L0 head = Plant;
	char state = 0;
	L0 tmp = NULL;
	cout << "*******************************************************************************************************************" << endl;
	cout << "|                    1 按植物编号进行修改       2 按植物名称进行修改    0  退出修改                               |" << endl;
	cout << "*******************************************************************************************************************" << endl;
	cin >> state;
	switch (state - '0')
	{
	case 0:
		return;
	case(1):
		int xiugai_num;
		cout << "请输入植物编号" << endl;
		cin >> xiugai_num;
		Plant_xiugai_num(xiugai_num, Plant);
		break;
	case(2):
		char xiugai_name[20];
		cout << "请输入植物名称" << endl;
		cin >> xiugai_name;
		Plant_xiugai_name(xiugai_name, Plant);
		break;
	default:
		printf("您的输入有误!\n");
		break;
	}
}

void Plant_xiugai_num(int num, L0& Plant)	//使用编号修改植物信息
{
	if (Plant == NULL)
	{
		cout << "当前植物信息为空" << endl;
	}
	L0 p = Plant;
	while (p != NULL)
	{
		int xiugai = 0;
		if (p->num == num)
		{
			printf("              ============================================================\n");
			printf("              **                       0-放弃修改                       **\n");
			printf("              **  1-编号               2-植物名          3-种属         **\n");
			printf("              **  4-花期               5-栽种地点        6-观赏性       **\n");
			printf("              **  7-维护信息           8-药用价值        9-历史意义     **\n");
			printf("              **                       10-修改全部                       **\n");
			printf("              ============================================================\n");
			printf("请选择你要修改的信息编号:");
			cin >> xiugai;
			switch (xiugai)
			{
			case 0:
				return;
			case 1:
				printf("请输入新编号:");
				scanf("%d", &p->num);
				printf("修改成功!\n");
				system("pause");
				break;
			case 2:
				printf("请输入植物名:");
				cin >> p->name;
				printf("修改成功!\n");
				break;

			case 3:
				cout << "请输入植物的种属：";
				cin >> p->type;
				printf("修改成功!\n");
				break;

			case 4:
				cout << "请输入植物的花期：";
				cin >> p->huaqi;
				printf("修改成功!\n");
				break;

			case 5:
				cout << "请输入植物的栽种地点：";
				cin >> p->location;
				printf("修改成功!\n");
				break;

			case 6:
				cout << "请输入植物的观赏性：";
				cin >> p->guanshang;
				printf("修改成功!\n");
				break;
			case 7:
				cout << "请输入植物的维护信息：";
				cin >> p->maintain;
				printf("修改成功!\n");
				break;
			case 8:
				cout << "请输入植物的药用价值：";
				cin >> p->yaoyong;
				printf("修改成功!\n");
				break;

			case 9:
				cout << "请输入植物的历史意义或纪念意义：";
				cin >> p->meaning;
				printf("修改成功!\n");
				break;

			case 10:
				cout << "请输入植物的名称：";
				cin >> p->name;
				cout << "请输入植物的种属：";
				cin >> p->type;
				cout << "请输入植物的花期：";
				cin >> p->huaqi;
				cout << "请输入植物的栽种地点：";
				cin >> p->location;
				cout << "请输入植物的观赏性：";
				cin >> p->guanshang;
				cout << "请输入植物的维护信息：";
				cin >> p->maintain;
				cout << "请输入植物的药用价值：";
				cin >> p->yaoyong;
				cout << "请输入植物的历史意义或纪念意义：";
				cin >> p->meaning;
				printf("修改成功!\n");
				break;
			}
		}
		else p = p->next;
	}
	cout << "输入的植物信息不存在" << endl;
}

void Plant_xiugai_name(char name[], L0& Plant)	//使用名称修改植物信息
{
	if (Plant == NULL)
	{
		cout << "当前植物信息为空" << endl;
	}
	L0 p = Plant;
	while (p != NULL)
	{
		int xiugai = 0;
		if (strcmp(name, p->name) == 0)
		{
			printf("              ============================================================\n");
			printf("              **                       0-放弃修改                       **\n");
			printf("              **  1-编号               2-植物名          3-种属         **\n");
			printf("              **  4-花期               5-栽种地点        6-观赏性       **\n");
			printf("              **  7-维护信息           8-药用价值        9-历史意义     **\n");
			printf("              **                       10-修改全部                       **\n");
			printf("              ============================================================\n");
			printf("请选择你要修改的信息编号:");
			cin >> xiugai;
			switch (xiugai)
			{
			case 0:
				return;
			case 1:
				printf("请输入新编号:");
				scanf("%d", &p->num);
				printf("修改成功!\n");
				system("pause");
				break;
			case 2:
				printf("请输入植物名:");
				cin >> p->name;
				printf("修改成功!\n");
				break;

			case 3:
				cout << "请输入植物的种属：";
				cin >> p->type;
				printf("修改成功!\n");
				break;

			case 4:
				cout << "请输入植物的花期：";
				cin >> p->huaqi;
				printf("修改成功!\n");
				break;

			case 5:
				cout << "请输入植物的栽种地点：";
				cin >> p->location;
				printf("修改成功!\n");
				break;

			case 6:
				cout << "请输入植物的观赏性：";
				cin >> p->guanshang;
				printf("修改成功!\n");
				break;
			case 7:
				cout << "请输入植物的维护信息：";
				cin >> p->maintain;
				printf("修改成功!\n");
				break;
			case 8:
				cout << "请输入植物的药用价值：";
				cin >> p->yaoyong;
				printf("修改成功!\n");
				break;

			case 9:
				cout << "请输入植物的历史意义或纪念意义：";
				cin >> p->meaning;
				printf("修改成功!\n");
				break;

			case 10:
				cout << "请输入植物的名称：";
				cin >> p->name;
				cout << "请输入植物的种属：";
				cin >> p->type;
				cout << "请输入植物的花期：";
				cin >> p->huaqi;
				cout << "请输入植物的栽种地点：";
				cin >> p->location;
				cout << "请输入植物的观赏性：";
				cin >> p->guanshang;
				cout << "请输入植物的维护信息：";
				cin >> p->maintain;
				cout << "请输入植物的药用价值：";
				cin >> p->yaoyong;
				cout << "请输入植物的历史意义或纪念意义：";
				cin >> p->meaning;
				printf("修改成功!\n");
				break;
			}
		}
		else p = p->next;
	}
	cout << "输入的植物信息不存在" << endl;
}

bool Visit_delete(L2& Visit)
{
	L2 head = Visit;
	char state = 0;
	L0 tmp = NULL;
	cout << "*******************************************************************************************************************" << endl;
	cout << "|                  1 按游览路线编号进行删除         2 按游览路线名称进行删除       0  退出删除                    |" << endl;
	cout << "*******************************************************************************************************************" << endl;
	cin >> state;
	switch (state - '0')
	{
	case(1):
		int del_num;
		cout << "请输入游览路线编号" << endl;
		cin >> del_num;
		return Visit_delete_num(del_num, Visit);
		break;
	case(2):
		char del_name[20];
		cout << "请输入游览路线名称" << endl;
		cin >> del_name;
		return Visit_delete_name(del_name, Visit);
		break;
	default:
		printf("您的输入有误!\n");
		return 0;
	}
}

void Visit_delete_num(int num, L2& Visit)	//使用编号查询游览路线
{
	if (Visit == NULL)
	{
		cout << "当前游览路线信息为空" << endl;
	}
	L2 p = Visit, q = NULL;
	if (p->num == num) {
		p = NULL;
		return;
	}
	while (p->next != NULL)
	{
		if (p->num == num)
		{
			if (p->next == NULL)
				q->next = NULL;
			else q->next = p->next;
			delete p;
		}
		else
		{
			q = p;
			p = p->next;
		}
	}
	cout << "输入的游览路线信息不存在" << endl;
}

void Visit_delete_name(char name[], L2& Visit)	//使用名称查询植物信息
{
	if (Visit == NULL)
	{
		cout << "当前游览路线信息为空" << endl;
	}
	L2 p = Visit, q = NULL;
	if (strcmp(name, p->name) == 0) {
		p = NULL;
		return;
	}
	while (p->next != NULL)
	{
		if (strcmp(name, p->name) == 0)
		{
			if (p->next == NULL)
				q->next = NULL;
			else q->next = p->next;
			delete p;
		}
		else {
			q = p;
			p = p->next;
		}
	}
	cout << "输入的游览路线信息不存在" << endl;
}

L2 Visit_chaxun(L2 Visit)
{

	L2 head = Visit;
	char state = 0;
	L2 tmp = NULL;
	cout << "*******************************************************************************************************************" << endl;
	cout << "|               1 按游览路线编号进行查询       2 按游览路线名称进行查询    0  退出查询                            |" << endl;
	cout << "*******************************************************************************************************************" << endl;
	cin >> state;
	switch (state - '0')
	{
	case(1):
		int cha_num;
		cout << "请输入游览路线编号" << endl;
		cin >> cha_num;
		tmp=Visit_chaxun_num(cha_num, Visit);
		if (tmp != NULL)
		{
			return tmp;
			break;
		}
		printf("您的输入有误!\n");
	case(2):
		char cha_name[20];
		cout << "请输入游览路线名称" << endl;
		cin >> cha_name;
		tmp=Visit_chaxun_name(cha_name, Visit);
		if (tmp != NULL)
		{
			return tmp;
			break;
		}
		printf("您的输入有误!\n");
		break;
	default:
		printf("您的输入有误!\n");
		break;
	}
	return NULL;
}

L2 Visit_chaxun_num(int num, L2 Visit)	//使用编号查询游览路线信息
{
	if (Visit == NULL)
	{
		cout << "当前游览路线信息为空" << endl;
		return NULL;
	}
	L2 p = Visit;
	while (p != NULL)
	{

		if (p->num == num)
		{
			PrintLNode2(p);
			return p;
		}
		else p = p->next;
	}
	cout << "输入的游览路线信息不存在" << endl;
	return NULL;
}

L2 Visit_chaxun_name(char name[], L2 Visit)	//使用名称查询游览路线信息
{
	if (Visit == NULL)
	{
		cout << "当前游览路线信息为空" << endl;
		return NULL;
	}
	L2 p = Visit;
	while (p != NULL)
	{

		if (strcmp(name, p->name) == 0)
		{
			PrintLNode2(p);
			return p;
		}
		else p = p->next;
	}
	cout << "输入的游览路线信息不存在" << endl;
	return NULL;
}

void Visit_xiugai(L2& Visit)
{
	L2 head = Visit;
	L0 head0 = Visit->plant;
	char state = 0;
	L0 tmp = NULL;
	cout << "*******************************************************************************************************************" << endl;
	cout << "|                 1 按游览路线编号进行修改       2 按游览路线名称进行修改    0  退出修改                          |" << endl;
	cout << "*******************************************************************************************************************" << endl;
	cin >> state;
	switch (state - '0')
	{
	case 0:
		return;
	case(1):
		int xiugai_num;
		cout << "请输入路线编号" << endl;
		cin >> xiugai_num;
		Visit_xiugai_num(xiugai_num, head);
		break;
	case(2):
		char xiugai_name[20];
		cout << "请输入路线名称" << endl;
		cin >> xiugai_name;
		Visit_xiugai_name(xiugai_name, head);
		break;
	default:
		printf("您的输入有误!\n");
		break;
	}
}

void Visit_xiugai_num(int num, L2& Visit)	//使用编号修改植物信息
{
	if (Visit == NULL)
	{
		cout << "当前植物信息为空" << endl;
	}
	L2 p = Visit;
	while (p != NULL)
	{
		if (Visit == NULL)
		{
			cout << "当前植物信息为空" << endl;
		}
		L2 p = Visit;
		while (p != NULL)
		{
			int xiugai = 0;
			if (num == p->num)
			{
				printf("              ==================================================\n");
				printf("              **               0-放弃修改                    **\n");
				printf("              **  1-编号       2-游览地点     3-植物信息     **\n");
				printf("              **               4-修改全部                    **\n");
				printf("              =================================================\n");
				printf("请选择你要修改的信息编号:");
				cin >> xiugai;
				switch (xiugai)
				{
				case 0:
					break;
				case 1:
					printf("请输入新编号:");
					scanf("%d", &p->num);
					printf("修改成功!\n");
					system("pause");
					break;
				case 2:
					printf("请输入新游览地点名:");
					cin >> p->name;
					printf("修改成功!\n");
					break;

				case 3:
					Plant_xiugai(p->plant);
				default:
					printf("您的输入有误!\n");
					break;
				}
			}
			else p = p->next;
		}
		cout << "输入的植物信息不存在" << endl;
	}
}

void Visit_xiugai_name(char name[], L2& Visit)	//使用名称修改植物信息
{
	if (Visit == NULL)
	{
		cout << "当前植物信息为空" << endl;
	}
	L2 p = Visit;
	while (p != NULL)
	{
		int xiugai = 0;
		if (strcmp(name, p->name) == 0)
		{
			printf("              ============================================================\n");
			printf("              **                    0-放弃修改                          **\n");
			printf("              **  1-编号            2-游览路线名          3-植物信息    **\n");
			printf("              **                    4-修改全部                          **\n");
			printf("              ============================================================\n");
			printf("请选择你要修改的信息编号:");
			cin >> xiugai;
			switch (xiugai)
			{
			case 0:
				break;
			case 1:
				printf("请输入新编号:");
				scanf("%d", &p->num);
				printf("修改成功!\n");
				system("pause");
				break;
			case 2:
				printf("请输入植物名:");
				cin >> p->name;
				printf("修改成功!\n");
				break;

			case 3:
				Plant_xiugai(p->plant);
			default:
				printf("您的输入有误!\n");
				break;
			}
		}
		else p = p->next;
	}
	cout << "输入的植物信息不存在" << endl;
}

bool Plant_star(L0 p)
{
	if (p == NULL) return false;
	char ch;
	cout << "是否收藏该植物信息？ 是（Y）/否（N）";
	cin >> ch;
	if (ch == 'N' || ch == 'n') return false;
	FILE* fp = NULL;
	if ((fp = fopen("Star.txt", "a")) == NULL)
	{
		cout << "Star.txt文件打开错误，请检查文件是否受损";
		return false;
	}
	fprintf(fp, "%d\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n", p->num, p->name, p->type, p->huaqi, p->location, p->guanshang, p->yaoyong, p->meaning);
	cout << "写入文件成功" << endl;
	fclose(fp);
	return true;
}

void Visit_star(L2 p)
{
	char ch;
	cout << "是否收藏该游览路线？ 是（Y）/否（N）";
	cin >> ch;
	if (ch == 'N' || ch == 'n') exit(0);
	FILE* fp1;
	if ((fp1 = fopen("Star.txt", "a")) == NULL)
	{
		cout << "Star.txt文件打开错误，请检查文件是否受损";
		exit(0);
	}
		fprintf(fp1, "%d\n%s\n", p->num, p->name);
		Fprint_Plant(p->plant);
	cout << "写入文件成功" << endl;
	fclose(fp1);
}

void Visit_bianli(L2 Visit)
{
	L2 q = Visit->next;
	while (q != NULL)
	{
		PrintLNode2(q);
		q = q->next;
	}
}

void Share()
{
	char a = 0;
	cout << "是否分享给他人？  是(Y) 否(N)"<<endl;
	cin >> a;
	if (a == 'y' || a == 'Y')
	{
		cout << "请扫码登录" << endl;
		system("pause");
		cout << "登录成功" << endl;
		cout << "输入将要分享的平台 微信朋友圈/QQ空间/抖音/微博/小红书" << endl;
		getchar();
		cout << "分享成功" << endl;
	}
}

void LogInMenu()	//登录界面
{
	cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "|                                           欢迎使用华南农业大学植物观赏系统                                      |" << endl;
	cout << "----------------------------------------------------***********----------------------------------------------------" << endl;
	cout << "|                                                1 以管理员身份登录                                               |" << endl;
	cout << "*******************************************************************************************************************" << endl;
	cout << "|                                                2 以用户身份登录                                                 |" << endl;
	cout << "*******************************************************************************************************************" << endl;
	cout << "|                                                3   新用户注册                                                   |" << endl;
	cout << "*******************************************************************************************************************" << endl;
	cout << "|                                                4      帮助                                                      |" << endl;
	cout << "*******************************************************************************************************************" << endl;
	cout << "|                                                0      退出                                                      |" << endl;
	cout << "----------------------------------------------------***********----------------------------------------------------" << endl;
}

void tuichujiemian()//退出界面
{
	cout << "----------------------------------------------------***********------------------------------------------------------" << endl;
	cout << "                                                    感谢您的使用                                                    |" << endl;
	cout << "|                                     BBBBBBBBB      YY     YY     EEEEEEEE                                         |" << endl;
	cout << "|                                     BB   BBB        YY   YY      EE                                               |" << endl;
	cout << "|                                     BB  BBB          YY YY       EE                                               |" << endl;
	cout << "|                                     BBBBB             YY         EEEEEEEE                                         |" << endl;
	cout << "|                                     BB  BBB           YY         EE                                               |" << endl;
	cout << "|                                     BB    BBB         YY         EE                                               |" << endl;
	cout << "|                                     BBBBBBBBB         YY         EEEEEEEE                                         |" << endl;
	cout << "----------------------------------------------------***********------------------------------------------------------" << endl;
}

void admin_caozuojiemian(LNode1 e)
{
	cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "|                                           欢迎使用华南农业大学植物观赏系统                                      |" << endl;
	cout << "|                                                                                                                 |" << endl;
	printf("                                                    %s你好                                                     ", e.name);
	cout << "|                                                                                                                 |" << endl;
	cout << "----------------------------------------------------***********----------------------------------------------------" << endl;
	cout << "|                                                  0 退出登录                                                     |" << endl;
	cout << "*******************************************************************************************************************" << endl;
	cout << "|                                  1   查询植物信息            2   查询赏花路线                                   |" << endl;
	cout << "*******************************************************************************************************************" << endl;
	cout << "|                                  3   添加植物信息            4   添加赏花路线                                   |" << endl;
	cout << "*******************************************************************************************************************" << endl;
	cout << "|                                  5   删除植物信息            6   删除赏花路线                                   |" << endl;
	cout << "*******************************************************************************************************************" << endl;
	cout << "|                                  7   修改植物信息            8   修改赏花路线                                   |" << endl;
	cout << "*******************************************************************************************************************" << endl;
	cout << "|                                  9   浏览植物信息            10  浏览赏花路线                                   |" << endl;
	cout << "*******************************************************************************************************************" << endl;
}

void user_caozuojiemian(LNode1 e)
{
	cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "|                                           欢迎使用华南农业大学植物观赏系统                                      |" << endl;
	cout << "|                                                                                                                 |" << endl;
	printf("                                                    %s你好                                                     ", e.name);
	cout << "|                                                                                                                 |" << endl;
	cout << "----------------------------------------------------***********----------------------------------------------------" << endl;
	cout << "|                                                  0 退出登录                                                     |" << endl;
	cout << "*******************************************************************************************************************" << endl;
	cout << "|                                  1   查询植物信息            2   查询赏花路线                                   |" << endl;
	cout << "*******************************************************************************************************************" << endl;
	cout << "|                                  3   浏览植物信息            4   浏览赏花路线                                   |" << endl;
	cout << "*******************************************************************************************************************" << endl;
}