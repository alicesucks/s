#include <iostream>
using namespace std;

class Overcoat {
	char* type;
	char* color;
	double price;
public:
	Overcoat();
	Overcoat(const char*, const char*, double);
	~Overcoat();
	void Input();
	void Output();
	bool operator == (const Overcoat&);
	Overcoat& operator= (const Overcoat&);
	bool operator>(const Overcoat&);
};
Overcoat::Overcoat() {
	type = nullptr;
	color = nullptr;
	price = 0.0;
}
Overcoat::Overcoat(const char* type, const char* color, double price) {
	this->type = new char[strlen(type) + 1];
	strcpy_s(this->type, strlen(type) + 1, type);
	this->color = new char[strlen(color) + 1];
	strcpy_s(this->color, strlen(color) + 1, color);
	this->price = price;
}
Overcoat::~Overcoat() {
	delete[] type;
	delete[] color;
}
void Overcoat::Input() {
	char buf[30]{ 0 };
	cout << "Enter name: ";
	cin.getline(buf, 30);
	type = new char[strlen(buf) + 1];
	strcpy_s(type, strlen(buf) + 1, buf);
	cout << "Input color of overcoat: ";
	cin.getline(buf, 30);
	color = new char[strlen(buf) + 1];
	strcpy_s(color, strlen(buf) + 1, buf);
	cout << "Input price: ";
	cin >> price;
	cin.ignore();
}
void Overcoat::Output() {
	cout << "Type: " << type << endl;
	cout << "Color: " << color << endl;
	cout << "Price: " << price << endl;
}
bool Overcoat::operator==(const Overcoat& o) {
	int res = strcmp(type, o.type);
	if (res == 0) {
		cout << "Types of overcoats are equal\n";
		return true;
	}
	else return false;
}
Overcoat& Overcoat::operator=(const Overcoat& o) {
	type = new char[strlen(o.type) + 1];
	strcpy_s(type, strlen(o.type) + 1, o.type);
	color = new char[strlen(o.color) + 1];
	strcpy_s(color, strlen(o.color) + 1, o.color);
	price = o.price;
	return*this;
}
bool Overcoat::operator>(const Overcoat& o) {
	if (price > o.price) {
		cout << "Price of overcoat a is bigger than overcoat b\n";
		return true;
	}
	else return false;
}

void main() {

	Overcoat a;
	a.Input();
	a.Output();

	Overcoat b;
	b.Input();
	b.Output();

	//a == b;

	/*a = b;
	a.Output();*/

	a > b;
}