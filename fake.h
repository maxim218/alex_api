// ����� - ���������� ������

// ���������� ����������
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
// ������������ ����
using namespace std;

// ����� ��� �������� ��������
class Structure {
	protected:
		// ��������� ��� �������� �������� �����
		struct keyStruct {
			// �������� �����
			string nameKey;
			// ������ ����� � �����
			int sizeKey;
		};
		
		// �������� ���������
		string structName;
		
	public:	
		// ������ ������
		vector <keyStruct> v;
	
		// �����������
		Structure(string structNameParam) {
			// ������ ��� ���������
			structName = structNameParam;
		}
		
		string getStructName() {
			return structName;
		}
		
		// ���������� �������� ������ ����� ���������
		void addKey(string nameKeyParam, int sizeKeyParam) {
			// ������� ������ - ����
			keyStruct key;
			// ������ ���� ������
			// �������� �����
			key.nameKey = nameKeyParam;
			// ������ ����� � �����
			key.sizeKey = sizeKeyParam;
			// ��������� ���� � ������ ������
			v.push_back(key);
		}
		
		// ����� �� ����� ����������� ���������
		void renderStructure() {
			cout << "\n\n";
			cout << "==================================";
			cout << "\n";
			// ����� ����� ���������
			cout << "Struct name: " << structName << "\n";
			cout << "\n";
			// ����� ������ ���������
			cout << "Keys: " << "\n";
			// ����������� �� ������� ������
			for(int i = 0; i < v.size(); i++) {
				cout << "\n";
				// ������� �������� �����
				cout << "Name: " << v[i].nameKey << "\n";
				// ������� ������ ����� � �����
				cout << "Size: " << v[i].sizeKey << "\n";
			}
			cout << "==================================";
			cout << "\n\n";
		}
};

// ������ ��� �������� ������������ ��������
vector <Structure> structVector;

// ��������� ��������� � ������ ��������
void fixStructure(Structure structure) {
	// ��������� ��������� � ����� ������� ��������
	structVector.push_back(structure);
	// ������� �������� ��������� �� �����
	structure.renderStructure();
}

// ��������� ������
void error(string s) {
	// ����� ����������� ������
	cout << "\n\n\n" << "Error: " << s << "\n\n\n";
	// �������� ������
	throw;
}

// ������� ��� �������� ������������� ����� � ���������
void controlKeyName(string structName, string keyName) {
	// ���������� ��� ���� ��������
	for(int i = 0; i < structVector.size(); i++) {
		// ���� ��� ��������� �� ��������� ��������� � ������ i-�� ���������
		if(structName == structVector[i].getStructName()) {
			// �������� ������ � i-��� ���������
			Structure structure = structVector[i];
			// ���������� ��� ����� ���������
			for(int k = 0; k < structure.v.size(); k++) {
				// ���� k-�� ���� ��������� � ������� ������, �� �������
				if(structure.v[k].nameKey == keyName) return;
			}
		}
	}
	// ���� ���������� �� �������, �� ���������� ������
	error("field '" + keyName + "' not exists in structure '" + structName + "'");
}

// ��������� ��� �������� �������� ����� � ��� ��������
struct keyStruct {
	// �������� �����
	string keyName;
	// �������� �����
	string keyValue;
};

// ����� ��� ���������� �������� ������ ���������� ���������
class Inserter {
	protected:
		// ��� ���������
		string structName;
	
	public:
		// ������ ��� ������� ������
		vector <keyStruct> v;
		// ��� �������� � ��������� ��������
		int valueFirst;
		int valueSecond;
		
		// �����������
		Inserter(string structNameParam) {
			// ������ ��� ���������
			structName = structNameParam;
		}
		
		// ����� ��� ��������� ����� ���������
		string getStructName() {
			// ���������� ��� ���������
			return structName;
		}
		
		// ����� ��� ������� ���� �������� ���������
		void setValues(int valueFirstParam, int valueSecondParam) {
			// ������ ������ ��������
			valueFirst = valueFirstParam;
			// ������ ������ ��������
			valueSecond = valueSecondParam;
		}
		
