// Калькулятор, считает выражения без скобок. Реализованы сложение, вычитание, умножение, деление, проценты, степень. 
// В качестве примера, в комменатариях разобрано выражение 4.0*3.2-5.4*6.0=

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
double getNumber (char getNumber_num [100], int getNumber_i, int getNumber_z); // функция получения числа из ввода
double mulDiv (char mulDiv_sign, double mulDiv_num, double mulDiv_num2); // функция операция (умножение, сложение, деление, вычитание, проценты, и т.д.)
double expression (char expr_array[100]); // функция расчитывающая выражение (объединяет getNumber и MulDiv). Не понимает приоритета знаков.
double func (char func_sign, char func_array [100], int func_i, int func_z, double func_temp2); // функция получения выражения из ввода.
double result (char result_array [100]); // функция считающая приоритеты знаков.

main ()
{
	char formula [100]; // массив для расчёта
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

double mulDiv (char mulDiv_sign, double mulDiv_num, double mulDiv_num2) // принимает переменные знака и чимла для расчёта
{
	double mulDiv_result;
	double mulDiv_temp2;
	switch (mulDiv_sign) // в зависимости от полученного знака, делаем нужное вычисление.
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
double expression (char expr_array[100]) // получаем массив от функции func. Пример 4.0*3.2-5.4*6.0= 
{
	char num [100];
	int expression_i = 0;
	int expression_z = -1; // счёт переменной z идёт до знака перед числом, поэтому инициализируется перед первым элементом массива. 
	char expression_sign;
	expression_sign = '*'; // при получение первого знака, число перед ним необходимо уимножить на 1, чтобы ввод не изменился. Т.е. отсутсвтвие ввода перед числом, равноценно умножению на 1.
	double expression_temp = 0;
	double expression_temp2 = 1; // при получение первого знака, число перед ним необходимо уимножить на 1, чтобы ввод не изменился. Т.е. отсутсвтвие ввода перед числом, равноценно умножению на 1. 1*3+3+3 = 
	while (expression_i < strlen (expr_array))// первый раз получает 4.0*3.2, второй 5.4*6.0
	{
		switch (expr_array[expression_i])
		{
			case ('-'):
				expression_temp = getNumber(expr_array, expression_i, expression_z); // при получении знака на вводе, находим число перед ним.
				expression_temp2 = mulDiv (expression_sign, expression_temp2, expression_temp); // полученное число, переменную temp2 и Sign передаём в функцию mulDiv. Первый раз 4.0*3.2, второй 5.4*6.0
				expression_sign = '-'; // знак записываем в переменную sign
				expression_i++;
				break; // переменная z не меняется, т.к. для этой функции + и - равноценны = или конец ввода.
			case ('+'):
				expression_temp = getNumber(expr_array, expression_i, expression_z);
				expression_temp2 = mulDiv (expression_sign, expression_temp2, expression_temp);
				expression_sign = '+';
				expression_i++;
				break;
			case ('*'): 
				expression_temp = getNumber(expr_array, expression_i, expression_z); // находим знак в выражении и получаем число перед ним. 
				expression_temp2 = mulDiv (expression_sign, expression_temp2, expression_temp); // полученное число умножаем на temp. 4.0*1, а второй раз 5.4 * 1
				expression_sign = '*';
				expression_z = expression_i; // выражение - это символы между знаками + или -, поэтому 
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
double getNumber (char getNumber_num [100], int getNumber_i, int getNumber_z) // получает переменные и массив
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
		if (isdigit(getNumber_num[count])) // пока получаем цифру записываем символы в масиив int, чтобы получить цифру вычитаем 48. Таким образом находим последовательность цифр.
		{
			nums[getNumber_k] = getNumber_num[count] - 48;
			getNumber_k++;
		}
			else // чтобы определить разделитель "."
			{
				if (getNumber_num[count] = '.') 
				{	

					rank = getNumber_i - count - 1; // вычисляем разряд (кол-во знаков после запчтой). Например получаем 4.0: 4 - число, пишем в масив, "." - номер 1 в массиве, 
													//вычисляем разряд i - count - 1 (4 - 2 - 1),  0 - число, пишем в массив. Получаем разряд 1.
					dotfault ++;
				}					
			}
	}	
	getNumber_j = getNumber_k - 1;
	for (count = 0; count < getNumber_k; count++)
	{	
		getNumber_temp = nums[count]*pow(10,getNumber_j)+getNumber_temp; // Полседовательность цифр превращаем в число. 4 и 0 = 4*10 + 0*1 = 40, 3 и 2 = 3*10 + 2*1 = 32. 
		getNumber_j--;	
	}
	getNumber_temp = getNumber_temp*pow(10,-rank); // теперь нужно получить конечный результат, путём умнлжения на 10^(-rank). 40*10^(-1) = 4.0, 32*10^(-1) = 3.2.
	getNumber_result = getNumber_temp;
	return getNumber_result;
}
double func (char func_sign, char func_array [100], int func_i, int func_z, double func_temp2) // получает массив и переменные от функции result и передаёт в expression. Пример 4.0*3.2-5.4*6.0=
{
	int func_k, func_count;
	char func_expr[100];
	double func_temp;
	func_k = 0;
	for (func_count = func_z+1; func_count <= func_i ; func_count++) // создает массив для функции expression. 
	{
		func_expr[func_k] = func_array[func_count]; // первый раз эта функция вызывается после "-". Тогда получаем массив 4.0*3.2, второй раз 5.4*6.0
		func_k++;
	}
		func_temp = expression (func_expr); // первый раз получает temp = 4.0*3.2 = 12.8, второй temp = 5.4*6.0 = 32.4
		func_temp2 = mulDiv (func_sign, func_temp, func_temp2); //первый раз получает temp2 = 12.8 (temp)+ 0 (temp2 = result_temp = 0), второй раз temp2 = 12.8 - 32.4 ( "-" получает от result)
		memset(func_expr, '0', 100);
	return func_temp2;
}
double result (char result_array[100]) // функция игнорирует *, / и другие знаки низкого приоритета. Пример 4.0*3.2-5.4*6.0=
{
	int result_z, result_i, count;
	double result_temp = 0;
	char result_sign = '+'; // инициализируем 0, чтобы прибавить к первому числу 0.
	result_i = 0; 
	result_z = -1;
	count = 0;
	while (result_i < strlen(result_array))
	{
		switch (result_array[result_i]) // ищет +, -, или =. Таким образом определяем выражение между знаками высокого приоритета.
		{
			case ('-'):
				result_temp = func (result_sign, result_array, result_i, result_z, result_temp); // выражение перед знаком передаем в func. И получаем temp. Например 4.0*3.2 - .... : знак "-", выражение 4.0*3.2 передаем в func, temp = 12.8. 
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
				result_temp = func (result_sign, result_array, result_i, result_z, result_temp); // перед "=" ..... - 5.4*6.0 : temp = "temp"(12.8) "sign" (-) 5.4*6.0 = 12.8 - 32.4 = - 19.6.  
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
