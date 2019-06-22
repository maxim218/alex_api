// ����� - ���������� ������

// ����������
#include "fake.h"
// ������������ ����
using namespace std;

int main() {
	// ������ ��� �������� ��������� � ������� ����� ������
	Structure manStruct("man");
	// ���������� ����� ������ � ���������
	manStruct.addKey("name", 3072);
	manStruct.addKey("surname", 4096);
	manStruct.addKey("age", 128);
	// �������� ��������� ����������
	fixStructure(manStruct);
	
	// ****************************************************************
	
	// ������ ��� ���������� ����� ������
	Inserter manA("man");
	// ����� ����� � �� ��������
	manA.addKeyValue("name", "Maxim");
	manA.addKeyValue("surname", "Kolotovkin");
	manA.addKeyValue("age", "21");
	// ������ ��� �������� ��������
	manA.setValues(100, 200);
	// �������� ������ ����������
	fixInserter(manA);
	
	// ****************************************************************
	
	// ������ ��� ���������� ����� ������
	Inserter manB("man");
	// ����� ����� � �� ��������
	manB.addKeyValue("name", "Alex");
	manB.addKeyValue("surname", "Ivanov");
	manB.addKeyValue("age", "17");
	// ������ ��� �������� ��������
	manB.setValues(450, 550);
	// �������� ������ ����������
	fixInserter(manB);
	
	// ****************************************************************
	
	// ������ ��� ���������� ����� ������
	Inserter manC("man");
	// ����� ����� � �� ��������
	manC.addKeyValue("name", "George");
	manC.addKeyValue("surname", "Petrov");
	manC.addKeyValue("age", "42");
	// ������ ��� �������� ��������
	manC.setValues(123, 456);
	// �������� ������ ����������
	fixInserter(manC);
	
	// ****************************************************************
	
	// ������ ��� ������ ������ �� ������ ������
	Selector selectorB("man");
	// ������ ����� �� ����������
	selectorB.addKeyValue("name", "Alex");
	selectorB.addKeyValue("surname", "Ivanov");
	selectorB.addKeyValue("age", "17");
	// ���������� ��� ��������� �������� � ������ ��������
	int v_b_1 = 0;
	int v_b_2 = 0;
	// ��������������� � �����������
	bool flagB = fixSelector(selectorB, v_b_1, v_b_2);
	// ���� ������ �������
	if(flagB) {
		// ������� ���������� �������� ������ �� �����
		cout << "Values:  " << v_b_1 << "  " << v_b_2 << "\n\n";
	} else {
		// ������ �� �������
		cout << "Record not found" << "\n\n";
	}
	
	// ****************************************************************
	
	// ������ ��� ������ ������ �� ������ ������
	Selector selectorA("man");
	// ������ ����� �� ����������
	selectorA.addKeyValue("name", "Maxim");
	selectorA.addKeyValue("surname", "Kolov");
	selectorA.addKeyValue("age", "21");
	// ���������� ��� ��������� �������� � ������ ��������
	int v_a_1 = 0;
	int v_a_2 = 0;
	// ��������������� � �����������
	bool flagA = fixSelector(selectorA, v_a_1, v_a_2);
	// ���� ������ �������
	if(flagA) {
		// ������� ���������� �������� ������ �� �����
		cout << "Values:  " << v_a_1 << "  " << v_a_2 << "\n\n";
	} else {
		// ������ �� �������
		cout << "Record not found" << "\n\n";
	}
	
	// ****************************************************************
	
	// ���������� ����������
	// ������ ��� ���������� ��� ������������ ������
	Inserter manQ("man");
	// ����� ����� � �� ��������
	manQ.addKeyValue("name", "Alex");
	manQ.addKeyValue("surname", "Ivanov");
	manQ.addKeyValue("age", "17");
	// ������ ��� �������� ��������
	manQ.setValues(7000, 8000);
	// �������� ������ ����������
	fixInserter(manQ);
	
	// ****************************************************************
	
	// ������ ��� ������ ������ �� ������ ������
	Selector selectorQ("man");
	// ������ ����� �� ����������
	selectorQ.addKeyValue("name", "Alex");
	selectorQ.addKeyValue("surname", "Ivanov");
	selectorQ.addKeyValue("age", "17");
	// ���������� ��� ��������� �������� � ������ ��������
	int v_q_1 = 0;
	int v_q_2 = 0;
	// ��������������� � �����������
	bool flagQ = fixSelector(selectorQ, v_q_1, v_q_2);
	// ���� ������ �������
	if(flagQ) {
		// ������� ���������� �������� ������ �� �����
		cout << "Values:  " << v_q_1 << "  " << v_q_2 << "\n\n";
	} else {
		// ������ �� �������
		cout << "Record not found" << "\n\n";
	}
	
	// ****************************************************************
	
	// �������� ���������� ������� ���� "man"
	int numberMan = fixPower("man");
	// ������� ���������� �� �����
	cout << "Man number:  " << numberMan << "\n\n";
	
	// ****************************************************************
	
	// �������� ������
	// ������ ��� �������� ������������ ������
	Remover removerC("man");
	// ������ ����� �� ����������
	removerC.addKeyValue("name", "George");
	removerC.addKeyValue("surname", "Petrov");
	removerC.addKeyValue("age", "42");
	// ���������� � ���������� ��� �������� ������
	bool flagRemoveC = fixRemove(removerC);
	// ���� �������� ������ �������
	if(flagRemoveC == true) {
		// ����� ��������� �� �������� ��������
		cout << "Deleting of record OK" << "\n\n";
	} else {
		// ������ �� ����������
		// ������ ������� �������������� ������
		cout << "Record was not found" << "\n\n";
	}
	
	// ****************************************************************
	
	// �������� ���������� ������� ���� "man"
	int numberManAfter = fixPower("man");
	// ������� ���������� �� �����
	cout << "Man number:  " << numberManAfter << "\n\n";
	
	// ****************************************************************
	// ****************************************************************
	
	Structure posStruct("pos");
	posStruct.addKey("xxx", 128);
	posStruct.addKey("yyy", 128);
	fixStructure(posStruct);
	
	
	for(int i = 1; i <= 5; i++) {
		// ��������� ��������� �����
		Inserter posInserter("pos");
		posInserter.addKeyValue("xxx", "x" + makeString(i));
		posInserter.addKeyValue("yyy", "y" + makeString(i));
		posInserter.setValues(i * 10, i * 20);
		fixInserter(posInserter);
		
		// ��������� ���������� ��������
		Inserter manInserter("man");
		manInserter.addKeyValue("name", "man_Name_" + makeString(i));
		manInserter.addKeyValue("surname", "man_Surname_" + makeString(i));
		manInserter.addKeyValue("age", "man_Age_" + makeString(i));
		manInserter.setValues(i * 10 + 5, i * 20 + 5);
		fixInserter(manInserter);
	}
	
	
	// �������� ���������� ������� ������� ����
	cout << "Man number: " << fixPower("man") << "\n\n";
	cout << "Pos number: " << fixPower("pos") << "\n\n\n";
	
	
	// �������� ������� �� ������� "man"
	Container manContainerMin;
	bool manExistsMin = fixMin("man", manContainerMin);
	if(manExistsMin) {
		cout << "Min man: \n";
		cout << "Name: " << manContainerMin.m["name"] << "\n";
		cout << "Surname: " << manContainerMin.m["surname"] << "\n";
		cout << "Age: " << manContainerMin.m["age"] << "\n";
		cout << "Values: " << manContainerMin.valueFirst << " " << manContainerMin.valueSecond << "\n\n\n";
	}
	
	
	// �������� �������� �� ������� "man"
	Container manContainerMax;
	bool maxExistsMax = fixMax("man", manContainerMax);
	if(maxExistsMax) {
		cout << "Max man \n";
		cout << "Name: " << manContainerMax.m["name"] << "\n";
		cout << "Surname: " << manContainerMax.m["surname"] << "\n";
		cout << "Age: " << manContainerMax.m["age"] << "\n";
		cout << "Values: " << manContainerMax.valueFirst << " " << manContainerMax.valueSecond << "\n\n\n";
	}
	
	
	// �������� ������� �� ������� "pos"
	Container posMinContainer;
	bool posExistsMin = fixMin("pos", posMinContainer);
	if(posExistsMin) {
		cout << "Min pos: \n";
		cout << "xxx: " << posMinContainer.m["xxx"] << "\n";
		cout << "yyy: " << posMinContainer.m["yyy"] << "\n";
		cout << "Values: " << posMinContainer.valueFirst << " " << posMinContainer.valueSecond << "\n\n\n";
	}
	
	
	// �������� �������� �� ������� "pos"
	Container posMaxContainer;
	bool posExistsMax = fixMax("pos", posMaxContainer);
	if(posExistsMax) {
		cout << "Max pos: \n";
		cout << "xxx: " << posMaxContainer.m["xxx"] << "\n";
		cout << "yyy: " << posMaxContainer.m["yyy"] << "\n";
		cout << "Values: " << posMaxContainer.valueFirst << " " << posMaxContainer.valueSecond << "\n\n\n";
	}
	
	
	// ������� �������� �������� � ��������� �������������� �������
	Container undefinedContainer;
	bool undefinedMinBool = fixMin("undefinedStruct", undefinedContainer);
	bool undefinedMaxBool = fixMax("undefinedStruct", undefinedContainer);
	if(undefinedMinBool == false) cout << "Record not found" << "\n\n\n";
	if(undefinedMaxBool == false) cout << "Record not found" << "\n\n\n";
	
	
	// ������� ���� ����������� ������ "man" � ������� �����������
	Container manRecord;
	// �������� ����������� ������
	bool interateMan = fixMin("man", manRecord);
	// ���� ����������� ������ ����������
	if(interateMan) {
		// ������� ����� � �������� ������
		cout << manRecord.m["name"] << " " << manRecord.m["surname"] << " " << manRecord.m["age"] << " : ";
		cout << manRecord.valueFirst << " " << manRecord.valueSecond << "\n";
	}
	// ��������������� ���������
	Container bufferManRecord;
	// ���� ��������� ������� ����������
	while(fixNext("man", manRecord.m, bufferManRecord) == true) {
		// �������� ��������� ������
		manRecord = bufferManRecord;
		// ������� ���������� ������ �� �����
		cout << manRecord.m["name"] << " " << manRecord.m["surname"] << " " << manRecord.m["age"] << " : ";
		cout << manRecord.valueFirst << " " << manRecord.valueSecond << "\n";
	}
	cout << "\n\n";
	
	
	// ������� ���� ����������� ������ "man" � ������� ��������
	Container manRecordQ;
	// �������� ������������ ������
	bool iterateManQ = fixMax("man", manRecordQ);
	// ���� ����������� ������ ����������
	if(iterateManQ) {
		// ������� ����� � �������� ������ �� �����
		cout << manRecordQ.m["name"] << " " << manRecordQ.m["surname"] << " " << manRecordQ.m["age"] << " : ";
		cout << manRecordQ.valueFirst << " " << manRecordQ.valueSecond << "\n";
	}
	// ��������������� ���������
	Container bufferManRecordQ;
	// ���� ���������� ������� ����������
	while(fixPrev("man", manRecordQ.m, bufferManRecordQ) == true) {
		// �������� ���������� ������
		manRecordQ = bufferManRecordQ;
		// ������� ���������� ������ �� �����
		cout << manRecordQ.m["name"] << " " << manRecordQ.m["surname"] << " " << manRecordQ.m["age"] << " : ";
		cout << manRecordQ.valueFirst << " " << manRecordQ.valueSecond << "\n";
	}
	cout << "\n\n";
	
	
	// ������� ���� ������� "pos" � ������� �����������
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
	
	
	// ������� ���� ������� "pos" � ������� ��������
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


