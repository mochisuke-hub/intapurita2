#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h> 

void suti();
void moji();
void syutu();
void keisan();
void mosi();
void choice();


typedef struct _info
{
	//�R�}���h
	char command[256];

	//���l�ϐ�
	char sutihen[256];
	char  sutiatai[256];

	//�����ϐ�
	char mojihen[256];
	char mojiatai[256];

	_info* next;
}INFO;

//�R�}���h
INFO* cp = (INFO*)malloc(sizeof(INFO));
INFO* cfirst = cp;

//���l�ϐ�����
INFO* sp = NULL;
INFO* sfirst = NULL;

//�����ϐ�����
INFO* mp = NULL;
INFO* mfirst = NULL;

//�o��
INFO* lp = (INFO*)malloc(sizeof(INFO));
char kari[256];
char atai[256];
int flg = 0;

//�v�Z
INFO* kp = (INFO*)malloc(sizeof(INFO));
INFO* kfirst = kp;
char sujiretu[256];
int ssahen, uuhen;
char kkari;
char enzan;
int seisu;
int i = 0, k = 0;
int ans[256];
int atta = 0;
int saflg = 0;

//����
INFO* shp = (INFO*)malloc(sizeof(INFO));
INFO* uhp = (INFO*)malloc(sizeof(INFO));
char sahen[256];
char hikaku[256];
char uhen[256];
int sflg = 0;
int uflg = 0;
int snum = 0;
int unum = 0;
int skari = 0;
int ukari = 0;
int syori = 0;

//���[�v
int kaisu;
int loop;
int g1 = 0, g2 = 0;
int lflg = 0;

//�I��
int owari = 0;

//�������肵��
int sikkari = 0;
int scnt = 0;


int main()
{
	printf("[]�@���@�Œ�l\n\n");
	printf("�E[��] �ϐ��� ����\n");
	printf("�E[��] �ϐ��� ����\n");
	printf("�E[�o��] [�l] �l\n");
	printf("�E[�o��] �ϐ���\n");
	printf("�E[�v�Z] �v�Z��(��F12 + 1 - num1 + num4 ;)\n");
	printf("�E[����] �ϐ���or�l ��r���Z�q �ϐ���or�l\n");
	printf("�E[���[�v]\n");
	printf("�E[�I���]\n\n");



	while (true)
	{
		scanf("%s", cp->command);

		if (strcmp(cp->command, "��") == 0)
		{
			suti();
			printf("\n----����----\n\n");
		}
		else if (strcmp(cp->command, "��") == 0)
		{
			moji();
			printf("\n----����----\n\n");
		}
		else if (strcmp(cp->command, "�o��") == 0)
		{
			syutu();
			printf("\n\n----����----\n\n");
		}
		else if (strcmp(cp->command, "�v�Z") == 0)
		{
			keisan();
			printf("\n\n----����----\n\n");
		}
		else if (strcmp(cp->command, "����") == 0)
		{
			mosi();
			printf("\n\n----����----\n\n");
		}
		else if (strcmp(cp->command, "���[�v") == 0)
		{
			lflg = 1;
			printf("���[�v�� �P���[�v�ł̏����̐�\n\n");
			scanf("%d %d", &kaisu, &loop);

			for (g1 = 1; g1 <= kaisu; g1++)
			{
				printf("���[�v%d����", g1);

				for (g2 = 1; g2 <= loop; g2++)
				{
					printf("%d/%d�@����\n\n", g2, loop);
					choice();
				}
			}

			printf("���[�v�I��\n");
			printf("\n\n----����----\n\n");

		}
		else if (strcmp(cp->command, "�I���") == 0)
		{
			break;
		}
		else
		{
			if (sikkari == 0)
			{
				sikkari = 1;
				printf("����������͂���\n\n");
			}
			scnt += 1;
			if (scnt == 3)
			{
				sikkari = 0;
				scnt = 0;
			}
		}
	}
}

void suti()
{
	if (sfirst != NULL)
	{
		sp->next = (INFO*)malloc(sizeof(INFO));
		sp = sp->next;
		scanf(" %s", sp->sutihen);
		scanf(" %s", sp->sutiatai);
		sp->next = NULL;
	}
	else
	{
		sp = (INFO*)malloc(sizeof(INFO));
		sfirst = sp;
		scanf(" %s", sp->sutihen);
		scanf(" %s", sp->sutiatai);
		sp->next = NULL;
	}
}

void moji()
{
	if (mfirst != NULL)
	{
		mp->next = (INFO*)malloc(sizeof(INFO));
		mp = mp->next;
		scanf(" %s", mp->mojihen);
		scanf(" %s", mp->mojiatai);
		mp->next = NULL;
	}
	else
	{
		mp = (INFO*)malloc(sizeof(INFO));
		mfirst = mp;
		scanf(" %s", mp->mojihen);
		scanf(" %s", mp->mojiatai);
		mp->next = NULL;
	}
}

