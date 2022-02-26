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
	//コマンド
	char command[256];

	//数値変数
	char sutihen[256];
	char  sutiatai[256];

	//文字変数
	char mojihen[256];
	char mojiatai[256];

	_info* next;
}INFO;

//コマンド
INFO* cp = (INFO*)malloc(sizeof(INFO));
INFO* cfirst = cp;

//数値変数入力
INFO* sp = NULL;
INFO* sfirst = NULL;

//文字変数入力
INFO* mp = NULL;
INFO* mfirst = NULL;

//出力
INFO* lp = (INFO*)malloc(sizeof(INFO));
char kari[256];
char atai[256];
int flg = 0;

//計算
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

//もし
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

//ループ
int kaisu;
int loop;
int g1 = 0, g2 = 0;
int lflg = 0;

//選ぶ
int owari = 0;

//しっかりしろ
int sikkari = 0;
int scnt = 0;


int main()
{
	printf("[]　←　固定値\n\n");
	printf("・[数] 変数名 数字\n");
	printf("・[文] 変数名 文字\n");
	printf("・[出力] [値] 値\n");
	printf("・[出力] 変数名\n");
	printf("・[計算] 計算式(例：12 + 1 - num1 + num4 ;)\n");
	printf("・[もし] 変数名or値 比較演算子 変数名or値\n");
	printf("・[ループ]\n");
	printf("・[終わり]\n\n");



	while (true)
	{
		scanf("%s", cp->command);

		if (strcmp(cp->command, "数") == 0)
		{
			suti();
			printf("\n----続き----\n\n");
		}
		else if (strcmp(cp->command, "文") == 0)
		{
			moji();
			printf("\n----続き----\n\n");
		}
		else if (strcmp(cp->command, "出力") == 0)
		{
			syutu();
			printf("\n\n----続き----\n\n");
		}
		else if (strcmp(cp->command, "計算") == 0)
		{
			keisan();
			printf("\n\n----続き----\n\n");
		}
		else if (strcmp(cp->command, "もし") == 0)
		{
			mosi();
			printf("\n\n----続き----\n\n");
		}
		else if (strcmp(cp->command, "ループ") == 0)
		{
			lflg = 1;
			printf("ループ回数 １ループでの処理の数\n\n");
			scanf("%d %d", &kaisu, &loop);

			for (g1 = 1; g1 <= kaisu; g1++)
			{
				printf("ループ%d周目", g1);

				for (g2 = 1; g2 <= loop; g2++)
				{
					printf("%d/%d　処理\n\n", g2, loop);
					choice();
				}
			}

			printf("ループ終了\n");
			printf("\n\n----続き----\n\n");

		}
		else if (strcmp(cp->command, "終わり") == 0)
		{
			break;
		}
		else
		{
			if (sikkari == 0)
			{
				sikkari = 1;
				printf("しっかり入力しろ\n\n");
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

	if (strcmp(kari, "値") == 0)
	{
		scanf("%s", atai);
		printf("\n----画面出力----\n\n");
		printf("%s", atai);
	}
	else
	{
		printf("\n----画面出力----\n\n");
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
	printf("計算結果 --> %d", ssahen);
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
					printf("==であった。\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf("==でなかった。\n");
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
					printf("==であった。\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf("==でなかった。\n");
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
					printf("==であった。\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf("==でなかった。\n");
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
					printf("==であった。\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf("==でなかった。\n");
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
					printf("!=であった。\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf("!=でなかった。\n");
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
					printf("!=であった。\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf("!=でなかった。\n");
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
					printf("!=であった。\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf("!=でなかった。\n");
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
					printf("!=であった。\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf("!=でなかった。\n");
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
					printf("<であった。\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf("<でなかった。\n");
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
					printf("<であった。\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf("<でなかった。\n");
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
					printf("<であった。\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf("<でなかった。\n");
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
					printf("<であった。\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf("<でなかった。\n");
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
					printf(">であった。\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf(">でなかった。\n");
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
					printf(">であった。\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf(">でなかった。\n");
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
					printf(">であった。\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf(">でなかった。\n");
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
					printf(">であった。\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf(">でなかった。\n");
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
					printf(">=であった。");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf(">=でなかった。\n");
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
					printf(">=であった。\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf(">=でなかった。\n");
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
					printf(">=であった。\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf(">=でなかった。\n");
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
					printf(">=であった。\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf(">=でなかった。\n");
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
					printf("<=であった。\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf("<=でなかった。\n");
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
					printf("<=であった。\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf("<=でなかった。\n");
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
					printf("<=であった。\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf("<=でなかった。\n");
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
					printf("<=であった。\n");
					while (owari != 1)
					{
						choice();
					}
					owari = 0;
				}
				else
				{
					printf("<=でなかった。\n");
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

	printf("行いたい処理の数字を入力\n\n");
	printf("1 数値変数作成\n");
	printf("2 文字変数作成\n");
	printf("3 出力\n");
	printf("4 計算\n");
	printf("5 もし\n");
	printf("6 終わり(if文が終わる)\n\n");

	scanf("%d", &syori2);

	switch (syori2)
	{
	case 1:
		printf("変数名 数字　↓入力\n");
		suti();
		printf("\n");
		break;
	case 2:
		printf("変数名 文字　↓入力\n");
		moji();
		printf("\n");
		break;
	case 3:
		printf("[値] 値\n");
		printf("or\n");
		printf("変数名　↓入力\n");
		syutu();
		printf("\n");
		break;
	case 4:
		printf("計算式(半角スペースなし)　↓入力\n");
		keisan();
		printf("\n");
		break;
	case 5:
		printf("変数名or値 比較演算子 変数名or値　↓入力\n");
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