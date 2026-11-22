#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <clocale>
#include <string>
#include <stdio.h>
#include <windows.h>

using namespace std;

struct voditel
{
	char surname[30];
	char name[30];
	char middlename[30];
	char car[15];
	char tech[20];
	char otdel[50];
};

voditel input_voditel()
{
	voditel v;
	cout << "Фамилия: "; cin >> v.surname;
	cout << "Имя: "; cin >> v.name;
	cout << "Отчество: "; cin >> v.middlename;
	cout << "Номер авто: "; cin >> v.car;
	cout << "Номер техпаспорта: "; cin >> v.tech;
	cin.ignore();
	cout << "Отделение регистрации ГАИ: "; cin.getline(v.otdel, 50);
	return v;
}
void create_file(const char* filename)
{
	FILE* f;
	voditel v;
	f = fopen(filename, "wb");
	if (f == NULL) {
		cout << "Ошибка открытия файла!\n";
		return;
	}

	for (int n = 1; n <= 5; n++)
	{
		cout << "\n---\n" << "Запись № " << n << "\n---\n";
		v = input_voditel();

		fwrite(&v, sizeof(voditel), 1, f);
		if (ferror(f))
		{
			cout << "\nОшибка записи в файл!\n";
			fclose(f);
			return;
		}
	}
	fclose(f);
}
void print_file(const char* filename)
{
	FILE* f;
	voditel v;
	f = fopen(filename, "rb");
	if (f == NULL)
	{
		cout << "Ошибка чтения файла!\n";
		return;
	}
	int num = 1;
	while (fread(&v, sizeof(voditel), 1, f) == 1)
	{
		cout << "\n---\n" << "Запись № " << num << "\n---\n";
		cout << "\nФамилия: " << v.surname;
		cout << "\nИмя: " << v.name;
		cout << "\nОтчество: " << v.middlename;
		cout << "\nНомер авто: " << v.car;
		cout << "\nНомер техпаспорта: " << v.tech;
		cout << "\nОтделение регистрации ГАИ: " << v.otdel;
		num++;
	}
	fclose(f);
}
void delete_f(const char* filename, int del_num)
{
	FILE* f;
	FILE* temp;
	voditel v;
	f = fopen(filename, "rb");
	temp = fopen("temp.dat", "wb");
	if (f == NULL) 
	{
		cout << "Ошибка открытия файла!\n";
		return;
	}
	if (temp == NULL)
	{
		cout << "Ошибка чтения файла!\n";
		return;
	}
	int num = 1;
	while (fread(&v, sizeof(voditel), 1, f) == 1)
	{
		if (num != del_num)
		{
			fwrite(&v, sizeof(voditel), 1, temp);
			if (ferror(temp))
			{
				cout << "\nОшибка записи в файл!\n";
				fclose(temp);
				return;
			}
		}
		num++;
	}
	fclose(f);
	fclose(temp);
	remove(filename);
	rename("temp.dat", filename);
}
void add2_f(const char* filename, const char* familia)
{
	FILE* f;
	FILE* temp;
	voditel v;
	f = fopen(filename, "rb");
	temp = fopen("temp.dat", "wb");
	if (f == NULL)
	{
		cout << "Ошибка открытия файла!\n";
		return;
	}
	if (temp == NULL)
	{
		cout << "Ошибка чтения файла!\n";
		return;
	}
	int num = 1;
	while (fread(&v, sizeof(voditel), 1, f) == 1)
	{
		if (string(v.surname) == familia)
		{
			for (int i = 1;i <= 2;i++)
			{
				cout << "\nВведите данные пользователя " << i << " : ";
				voditel noviy = input_voditel();
				fwrite(&noviy, sizeof(voditel), 1, temp);
			}
		}
		fwrite(&v, sizeof(voditel), 1, temp);
		num++;
	}
	fclose(f);
	fclose(temp);
	remove(filename);
	rename("temp.dat", filename);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	create_file("voditeli");
	print_file("voditeli");
	int n;
	cout << "\n\nВведите номер удаления: "; cin >> n;
	delete_f("voditeli", n);
	print_file("voditeli");
	char fam[30];
	cout << "\n\nВведите Фамилию: "; cin >> fam;
	add2_f("voditeli", fam);
	print_file("voditeli");
	return 0;
}
