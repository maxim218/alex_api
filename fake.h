// автор - Колотовкин Максим

// подключаем библиотеки
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
// пространство имен
using namespace std;

// класс для создания стуктуры
class Structure {
	protected:
		// структура для хранения строения ключа
		struct keyStruct {
			// название ключа
			string nameKey;
			// размер ключа в битах
			int sizeKey;
		};
		
		// название структуры
		string structName;
		
	public:	
		// массив ключей
		vector <keyStruct> v;
	
		// конструктор
		Structure(string structNameParam) {
			// задаем имя структуры
			structName = structNameParam;
		}
		
		string getStructName() {
			return structName;
		}
		
		// добавление описания нового ключа структуры
		void addKey(string nameKeyParam, int sizeKeyParam) {
			// создаем запись - ключ
			keyStruct key;
			// задаем поля записи
			// название ключа
			key.nameKey = nameKeyParam;
			// размер ключа в битах
			key.sizeKey = sizeKeyParam;
			// добавляем ключ в массив ключей
			v.push_back(key);
		}
		
		// вывод на экран содержимого структуры
		void renderStructure() {
			cout << "\n\n";
			cout << "==================================";
			cout << "\n";
			// вывод имени структуры
			cout << "Struct name: " << structName << "\n";
			cout << "\n";
			// вывод ключей структуры
			cout << "Keys: " << "\n";
			// пробегаемся по массиву ключей
			for(int i = 0; i < v.size(); i++) {
				cout << "\n";
				// выводим название ключа
				cout << "Name: " << v[i].nameKey << "\n";
				// выводим размер ключа в битах
				cout << "Size: " << v[i].sizeKey << "\n";
			}
			cout << "==================================";
			cout << "\n\n";
		}
};

// массив для хранения существующих структур
vector <Structure> structVector;

// сохраняем структуру в массив структур
void fixStructure(Structure structure) {
	// добавляем структуру в конец массива структур
	structVector.push_back(structure);
	// выводим описание структуры на экран
	structure.renderStructure();
}

// генерация ошибки
void error(string s) {
	// вывод содержимого ошибки
	cout << "\n\n\n" << "Error: " << s << "\n\n\n";
	// создание ошибки
	throw;
}

// функция для проверки существования ключа в структуре
void controlKeyName(string structName, string keyName) {
	// перебираем все типы структур
	for(int i = 0; i < structVector.size(); i++) {
		// если имя структуры из параметра совпадает с именем i-ой структуры
		if(structName == structVector[i].getStructName()) {
			// получаем доступ к i-той структуре
			Structure structure = structVector[i];
			// перебираем все ключи структуры
			for(int k = 0; k < structure.v.size(); k++) {
				// если k-ый ключ совпадает с искомым ключом, то выходим
				if(structure.v[k].nameKey == keyName) return;
			}
		}
	}
	// если совпадений не найдено, то генерируем ошибку
	error("field '" + keyName + "' not exists in structure '" + structName + "'");
}

// структура для хранения названия ключа и его значения
struct keyStruct {
	// название ключа
	string keyName;
	// значение ключа
	string keyValue;
};

// класс для реазизации создания нового экземпляра структуры
class Inserter {
	protected:
		// имя структуры
		string structName;
	
	public:
		// массив для храненя ключей
		vector <keyStruct> v;
		// два хранимых в структуре значения
		int valueFirst;
		int valueSecond;
		
		// конструктор
		Inserter(string structNameParam) {
			// задаем имя структуры
			structName = structNameParam;
		}
		
		// метод для получения имени структуры
		string getStructName() {
			// возвращаем имя структуры
			return structName;
		}
		
		// метод для задания двух значений структуры
		void setValues(int valueFirstParam, int valueSecondParam) {
			// задаем первое значение
			valueFirst = valueFirstParam;
			// задаем второе значение
			valueSecond = valueSecondParam;
		}
		
