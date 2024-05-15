#include <iostream>
#include<cstdio>

using namespace std;

typedef struct LinkList0	//ֲ����Ϣ����
{
	int num;			//���
	char name[20];		//ֲ����
	char type[20];		//����
	char huaqi[16];		//����
	char location[20];	//���ֵص�
	char guanshang[10];	//������
	char maintain[200];	//ά��
	char yaoyong[1000];	//ҩ�ü�ֵ
	char meaning[100];	//��ʷ������������
	LinkList0* next;
}LNode0, * L0;


typedef struct LinkList1 // ����Ա/�û��˺���������
{
	int state;			// �û���� 1Ϊ����Ա 2Ϊ�û�
	char name[10];
	char key[100];
	LinkList1* next;
}LNode1, * L1;

typedef struct LinkList2	//����·����Ϣ����
{
	int num;				//���
	char name[20];			//�ص���
	L0 plant;
	LinkList2* next;
}LNode2, * L2;


void InitL0(L0& L);										//��ʼ��L0
void InitL1(L1& L);										//��ʼ��L1
void InitL2(L2& L);										//��ʼ��L2
void CreateL0(int n, L0& Plant);						//������ͷ����ֲ����Ϣ����
void Createyonghu(L1& L);								//������ͷ�����û���Ϣ����
void CreateVisit(int num,L2& L);						//������ͷ��������·����Ϣ����
void PrintLNode0(L0 p);									//���L0���
void PrintLNode2(L2 p);									//���L2���
bool LoadFile_Plant(FILE* PlantFilePoi, L0& Plant);		//����PLant�ļ��е�����
bool LoadFile_User(FILE* UserFilePoi, L1& User);		//����User�ļ��е�����
bool LoadFile_Visit(FILE* fp, L2& Visit);				//����Visit�ļ��е�����
void Fprint_Plant(L0 Plant);							//����Plantд���ļ���
void Fprint_User(L1 User);								//����Userд���ļ���
void Fprint_Visit(L2 Visit);							//����Visitд���ļ���
L0 Plant_chaxun(L0 Plant);								//��ѯֲ����Ϣ
L0 Plant_chaxun_num(int num, L0 Plant);					//ʹ�ñ�Ų�ѯֲ����Ϣ
L0 Plant_chaxun_name(char name[], L0 Plant);			//ʹ�����Ʋ�ѯֲ����Ϣ
L2 Visit_chaxun(L2 Visit);								//��ѯ����·��
L2 Visit_chaxun_num(int num, L2 Visit);					//ʹ�ñ�Ų�ѯ����·��
L2 Visit_chaxun_name(char name[], L2 Visit);			//ʹ�����Ʋ�ѯ����·��
bool Plant_delete(L0& Plant);							//ɾ��ֲ����Ϣ
void Plant_delete_num(int num, L0& Plant);				//ʹ�ñ��ɾ��ֲ����Ϣ
void Plant_delete_name(char name[], L0& Plant);			//ʹ������ɾ��ֲ����Ϣ
void Visit_delete(L2& Visit);							//ɾ������·��
void Visit_delete_num(int num, L2& Visit);				//ʹ�ñ��ɾ������·��
void Visit_delete_name(char name[], L2& Visit);			//ʹ������ɾ������·��
void Plant_xiugai(L0& Plant);							//�޸�ֲ����Ϣ
void Plant_xiugai_num(int num, L0& Plant);				//ʹ�ñ���޸�ֲ����Ϣ
void Plant_xiugai_name(char name[], L0& Plant);			//ʹ�������޸�ֲ����Ϣ
void Visit_xiugai(L2& Visit);							//�޸�����·��
void Visit_xiugai_num(int num, L2& Visit);				//ʹ�ñ���޸�����·��
void Visit_xiugai_name(char name[], L2& Visit);			//ʹ�������޸�����·��
void Plant_bianli(L0 Plant);							//����ֲ����Ϣ
bool Plant_star(L0 p);									//�ղ�ֲ����Ϣ
void Visit_star(L2 p);									//�ղ�����·��
void Visit_bianli(L2 Visit);							//��������·��
void Share();											//������
void LogInMenu();										//��¼����
void tuichujiemian();									//�˳�����
void admin_caozuojiemian(LNode1 e);						//����Ա��������
void user_caozuojiemian(LNode1 e);						//�û���������
bool Login_admin(L1 User, LNode1& e);					//����Ա��¼
bool Login_user(L1 User, LNode1& e);					//�û���¼

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
	cout << "|                                             ��ӭʹ�û���ũҵ��ѧֲ�����ϵͳ                                      |" << endl;
	cout << "|------------------------------------------------------***********--------------------------------------------------|" << endl;
	cout << endl;
	cout << "                                                  �� ¼��Y or N��" << endl;

	//��¼ģ��
	char denglu[10];
	int state = 1, times = 5;
	int glycz = 1, yhcz = 1;	//����Ա���� �û�����
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
							cout << "��������ѡ������" << endl;
							cin >> glycz;
							switch (glycz)
							{

							case 1://��ѯֲ����Ϣ
							{
								LoadFile_Plant(fp, Plant);
								if (Plant == NULL)
								{
									cout << "ֲ����ϢΪ�գ�����¼�����ݣ�" << endl;
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
							case 2: //��ѯ����·����Ϣ
							{
								LoadFile_Visit(fp, Visit);
								if (Visit == NULL)
								{
									cout << "����·����ϢΪ�գ�����¼�����ݣ�" << endl;
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

							case 3: //����ֲ����Ϣ
							{
								LoadFile_Plant(fp, Plant);
								int n = 0;
								cout << "������Ҫ����ֲ��ĸ���" << endl;
								cin >> n;
								CreateL0(n, Plant);
								Fprint_Plant(Plant);
								system("pause");
								break;

							}

							case 4: //��������·��
							{
								LoadFile_Visit(fp, Visit);
								if (Visit == NULL)
								{
									cout << "����·����ϢΪ�գ�����¼�����ݣ�" << endl;
									system("pause");
									break;
								}
								else
								{
									int n = 0;
									cout << "������Ҫ��������·�ߵĸ���" << endl;
									cin >> n;
									CreateVisit(n, Visit);
									Fprint_Visit(Visit);
									system("pause");
									break;
								}
							}
							case 5: //ɾ��ֲ����Ϣ
							{
								LoadFile_Plant(fp, Plant);
								if (Plant == NULL)
								{
									cout << "ֲ����ϢΪ�գ�����¼�����ݣ�" << endl;
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

							case 6://ɾ������·��
							{
								LoadFile_Visit(fp, Visit);
								if (Visit == NULL)
								{
									cout << "����·��Ϊ�գ�����¼�����ݣ�" << endl;
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
							case 7://�޸�ֲ����Ϣ
							{
								LoadFile_Plant(fp, Plant);
								if (Plant == NULL)
								{
									cout << "ֲ����ϢΪ�գ�����¼�����ݣ�" << endl;
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
							case 8://�޸�����·��
							{
								LoadFile_Visit(fp, Visit);
								if (Visit == NULL)
								{
									cout << "����·��Ϊ�գ�����¼�����ݣ�" << endl;
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
							case 9://����ֲ����Ϣ
							{
								LoadFile_Plant(fp, Plant);
								if (Plant == NULL)
								{
									cout << "ֲ����ϢΪ�գ�����¼�����ݣ�" << endl;
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
									cout << "����·����ϢΪ�գ�����¼�����ݣ�" << endl;
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
								cout << "��������������������룡" << endl;
								system("pause");
								break;
							}
						}
						if (glycz == 0) break;
					}
					cout << "�˳���¼������ N" << endl;
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
							cout << "��������ѡ������" << endl;
							cin >> yhcz;
							switch (yhcz)
							{
							case 0:
								break;
							case 1://��ѯֲ����Ϣ
							{
								LoadFile_Plant(fp, Plant);
								if (Plant == NULL)
								{
									cout << "ֲ����ϢΪ�գ�����¼�����ݣ�" << endl;
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
										cout << "�Ƿ������ѯ�� �ǣ�1�� ��0��";
										cin >> flag;
										if (flag == 0) break;
									}
								}

								break;
							}
							case 2: //��ѯ����·����Ϣ
							{
								LoadFile_Visit(fp, Visit);
								if (Visit == NULL)
								{
									cout << "����·����ϢΪ�գ�����¼�����ݣ�" << endl;
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
										cout << "�Ƿ������ѯ�� �ǣ�1�� ��0��";
										cin >> flag;
										if (flag == 0) break;
									}
								}
								break;
							}
							case 3://����ֲ����Ϣ
							{
								LoadFile_Visit(fp, Visit);
								if (Visit == NULL)
								{
									cout << "����·����ϢΪ�գ�����¼�����ݣ�" << endl;
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
							case 4: //��������·��
							{
								LoadFile_Visit(fp, Visit);
								if (Visit == NULL)
								{
									cout << "����·����ϢΪ�գ�����¼�����ݣ�" << endl;
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
								printf("������������,����������!\n");
								system("pause");
								break;

							}
						}
						if (yhcz == 0) break;
					}
					cout << "�˳���¼������ N" << endl;
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
				cout << "|                                      �������� ��绰��ϵ��13825773655                                           |" << endl;
				cout << "*******************************************************************************************************************" << endl;
				system("pause");
				break;
			default:
				printf("������������!\n");
				system("pause");
				break;
			}
		}
	}
	tuichujiemian();
	return 0;
}

void InitL0(L0& L)		//��ʼ��L0
{
	L0 p = new LNode0[1];
	p->next = NULL;
	L = p;
}

void InitL1(L1& L)		//��ʼ��L1
{
	L1 p = new LNode1[1];
	p->next = NULL;
	L = p;
}

void InitL2(L2& L)		//��ʼ��L2
{
	L2 p = new LNode2[1];
	L0 q;
	InitL0(q);
	p->next = NULL;
	p->plant = q;
	L = p;
}

void CreateL0(int n, L0& Plant)	//����ֲ����Ϣ
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
			cout << "������ֲ��ı�ţ�";
			cin >> tmp->num;
			cout << "������ֲ������ƣ�";
			cin >> tmp->name;
			cout << "������ֲ���������";
			cin >> tmp->type;
			cout << "������ֲ��Ļ��ڣ�";
			cin >> tmp->huaqi;
			cout << "������ֲ������ֵص㣺";
			cin >> tmp->location;
			cout << "������ֲ��Ĺ����ԣ�";
			cin >> tmp->guanshang;
			cout << "������ֲ���ά����Ϣ��";
			cin >> tmp->maintain;
			cout << "������ֲ���ҩ�ü�ֵ��";
			cin >> tmp->yaoyong;
			cout << "������ֲ�����ʷ�����������壺";
			cin >> tmp->meaning;
			p->next = tmp;
			p = tmp;
			
	}
}

void  CreateVisitL0(int n, L0& L)	//���������ص��ֲ����Ϣ
{
	L0 p = L;
	for (int i = 0; i < n; i++)
	{
		L0 tmp = new LNode0[1];
		cout << "������ֲ��ı�ţ�";
		cin >> tmp->num;
		cout << "������ֲ������ƣ�";
		cin >> tmp->name;
		cout << "������ֲ���������";
		cin >> tmp->type;
		cout << "������ֲ��Ļ��ڣ�";
		cin >> tmp->huaqi;
		cout << "������ֲ������ֵص㣺";
		cin >> tmp->location;
		cout << "������ֲ��Ĺ����ԣ�";
		cin >> tmp->guanshang;
		cout << "������ֲ���ά����Ϣ��";
		cin >> tmp->maintain;
		cout << "������ֲ���ҩ�ü�ֵ��";
		cin >> tmp->yaoyong;
		cout << "������ֲ�����ʷ�����������壺";
		cin >> tmp->meaning;
		tmp->next = NULL;
		if (p == NULL) p = tmp;
		else  p = p->next;
		p->next = tmp;
	}
}

void Createyonghu(L1& User)			//�����û���Ϣ
{
	L1 tmp = new LNode1[1];
	tmp->next = NULL;
	cout << "�������û����ƣ����Ʋ�����10���֣���";
	cin >> tmp->name;
	cout << "�������û����루���벻����20���ַ�����";
	cin >> tmp->key;
	tmp->state = 2;
	L1 p = User;
	if (p == NULL) p = tmp;
	else while (p->next != NULL) p = p->next;
	p->next = tmp;
}

void CreateVisit(int num,L2& Visit) //�������·��
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
		cout << "����������·�ߵı��" << endl;
		cin >> tmp->num;
		cout << "����������·�ߵ�����" << endl;
		cin >> tmp->name;
		cout << "����������·���г��ֵ�ֲ������" << endl;
		cin >> n;
		CreateVisitL0(n, q);
		if (p == NULL) p = tmp;
		else while (p->next != NULL) p = p->next;
		p->next = tmp;
	}
}

bool LoadFile_Plant(FILE* fp, L0& Plant)	//����PLant�ļ��е�����
{
	fp = fopen("Plant.txt", "r");
	if (fp == NULL)
	{
		cout << "Plant.txt�ļ��򿪴���" << endl;	
		cout << "����ϵͳ�����Plant.txt�ļ��Ƿ�����" << endl;
		return false;		
	}
	L0 p = NULL;
	L0 q = Plant;	
	char ch = fgetc(fp);
	if (ch == EOF)
	{ 
		cout << "��ǰPlant.txt�ļ�Ϊ��" << endl;
		cout << "����ϵͳ�����Plant.txt�ļ��Ƿ�����" << endl;
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

bool LoadFile_User(FILE* fp, L1& User)		//����User�ļ��е�����
{
	if ((fp = fopen("User.txt", "r")) == NULL)
	{
		cout << "User.txt�ļ��򿪴���" << endl;
		cout << "����ϵͳ�����Plant.txt�ļ��Ƿ�����" << endl;
		return false;
	}
	char ch = fgetc(fp);
	if (ch == EOF)
	{
		cout << "��ǰUser.txt�ļ�Ϊ��" << endl;
		cout << "����ϵͳ�����Plant.txt�ļ��Ƿ�����" << endl;
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

bool LoadFile_Visit(FILE* fp, L2& Visit)//����Visit�ļ�
{
	fp = fopen("Visit.txt", "r");
	if (fp == NULL)
	{
		cout << "VIsit.txt�ļ��򿪴���" << endl;
		cout << "����ϵͳ�����Plant.txt�ļ��Ƿ�����" << endl;
		return false;
	}
	char ch = fgetc(fp);
	if (ch == EOF)
	{
		cout << "��ǰVIsit.txt�ļ�Ϊ��" << endl;
		cout << "����ϵͳ�����VIsit.txt�ļ��Ƿ�����" << endl;
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
		cout << "Plant.txt�ļ��򿪴��������ļ��Ƿ�����";
		exit(0);
	}
	L0 p = Plant->next;
	for (; p != NULL;p=p->next)
	{
		fprintf(fp, "%d\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",p->num,p->name,p->type,p->huaqi,p->location,p->guanshang,p->maintain,p->yaoyong,p->meaning);
	}
	cout << "д���ļ��ɹ�" << endl;
	fclose(fp);
}

void Fprint_Visit(L2 Visit)
{
	FILE* fp1;
	if ((fp1 = fopen("Visit.txt", "w")) == NULL)
	{
		cout << "Visit.txt�ļ��򿪴��������ļ��Ƿ�����";
		exit(0);
	}
	L2 p = Visit->next;
	for (; p != NULL; p = p->next)
	{
		fprintf(fp1, "%d\n%s\n", p->num, p->name);
		Fprint_Plant(p->plant);
	}
	cout << "д���ļ��ɹ�" << endl;
	fclose(fp1);
}

void Fprint_User(L1 User) 
{
	FILE* fp;
	if ((fp = fopen("User.txt", "w")) == NULL)
	{
		cout << "User.txt�ļ��򿪴��������ļ��Ƿ�����";
		exit(0);
	}
	L1 p = User->next;
	for (; p != NULL; p = p->next)
	{
		fprintf(fp, "%d\n%s\n%s\n", p->state, p->name, p->key);
	}
	cout << "д���ļ��ɹ�" << endl;
	fclose(fp);
}

bool Login_admin(L1 User,LNode1& e) //����Ա��¼
{
	L1 p = User;
	if (p == NULL)
	{
		cout << "User�ļ�Ϊ�գ������Ƿ�����!" << endl;
		return false;
	}
	int flag = 1;
		char name[10], key[100];
		cout << "���������Ա�˺�" << endl;
		cin >> name;
		while(p!=NULL)
		{
			if ((strcmp(name, p->name) == 0) && p->state == 1)
			{
				cout << "����������" << endl;
				scanf("%s", &key);
				if (strcmp(key, p->key) == 0)
				{
					e = *p;
					return true;
				}
				else cout << "�˺Ż��������" << endl;
			}
			else p = p->next;
		}
		cout << "������˻�������" << endl;
		return false;
}

bool Login_user(L1 User,  LNode1& e) //�û���¼
{
	L1 p = User;
	if (p == NULL)
	{
		cout << "User�ļ�Ϊ�գ������Ƿ�����!" << endl;
		return false;
	}
	int flag = 1;
	char name[10], key[100];
	cout << "�����������˺�" << endl;
	cin >> name;
	while (p != NULL)
	{
		if ((strcmp(name, p->name) == 0) && p->state == 2)
		{
			cout << "����������" << endl;
			scanf("%s", &key);
			if (strcmp(key, p->key) == 0)
			{
				e = *p;
				return true;
			}
			else cout << "�˺Ż��������" << endl;
		}
		else p = p->next;
	}
	cout << "������˻�������" << endl;
	return false;
}

void PrintLNode0(L0 p)
{
	if (p == NULL)
	{
		cout << "ֲ����ϢΪ��" << endl;
		exit(0);
	}
	cout << " ======================================" << endl;
	cout << " |             ֲ����Ϣ����           |" << endl;
	cout << " ======================================" << endl;
	cout << " |              ���                  |" << endl;
	printf("                 %d               \n", p->num);
	cout << " ======================================" << endl;
	cout << " |              ����                  |" << endl;
	printf("                 %s               \n", p->name);
	cout << " ======================================" << endl;
	cout << " |              ����                  |" << endl;
	printf("               %s               \n", p->type);
	cout << " ======================================" << endl;
	cout << " |              ����                  |" << endl;
	printf("                 %s               \n", p->huaqi);
	cout << " ======================================" << endl;
	cout << " |            ���ֵص�                |" << endl;
	printf("              %s               \n", p->location);
	cout << " ======================================" << endl;
	cout << " |            ������                  |" << endl;
	printf("              %s               \n", p->guanshang);
	cout << " ======================================" << endl;
	cout << " |            ֲ��ά��                |" << endl;
	printf("   %s\n", p->maintain);
	cout << " ======================================" << endl;
	cout << " |            ҩ�ü�ֵ                |" << endl;
	printf(   "%s\n", p->yaoyong);
	cout << " ======================================" << endl;
	cout << " |             ��ʷ����               |" << endl;
	printf("   %s               \n", p->meaning);
	cout << " ======================================" << endl;
	printf("\n");
}

void PrintLNode2(L2 p)
{
	if (p == NULL)
	{
		cout << "����·����ϢΪ��" << endl;
		exit(0);
	}
	L0 q = p->plant;
	cout << "            ������Ϣ����       " << endl;
	cout << " ======================================" << endl;
	cout << "                ���              " << endl;
	printf("                 %d               \n", p->num);
	cout << " ======================================" << endl;
	cout << "              ·������              " << endl;
	printf("                 %s               \n", p->name);
	cout << " ======================================" << endl;
	while (q != NULL)
	{
		if (q == NULL)
		{
			cout << "ֲ����ϢΪ��" << endl;
			exit(0);
		}
		cout << "               ֲ����Ϣ����       " << endl;
		cout << " ======================================" << endl;
		cout << " |              ���                  |" << endl;
		cout << "              " << q->num << endl;
		cout << " ======================================" << endl;
		cout << " |              ����                  |" << endl;
		cout << "                 " << q->name << endl;;
		cout << " ======================================" << endl;
		cout << " |              ����                  |" << endl;
		printf("                  %s               \n", q->type);
		cout << " ======================================" << endl;
		cout << " |              ����                  |" << endl;
		printf("                  %s               \n", q->huaqi);
		cout << " ======================================" << endl;
		cout << " |            ���ֵص�                |" << endl;
		printf("                  %s               \n", q->location);
		cout << " ======================================" << endl;
		cout << " |             ������                 | " << endl;
		printf("                  %s               \n", q->guanshang);
		cout << " ======================================" << endl;
		cout << " |            ֲ��ά��                |" << endl;
		printf("              %s               \n", q->maintain);
		cout << " ======================================" << endl;
		cout << " |            ҩ�ü�ֵ                |" << endl;
		printf( "                 %s                  \n", q->yaoyong);
		cout << " ======================================" << endl;
		cout << " |            ��ʷ����                |" << endl;
		printf("                  %s               \n", q->meaning);
		cout << " ======================================" << endl;
		q = q->next;
	}
}

L0 Plant_chaxun(L0 Plant)	//��ѯֲ����Ϣ
{

	L0 tmp = NULL;
	char state = 0;
	cout << "*******************************************************************************************************************" << endl;
	cout << "|                    1 ��ֲ���Ž��в�ѯ       2 ��ֲ�����ƽ��в�ѯ    0  �˳���ѯ                               |" << endl;
	cout << "*******************************************************************************************************************" << endl;
	cin >> state;
	if (state == '0') return NULL;
	switch (state - '0')
	{
	case(1):
		int cha_num;
		cout << "������ֲ����" << endl;
		cin >> cha_num;
		tmp=Plant_chaxun_num(cha_num, Plant);
		if (tmp != NULL)
		{
			return tmp;
			break;
		}
		printf("������������!\n");
		break;
	case(2):
		char cha_name[20];
		cout << "������ֲ������" << endl;
		cin >> cha_name;
		tmp = Plant_chaxun_name(cha_name, Plant);
		if (tmp != NULL)
		{
			return tmp;
			break;
		}
		printf("������������!\n");
		break;
	default:
		printf("������������!\n");
		break;
	}
	return NULL;
}

L0 Plant_chaxun_num(int num, L0 Plant)	//ʹ�ñ�Ų�ѯֲ����Ϣ
{
	if (Plant == NULL)
	{
		cout << "��ǰֲ����ϢΪ��" << endl;
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
	cout << "�����ֲ����Ϣ������" << endl;
	return NULL;
}

L0 Plant_chaxun_name(char name[], L0 Plant)	//ʹ�����Ʋ�ѯֲ����Ϣ
{
	if (Plant == NULL)
	{
		cout << "��ǰֲ����ϢΪ��" << endl;
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
	cout << "�����ֲ����Ϣ������" << endl;
	return NULL;
}

bool Plant_delete(L0& Plant)
{
	L0 head = Plant;
	char state = 0;
	L0 tmp = NULL;
	cout << "*******************************************************************************************************************" << endl;
	cout << "|                    1 ��ֲ���Ž���ɾ��       2 ��ֲ�����ƽ���ɾ��    0  �˳�ɾ��                               |" << endl;
	cout << "*******************************************************************************************************************" << endl;
	cin >> state;
	if (state == '0') return false;
	switch (state - '0')
	{
	case(1):
		int del_num;
		cout << "������ֲ����" << endl;
		cin >> del_num;
		Plant_delete_num(del_num, Plant);
		break;
	case(2):
		char del_name[20];
		cout << "������ֲ������" << endl;
		cin >> del_name;
		Plant_delete_name(del_name, Plant);
		break;
	}
	return true;
}

void Plant_delete_num(int num, L0& Plant)	//ʹ�ñ�Ų�ѯֲ����Ϣ
{
	if (Plant == NULL)
	{
		cout << "��ǰֲ����ϢΪ��" << endl;
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

		cout << "�����ֲ����Ϣ������" << endl;
	}
}

void Plant_delete_name(char name[], L0& Plant)	//ʹ������ɾ��ѯֲ����Ϣ
{
	if (Plant == NULL)
	{
		cout << "��ǰֲ����ϢΪ��" << endl;
		return;
	}
	L0 p = Plant->next, q = Plant;
	while (p != NULL)
	{
		if (strcmp(name, p->name) == 0)
		{
			q->next = p->next; 
			delete p;
			cout << "ֲ����Ϣɾ���ɹ�" << endl;
			return;
		}
		else
		{
			q = p; 
			p = p->next; 
		}
	}
	}
	cout << "�����ֲ����Ϣ������" << endl;
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
	cout << "|                    1 ��ֲ���Ž����޸�       2 ��ֲ�����ƽ����޸�    0  �˳��޸�                               |" << endl;
	cout << "*******************************************************************************************************************" << endl;
	cin >> state;
	switch (state - '0')
	{
	case 0:
		return;
	case(1):
		int xiugai_num;
		cout << "������ֲ����" << endl;
		cin >> xiugai_num;
		Plant_xiugai_num(xiugai_num, Plant);
		break;
	case(2):
		char xiugai_name[20];
		cout << "������ֲ������" << endl;
		cin >> xiugai_name;
		Plant_xiugai_name(xiugai_name, Plant);
		break;
	default:
		printf("������������!\n");
		break;
	}
}

void Plant_xiugai_num(int num, L0& Plant)	//ʹ�ñ���޸�ֲ����Ϣ
{
	if (Plant == NULL)
	{
		cout << "��ǰֲ����ϢΪ��" << endl;
	}
	L0 p = Plant;
	while (p != NULL)
	{
		int xiugai = 0;
		if (p->num == num)
		{
			printf("              ============================================================\n");
			printf("              **                       0-�����޸�                       **\n");
			printf("              **  1-���               2-ֲ����          3-����         **\n");
			printf("              **  4-����               5-���ֵص�        6-������       **\n");
			printf("              **  7-ά����Ϣ           8-ҩ�ü�ֵ        9-��ʷ����     **\n");
			printf("              **                       10-�޸�ȫ��                       **\n");
			printf("              ============================================================\n");
			printf("��ѡ����Ҫ�޸ĵ���Ϣ���:");
			cin >> xiugai;
			switch (xiugai)
			{
			case 0:
				return;
			case 1:
				printf("�������±��:");
				scanf("%d", &p->num);
				printf("�޸ĳɹ�!\n");
				system("pause");
				break;
			case 2:
				printf("������ֲ����:");
				cin >> p->name;
				printf("�޸ĳɹ�!\n");
				break;

			case 3:
				cout << "������ֲ���������";
				cin >> p->type;
				printf("�޸ĳɹ�!\n");
				break;

			case 4:
				cout << "������ֲ��Ļ��ڣ�";
				cin >> p->huaqi;
				printf("�޸ĳɹ�!\n");
				break;

			case 5:
				cout << "������ֲ������ֵص㣺";
				cin >> p->location;
				printf("�޸ĳɹ�!\n");
				break;

			case 6:
				cout << "������ֲ��Ĺ����ԣ�";
				cin >> p->guanshang;
				printf("�޸ĳɹ�!\n");
				break;
			case 7:
				cout << "������ֲ���ά����Ϣ��";
				cin >> p->maintain;
				printf("�޸ĳɹ�!\n");
				break;
			case 8:
				cout << "������ֲ���ҩ�ü�ֵ��";
				cin >> p->yaoyong;
				printf("�޸ĳɹ�!\n");
				break;

			case 9:
				cout << "������ֲ�����ʷ�����������壺";
				cin >> p->meaning;
				printf("�޸ĳɹ�!\n");
				break;

			case 10:
				cout << "������ֲ������ƣ�";
				cin >> p->name;
				cout << "������ֲ���������";
				cin >> p->type;
				cout << "������ֲ��Ļ��ڣ�";
				cin >> p->huaqi;
				cout << "������ֲ������ֵص㣺";
				cin >> p->location;
				cout << "������ֲ��Ĺ����ԣ�";
				cin >> p->guanshang;
				cout << "������ֲ���ά����Ϣ��";
				cin >> p->maintain;
				cout << "������ֲ���ҩ�ü�ֵ��";
				cin >> p->yaoyong;
				cout << "������ֲ�����ʷ�����������壺";
				cin >> p->meaning;
				printf("�޸ĳɹ�!\n");
				break;
			}
		}
		else p = p->next;
	}
	cout << "�����ֲ����Ϣ������" << endl;
}

void Plant_xiugai_name(char name[], L0& Plant)	//ʹ�������޸�ֲ����Ϣ
{
	if (Plant == NULL)
	{
		cout << "��ǰֲ����ϢΪ��" << endl;
	}
	L0 p = Plant;
	while (p != NULL)
	{
		int xiugai = 0;
		if (strcmp(name, p->name) == 0)
		{
			printf("              ============================================================\n");
			printf("              **                       0-�����޸�                       **\n");
			printf("              **  1-���               2-ֲ����          3-����         **\n");
			printf("              **  4-����               5-���ֵص�        6-������       **\n");
			printf("              **  7-ά����Ϣ           8-ҩ�ü�ֵ        9-��ʷ����     **\n");
			printf("              **                       10-�޸�ȫ��                       **\n");
			printf("              ============================================================\n");
			printf("��ѡ����Ҫ�޸ĵ���Ϣ���:");
			cin >> xiugai;
			switch (xiugai)
			{
			case 0:
				return;
			case 1:
				printf("�������±��:");
				scanf("%d", &p->num);
				printf("�޸ĳɹ�!\n");
				system("pause");
				break;
			case 2:
				printf("������ֲ����:");
				cin >> p->name;
				printf("�޸ĳɹ�!\n");
				break;

			case 3:
				cout << "������ֲ���������";
				cin >> p->type;
				printf("�޸ĳɹ�!\n");
				break;

			case 4:
				cout << "������ֲ��Ļ��ڣ�";
				cin >> p->huaqi;
				printf("�޸ĳɹ�!\n");
				break;

			case 5:
				cout << "������ֲ������ֵص㣺";
				cin >> p->location;
				printf("�޸ĳɹ�!\n");
				break;

			case 6:
				cout << "������ֲ��Ĺ����ԣ�";
				cin >> p->guanshang;
				printf("�޸ĳɹ�!\n");
				break;
			case 7:
				cout << "������ֲ���ά����Ϣ��";
				cin >> p->maintain;
				printf("�޸ĳɹ�!\n");
				break;
			case 8:
				cout << "������ֲ���ҩ�ü�ֵ��";
				cin >> p->yaoyong;
				printf("�޸ĳɹ�!\n");
				break;

			case 9:
				cout << "������ֲ�����ʷ�����������壺";
				cin >> p->meaning;
				printf("�޸ĳɹ�!\n");
				break;

			case 10:
				cout << "������ֲ������ƣ�";
				cin >> p->name;
				cout << "������ֲ���������";
				cin >> p->type;
				cout << "������ֲ��Ļ��ڣ�";
				cin >> p->huaqi;
				cout << "������ֲ������ֵص㣺";
				cin >> p->location;
				cout << "������ֲ��Ĺ����ԣ�";
				cin >> p->guanshang;
				cout << "������ֲ���ά����Ϣ��";
				cin >> p->maintain;
				cout << "������ֲ���ҩ�ü�ֵ��";
				cin >> p->yaoyong;
				cout << "������ֲ�����ʷ�����������壺";
				cin >> p->meaning;
				printf("�޸ĳɹ�!\n");
				break;
			}
		}
		else p = p->next;
	}
	cout << "�����ֲ����Ϣ������" << endl;
}

bool Visit_delete(L2& Visit)
{
	L2 head = Visit;
	char state = 0;
	L0 tmp = NULL;
	cout << "*******************************************************************************************************************" << endl;
	cout << "|                  1 ������·�߱�Ž���ɾ��         2 ������·�����ƽ���ɾ��       0  �˳�ɾ��                    |" << endl;
	cout << "*******************************************************************************************************************" << endl;
	cin >> state;
	switch (state - '0')
	{
	case(1):
		int del_num;
		cout << "����������·�߱��" << endl;
		cin >> del_num;
		return Visit_delete_num(del_num, Visit);
		break;
	case(2):
		char del_name[20];
		cout << "����������·������" << endl;
		cin >> del_name;
		return Visit_delete_name(del_name, Visit);
		break;
	default:
		printf("������������!\n");
		return 0;
	}
}

void Visit_delete_num(int num, L2& Visit)	//ʹ�ñ�Ų�ѯ����·��
{
	if (Visit == NULL)
	{
		cout << "��ǰ����·����ϢΪ��" << endl;
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
	cout << "���������·����Ϣ������" << endl;
}

void Visit_delete_name(char name[], L2& Visit)	//ʹ�����Ʋ�ѯֲ����Ϣ
{
	if (Visit == NULL)
	{
		cout << "��ǰ����·����ϢΪ��" << endl;
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
	cout << "���������·����Ϣ������" << endl;
}

L2 Visit_chaxun(L2 Visit)
{

	L2 head = Visit;
	char state = 0;
	L2 tmp = NULL;
	cout << "*******************************************************************************************************************" << endl;
	cout << "|               1 ������·�߱�Ž��в�ѯ       2 ������·�����ƽ��в�ѯ    0  �˳���ѯ                            |" << endl;
	cout << "*******************************************************************************************************************" << endl;
	cin >> state;
	switch (state - '0')
	{
	case(1):
		int cha_num;
		cout << "����������·�߱��" << endl;
		cin >> cha_num;
		tmp=Visit_chaxun_num(cha_num, Visit);
		if (tmp != NULL)
		{
			return tmp;
			break;
		}
		printf("������������!\n");
	case(2):
		char cha_name[20];
		cout << "����������·������" << endl;
		cin >> cha_name;
		tmp=Visit_chaxun_name(cha_name, Visit);
		if (tmp != NULL)
		{
			return tmp;
			break;
		}
		printf("������������!\n");
		break;
	default:
		printf("������������!\n");
		break;
	}
	return NULL;
}

L2 Visit_chaxun_num(int num, L2 Visit)	//ʹ�ñ�Ų�ѯ����·����Ϣ
{
	if (Visit == NULL)
	{
		cout << "��ǰ����·����ϢΪ��" << endl;
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
	cout << "���������·����Ϣ������" << endl;
	return NULL;
}

L2 Visit_chaxun_name(char name[], L2 Visit)	//ʹ�����Ʋ�ѯ����·����Ϣ
{
	if (Visit == NULL)
	{
		cout << "��ǰ����·����ϢΪ��" << endl;
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
	cout << "���������·����Ϣ������" << endl;
	return NULL;
}

void Visit_xiugai(L2& Visit)
{
	L2 head = Visit;
	L0 head0 = Visit->plant;
	char state = 0;
	L0 tmp = NULL;
	cout << "*******************************************************************************************************************" << endl;
	cout << "|                 1 ������·�߱�Ž����޸�       2 ������·�����ƽ����޸�    0  �˳��޸�                          |" << endl;
	cout << "*******************************************************************************************************************" << endl;
	cin >> state;
	switch (state - '0')
	{
	case 0:
		return;
	case(1):
		int xiugai_num;
		cout << "������·�߱��" << endl;
		cin >> xiugai_num;
		Visit_xiugai_num(xiugai_num, head);
		break;
	case(2):
		char xiugai_name[20];
		cout << "������·������" << endl;
		cin >> xiugai_name;
		Visit_xiugai_name(xiugai_name, head);
		break;
	default:
		printf("������������!\n");
		break;
	}
}

void Visit_xiugai_num(int num, L2& Visit)	//ʹ�ñ���޸�ֲ����Ϣ
{
	if (Visit == NULL)
	{
		cout << "��ǰֲ����ϢΪ��" << endl;
	}
	L2 p = Visit;
	while (p != NULL)
	{
		if (Visit == NULL)
		{
			cout << "��ǰֲ����ϢΪ��" << endl;
		}
		L2 p = Visit;
		while (p != NULL)
		{
			int xiugai = 0;
			if (num == p->num)
			{
				printf("              ==================================================\n");
				printf("              **               0-�����޸�                    **\n");
				printf("              **  1-���       2-�����ص�     3-ֲ����Ϣ     **\n");
				printf("              **               4-�޸�ȫ��                    **\n");
				printf("              =================================================\n");
				printf("��ѡ����Ҫ�޸ĵ���Ϣ���:");
				cin >> xiugai;
				switch (xiugai)
				{
				case 0:
					break;
				case 1:
					printf("�������±��:");
					scanf("%d", &p->num);
					printf("�޸ĳɹ�!\n");
					system("pause");
					break;
				case 2:
					printf("�������������ص���:");
					cin >> p->name;
					printf("�޸ĳɹ�!\n");
					break;

				case 3:
					Plant_xiugai(p->plant);
				default:
					printf("������������!\n");
					break;
				}
			}
			else p = p->next;
		}
		cout << "�����ֲ����Ϣ������" << endl;
	}
}

void Visit_xiugai_name(char name[], L2& Visit)	//ʹ�������޸�ֲ����Ϣ
{
	if (Visit == NULL)
	{
		cout << "��ǰֲ����ϢΪ��" << endl;
	}
	L2 p = Visit;
	while (p != NULL)
	{
		int xiugai = 0;
		if (strcmp(name, p->name) == 0)
		{
			printf("              ============================================================\n");
			printf("              **                    0-�����޸�                          **\n");
			printf("              **  1-���            2-����·����          3-ֲ����Ϣ    **\n");
			printf("              **                    4-�޸�ȫ��                          **\n");
			printf("              ============================================================\n");
			printf("��ѡ����Ҫ�޸ĵ���Ϣ���:");
			cin >> xiugai;
			switch (xiugai)
			{
			case 0:
				break;
			case 1:
				printf("�������±��:");
				scanf("%d", &p->num);
				printf("�޸ĳɹ�!\n");
				system("pause");
				break;
			case 2:
				printf("������ֲ����:");
				cin >> p->name;
				printf("�޸ĳɹ�!\n");
				break;

			case 3:
				Plant_xiugai(p->plant);
			default:
				printf("������������!\n");
				break;
			}
		}
		else p = p->next;
	}
	cout << "�����ֲ����Ϣ������" << endl;
}

bool Plant_star(L0 p)
{
	if (p == NULL) return false;
	char ch;
	cout << "�Ƿ��ղظ�ֲ����Ϣ�� �ǣ�Y��/��N��";
	cin >> ch;
	if (ch == 'N' || ch == 'n') return false;
	FILE* fp = NULL;
	if ((fp = fopen("Star.txt", "a")) == NULL)
	{
		cout << "Star.txt�ļ��򿪴��������ļ��Ƿ�����";
		return false;
	}
	fprintf(fp, "%d\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n", p->num, p->name, p->type, p->huaqi, p->location, p->guanshang, p->yaoyong, p->meaning);
	cout << "д���ļ��ɹ�" << endl;
	fclose(fp);
	return true;
}

void Visit_star(L2 p)
{
	char ch;
	cout << "�Ƿ��ղظ�����·�ߣ� �ǣ�Y��/��N��";
	cin >> ch;
	if (ch == 'N' || ch == 'n') exit(0);
	FILE* fp1;
	if ((fp1 = fopen("Star.txt", "a")) == NULL)
	{
		cout << "Star.txt�ļ��򿪴��������ļ��Ƿ�����";
		exit(0);
	}
		fprintf(fp1, "%d\n%s\n", p->num, p->name);
		Fprint_Plant(p->plant);
	cout << "д���ļ��ɹ�" << endl;
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
	cout << "�Ƿ��������ˣ�  ��(Y) ��(N)"<<endl;
	cin >> a;
	if (a == 'y' || a == 'Y')
	{
		cout << "��ɨ���¼" << endl;
		system("pause");
		cout << "��¼�ɹ�" << endl;
		cout << "���뽫Ҫ�����ƽ̨ ΢������Ȧ/QQ�ռ�/����/΢��/С����" << endl;
		getchar();
		cout << "����ɹ�" << endl;
	}
}

void LogInMenu()	//��¼����
{
	cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "|                                           ��ӭʹ�û���ũҵ��ѧֲ�����ϵͳ                                      |" << endl;
	cout << "----------------------------------------------------***********----------------------------------------------------" << endl;
	cout << "|                                                1 �Թ���Ա��ݵ�¼                                               |" << endl;
	cout << "*******************************************************************************************************************" << endl;
	cout << "|                                                2 ���û���ݵ�¼                                                 |" << endl;
	cout << "*******************************************************************************************************************" << endl;
	cout << "|                                                3   ���û�ע��                                                   |" << endl;
	cout << "*******************************************************************************************************************" << endl;
	cout << "|                                                4      ����                                                      |" << endl;
	cout << "*******************************************************************************************************************" << endl;
	cout << "|                                                0      �˳�                                                      |" << endl;
	cout << "----------------------------------------------------***********----------------------------------------------------" << endl;
}

void tuichujiemian()//�˳�����
{
	cout << "----------------------------------------------------***********------------------------------------------------------" << endl;
	cout << "                                                    ��л����ʹ��                                                    |" << endl;
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
	cout << "|                                           ��ӭʹ�û���ũҵ��ѧֲ�����ϵͳ                                      |" << endl;
	cout << "|                                                                                                                 |" << endl;
	printf("                                                    %s���                                                     ", e.name);
	cout << "|                                                                                                                 |" << endl;
	cout << "----------------------------------------------------***********----------------------------------------------------" << endl;
	cout << "|                                                  0 �˳���¼                                                     |" << endl;
	cout << "*******************************************************************************************************************" << endl;
	cout << "|                                  1   ��ѯֲ����Ϣ            2   ��ѯ�ͻ�·��                                   |" << endl;
	cout << "*******************************************************************************************************************" << endl;
	cout << "|                                  3   ���ֲ����Ϣ            4   ����ͻ�·��                                   |" << endl;
	cout << "*******************************************************************************************************************" << endl;
	cout << "|                                  5   ɾ��ֲ����Ϣ            6   ɾ���ͻ�·��                                   |" << endl;
	cout << "*******************************************************************************************************************" << endl;
	cout << "|                                  7   �޸�ֲ����Ϣ            8   �޸��ͻ�·��                                   |" << endl;
	cout << "*******************************************************************************************************************" << endl;
	cout << "|                                  9   ���ֲ����Ϣ            10  ����ͻ�·��                                   |" << endl;
	cout << "*******************************************************************************************************************" << endl;
}

void user_caozuojiemian(LNode1 e)
{
	cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "|                                           ��ӭʹ�û���ũҵ��ѧֲ�����ϵͳ                                      |" << endl;
	cout << "|                                                                                                                 |" << endl;
	printf("                                                    %s���                                                     ", e.name);
	cout << "|                                                                                                                 |" << endl;
	cout << "----------------------------------------------------***********----------------------------------------------------" << endl;
	cout << "|                                                  0 �˳���¼                                                     |" << endl;
	cout << "*******************************************************************************************************************" << endl;
	cout << "|                                  1   ��ѯֲ����Ϣ            2   ��ѯ�ͻ�·��                                   |" << endl;
	cout << "*******************************************************************************************************************" << endl;
	cout << "|                                  3   ���ֲ����Ϣ            4   ����ͻ�·��                                   |" << endl;
	cout << "*******************************************************************************************************************" << endl;
}