		// ��������� ���� � ����� �������
		void addKeyValue(string keyNameParam, string keyValueParam) {
			// �������� ������������� ����
			controlKeyName(structName, keyNameParam);
			// ������� ����
			keyStruct key;
			// ������ �������� �����
			key.keyName = keyNameParam;
			// ������ �������� �����
			key.keyValue = keyValueParam;
			// ��������� ���� � ����� �������
			v.push_back(key);
		}
		
		// ����� ��� �������� ���������� ���������� ������
		// �������������� ������� "����������"
		void removeMe() {
			// �������� ��� ���������
			structName = "____it_is_removed_element____";
			// ����������� �� ������� ������
			for(int i = 0; i < v.size(); i++) {
				// �������� �������� �����
				v[i].keyName = "____it_is_removed_element____";
				// �������� �������� �����
				v[i].keyValue = "____it_is_removed_element____";
			}
		}
		
		// ������� ���������� ����������� ������ �� �����
		void renderInserter() {
			cout << "\n\n";
			cout << "********************************";
			cout << "\n";
			// ������� �� ����� ��� ���������
			cout << "Struct name: " << structName << "\n";
			cout << "\n";
			// ����� ������ ���������
			cout << "Keys: " << "\n";
			// ����������� �� ������� ������
			for(int i = 0; i < v.size(); i++) {
				cout << "\n";
				// ����� �������� �����
				cout << "Key: " << v[i].keyName << "\n";
				// ����� �������� �����
				cout << "Value: " << v[i].keyValue << "\n";
			}
			cout << "\n";
			// ����� ���� �������� � ������ ��������
			cout << "Values: " << "\n";
			cout << "\n";
			// ����� ������� �������� � ������
			cout << "First: " << valueFirst << "\n";
			// ����� ������� �������� � ������
			cout << "Second: " << valueSecond << "\n";
 			cout << "********************************";
			cout << "\n\n";
		}	
};

// �������������� �� ����� � ������
template <typename tip>
string makeString(tip x){
    ostringstream oss;
    oss << x;
    return oss.str();
}

// ������� ��������� ���� �������� ������
bool compareKeys(vector <keyStruct> vAAA, vector <keyStruct> vBBB) {
	// ���� ���������� ������ �� ���������
	if(vAAA.size() != vBBB.size()) {
		// ������ ���������� ������
		// ��������� ������� �������� � ������
		string sFirst = makeString( vAAA.size() );
		string sSecond = makeString( vBBB.size() );
		// ���������� ������
		error("not equal number of keys (" + sFirst + " and " + sSecond + ")");
	}
	// ����������� �� ������� ������� ������
	for(int i = 0; i < vAAA.size(); i++)
		// ����������� �� ������� ������� ������
		for(int j = 0; j < vBBB.size(); j++)
			// ���� ����� ������ ���������
			if(vAAA[i].keyName == vBBB[j].keyName)
				// ���� �������� � ������ ������ 
				if(vAAA[i].keyValue != vBBB[j].keyValue)
					// ������� ������ �� ����������
					return false;
	// ������� ������ ����������
	return true;
}

// ������ ��� �������� ������������ ����������� �������
vector <Inserter> inserterVector;

// ���������� ������ ���������� ������
void fixInserter(Inserter inserter) {
	// ����������� �� ������� ������������ �������
	for(int i = 0; i < inserterVector.size(); i++) {
		// ���� ������ � ������� � ����������� ������ ����� ���������� ���
		if(inserterVector[i].getStructName() == inserter.getStructName()) {
			// ���� � ������� ��������� ��� �����
			if(compareKeys(inserterVector[i].v, inserter.v) == true) {
				// �������� ������ � �������
				inserterVector[i] = inserter;
				// ������� �� ����� ���������� ����������� ������
				inserter.renderInserter();
				// ������� �� �������
				return;
			}
		}	
	}
	// ���� �� ���������� �� ����������
	// ��������� ����� ������ � ����� �������
	inserterVector.push_back(inserter);
	// ������� �� ����� ���������� ����������� ������
	inserter.renderInserter();
}