		// добавляем ключ в конец массива
		void addKeyValue(string keyNameParam, string keyValueParam) {
			// проверка существования поля
			controlKeyName(structName, keyNameParam);
			// создаем ключ
			keyStruct key;
			// задаем название ключа
			key.keyName = keyNameParam;
			// задаем значение ключа
			key.keyValue = keyValueParam;
			// добавляем ключ в конец массива
			v.push_back(key);
		}
		
		// метод для удаления созданного экземпляра записи
		// осуществляется методом "маркировки"
		void removeMe() {
			// изменяем имя структуры
			structName = "____it_is_removed_element____";
			// пробегаемся по массиву ключей
			for(int i = 0; i < v.size(); i++) {
				// изменяем название ключа
				v[i].keyName = "____it_is_removed_element____";
				// изменяем значение ключа
				v[i].keyValue = "____it_is_removed_element____";
			}
		}
		
		// выводим содержимое вставляемой записи на экран
		void renderInserter() {
			cout << "\n\n";
			cout << "********************************";
			cout << "\n";
			// выводим на экран имя структуры
			cout << "Struct name: " << structName << "\n";
			cout << "\n";
			// вывод ключей структуры
			cout << "Keys: " << "\n";
			// пробегаемся по массиву ключей
			for(int i = 0; i < v.size(); i++) {
				cout << "\n";
				// вывод названия ключа
				cout << "Key: " << v[i].keyName << "\n";
				// вывод значения ключа
				cout << "Value: " << v[i].keyValue << "\n";
			}
			cout << "\n";
			// вывод двух хранимых в записи значений
			cout << "Values: " << "\n";
			cout << "\n";
			// вывод первого значения в записи
			cout << "First: " << valueFirst << "\n";
			// вывод второго значения в записи
			cout << "Second: " << valueSecond << "\n";
 			cout << "********************************";
			cout << "\n\n";
		}	
};

// преобразование из числа в строку
template <typename tip>
string makeString(tip x){
    ostringstream oss;
    oss << x;
    return oss.str();
}

// функция сравнения двух массивов ключей
bool compareKeys(vector <keyStruct> vAAA, vector <keyStruct> vBBB) {
	// если количество ключей не совпадает
	if(vAAA.size() != vBBB.size()) {
		// разное количество ключей
		// переводим размеры массивов в строки
		string sFirst = makeString( vAAA.size() );
		string sSecond = makeString( vBBB.size() );
		// генерируем ошибку
		error("not equal number of keys (" + sFirst + " and " + sSecond + ")");
	}
	// пробегаемся по первому массиву ключей
	for(int i = 0; i < vAAA.size(); i++)
		// пробегаемся по второму массиву ключей
		for(int j = 0; j < vBBB.size(); j++)
			// если имена ключей совпадают
			if(vAAA[i].keyName == vBBB[j].keyName)
				// если значения в ключах разные 
				if(vAAA[i].keyValue != vBBB[j].keyValue)
					// массивы ключей не одинаковые
					return false;
	// массивы ключей одинаковые
	return true;
}

// массив для хранения существующих экземпляров записей
vector <Inserter> inserterVector;

// сохранение нового экземпляра записи
void fixInserter(Inserter inserter) {
	// пробегаемся по массиву существующих записей
	for(int i = 0; i < inserterVector.size(); i++) {
		// если запись в массиве и добавляемая запись имеют одинаковый тип
		if(inserterVector[i].getStructName() == inserter.getStructName()) {
			// если у записей совпадают все ключи
			if(compareKeys(inserterVector[i].v, inserter.v) == true) {
				// изменяем запись в массиве
				inserterVector[i] = inserter;
				// выводим на экран содержимое добавляемой записи
				inserter.renderInserter();
				// выходим из функции
				return;
			}
		}	
	}
	// если же совпадение не обнаружено
	// добавляем новую запись в конец массива
	inserterVector.push_back(inserter);
	// выводим на экран содержимое добавляемой записи
	inserter.renderInserter();
}

