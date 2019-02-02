/* NIM/Nama  : 13517050/Christopher Billy Setiawan, 13517116/Ferdy Santoso, 13517137/Vincent Budianto
 * Nama file : calculator.c
 * Topik     : Tugas Besar II IF2220-Teori Bahasa Formal dan Otomata / Aplikasi CFG dan PDA pada Pengenalan Ekspresi Matematika
 * Tanggal   : 21 November 2018
 * Deskripsi : Program yang dapat menerima input suatu string persoalan matematika dasar dan mengeluarkan hasil solusi dari persoalan tersebut */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boolean.h"

/* Context Free Grammar
 * calculate:
 *   S -> T | S+T | S-T
 * kali bagi pangkat:
 *   T -> F | T*F | T/F | T^F
 * tanda:
 *   F -> (S) | -A | A | A.A | -A.A
 * angka:
 *   A -> 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | AA
*/

//Kamus Global
char *c;				//variabel untuk string
boolean cekSyntax;		//variabel pengecekan syntax
boolean cekMath;		//variabel pengecekan hasil
int count;				//variabel pengecekan kurung buka dan kurung tutup

//Spesifikasi Fungsi dan Prosedur
double GetAngka();
/* mengembalikan nilai yang dibaca dari string */
double CPangkat();
/* mengembalikan nilai yang sudah dipangkat */
double CKaliBagi();
/* mengembalikan nilai yang sudah dikali atau dibagi */
double CTambahKurang();
/* mengembalikan nilai yang sudah ditambah atau dikurang */

