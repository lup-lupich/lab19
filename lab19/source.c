#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

int task1(void);
int task2(void);
void tabulation(FILE* ptr_file_name);

int main(void) {

	setlocale(LC_CTYPE, "RUS");

	int user_task;

	printf("Выберите задание: ");
	scanf("%d", &user_task);
	printf("\n");

	switch (user_task) {
	case 1: task1(); break;
	case 2: task2(); break;
	default: printf("Такого задания нет\n");
	}

	return 0;
}

int task1(void) {

	char fname[20] = "number.txt";
	FILE* out;

	puts("Создание файла");

	if ((out = fopen(fname, "at")) == NULL) {

		printf("Ошибка открытия файла\n");
		return -1;
	}

	fprintf(out, "%d\n", 5);
	fprintf(out, "%.2f\n", 12.56);

	fclose(out);

	return 0;
}

int task2(void) {

	int write_or_add;
	char fname2[20] = "temp.txt";
	FILE* ptr_temp_txt;

	printf("1) запись в новый файл \n2) дозапись в существующий\n");
	scanf("%d", &write_or_add);

	switch (write_or_add) {

	case 1:
		if ((ptr_temp_txt = fopen(fname2, "wt")) == NULL) {

			printf("Ошибка открытия файла\n");
			return -1;
		}

		tabulation(ptr_temp_txt);

		fclose(ptr_temp_txt);

		break;
	
	case 2: 
		if ((ptr_temp_txt = fopen(fname2, "at")) == NULL) {

			printf("Ошибка открытия файла\n");
			return -1;
		}

		tabulation(ptr_temp_txt);

		fclose(ptr_temp_txt);

		break;
	default: printf("Такой фукнции нет\n");
	}	

	return 0;
}

void tabulation(FILE* ptr_file_name) {

	int start, end;
	float step;

	printf("y = x^3 - 4x^2 + 2. Введите шаг табуляции\n");
	scanf("%f", &step);

	printf("Введите начало интервала\n");
	scanf("%d", &start);

	printf("Введите конец интервала\n");
	scanf("%d", &end);

	fprintf(ptr_file_name, "-----------------------\n");
	fprintf(ptr_file_name, "| %8s | %8s |\n", "x", "y");
	fprintf(ptr_file_name, "-----------------------\n");

	for (float i = start; i <= end; i += step) {

		fprintf(ptr_file_name, "| %8.2f | %8.2f |\n", i, pow(i, 3) - 4 * pow(i, 2) + 2);
		fprintf(ptr_file_name, "-----------------------\n");
	}
}