// класс для поиска экземпляра записи по ключам
class Selector {
	protected:
		// массив для хранения ключей
		vector <keyStruct> v;
		// имя структуры
		string structName;
		
	public:
		// конструктор
		Selector(string structNameParam) {
			// задаем имя структуры
			structName = structNameParam;
		}
		
		// добавление ключа в массив ключей
		void addKeyValue(string keyNameParam, string keyValueParam) {
			// проверка существования поля
			controlKeyName(structName, keyNameParam);
			// создаем ключ
			keyStruct key;
			// задаем имя ключа
			key.keyName = keyNameParam;
			// задаем значение ключа
			key.keyValue = keyValueParam;
			// добавляем ключ в массив ключей
			v.push_back(key);
		}
		
		// поиск записи
		bool startSelect(int &valueFirst, int &valueSecond) {
			// начальная инициализация значений искомой записи
			valueFirst = 0;
			valueSecond = 0;
			// перебираем все элементы массива существующих записей
			for(int i = 0; i < inserterVector.size(); i++) {
				// получаем i-ый элемент массива
				Inserter inserter = inserterVector[i];
				// если имя структуры i-го элемента совпадает с именем структуры искомой записи
				if(inserter.getStructName() == structName) {
					// сравниваем их ключи
					bool r = compareKeys(v, inserter.v);
					// если все ключи совпадают
					if(r == true) {
						// задаем первое значение
						valueFirst = inserter.valueFirst;
						// задаем второе значение
						valueSecond = inserter.valueSecond;
						// возвращаем флаг - запись успешно найдена
						return true;
					}
				}
			}
			// возвращаем флаг - запись НЕ найдена
			return false;
		}
};

// поиск записи
bool fixSelector(Selector selector, int &valueFirst, int &valueSecond) {
	// вызываем метод поиска записи
	bool flag = selector.startSelect(valueFirst, valueSecond);
	// возвращаем флаг (найдена или НЕ найдена)
	return flag;
}

// функция получения количества существующих записей определенного типа
int fixPower(string structName) {
	// обнуляем счетчик
	int count = 0;
	// перебираем все существующие записи
	for(int i = 0; i < inserterVector.size(); i++) {
		// если имя структуры в массива совпадает с именем структуры из параметра
		if(inserterVector[i].getStructName() == structName) {
			// увеличиваем счетчик
			++count;
		}
	}
	// возврвщаем количество записей определенного типа
	return count;
}

// класс для удаления определенной записи
class Remover {
	protected:
		// массив ключей
		vector <keyStruct> v;
		// имя структуры
		string structName;
		
	public:
		// консруктор
		Remover(string structNameParam) {
			// задание имени структуры
			structName = structNameParam;
		}
		
		// добавление ключа в массив ключей
		void addKeyValue(string keyNameParam, string keyValueParam) {
			// проверка существования поля
			controlKeyName(structName, keyNameParam);
			// создаем ключ
			keyStruct key;
			// задаем имя ключа
			key.keyName = keyNameParam;
			// задаем значение ключа
			key.keyValue = keyValueParam;
			// добавляем ключ в массив ключей
			v.push_back(key);
		}
		
		// метод для удаления записи
		bool removeRecord() {
			// пробегаемся по массиву существующих записей
			for(int i = 0; i < inserterVector.size(); i++) {
				// получаем i-ую запись
				Inserter inserter = inserterVector[i];
				// если имя стурктуры i-ой записи совпадает с именем записи из параметра
				if(inserter.getStructName() == structName) {
					// сравниваем ключи
					bool r = compareKeys(v, inserter.v);
					// если значения ключей совпадают
					if(r == true) {
						// удаляем запись методом маркировки
						inserterVector[i].removeMe();
						// возвращаем флаг - запись успешно удалена
						return true;
					}
				}
			}
			// возвращаем флаг - запись не найдена (нельзя удалить несуществующую запись)
			return false;
		}
};

