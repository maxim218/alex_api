// автор - Колотовкин Максим

// библиотека
#include "fake.h"
// пространство имен
using namespace std;

int main() {
	// объект для создания структуры и задания типов ключей
	Structure manStruct("man");
	// добавление типов ключей в структуру
	manStruct.addKey("name", 3072);
	manStruct.addKey("surname", 4096);
	manStruct.addKey("age", 128);
	// передача структуры процессору
	fixStructure(manStruct);
	
	// ****************************************************************
	
	// объект для добавления новой записи
	Inserter manA("man");
	// задаём ключи и их значения
	manA.addKeyValue("name", "Maxim");
	manA.addKeyValue("surname", "Kolotovkin");
	manA.addKeyValue("age", "21");
	// задаем два хранимых значения
	manA.setValues(100, 200);
	// передаем запись процессору
	fixInserter(manA);
	
	// ****************************************************************
	
	// объект для добавления новой записи
	Inserter manB("man");
	// задаём ключи и их значения
	manB.addKeyValue("name", "Alex");
	manB.addKeyValue("surname", "Ivanov");
	manB.addKeyValue("age", "17");
	// задаем два хранимых значения
	manB.setValues(450, 550);
	// передаем запись процессору
	fixInserter(manB);
	
	// ****************************************************************
	
	// объект для добавления новой записи
	Inserter manC("man");
	// задаём ключи и их значения
	manC.addKeyValue("name", "George");
	manC.addKeyValue("surname", "Petrov");
	manC.addKeyValue("age", "42");
	// задаем два хранимых значения
	manC.setValues(123, 456);
	// передаем запись процессору
	fixInserter(manC);
	
	// ****************************************************************
	
	// объект для поиска записи по набору ключей
	Selector selectorB("man");
	// задаем ключи со значениями
	selectorB.addKeyValue("name", "Alex");
	selectorB.addKeyValue("surname", "Ivanov");
	selectorB.addKeyValue("age", "17");
	// переменные для получения хранимых в записи значений
	int v_b_1 = 0;
	int v_b_2 = 0;
	// взаимодействуем с процессором
	bool flagB = fixSelector(selectorB, v_b_1, v_b_2);
	// если запись найдена
	if(flagB) {
		// выводим полученные значения записи на экран
		cout << "Values:  " << v_b_1 << "  " << v_b_2 << "\n\n";
	} else {
		// запись не найдена
		cout << "Record not found" << "\n\n";
	}
	
	// ****************************************************************
	
	// объект для поиска записи по набору ключей
	Selector selectorA("man");
	// задаем ключи со значениями
	selectorA.addKeyValue("name", "Maxim");
	selectorA.addKeyValue("surname", "Kolov");
	selectorA.addKeyValue("age", "21");
	// переменные для получения хранимых в записи значений
	int v_a_1 = 0;
	int v_a_2 = 0;
	// взаимодействуем с процессором
	bool flagA = fixSelector(selectorA, v_a_1, v_a_2);
	// если запись найдена
	if(flagA) {
		// выводим полученные значения записи на экран
		cout << "Values:  " << v_a_1 << "  " << v_a_2 << "\n\n";
	} else {
		// запись не найдена
		cout << "Record not found" << "\n\n";
	}
	
	// ****************************************************************
	
	// реализация обновления
	// объект для обновления уже существующей записи
	Inserter manQ("man");
	// задаём ключи и их значения
	manQ.addKeyValue("name", "Alex");
	manQ.addKeyValue("surname", "Ivanov");
	manQ.addKeyValue("age", "17");
	// задаем два хранимых значения
	manQ.setValues(7000, 8000);
	// передаем запись процессору
	fixInserter(manQ);
	
	// ****************************************************************
	
	// объект для поиска записи по набору ключей
	Selector selectorQ("man");
	// задаем ключи со значениями
	selectorQ.addKeyValue("name", "Alex");
	selectorQ.addKeyValue("surname", "Ivanov");
	selectorQ.addKeyValue("age", "17");
	// переменные для получения хранимых в записи значений
	int v_q_1 = 0;
	int v_q_2 = 0;
	// взаимодействуем с процессором
	bool flagQ = fixSelector(selectorQ, v_q_1, v_q_2);
	// если запись найдена
	if(flagQ) {
		// выводим полученные значения записи на экран
		cout << "Values:  " << v_q_1 << "  " << v_q_2 << "\n\n";
	} else {
		// запись не найдена
		cout << "Record not found" << "\n\n";
	}
	
	// ****************************************************************
	
	// получаем количество записей типа "man"
	int numberMan = fixPower("man");
	// выводим количество на экран
	cout << "Man number:  " << numberMan << "\n\n";
	
	// ****************************************************************
	
	// удаление записи
	// объект для удаления определенной записи
	Remover removerC("man");
	// задаем ключи со значениями
	removerC.addKeyValue("name", "George");
	removerC.addKeyValue("surname", "Petrov");
	removerC.addKeyValue("age", "42");
	// обращаемся к процессору для удаления записи
	bool flagRemoveC = fixRemove(removerC);
	// если удаление прошло успешно
	if(flagRemoveC == true) {
		// вывод сообщения об успешном удалении
		cout << "Deleting of record OK" << "\n\n";
	} else {
		// записи не существует
		// нельзя удалить несуществующую запись
		cout << "Record was not found" << "\n\n";
	}
	
	// ****************************************************************
	
	// получаем количество записей типа "man"
	int numberManAfter = fixPower("man");
	// выводим количество на экран
	cout << "Man number:  " << numberManAfter << "\n\n";
	
	// ****************************************************************
	// ****************************************************************
	
	Structure posStruct("pos");
	posStruct.addKey("xxx", 128);
	posStruct.addKey("yyy", 128);
	fixStructure(posStruct);
	
	
	for(int i = 1; i <= 5; i++) {
		// добавляем очередную точку
		Inserter posInserter("pos");
		posInserter.addKeyValue("xxx", "x" + makeString(i));
		posInserter.addKeyValue("yyy", "y" + makeString(i));
		posInserter.setValues(i * 10, i * 20);
		fixInserter(posInserter);
		
		// добавляем очередного человека
		Inserter manInserter("man");
		manInserter.addKeyValue("name", "man_Name_" + makeString(i));
		manInserter.addKeyValue("surname", "man_Surname_" + makeString(i));
		manInserter.addKeyValue("age", "man_Age_" + makeString(i));
		manInserter.setValues(i * 10 + 5, i * 20 + 5);
		fixInserter(manInserter);
	}
	
	
	// получаем количество записей разного типа
	cout << "Man number: " << fixPower("man") << "\n\n";
	cout << "Pos number: " << fixPower("pos") << "\n\n\n";
	
	
	// получаем минимум из записей "man"
	Container manContainerMin;
	bool manExistsMin = fixMin("man", manContainerMin);
	if(manExistsMin) {
		cout << "Min man: \n";
		cout << "Name: " << manContainerMin.m["name"] << "\n";
		cout << "Surname: " << manContainerMin.m["surname"] << "\n";
		cout << "Age: " << manContainerMin.m["age"] << "\n";
		cout << "Values: " << manContainerMin.valueFirst << " " << manContainerMin.valueSecond << "\n\n\n";
	}
	
	
	// получаем максимум из записей "man"
	Container manContainerMax;
	bool maxExistsMax = fixMax("man", manContainerMax);
	if(maxExistsMax) {
		cout << "Max man \n";
		cout << "Name: " << manContainerMax.m["name"] << "\n";
		cout << "Surname: " << manContainerMax.m["surname"] << "\n";
		cout << "Age: " << manContainerMax.m["age"] << "\n";
		cout << "Values: " << manContainerMax.valueFirst << " " << manContainerMax.valueSecond << "\n\n\n";
	}
	
	
	// получаем минимум из записей "pos"
	Container posMinContainer;
	bool posExistsMin = fixMin("pos", posMinContainer);
	if(posExistsMin) {
		cout << "Min pos: \n";
		cout << "xxx: " << posMinContainer.m["xxx"] << "\n";
		cout << "yyy: " << posMinContainer.m["yyy"] << "\n";
		cout << "Values: " << posMinContainer.valueFirst << " " << posMinContainer.valueSecond << "\n\n\n";
	}
	
	
	// получаем максимум из записей "pos"
	Container posMaxContainer;
	bool posExistsMax = fixMax("pos", posMaxContainer);
	if(posExistsMax) {
		cout << "Max pos: \n";
		cout << "xxx: " << posMaxContainer.m["xxx"] << "\n";
		cout << "yyy: " << posMaxContainer.m["yyy"] << "\n";
		cout << "Values: " << posMaxContainer.valueFirst << " " << posMaxContainer.valueSecond << "\n\n\n";
	}
	
	
	// попытка получить минимумы и максимумы несуществующих записей
	Container undefinedContainer;
	bool undefinedMinBool = fixMin("undefinedStruct", undefinedContainer);
	bool undefinedMaxBool = fixMax("undefinedStruct", undefinedContainer);
	if(undefinedMinBool == false) cout << "Record not found" << "\n\n\n";
	if(undefinedMaxBool == false) cout << "Record not found" << "\n\n\n";
	
	
	// перебор всех экземпляров записи "man" в порядке возрастания
	Container manRecord;
	// получаем минимальную запись
	bool interateMan = fixMin("man", manRecord);
	// если минимальная запись существует
	if(interateMan) {
		// выводим ключи и значения записи
		cout << manRecord.m["name"] << " " << manRecord.m["surname"] << " " << manRecord.m["age"] << " : ";
		cout << manRecord.valueFirst << " " << manRecord.valueSecond << "\n";
	}
	// вспомогательная структура
	Container bufferManRecord;
	// пока следующий элемент существует
	while(fixNext("man", manRecord.m, bufferManRecord) == true) {
		// получаем следующую запись
		manRecord = bufferManRecord;
		// выводим содержимое записи на экран
		cout << manRecord.m["name"] << " " << manRecord.m["surname"] << " " << manRecord.m["age"] << " : ";
		cout << manRecord.valueFirst << " " << manRecord.valueSecond << "\n";
	}
	cout << "\n\n";
	
	
	// перебор всех экземпляров записи "man" в порядке Убывания
	Container manRecordQ;
	// получаем максимальную запись
	bool iterateManQ = fixMax("man", manRecordQ);
	// если максиальная запись существует
	if(iterateManQ) {
		// выводим ключи и значения записи на экран
		cout << manRecordQ.m["name"] << " " << manRecordQ.m["surname"] << " " << manRecordQ.m["age"] << " : ";
		cout << manRecordQ.valueFirst << " " << manRecordQ.valueSecond << "\n";
	}
	// вспомогательная структура
	Container bufferManRecordQ;
	// пока предыдущий элемент существует
	while(fixPrev("man", manRecordQ.m, bufferManRecordQ) == true) {
		// получаем предыдущую запись
		manRecordQ = bufferManRecordQ;
		// выводим содержимое записи на экран
		cout << manRecordQ.m["name"] << " " << manRecordQ.m["surname"] << " " << manRecordQ.m["age"] << " : ";
		cout << manRecordQ.valueFirst << " " << manRecordQ.valueSecond << "\n";
	}
	cout << "\n\n";
	
	
	// перебор всех записей "pos" в порядке возрастания
	Container posAContainer;
	bool posA = fixMin("pos", posAContainer);
	if(posA) {
		cout << posAContainer.m["xxx"] << " " << posAContainer.m["yyy"] << " : ";
		cout << posAContainer.valueFirst << " " << posAContainer.valueSecond << "\n";
	}
	Container posBufA;
	while(fixNext("pos", posAContainer.m, posBufA) == true) {
		posAContainer = posBufA;
		cout << posAContainer.m["xxx"] << " " << posAContainer.m["yyy"] << " : ";
		cout << posAContainer.valueFirst << " " << posAContainer.valueSecond << "\n";
	}
	cout << "\n\n";
	
	
	// перебор всех записей "pos" в порядке убывания
	Container posBContainer;
	bool posB = fixMax("pos", posBContainer);
	if(posB) {
		cout << posBContainer.m["xxx"] << " " << posBContainer.m["yyy"] << " : ";
		cout << posBContainer.valueFirst << " " << posBContainer.valueSecond << "\n";
	}
	Container posBufB;
	while(fixPrev("pos", posBContainer.m, posBufB) == true) {
		posBContainer = posBufB;
		cout << posBContainer.m["xxx"] << " " << posBContainer.m["yyy"] << " : ";
		cout << posBContainer.valueFirst << " " << posBContainer.valueSecond << "\n";
	}
	cout << "\n\n";
	
	// ****************************************************************
	// ****************************************************************
	
	cout << "All tests OK !!!  \n";
	
	cout << "\n\n";
	system("pause");
	return 0;
}


