#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

//Название, режиссер, продолжительность, год выхода, сборы, общепринятный рейтинг
//рейтинг фильмотеки фильма
//пользовательская оценка
//статус
//название, телефон и e-mail службы поддержки ресурса

class FIO {
private:
	string name;
	string surname;
	string patronymic;
public:
	FIO(string _name, string _surname, string _patronymic):
		name(_name), surname(_surname), patronymic(_patronymic){}

	string get_name() const {
		return name;
	}

	string get_surname() const {
		return surname;
	}

	string get_patronymic() const {
		return patronymic;
	}

	FIO& operator=(const FIO& fio) {
		name = fio.get_name();
		surname = fio.get_surname();
		patronymic = fio.get_patronymic();
		return *this;
	}

	bool operator==(const FIO& fio) const {
		return name == fio.get_name() &&
			surname == fio.get_surname() &&
			patronymic == fio.get_patronymic();
	}

	friend ostream& operator<<(ostream& out, const FIO& fio) {
		out << fio.surname << " " <<
			fio.name << " " <<
			fio.patronymic << "\n";
		return out;
	}

	friend std::istream& operator>> (std::istream& in, FIO& fio) {
		in >> fio.surname;
		in >> fio.name;
		in >> fio.patronymic;
		return in;
	}




};

class SupportService {
protected:
	string name;
	string numPhone;
	string e_mail;
public:
	SupportService() :
		name("undefined"), numPhone("undefined"), e_mail("undefined") {}

	SupportService(string _name, string _numPhone, string _e_mail) :
		name(_name), numPhone(_numPhone), e_mail(_e_mail) {}

	SupportService(const class SupportService& sup) :
		name(sup.name), numPhone(sup.numPhone), e_mail(sup.e_mail) {}



	void PrintSupport() {
		cout << "The name of support service: " << name << endl;
		cout << "The phone number: " << numPhone << endl;
		cout << "The e_mail of support service: " << e_mail << endl;
	}
};

class Data {
protected:
	int day;
	int month;
	int year;
	friend class Film;
public:
	Data() :
		day(0), month(0), year(0) {}

	Data(int _day, int _month, int _year) :
		day(_day), month(_month), year(_year) {}

	Data(const class Data& data) :
		day(data.day), month(data.month), year(data.year) {}
};

class Film {
private:
	string title;
	Data date_of_release;
	FIO director;
	string duration;
	int sum_of_money;
	int rating;
public:
	Film(string _title, int _day, int _month, int _year,
		string _name, string _surname, string _patronymic,
		string _duration, int _sum_of_money, int _rating) :
		title(_title), date_of_release(Data(_day, _month, _year)),
		director(FIO(_name, _surname, _patronymic)), duration(_duration),
		sum_of_money(_sum_of_money), rating(_rating) {}

	Film(const class Film& film) :
		title(film.title), date_of_release(film.date_of_release), director(film.director),
		duration(film.duration), sum_of_money(film.sum_of_money), rating(film.rating) {}



};



void main() {

	SupportService* support = new SupportService("Support Service", "+88005623441", "SupService@gmail.com");
	support->PrintSupport();
}