// функция для удаления записи
bool fixRemove(Remover &remover) {
	// пытаемся удалить запись
	bool flag = remover.removeRecord();
	// возвращаем флаг удаления записи (удалена или НЕ найдена)
	return flag;
}

// структура для получения содержимого экземпляра записи
struct Container {
	// словарь с ключами и их значениями
	map <string, string> m;
	// два хранимых в записи значения
	int valueFirst;
	int valueSecond;
};

// получение минимального экземпляра записи
bool fixMin(string structNameParam, Container &container) {
	// перебираем все записи в порядке возрастания индекса
	for(int i = 0; i < inserterVector.size(); i++) {
		// если у i-го элемента совпадает имя структуры с искомой структурой
		if(inserterVector[i].getStructName() == structNameParam) {
			// получаем i-ый элемент
			Inserter inserter = inserterVector[i];
			// копируем хранимые значения
			container.valueFirst = inserter.valueFirst;
			container.valueSecond = inserter.valueSecond;
			// перебираем все ключи
			for(int k = 0; k < inserter.v.size(); k++) {
				// получаем имя ключа
				string key = inserter.v[k].keyName;
				// получаем значение ключа
				string value = inserter.v[k].keyValue;
				// сохраняем ключ со значением в словарь
				container.m[key] = value;
			}
			// искомая запись найдена
			return true;
		}
	}
	// запись НЕ найдена
	return false;
}

// получение максимального экземпляра записи
bool fixMax(string structNameParam, Container &container) {
	// перебираем элементы в порядке убывания индекса
	for(int i = inserterVector.size() - 1; i >= 0; i--) {
		// если у i-го элемента совпадает имя структуры с искомой структурой
		if(inserterVector[i].getStructName() == structNameParam) {
			// получаем i-ый элемент
			Inserter inserter = inserterVector[i];
			// копируем хранимые значения
			container.valueFirst = inserter.valueFirst;
			container.valueSecond = inserter.valueSecond;
			// перебираем все ключи
			for(int k = 0; k < inserter.v.size(); k++) {
				// получаем имя ключа
				string key = inserter.v[k].keyName;
				// получаем значение ключа
				string value = inserter.v[k].keyValue;
				// сохраняем ключ со значением в словарь
				container.m[key] = value;
			}
			// искомая запись найдена
			return true;
		}
	}
	// запись НЕ найдена
	return false;
}

// функция получения следующего элемента
bool fixNext(string structNameParam, map <string, string> d, Container &result) {
	// индекс для хранения номера записи с ключами из словаря "d"
	int index = -1;
	
	// перебираем все существующие записи в порядке возраствания индекса
	for(int i = 0; i < inserterVector.size(); i++) {
		// если у записи подходящее название
		if(inserterVector[i].getStructName() == structNameParam) {
			// получаем доступ к i-той записи
			Inserter inserter = inserterVector[i];
			// стурктура для хранения ключей со значениями
			Container container;
			// пробегаемся по всем ключам записи
			for(int k = 0; k < inserter.v.size(); k++) {
				// получаем имя ключа
				string key = inserter.v[k].keyName;
				// получаем значение ключа
				string value = inserter.v[k].keyValue;
				// сохраняем ключ в контейнер
				container.m[key] = value;
			}
			// флаг - изначально предполагаем, что ключи из параметра совпадают с ключами данной записи
			bool equal = true;
			// перебираем все ключи из словаря, переданного в качестве параметра функции
			for(map <string, string> :: iterator iter = d.begin(); iter != d.end(); iter++) {
				// получаем имя ключа
				string key = (*iter).first;
				// если значение по ключу не совпадает
				if(d[key] != container.m[key]) {
					// значение ключей не совпадает
					equal = false;
				}
			}
			// если ключи не совпадали, то переходим к проверке следующей записи
			if(equal == false) continue;
			// если ключи совпали
			if(equal == true) {
				// сохраняем номер записи
				index = i;
				// выходим из цикла
				break;
			}
		}
	}
	
	// если номер подходящей записи не найден
	if(index == -1) {
		// результат НЕ найден
		return false;
	}
	
	// перебираем все элементы в порядке возрастания индекса
	// начинаем перебор со СЛЕДУЮЩЕГО после найденного в предыдущем цикле
	for(int i = index + 1; i < inserterVector.size(); i++) {
		// если имена структур совпадают
		if(inserterVector[i].getStructName() == structNameParam) {
			// получаем доступ к i-той записи
			Inserter inserter = inserterVector[i];
			// структура для сохранения результата
			Container container;
			// сохраняем хранимые два значения
			container.valueFirst = inserter.valueFirst;
			container.valueSecond = inserter.valueSecond;
			// перебираем все ключи
			for(int k = 0; k < inserter.v.size(); k++) {
				// получаем имя ключа
				string key = inserter.v[k].keyName;
				// получаем значение в ключе
				string value = inserter.v[k].keyValue;
				// сохраняем ключ в словарь
				container.m[key] = value;
			}
			// копируем полученные данные для выдачи результата
			result = container;
			// результат найден
			return true;
		}
	}
	
	// результат НЕ найден
	return false;
}