// ����� ��� ������ ���������� ������ �� ������
class Selector {
	protected:
		// ������ ��� �������� ������
		vector <keyStruct> v;
		// ��� ���������
		string structName;
		
	public:
		// �����������
		Selector(string structNameParam) {
			// ������ ��� ���������
			structName = structNameParam;
		}
		
		// ���������� ����� � ������ ������
		void addKeyValue(string keyNameParam, string keyValueParam) {
			// �������� ������������� ����
			controlKeyName(structName, keyNameParam);
			// ������� ����
			keyStruct key;
			// ������ ��� �����
			key.keyName = keyNameParam;
			// ������ �������� �����
			key.keyValue = keyValueParam;
			// ��������� ���� � ������ ������
			v.push_back(key);
		}
		
		// ����� ������
		bool startSelect(int &valueFirst, int &valueSecond) {
			// ��������� ������������� �������� ������� ������
			valueFirst = 0;
			valueSecond = 0;
			// ���������� ��� �������� ������� ������������ �������
			for(int i = 0; i < inserterVector.size(); i++) {
				// �������� i-�� ������� �������
				Inserter inserter = inserterVector[i];
				// ���� ��� ��������� i-�� �������� ��������� � ������ ��������� ������� ������
				if(inserter.getStructName() == structName) {
					// ���������� �� �����
					bool r = compareKeys(v, inserter.v);
					// ���� ��� ����� ���������
					if(r == true) {
						// ������ ������ ��������
						valueFirst = inserter.valueFirst;
						// ������ ������ ��������
						valueSecond = inserter.valueSecond;
						// ���������� ���� - ������ ������� �������
						return true;
					}
				}
			}
			// ���������� ���� - ������ �� �������
			return false;
		}
};

// ����� ������
bool fixSelector(Selector selector, int &valueFirst, int &valueSecond) {
	// �������� ����� ������ ������
	bool flag = selector.startSelect(valueFirst, valueSecond);
	// ���������� ���� (������� ��� �� �������)
	return flag;
}

// ������� ��������� ���������� ������������ ������� ������������� ����
int fixPower(string structName) {
	// �������� �������
	int count = 0;
	// ���������� ��� ������������ ������
	for(int i = 0; i < inserterVector.size(); i++) {
		// ���� ��� ��������� � ������� ��������� � ������ ��������� �� ���������
		if(inserterVector[i].getStructName() == structName) {
			// ����������� �������
			++count;
		}
	}
	// ���������� ���������� ������� ������������� ����
	return count;
}

// ����� ��� �������� ������������ ������
class Remover {
	protected:
		// ������ ������
		vector <keyStruct> v;
		// ��� ���������
		string structName;
		
	public:
		// ����������
		Remover(string structNameParam) {
			// ������� ����� ���������
			structName = structNameParam;
		}
		
		// ���������� ����� � ������ ������
		void addKeyValue(string keyNameParam, string keyValueParam) {
			// �������� ������������� ����
			controlKeyName(structName, keyNameParam);
			// ������� ����
			keyStruct key;
			// ������ ��� �����
			key.keyName = keyNameParam;
			// ������ �������� �����
			key.keyValue = keyValueParam;
			// ��������� ���� � ������ ������
			v.push_back(key);
		}
		
		// ����� ��� �������� ������
		bool removeRecord() {
			// ����������� �� ������� ������������ �������
			for(int i = 0; i < inserterVector.size(); i++) {
				// �������� i-�� ������
				Inserter inserter = inserterVector[i];
				// ���� ��� ��������� i-�� ������ ��������� � ������ ������ �� ���������
				if(inserter.getStructName() == structName) {
					// ���������� �����
					bool r = compareKeys(v, inserter.v);
					// ���� �������� ������ ���������
					if(r == true) {
						// ������� ������ ������� ����������
						inserterVector[i].removeMe();
						// ���������� ���� - ������ ������� �������
						return true;
					}
				}
			}
			// ���������� ���� - ������ �� ������� (������ ������� �������������� ������)
			return false;
		}
};

