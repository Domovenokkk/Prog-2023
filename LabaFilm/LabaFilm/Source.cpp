#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>


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
private:
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

	friend ostream& operator<<(ostream& out, const SupportService& sup) {
		out << "Name of service: " << sup.name << "\n" <<
			"Phone number:" << sup.numPhone << "\n" <<
			"E-mail:" << sup.e_mail << "\n";
		return out;
	}
};

class Data {
private:
	int day;
	int month;
	int year;
public:
	Data(int _day, int _month, int _year) :
		day(_day), month(_month), year(_year) {}

	void set_day(int _day) {
		day = _day;
	}

	int get_day() const {
		return day;
	}

	void set_month(int _month) {
		month = _month;
	}

	int get_month() const {
		return month;
	}

	void set_year(int _year) {
		year = _year;
	}

	int get_year() const {
		return year;
	}

	bool operator==(const Data& date) const {
		return day == date.get_day() &&
			month == date.get_month() &&
			year == date.get_year();
	}

	friend ostream& operator<<(ostream& out, const Data& data) {
		out << data.day << "." <<
			data.month << "." <<
			data.year << "\n";
		return out;
	}
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
//	Film(string _title, Data _date_of_release, FIO _director, string _duration,
//		int _sum_of_money, int _rating) :
//		title(_title), date_of_release(_date_of_release), director(_director),
//		duration(_duration), sum_of_money(_sum_of_money), rating(_rating) {}

	Film(string _title, string _duration, int _sum_of_money, int _rating, 
		Data _date_of_release, FIO _director):
		title(_title),  duration(_duration), sum_of_money(_sum_of_money),
		rating(_rating), date_of_release(_date_of_release), director(_director) {}



	string get_title() const {
		return title;
	}

	Data get_data() const {
		return date_of_release;
	}

	FIO get_director() const {
		return director;
	}

	string get_duration() const {
		return duration;
	}

	int get_sum() const {
		return sum_of_money;
	}

	int get_rating() const {
		return rating;
	}

	Film& operator=(const Film& film) {
		title = film.get_title();
		date_of_release = film.get_data();
		director = film.get_director();
		duration = film.get_duration();
		sum_of_money = film.get_sum();
		rating = film.get_rating();
		return *this;
	}

	bool operator==(const Film& film) {
		return title == get_title() &&
			date_of_release == get_data() &&
			director == get_director() &&
			duration == get_duration() &&
			sum_of_money == get_sum() &&
			rating == get_rating();

	}

	//Film& operator=(const Film& film) {
	//	title = film.get_title();
	//	date_of_release = film.get_data();
	//	director = film.get_director();
	//	duration = film.get_duration();
	//	sum_of_money = film.get_sum();
	//	rating = film.get_rating();
	//	return *this;
	//}

	friend ostream& operator<<(ostream& out, const Film& film) {
		out << film.title << " " <<
			film.date_of_release << " " <<
			film.director << " " <<
			film.duration << " " <<
			film.sum_of_money << " " <<
			film.rating << "\n";
		return out;
	}

	friend istream& operator>> (istream& in, Film& film) {
		in >> film.title;
		in >> film.duration;
		in >> film.director;
		return in;
	}

};

class Filmoteka {
private:
	string nameFilmoteka;
	vector<Film> films;
public:
	Filmoteka(string _nameFilmoteka) : nameFilmoteka(_nameFilmoteka) {}

	void AddFilm(const Film film) {
		films.push_back(film);
	}

	string get_nameF() const {
		return nameFilmoteka;
	}

	vector<Film> get_films() const {
		return films;
	}

	Filmoteka& operator=(const Filmoteka& teka) {
		nameFilmoteka = teka.get_nameF();
		films = teka.get_films();
		return *this;
	}

	bool operator==(const Filmoteka& teka) const {
		return nameFilmoteka == teka.get_nameF() &&
			films == teka.get_films();
	}

	friend std::ostream& operator<<(std::ostream& out, const Filmoteka& teka) {
		out << "Welcome to " << teka.get_nameF() << ". Here you can watch films that interest you.\n" <<
			"-----Movies in your film library.-----";

		vector<Film> films = teka.get_films();
		for (int  i = 0; i < films.size(); i++) {
			out << films[i] << "\n";
		}
		
		out << "----------\n";

		return out;
	}
};


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SupportService sup("Support Service", "+79196575674", "supportservice@gmail.com");
	cout << sup;

	Film firstfilm("ABCf", "1:45:22", 10000, 8);
	Data firstdate(29, 01, 2005);
	FIO firstdeirectro("A", "B", "C");

	return 0;

}