// функция получения ПРЕДЫДУЩЕГО элемента
bool fixPrev(string structNameParam, map <string, string> d, Container &result) {
	// индекс для хранения номера записи с ключами из словаря "d"
	int index = -1;
	
	// перебираем все существующие записи в порядке УБЫВАНИЯ индекса
	for(int i = inserterVector.size() - 1; i >= 0; i--) {
		// если у записи подходящее название
		if(inserterVector[i].getStructName() == structNameParam) {
			// получаем доступ к i-той записи
			Inserter inserter = inserterVector[i];
			// стурктура для хранения ключей со значениями
			Container container;
			// пробегаемся по всем ключам записи
			for(int k = 0; k < inserter.v.size(); k++) {
				// получаем имя ключа
				string key = inserter.v[k].keyName;
				// получаем значение ключа
				string value = inserter.v[k].keyValue;
				// сохраняем ключ в контейнер
				container.m[key] = value;
			}
			// флаг - изначально предполагаем, что ключи из параметра совпадают с ключами данной записи
			bool equal = true;
			// перебираем все ключи из словаря, переданного в качестве параметра функции
			for(map <string, string> :: iterator iter = d.begin(); iter != d.end(); iter++) {
				// получаем имя ключа
				string key = (*iter).first;
				// если значение по ключу не совпадает
				if(d[key] != container.m[key]) {
					// значение ключей не совпадает
					equal = false;
				}
			}
			// если ключи не совпадали, то переходим к проверке следующей записи
			if(equal == false) continue;
			// если ключи совпали
			if(equal == true) {
				// сохраняем номер записи
				index = i;
				// выходим из цикла
				break;
			}
		}
	}
	
	// если номер подходящей записи не найден
	if(index == -1) {
		// результат НЕ найден
		return false;
	}
	
	// перебираем все элементы в порядке УБЫВАНИЯ индекса
	// начинаем перебор с ПРЕДЫДУЩЕГО до найденного в предыдущем цикле
	for(int i = index - 1; i >= 0; i--) {
		// если имена структур совпадают
		if(inserterVector[i].getStructName() == structNameParam) {
			// получаем доступ к i-той записи
			Inserter inserter = inserterVector[i];
			// структура для сохранения результата
			Container container;
			// сохраняем хранимые два значения
			container.valueFirst = inserter.valueFirst;
			container.valueSecond = inserter.valueSecond;
			// перебираем все ключи
			for(int k = 0; k < inserter.v.size(); k++) {
				// получаем имя ключа
				string key = inserter.v[k].keyName;
				// получаем значение в ключе
				string value = inserter.v[k].keyValue;
				// сохраняем ключ в словарь
				container.m[key] = value;
			}
			// копируем полученные данные для выдачи результата
			result = container;
			// результат найден
			return true;
		}
	}
	
	// результат НЕ найден
	return false;
}