void syutu()
{
	scanf(" %s", kari);

	if (strcmp(kari, "�l") == 0)
	{
		scanf("%s", atai);
		printf("\n----��ʏo��----\n\n");
		printf("%s", atai);
	}
	else
	{
		printf("\n----��ʏo��----\n\n");
		lp = sfirst;
		while (lp != NULL)
		{
			if (strcmp(lp->sutihen, kari) == 0)
			{
				printf("%s", lp->sutiatai);
				flg = 1;
				break;
			}
			lp = lp->next;
		}

		if (flg != 1)
		{
			lp = mfirst;
			while (lp != NULL)
			{
				if (strcmp(lp->mojihen, kari) == 0)
				{
					printf("%s", lp->mojiatai);
					flg = 1;
					break;
				}
				lp = lp->next;
			}
		}

		if (flg != 1)
		{
			scanf("%s", atai);
			printf("%s", atai);
		}
		flg = 0;
	}
}

void keisan()
{
	while (true)
	{
		scanf("%s", sujiretu);

		if (saflg == 0)
		{
			lp = sfirst;
			while (lp != NULL)
			{
				if (strcmp(lp->sutihen, sujiretu) == 0)
				{
					atta = 1;
					break;
				}
				lp = lp->next;
			}
		}
		if (atta == 0)
		{
			if (sujiretu[0] >= '0' && sujiretu[0] <= '9' && saflg == 0)
			{
				ssahen = atoi(sujiretu);
				saflg = 1;
			}
			else if (sujiretu[0] == '+' || sujiretu[0] == '-' || sujiretu[0] == '*' || sujiretu[0] == '/')
			{
				enzan = sujiretu[0];

				scanf(" %s", sujiretu);

				lp = sfirst;
				while (lp != NULL)
				{
					if (strcmp(lp->sutihen, sujiretu) == 0)
					{
						atta = 1;
						break;
					}
					lp = lp->next;
				}

				if (atta == 0)
				{
					uuhen = atoi(sujiretu);
				}
				else
				{
					uuhen = atoi(lp->sutiatai);
					atta = 0;
				}


				if (enzan == '+')
				{
					ssahen = ssahen + uuhen;
				}
				else if (enzan == '-')
				{
					ssahen = ssahen - uuhen;
				}
				else if (enzan == '*')
				{
					ssahen = ssahen * uuhen;
				}
				else if (enzan == '/')
				{
					ssahen = ssahen / uuhen;
				}
				saflg = 0;
			}
			else if (sujiretu[i] == ';')
			{
				break;
			}
		}
		else
		{
			if (saflg == 0)
			{
				ssahen = atoi(lp->sutiatai);
			}
			else
			{
				if (sujiretu[0] == '+' || sujiretu[0] == '-' || sujiretu[0] == '*' || sujiretu[0] == '/')
				{
					enzan = sujiretu[0];

					scanf(" %s", sujiretu);
					uuhen = atoi(lp->sutiatai);


					if (enzan == '+')
					{
						ssahen = ssahen + uuhen;
					}
					else if (enzan == '-')
					{
						ssahen = ssahen - uuhen;
					}
					else if (enzan == '*')
					{
						ssahen = ssahen * uuhen;
					}
					else if (enzan == '/')
					{
						ssahen = ssahen / uuhen;
					}
					saflg = 0;
				}
			}
			atta = 0;
		}
	}
	printf("�v�Z���� --> %d", ssahen);
}

