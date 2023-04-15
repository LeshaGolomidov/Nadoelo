#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;


class Cars {

public:
	
	Cars(const string& model) : m_model(model) {}
	virtual ~Cars() {}
	virtual void print_mod() = 0;

	const string& get_model() const { return m_model; }


private:
	
	string m_model;
};


class Mercedes : public Cars {

public:
	
	Mercedes(const string& model) : Cars(model) {}
	virtual ~Mercedes() { print_mod(); }
	void print_mod() { cout << "Mercedes" << get_model() << endl; }
};



class Vaz : public Cars {

public:
	
	Vaz(const string& model) : Cars(model) {}
	virtual ~Vaz() { print_mod(); }
	void print_mod() { cout << "Vaz" << get_model() << endl; }
};


class Moskwitch : public Cars {

public:
	
	Moskwitch(const string& model) : Cars(model) {}
	virtual ~Moskwitch() { print_mod(); }
	void print_mod() { cout << "Moskwitch" << get_model() << endl; }

};


int main() {
	vector <shared_ptr <Cars> > car;
	fstream file;
	file.open("cars.txt");

	if (file.is_open()) {

		string name, model;

		while (file >> name >> model) {
				
			if (name == "Mercedes")
				car.push_back(make_shared<Mercedes>(model));
			else if (name == "Vaz")
				car.push_back(make_shared<Vaz>(model));
			else if (name == "Moskwitch")
				car.push_back(make_shared<Moskwitch>(model));
		}
	}

	else
		cout << "-Error-";

	file.close();


	return 0;

}