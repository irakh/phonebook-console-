#include <iostream>
#include <map>
#include <string>

void commands();  //Вывод меню
void create();  //Создать или добавить элемент
void show();  //Вывести на экран
void remove();  //Удалить элемент
void clear();  //Очистить контейнер
void same_name();  //Поиск номера телефона по имени
int enter_num();  //Проверка и ввод числа

std::multimap <std::string, std::string> student;
std::multimap <std::string, std::string>::iterator it;

int main()
{
	setlocale(LC_ALL, "Russian"); // задаём русский текст
	system("chcp 1251"); // настраиваем кодировку консоли

	std::cout << "Сделала Ханова Ирина Т12О-209Б-20\n";
	int menu_point;
	void(*ptr_f)();
	ptr_f = commands;
	ptr_f();

	while (true)
	{
		menu_point = 0;

		while (menu_point < 1 or menu_point > 7)
		{
			std::cout << "Выберите пункт меню: ";
			menu_point = enter_num();
		}
		switch (menu_point)
		{
		case 1:
			ptr_f = commands;
			break;
		case 2:
			ptr_f = create;
			break;
		case 3:
			ptr_f = show;
			break;
		case 4:
			ptr_f = remove;
			break;
		case 5:
			ptr_f = clear;
			break;
		case 6:
			ptr_f = same_name;
			break;
		case 7:
			return 0;
		}
		ptr_f();
	}
}

void commands()
{
	std::cout << "1) Меню\n";
	std::cout << "2) Создать или добавить элемент\n";
	std::cout << "3) Вывести на экран\n";
	std::cout << "4) Удалить элемент\n";
	std::cout << "5) Очистить\n";
	std::cout << "6) Поиск по имени\n";
	std::cout << "7) Выход\n";
}

void create()
{
	std::string name;
	std::string nomer;

	int leave = 0;
	char answer = '1';

	while (!leave)
	{
		std::cout << "Введите имя: ";
		std::cin >> name;
		std::cout << "Введите номер телефона: ";
		std::cin >> nomer;
		student.emplace(name, nomer);

		std::cout << "Для выхода нажмите 1. Для продолжения ввода любой другой символ...\n";
		std::cin >> answer;
		if (answer == '1') leave = 1;

	}

}

void show()
{
	it = student.begin();
	for (; it != student.end(); it++)
		std::cout << it->first << " " << it->second << std::endl;

}

void remove()
{
	it = student.begin();
	std::string name_to_del;

	std::cout << "Введите имя для удаления: ";
	std::cin >> name_to_del;

	it = student.find(name_to_del);
	student.erase(it);
	std::cout << "Элемент удален. \n";
}

void clear()
{
	it = student.begin();

	student.erase(it, student.end());
	std::cout << "Телефонный справочник очищен. \n";
}

void same_name()
{
	it = student.begin();
	std::string name_to_find;
	int count;

	std::cout << "Введите имя для поиска номера телефона: ";
	std::cin >> name_to_find;

	count = student.count(name_to_find);
	if (count >= 1) {
		std::cout << "Контакт найден. \n";
		it = student.find(name_to_find);
		std::cout << it->first << " " << it->second << std::endl;
	}
	else std::cout << "Контакт не найден. \n";
}

int enter_num()
{
	int leave = 0;
	char str[128];
	int digit = 0;
	int i, temp, length, result;

	while (!leave)
	{
		//ввод числа
		std::cin >> str;
		std::cout << "Введите кол-во цифр в введенном числе ";
		std::cin >> length;

		temp = length;
		leave = 1;

		for (i = 0; i < temp; i++)
		{
			digit = str[i];
			//проверка цифр
			if ((digit >= '0') and (digit <= '9'))
			{
				temp--;
			}
			else leave = 0;
		}

		if (!leave) std::cout << std::endl << "Введено не число";
	}

	result = 0;
	//перевод значения из строки
	//однозначные числа
	if (length == 1)
		result += (str[0] - '0');
	//многозначные числа
	else
	{
		temp = length + 1;
		result += (str[0] - '0');
		for (i = 1; i < temp; i++)
		{
			result = result * 10 + (str[i] - '0');
			temp--;
		}
	}
	return result;
}


