// �����������, ������� ��������� ��� ������. ����������� ��������, ���������, ���������, �������, ��������, �������. 
// � �������� �������, � ������������� ��������� ��������� 4.0*3.2-5.4*6.0=

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
double getNumber (char getNumber_num [100], int getNumber_i, int getNumber_z); // ������� ��������� ����� �� �����
double mulDiv (char mulDiv_sign, double mulDiv_num, double mulDiv_num2); // ������� �������� (���������, ��������, �������, ���������, ��������, � �.�.)
double expression (char expr_array[100]); // ������� ������������� ��������� (���������� getNumber � MulDiv). �� �������� ���������� ������.
double func (char func_sign, char func_array [100], int func_i, int func_z, double func_temp2); // ������� ��������� ��������� �� �����.
double result (char result_array [100]); // ������� ��������� ���������� ������.

main ()
{
	char formula [100]; // ������ ��� �������
	char num [100] = {0}; 
	char sign = '+'; 
	int i, z, k, count;
	double temp, temp2;
	temp2 = 0;
	temp = 0;
	i = 0;
	count = 0;
	gets (formula);
	temp = result(formula);
printf ("=%f\n", temp);
return 0;
}

double mulDiv (char mulDiv_sign, double mulDiv_num, double mulDiv_num2) // ��������� ���������� ����� � ����� ��� �������
{
	double mulDiv_result;
	double mulDiv_temp2;
	switch (mulDiv_sign) // � ����������� �� ����������� �����, ������ ������ ����������.
	{
		case ('*'):
			mulDiv_temp2 = mulDiv_num2*mulDiv_num;
			break;
		case ('/'):
			mulDiv_temp2 = mulDiv_num/mulDiv_num2;
			break;
		case ('^'):
			mulDiv_temp2 = pow(mulDiv_num, mulDiv_num2);
			break;
		case ('%'):
			mulDiv_temp2 = (100*mulDiv_num)/mulDiv_num2;
			break;
		case ('+'):
			mulDiv_temp2 = mulDiv_num2+mulDiv_num;
			break;
		case ('-'):
			mulDiv_temp2 = mulDiv_num2 - mulDiv_num;
			break;
		default:
			mulDiv_temp2 = mulDiv_num;
			break;
			
	}
	mulDiv_result = mulDiv_temp2;
	return mulDiv_result;
}
double expression (char expr_array[100]) // �������� ������ �� ������� func. ������ 4.0*3.2-5.4*6.0= 
{
	char num [100];
	int expression_i = 0;
	int expression_z = -1; // ���� ���������� z ��� �� ����� ����� ������, ������� ���������������� ����� ������ ��������� �������. 
	char expression_sign;
	expression_sign = '*'; // ��� ��������� ������� �����, ����� ����� ��� ���������� ��������� �� 1, ����� ���� �� ���������. �.�. ����������� ����� ����� ������, ���������� ��������� �� 1.
	double expression_temp = 0;
	double expression_temp2 = 1; // ��� ��������� ������� �����, ����� ����� ��� ���������� ��������� �� 1, ����� ���� �� ���������. �.�. ����������� ����� ����� ������, ���������� ��������� �� 1. 1*3+3+3 = 
	while (expression_i < strlen (expr_array))// ������ ��� �������� 4.0*3.2, ������ 5.4*6.0
	{
		switch (expr_array[expression_i])
		{
			case ('-'):
				expression_temp = getNumber(expr_array, expression_i, expression_z); // ��� ��������� ����� �� �����, ������� ����� ����� ���.
				expression_temp2 = mulDiv (expression_sign, expression_temp2, expression_temp); // ���������� �����, ���������� temp2 � Sign ������� � ������� mulDiv. ������ ��� 4.0*3.2, ������ 5.4*6.0
				expression_sign = '-'; // ���� ���������� � ���������� sign
				expression_i++;
				break; // ���������� z �� ��������, �.�. ��� ���� ������� + � - ���������� = ��� ����� �����.
			case ('+'):
				expression_temp = getNumber(expr_array, expression_i, expression_z);
				expression_temp2 = mulDiv (expression_sign, expression_temp2, expression_temp);
				expression_sign = '+';
				expression_i++;
				break;
			case ('*'): 
				expression_temp = getNumber(expr_array, expression_i, expression_z); // ������� ���� � ��������� � �������� ����� ����� ���. 
				expression_temp2 = mulDiv (expression_sign, expression_temp2, expression_temp); // ���������� ����� �������� �� temp. 4.0*1, � ������ ��� 5.4 * 1
				expression_sign = '*';
				expression_z = expression_i; // ��������� - ��� ������� ����� ������� + ��� -, ������� 
				expression_i++;
				break;
			case ('/'):
				expression_temp = getNumber(expr_array, expression_i, expression_z);
				expression_temp2 = mulDiv (expression_sign, expression_temp2, expression_temp);
				expression_sign = '/';
				expression_z = expression_i;
				expression_i++;
				break;
			case ('^'):
				expression_temp = getNumber(expr_array, expression_i, expression_z);
				expression_temp2 = mulDiv (expression_sign, expression_temp2, expression_temp);
				expression_sign = '^';
				expression_z = expression_i;
				expression_i++;
				break;
			case ('%'):
				expression_temp = getNumber(expr_array, expression_i, expression_z);
				expression_temp2 = mulDiv (expression_sign, expression_temp2, expression_temp);
				expression_sign = '%';
				expression_z = expression_i;
				expression_i++;
				break;
			case ('='):
				expression_temp = getNumber(expr_array, expression_i, expression_z);
				expression_temp2 = mulDiv (expression_sign, expression_temp2, expression_temp);
				expression_z = expression_i;
				expression_i++;
				break;
			default:
				expression_i++;
		}
	}
	return expression_temp2;
}
double getNumber (char getNumber_num [100], int getNumber_i, int getNumber_z) // �������� ���������� � ������
{
	int count, getNumber_k, getNumber_j, dotfault, rank, i;
	double getNumber_temp, getNumber_result;
	int nums [100];
	getNumber_k = 0;
	dotfault = 0;
	getNumber_temp = 0;
	rank = 0;
	for (count = getNumber_z + 1; count < getNumber_i; count++)
	{
		if (isdigit(getNumber_num[count])) // ���� �������� ����� ���������� ������� � ������ int, ����� �������� ����� �������� 48. ����� ������� ������� ������������������ ����.
		{
			nums[getNumber_k] = getNumber_num[count] - 48;
			getNumber_k++;
		}
			else // ����� ���������� ����������� "."
			{
				if (getNumber_num[count] = '.') 
				{	

					rank = getNumber_i - count - 1; // ��������� ������ (���-�� ������ ����� �������). �������� �������� 4.0: 4 - �����, ����� � �����, "." - ����� 1 � �������, 
													//��������� ������ i - count - 1 (4 - 2 - 1),  0 - �����, ����� � ������. �������� ������ 1.
					dotfault ++;
				}					
			}
	}	
	getNumber_j = getNumber_k - 1;
	for (count = 0; count < getNumber_k; count++)
	{	
		getNumber_temp = nums[count]*pow(10,getNumber_j)+getNumber_temp; // ������������������ ���� ���������� � �����. 4 � 0 = 4*10 + 0*1 = 40, 3 � 2 = 3*10 + 2*1 = 32. 
		getNumber_j--;	
	}
	getNumber_temp = getNumber_temp*pow(10,-rank); // ������ ����� �������� �������� ���������, ���� ��������� �� 10^(-rank). 40*10^(-1) = 4.0, 32*10^(-1) = 3.2.
	getNumber_result = getNumber_temp;
	return getNumber_result;
}
double func (char func_sign, char func_array [100], int func_i, int func_z, double func_temp2) // �������� ������ � ���������� �� ������� result � ������� � expression. ������ 4.0*3.2-5.4*6.0=
{
	int func_k, func_count;
	char func_expr[100];
	double func_temp;
	func_k = 0;
	for (func_count = func_z+1; func_count <= func_i ; func_count++) // ������� ������ ��� ������� expression. 
	{
		func_expr[func_k] = func_array[func_count]; // ������ ��� ��� ������� ���������� ����� "-". ����� �������� ������ 4.0*3.2, ������ ��� 5.4*6.0
		func_k++;
	}
		func_temp = expression (func_expr); // ������ ��� �������� temp = 4.0*3.2 = 12.8, ������ temp = 5.4*6.0 = 32.4
		func_temp2 = mulDiv (func_sign, func_temp, func_temp2); //������ ��� �������� temp2 = 12.8 (temp)+ 0 (temp2 = result_temp = 0), ������ ��� temp2 = 12.8 - 32.4 ( "-" �������� �� result)
		memset(func_expr, '0', 100);
	return func_temp2;
}
double result (char result_array[100]) // ������� ���������� *, / � ������ ����� ������� ����������. ������ 4.0*3.2-5.4*6.0=
{
	int result_z, result_i, count;
	double result_temp = 0;
	char result_sign = '+'; // �������������� 0, ����� ��������� � ������� ����� 0.
	result_i = 0; 
	result_z = -1;
	count = 0;
	while (result_i < strlen(result_array))
	{
		switch (result_array[result_i]) // ���� +, -, ��� =. ����� ������� ���������� ��������� ����� ������� �������� ����������.
		{
			case ('-'):
				result_temp = func (result_sign, result_array, result_i, result_z, result_temp); // ��������� ����� ������ �������� � func. � �������� temp. �������� 4.0*3.2 - .... : ���� "-", ��������� 4.0*3.2 �������� � func, temp = 12.8. 
				result_sign = result_array[result_i];
				result_z = result_i; 
				result_i++;
				break;
			case ('+'):
				result_temp = func (result_sign, result_array, result_i, result_z, result_temp);
				result_sign = result_array[result_i];
				result_z = result_i;
				result_i++;
				break;
			case ('='):
				result_temp = func (result_sign, result_array, result_i, result_z, result_temp); // ����� "=" ..... - 5.4*6.0 : temp = "temp"(12.8) "sign" (-) 5.4*6.0 = 12.8 - 32.4 = - 19.6.  
				result_sign = result_array[result_i];
				result_z = result_i;
				result_i++;
				break;
			default:
				result_i++;
		}
	}
	return result_temp;
}