// ������� ��� �������� ������
bool fixRemove(Remover &remover) {
	// �������� ������� ������
	bool flag = remover.removeRecord();
	// ���������� ���� �������� ������ (������� ��� �� �������)
	return flag;
}

// ��������� ��� ��������� ����������� ���������� ������
struct Container {
	// ������� � ������� � �� ����������
	map <string, string> m;
	// ��� �������� � ������ ��������
	int valueFirst;
	int valueSecond;
};

// ��������� ������������ ���������� ������
bool fixMin(string structNameParam, Container &container) {
	// ���������� ��� ������ � ������� ����������� �������
	for(int i = 0; i < inserterVector.size(); i++) {
		// ���� � i-�� �������� ��������� ��� ��������� � ������� ����������
		if(inserterVector[i].getStructName() == structNameParam) {
			// �������� i-�� �������
			Inserter inserter = inserterVector[i];
			// �������� �������� ��������
			container.valueFirst = inserter.valueFirst;
			container.valueSecond = inserter.valueSecond;
			// ���������� ��� �����
			for(int k = 0; k < inserter.v.size(); k++) {
				// �������� ��� �����
				string key = inserter.v[k].keyName;
				// �������� �������� �����
				string value = inserter.v[k].keyValue;
				// ��������� ���� �� ��������� � �������
				container.m[key] = value;
			}
			// ������� ������ �������
			return true;
		}
	}
	// ������ �� �������
	return false;
}

// ��������� ������������� ���������� ������
bool fixMax(string structNameParam, Container &container) {
	// ���������� �������� � ������� �������� �������
	for(int i = inserterVector.size() - 1; i >= 0; i--) {
		// ���� � i-�� �������� ��������� ��� ��������� � ������� ����������
		if(inserterVector[i].getStructName() == structNameParam) {
			// �������� i-�� �������
			Inserter inserter = inserterVector[i];
			// �������� �������� ��������
			container.valueFirst = inserter.valueFirst;
			container.valueSecond = inserter.valueSecond;
			// ���������� ��� �����
			for(int k = 0; k < inserter.v.size(); k++) {
				// �������� ��� �����
				string key = inserter.v[k].keyName;
				// �������� �������� �����
				string value = inserter.v[k].keyValue;
				// ��������� ���� �� ��������� � �������
				container.m[key] = value;
			}
			// ������� ������ �������
			return true;
		}
	}
	// ������ �� �������
	return false;
}

// ������� ��������� ���������� ��������
bool fixNext(string structNameParam, map <string, string> d, Container &result) {
	// ������ ��� �������� ������ ������ � ������� �� ������� "d"
	int index = -1;
	
	// ���������� ��� ������������ ������ � ������� ������������ �������
	for(int i = 0; i < inserterVector.size(); i++) {
		// ���� � ������ ���������� ��������
		if(inserterVector[i].getStructName() == structNameParam) {
			// �������� ������ � i-��� ������
			Inserter inserter = inserterVector[i];
			// ��������� ��� �������� ������ �� ����������
			Container container;
			// ����������� �� ���� ������ ������
			for(int k = 0; k < inserter.v.size(); k++) {
				// �������� ��� �����
				string key = inserter.v[k].keyName;
				// �������� �������� �����
				string value = inserter.v[k].keyValue;
				// ��������� ���� � ���������
				container.m[key] = value;
			}
			// ���� - ���������� ������������, ��� ����� �� ��������� ��������� � ������� ������ ������
			bool equal = true;
			// ���������� ��� ����� �� �������, ����������� � �������� ��������� �������
			for(map <string, string> :: iterator iter = d.begin(); iter != d.end(); iter++) {
				// �������� ��� �����
				string key = (*iter).first;
				// ���� �������� �� ����� �� ���������
				if(d[key] != container.m[key]) {
					// �������� ������ �� ���������
					equal = false;
				}
			}
			// ���� ����� �� ���������, �� ��������� � �������� ��������� ������
			if(equal == false) continue;
			// ���� ����� �������
			if(equal == true) {
				// ��������� ����� ������
				index = i;
				// ������� �� �����
				break;
			}
		}
	}
	
	// ���� ����� ���������� ������ �� ������
	if(index == -1) {
		// ��������� �� ������
		return false;
	}
	
	// ���������� ��� �������� � ������� ����������� �������
	// �������� ������� �� ���������� ����� ���������� � ���������� �����
	for(int i = index + 1; i < inserterVector.size(); i++) {
		// ���� ����� �������� ���������
		if(inserterVector[i].getStructName() == structNameParam) {
			// �������� ������ � i-��� ������
			Inserter inserter = inserterVector[i];
			// ��������� ��� ���������� ����������
			Container container;
			// ��������� �������� ��� ��������
			container.valueFirst = inserter.valueFirst;
			container.valueSecond = inserter.valueSecond;
			// ���������� ��� �����
			for(int k = 0; k < inserter.v.size(); k++) {
				// �������� ��� �����
				string key = inserter.v[k].keyName;
				// �������� �������� � �����
				string value = inserter.v[k].keyValue;
				// ��������� ���� � �������
				container.m[key] = value;
			}
			// �������� ���������� ������ ��� ������ ����������
			result = container;
			// ��������� ������
			return true;
		}
	}
	
	// ��������� �� ������
	return false;
}