void mosi()
{
	scanf(" %s", sahen);
	scanf(" %s", hikaku);
	scanf(" %s", uhen);

	shp = sfirst;
	while (shp != NULL)
	{
		if (strcmp(shp->sutihen, sahen) == 0)
		{
			sflg = 1;
			skari = atoi(shp->sutiatai);
			break;
		}
		shp = shp->next;
	}
	if (sflg == 0)
	{
		snum = atoi(sahen);
	}

	uhp = sfirst;
	while (uhp != NULL)
	{
		if (strcmp(uhp->sutihen, uhen) == 0)
		{
			uflg = 1;
			ukari = atoi(uhp->sutiatai);
			break;
		}
		uhp = uhp->next;
	}
	if (uflg == 0)
	{
		unum = atoi(uhen);
	}



	if (strcmp(hikaku, "==") == 0)
	{
		if (sflg == 0)
		{
			if (uflg == 1)
			{
				if (snum == ukari)
				{
					printf("==�ł������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf("==�łȂ������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
			}
			else
			{
				if (snum == unum)
				{
					printf("==�ł������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf("==�łȂ������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
			}
		}
		else
		{
			if (uflg == 1)
			{
				if (skari == ukari)
				{
					printf("==�ł������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf("==�łȂ������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
			}
			else
			{
				if (skari == unum)
				{
					printf("==�ł������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf("==�łȂ������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
			}
		}
	}
	else if (strcmp(hikaku, "!=") == 0)
	{
		if (sflg == 0)
		{
			if (uflg == 1)
			{
				if (snum != ukari)
				{
					printf("!=�ł������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf("!=�łȂ������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
			}
			else
			{
				if (snum != unum)
				{
					printf("!=�ł������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf("!=�łȂ������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
			}
		}
		else
		{
			if (uflg == 1)
			{
				if (skari != ukari)
				{
					printf("!=�ł������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf("!=�łȂ������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
			}
			else
			{
				if (skari != unum)
				{
					printf("!=�ł������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf("!=�łȂ������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
			}
		}

	}
	else if (strcmp(hikaku, "<") == 0)
	{
		if (sflg == 0)
		{
			if (uflg == 1)
			{
				if (snum < ukari)
				{
					printf("<�ł������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf("<�łȂ������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
			}
			else
			{
				if (snum < unum)
				{
					printf("<�ł������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf("<�łȂ������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
			}
		}
		else
		{
			if (uflg < 1)
			{
				if (skari < ukari)
				{
					printf("<�ł������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf("<�łȂ������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
			}
			else
			{
				if (skari < unum)
				{
					printf("<�ł������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf("<�łȂ������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
			}
		}

	}
	else if (strcmp(hikaku, ">") == 0)
	{
		if (sflg == 0)
		{
			if (uflg == 1)
			{
				if (snum > ukari)
				{
					printf(">�ł������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf(">�łȂ������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
			}
			else
			{
				if (snum > unum)
				{
					printf(">�ł������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf(">�łȂ������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
			}
		}
		else
		{
			if (uflg == 1)
			{
				if (skari > ukari)
				{
					printf(">�ł������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf(">�łȂ������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
			}
			else
			{
				if (skari > unum)
				{
					printf(">�ł������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf(">�łȂ������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
			}
		}

	}
	else if (strcmp(hikaku, ">=") == 0)
	{
		if (sflg == 0)
		{
			if (uflg == 1)
			{
				if (snum >= ukari)
				{
					printf(">=�ł������B");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf(">=�łȂ������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
			}
			else
			{
				if (snum >= unum)
				{
					printf(">=�ł������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf(">=�łȂ������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
			}
		}
		else
		{
			if (uflg == 1)
			{
				if (skari >= ukari)
				{
					printf(">=�ł������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf(">=�łȂ������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
			}
			else
			{
				if (skari >= unum)
				{
					printf(">=�ł������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf(">=�łȂ������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
			}
		}

	}
	else if (strcmp(hikaku, "<=") == 0)
	{
		if (sflg == 0)
		{
			if (uflg == 1)
			{
				if (snum <= ukari)
				{
					printf("<=�ł������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf("<=�łȂ������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
			}
			else
			{
				if (snum <= unum)
				{
					printf("<=�ł������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf("<=�łȂ������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
			}
		}
		else
		{
			if (uflg == 1)
			{
				if (skari <= ukari)
				{
					printf("<=�ł������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf("<=�łȂ������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
			}
			else
			{
				if (skari <= unum)
				{
					printf("<=�ł������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf("<=�łȂ������B\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
			}
		}

	}

	sflg = 0;
	uflg = 0;
}

void choice()
{
	int syori2 = 0;

	printf("�s�����������̐��������\n\n");
	printf("1 ���l�ϐ��쐬\n");
	printf("2 �����ϐ��쐬\n");
	printf("3 �o��\n");
	printf("4 �v�Z\n");
	printf("5 ����\n");
	printf("6 �I���(if�����I���)\n\n");

	scanf("%d", &syori2);

	switch (syori2)
	{
	case 1:
		printf("�ϐ��� �����@������\n");
		suti();
		printf("\n");
		break;
	case 2:
		printf("�ϐ��� �����@������\n");
		moji();
		printf("\n");
		break;
	case 3:
		printf("[�l] �l\n");
		printf("or\n");
		printf("�ϐ����@������\n");
		syutu();
		printf("\n");
		break;
	case 4:
		printf("�v�Z��(���p�X�y�[�X�Ȃ�)�@������\n");
		keisan();
		printf("\n");
		break;
	case 5:
		printf("�ϐ���or�l ��r���Z�q �ϐ���or�l�@������\n");
		mosi();
		printf("\n");
		break;
	case 6:
		owari = 1;
		break;
	default:
		break;
	}
}