int main(int argc, char *argv[])
{
	//Kamus
	char input[100];
	double result;
	int i, j;
	
	char c1[200] = "   .oooooo.             oooo                        oooo                .                         oooooooooooo oooooo     oooo oooooooooo.";
	char c2[200] = "  d8P'  `Y8b            `888                        `888              .o8                         `888'     `8  `888.     .8'  `888'   `Y8b";
	char c3[200] = " 888           .oooo.    888   .ooooo.  oooo  oooo   888   .oooo.   .o888oo  .ooooo.  oooo d8b     888           `888.   .8'    888     888";
	char c4[200] = " 888          `P  )88b   888  d88' `'Y8 `888  `888   888  `P  )88b    888   d88' `88b `888\"\"8P     888oooo8       `888. .8'     888oooo888'";
	char c5[200] = " 888           .oP'888   888  888        888   888   888   .oP`888    888   888   888  888         888    '        `888.8'      888    `88b";
	char c6[200] = " `88b    ooo  d8(  888   888  888   .o8  888   888   888  d8(  888    888 . 888   888  888         888              `888'       888    .88P";
	char c7[200] = "  `Y8bood8P'  `Y888\"\"8o o888o `Y8bod8P'  `V88V'V8P' o888o `Y888\"\"8o   '888' `Y8bod8P' d888b       o888o              `8'       o888bood8P'";
	char *v1 = "-v";
	char *v2 = "--version";
	char *h = "-h";
	
	//Algoritma
	if(argc >= 2)
	{
		if(strcmp(argv[1],h) == 0)
		{
			system("cls");
			printf("%s\n", c1);
			printf("%s\n", c2);
			printf("%s\n", c3);
			printf("%s\n", c4);
			printf("%s\n", c5);
			printf("%s\n", c6);
			printf("%s\n\n", c7);
			printf(" Thank you for using our Calculator FVB !\n");
			printf(" to use this program :\n");
			printf(" 1. Run calculator.exe\n");
			printf(" 2. input your Problem Equation\n");
			printf(" 3. get your Result!\n");
			printf(" 4. if (your equation is not valid) {the result will be \"SYNTAX ERROR\"}\n");
			printf(" 5. else if (your equation can't be fathom by our program) {the result will be \"MATH ERROR\"}\n");
			printf(" 6. Type 'exit' to close the program\n\n");
			printf(" Arguments :\n");
			printf(" -h \t\t\t\t Show help\n");
			printf(" --version -v \t\t\t Show the version of program\n\n");
			printf(" CREDIT BY :\n");
			printf(" 1. Christopher Billy Setiawan / 13517050\n");
			printf(" 2. Ferdy Santoso / 13517116\n");
			printf(" 3. Vincent Budianto / 13517137\n");
		}
		else if(strcmp(argv[1],v1) == 0 || strcmp(argv[1],v2) == 0)
		{
			system("cls");
			printf("%s\n", c1);
			printf("%s\n", c2);
			printf("%s\n", c3);
			printf("%s\n", c4);
			printf("%s\n", c5);
			printf("%s\n", c6);
			printf("%s\n\n", c7);
			printf("                                                     Calculator 2.0 (2018 Nov 19 22:35)                                                     \n");
			printf("                                    Made By Christopher Billy Setiawan, Ferdy Santoso, Vincent Budianto                                \n");
			printf("                                        Informatics Engineering Institute Technology of Bandung 2018                                \n");
		}
		return 0;
	}
	else
	{
		system("cls");
		for(i = 0; i < 8; i++)
		{
			printf(" _____________________________________________________________________________________________________________________________________________ \n");
			switch (i)
			{
				case 1 :
				{
					printf("|%s  |\n",c1);
					break;
				}
				case 2 :
				{
					printf("|%s  |\n",c1);
					printf("|%s |\n",c2);
					break;
				}
				case 3 :
				{
					printf("|%s  |\n",c1);
					printf("|%s |\n",c2);
					printf("|%s |\n",c3);
					break;
				}
				case 4 :
				{
					printf("|%s  |\n",c1);
					printf("|%s |\n",c2);
					printf("|%s |\n",c3);
					printf("|%s |\n",c4);
					break;
				}
				case 5 :
				{
					printf("|%s  |\n",c1);
					printf("|%s |\n",c2);
					printf("|%s |\n",c3);
					printf("|%s |\n",c4);
					printf("|%s |\n",c5);
					break;
				}
				case 6 :
				{
					printf("|%s  |\n",c1);
					printf("|%s |\n",c2);
					printf("|%s |\n",c3);
					printf("|%s |\n",c4);
					printf("|%s |\n",c5);
					printf("|%s |\n",c6);
					break;
				}
				case 7 :
				{
					printf("|%s  |\n",c1);
					printf("|%s |\n",c2);
					printf("|%s |\n",c3);
					printf("|%s |\n",c4);
					printf("|%s |\n",c5);
					printf("|%s |\n",c6);
					printf("|%s  |\n",c7);
					break;
				}
			}
			for(j = (7 - i); j > 0; j--)
			{
				printf("|                                                                                                                                            |\n");
			}
			printf("|____________________________________________________________________________________________________________________________________________|\n");
			if(i != 7)
			{
				sleep(1);
				system("cls");
			}
			else
			{
				sleep(2);
			}
		}
		system("cls");
		do
		{
			system("cls");
			printf(" _____________________________________________________________________________________________________________________________________________ \n");
			printf("|%s  |\n",c1);
			printf("|%s |\n",c2);
			printf("|%s |\n",c3);
			printf("|%s |\n",c4);
			printf("|%s |\n",c5);
			printf("|%s |\n",c6);
			printf("|%s  |\n",c7);
			printf("|____________________________________________________________________________________________________________________________________________|\n");
			cekSyntax = false;
			cekMath = false;
			count = 0;
			printf(" Masukan Input :\n >> ");
			scanf("%s", input);
			if (strcmp(input, "exit") == 0)
			{
				system("cls");
				printf(" ______________________________________________________________________ \n");
				printf("|                                                                      |\n");
				printf("|                                CREDIT                                |\n");
				printf("|                                                                      |\n");
				printf("|                 13517050 - Christopher Billy Setiawan                |\n");
				printf("|                       13517116 - Ferdy Santoso                       |\n");	
				printf("|                     13517137 - Vincent Budianto                      |\n");
				printf("|______________________________________________________________________|\n");
				sleep(2);
				exit(0);
			}
			else
			{
				c = input;
				result = CTambahKurang();
				if (*c == ')')
				{
					count--;
				}
				else if (*c == '(')
				{
					count++;
				}
				if ((cekSyntax) || (count != 0))
				{
					printf(" SYNTAX ERROR\n");
				}
				else if (cekMath)
				{
					printf(" MATH ERROR\n");
				}
				else
				{
					printf(" Result : %.2f\n",result);
				}
			}
		}
		while (getch());
	}
}