// ������� ��������� ����������� ��������
bool fixPrev(string structNameParam, map <string, string> d, Container &result) {
	// ������ ��� �������� ������ ������ � ������� �� ������� "d"
	int index = -1;
	
	// ���������� ��� ������������ ������ � ������� �������� �������
	for(int i = inserterVector.size() - 1; i >= 0; i--) {
		// ���� � ������ ���������� ��������
		if(inserterVector[i].getStructName() == structNameParam) {
			// �������� ������ � i-��� ������
			Inserter inserter = inserterVector[i];
			// ��������� ��� �������� ������ �� ����������
			Container container;
			// ����������� �� ���� ������ ������
			for(int k = 0; k < inserter.v.size(); k++) {
				// �������� ��� �����
				string key = inserter.v[k].keyName;
				// �������� �������� �����
				string value = inserter.v[k].keyValue;
				// ��������� ���� � ���������
				container.m[key] = value;
			}
			// ���� - ���������� ������������, ��� ����� �� ��������� ��������� � ������� ������ ������
			bool equal = true;
			// ���������� ��� ����� �� �������, ����������� � �������� ��������� �������
			for(map <string, string> :: iterator iter = d.begin(); iter != d.end(); iter++) {
				// �������� ��� �����
				string key = (*iter).first;
				// ���� �������� �� ����� �� ���������
				if(d[key] != container.m[key]) {
					// �������� ������ �� ���������
					equal = false;
				}
			}
			// ���� ����� �� ���������, �� ��������� � �������� ��������� ������
			if(equal == false) continue;
			// ���� ����� �������
			if(equal == true) {
				// ��������� ����� ������
				index = i;
				// ������� �� �����
				break;
			}
		}
	}
	
	// ���� ����� ���������� ������ �� ������
	if(index == -1) {
		// ��������� �� ������
		return false;
	}
	
	// ���������� ��� �������� � ������� �������� �������
	// �������� ������� � ����������� �� ���������� � ���������� �����
	for(int i = index - 1; i >= 0; i--) {
		// ���� ����� �������� ���������
		if(inserterVector[i].getStructName() == structNameParam) {
			// �������� ������ � i-��� ������
			Inserter inserter = inserterVector[i];
			// ��������� ��� ���������� ����������
			Container container;
			// ��������� �������� ��� ��������
			container.valueFirst = inserter.valueFirst;
			container.valueSecond = inserter.valueSecond;
			// ���������� ��� �����
			for(int k = 0; k < inserter.v.size(); k++) {
				// �������� ��� �����
				string key = inserter.v[k].keyName;
				// �������� �������� � �����
				string value = inserter.v[k].keyValue;
				// ��������� ���� � �������
				container.m[key] = value;
			}
			// �������� ���������� ������ ��� ������ ����������
			result = container;
			// ��������� ������
			return true;
		}
	}
	
	// ��������� �� ������
	return false;
}