//Realisasi Fungsi dan Prosedur
double GetAngka()
/* mengembalikan nilai yang dibaca dari string */
{
	//Kamus
	double floating;
	double number;
	double weight;
	int i, j, loop;

	//Algoritma
	number = 0;
	if ((*c >= '0') && (*c <= '9'))
	{
		while ((*c >= '0') && (*c <= '9'))
		{
			number = (number * 10) + (*c - '0');
			c++;
		}
	}
	else if (*c == '-')
	{
		++c;
		if ((*c == '.') || (*c == '+') || (*c == '-') || (*c == '*') || (*c == '/') || (*c == '^') || (*c == ')') || (*c == '\0'))
		{
			cekSyntax = true;
		}
		else
		{
			while ((*c >= '0') && (*c <= '9'))
			{
				number = (number * 10) + (*c - '0');
				c++;
			}
			number *= -1;
		}
	}
	else if (*c == '(')
	{
		count++;
		c++;
		if ((*c == '.') || (*c == '+') || (*c == '*') || (*c == '/') || (*c == '^') || (*c == ')') || (*c == '\0'))
		{
			cekSyntax = true;
		}
		else
		{
			number = CTambahKurang();
			if (*c == ')')
			{
				count--;
				c++;
				if ((*c == '.') || ((*c >= '0') && (*c <= '9')))
				{
					cekSyntax = true;
				}
			}
		}
	}
	if (*c == '.')
	{
		cekSyntax = false;
		++c;
		if ((*c == '.') || (*c == '+') || (*c == '-') || (*c == '*') || (*c == '/') || (*c == '^') || (*c == '(') || (*c == ')') || (*c == '\0'))
		{
			cekSyntax = true;
		}
		else
		{
			loop = 0;
			weight = 1;
			while ((*c >= '0') && (*c <= '9'))
			{
				weight /= 10;
				floating = (*c - '0') * weight;
				if (number > 0)
				{
					number += floating;
				}
				else if (number < 0)
				{
					number -= floating;
				}
				else if (number == 0)
				{
					c--;
					c--;
					for (i = 0; i <= loop; i++)
					{
						c--;
					}
					if (*c == '-')
					{
						number -= floating;
					}
					else
					{
						number += floating;
					}
					c++;
					c++;
					for (j = 0; j <= loop; j++)
					{
						c++;
					}
				}
				loop++;
				c++;
			}
		}
	}
	return (number);
}
double CPangkat()
/* mengembalikan nilai yang sudah dipangkat */
{
	//Kamus
	double exp1;
	double exp2;

	//Algoritma
	exp1 = GetAngka();
	while (*c == '^')
	{
		++c;
		if ((*c == '.') || (*c == '+') || (*c == '-') || (*c == '*') || (*c == '/') || (*c == '^') || (*c == ')') || (*c == '\0'))
		{
			cekSyntax = true;
		}
		else
		{
			exp2 = CPangkat();
			if ((exp1 < 0) && ((exp2 > 0) && (exp2 < 1)))
			{
				cekMath = true;
			}
			else
			{
				exp1 = pow(exp1, exp2);
			}
		}
	}
	return (exp1);
}
double CKaliBagi()
/* mengembalikan nilai yang sudah dikali atau dibagi */
{
	//Kamus
	double pro1;
	double pro2;

	//Algoritma
	pro1 = CPangkat();
	while ((*c == '*') || (*c == '/'))
	{
		if (*c == '*')
		{
			++c;
			if ((*c == '.') || (*c == '+') || (*c == '-') || (*c == '*') || (*c == '/') || (*c == '^') || (*c == ')') || (*c == '\0'))
			{
				cekSyntax = true;
			}
			else
			{
				pro2 = CPangkat();
				pro1 *= pro2;
			}
		}
		if (*c == '/')
		{
			++c;
			if ((*c == '.') || (*c == '+') || (*c == '-') || (*c == '*') || (*c == '/') || (*c == '^') || (*c == ')') || (*c == '\0'))
			{
				cekSyntax = true;
			}
			else if (*c == '0')
			{
				cekMath = true;
			}
			else
			{
				pro2 = CPangkat();
				if (pro2 == 0)
				{
					cekMath = true;
				}
				else
				{
					pro1 /= pro2;
				}
			}
		}
	}
	return (pro1);
}
double CTambahKurang()
/* mengembalikan nilai yang sudah ditambah atau dikurang */
{
	//Kamus
	double sum1;
	double sum2;

	//Algoritma
	sum1 = CKaliBagi();
	while ((*c == '+') || (*c == '-'))
	{
		if (*c == '+')
		{
			++c;
			if ((*c == '.') || (*c == '+') || (*c == '-') || (*c == '*') || (*c == '/') || (*c == '^') || (*c == ')') || (*c == '\0'))
			{
				cekSyntax = true;
			}
			else
			{
				sum2 = CKaliBagi();
				sum1 += sum2;
			}
		}
		if (*c == '-')
		{
			++c;
			if ((*c == '.') || (*c == '+') || (*c == '-') || (*c == '*') || (*c == '/') || (*c == '^') || (*c == ')') || (*c == '\0'))
			{
				cekSyntax = true;
			}
			else
			{
				sum2 = CKaliBagi();
				sum1 -= sum2;
			}
		}
	}
	return (sum1);
}
