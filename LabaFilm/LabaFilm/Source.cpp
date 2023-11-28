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
//

class FIO {
	std::string name, surname, lastname;
public:
	FIO() {
		name = "no name";
		surname = "no surname";
		lastname = "no lastname";
	}
	FIO(std::string _name, std::string _surname,
		std::string _lastname) :name(_name), surname(_surname), lastname(_lastname) {}
	FIO(const FIO& a) :name(a.name), surname(a.surname), lastname(a.lastname) {}
	FIO& operator =(FIO& a) {
		if (this != &a) {
			FIO tmp(a);
			this->swap(tmp);
		}
		return *this;
	}
	void swap(FIO& a) {
		std::swap(this->name, a.name);
		std::swap(this->surname, a.surname);
		std::swap(this->lastname, a.lastname);
	}

	friend std::ostream& operator << (std::ostream& out, const FIO& a);
	friend std::istream& operator>>(std::istream& in, FIO& a);
	friend bool operator ==(const FIO& a, const FIO& b) {
		return (a.name == b.name) && (a.surname == b.surname) && (a.lastname == b.lastname);
	}

	string get_name() const{
		return name;
	}
	string get_surname() const {
		return surname;
	}
	string get_lastname() const {
		return lastname;
	}


	FIO& operator=(const FIO& a) {
		name = a.get_name();
		surname = a.get_surname();
		lastname = a.get_lastname();
		return *this;
	}
};

std::ostream& operator << (std::ostream& out, const FIO& a) {
	out << a.name << " " << a.surname << " " << a.lastname;
	return out;
}

std::istream& operator>>(std::istream& input, FIO& a) {
	std::cout << "Input name: ";
	input >> a.name;
	std::cout << "Input surname: ";
	input >> a.surname;
	std::cout << "Input lastname: ";
	input >> a.lastname;
	return input;
}

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
	int day;
	int month;
	int year;
public:
	Data() {
		day = 0;
		month = 0;
		year = 0;
	}

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

	friend ostream& operator<<(ostream& out, const Data& data);
	friend istream& operator>>(istream& input, Data& a);
};

ostream& operator<<(ostream& out, const Data& data) {
	out << data.day << "." <<
		data.month << "." <<
		data.year << "\n";
	return out;
}
istream& operator>>(istream& input, Data& a) {
	std::cout << "Input day: ";
	input >> a.day;
	std::cout << "Input month: ";
	input >> a.month;
	std::cout << "Input year: ";
	input >> a.year;
	return input;
}


enum Genre {Science_fiction, Horror, Documentary, Animated, Thriller, Drama, Comedy, Adventury, None};

class Film {
private:
	string title;
	/*Genre genre;*/
	Data date_of_release;
	FIO director;
	string duration;
	int sum_of_money;
	int rating;
public:
	
	Film() {
		title = "None";
		/*genre = None;*/
		duration = "None";
		sum_of_money = 0;
		rating = 0;
	}

	Film(string _title/*, Genre _genre*/, string _duration, int _sum_of_money, int _rating,
		Data _date_of_release, FIO _director) :
		title(_title)/*, genre(_genre)*/, duration(_duration), sum_of_money(_sum_of_money),
		rating(_rating), date_of_release(_date_of_release), director(_director) {}

	Film(const Film& film) : title(film.title), /*genre(film.genre),*/ duration(film.duration),
		sum_of_money(film.sum_of_money), rating(film.rating), date_of_release(film.date_of_release),
		director(film.director) 
	{}

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

	friend ostream& operator<<(ostream& out, const Film& film);

	friend istream& operator>> (istream& in, Film& film);

	Film& operator=(const Film& film) {
		title = film.get_title();
		date_of_release = film.get_data();
		director = film.get_director();
		duration = film.get_duration();
		sum_of_money = film.get_sum();
		rating = film.get_rating();
		return *this;
	}
};

ostream& operator<<(ostream& out, const Film& film) {
	out << "--" << film.title << "--" << endl;
	/*if (film.genre == Science_fiction) {
		out << "Movie Genre: Science fiction" << endl;
	}
	else if (film.genre == Horror) {
		out << "Movie Genre: Horror" << endl;
	}
	else if (film.genre == Documentary) {
		out << "Movie Genre: Documentary" << endl;
	}
	else if (film.genre == Animated) {
		out << "Movie Genre: Animated" << endl;
	}
	else if (film.genre == Thriller) {
		out << "Movie Genre: Theriller" << endl;
	}
	else if (film.genre == Drama) {
		out << "Movie Genre: Drama" << endl;
	}
	else if (film.genre == Comedy) {
		out << "Movie Genre: Comedy" << endl;
	}
	else if (film.genre == Adventury) {
		out << "Movie Genre: Adventury" << endl;
	}
	else if (film.genre == None) {
		out << "Movie Genre: None" << endl;
	}*/
	out << "Date of release: " << film.date_of_release << endl;
	out << "Director: " << film.director << endl;
	out << "Duration: " << film.duration << endl;
	out << "Fundraising: " << film.sum_of_money << endl;
	out << "Rating: " << film.rating << endl;
	return out;
}
istream& operator>> (istream& in, Film& film) {
	int n = 0;
	cout << "Movie data." << endl;
	cout << "Print the name of movie: ";
	in >> film.title;
	//cout << "Choose a movie genre from the list below: ";
	//cout << "\n1. Science fiction\n2. Horror\n3. Documentary\n4. Animated\n" <<
	//	"5. Thriller\n6. Drama\n7. Comedy\n8. Adventury" << endl;
	//in >> n;
	//if (n == 1) {
	//	film.genre = Science_fiction;
	//}
	//else if (n == 2) {
	//	film.genre = Horror;
	//}
	//else if (n == 3) {
	//	film.genre = Documentary;
	//}
	//else if (n == 4) {
	//	film.genre = Animated;
	//}
	//else if (n == 5) {
	//	film.genre = Thriller;
	//}
	//else if (n == 6) {
	//	film.genre = Drama;
	//}
	//else if (n == 7) {
	//	film.genre = Comedy;
	//}
	//else if (n == 8) {
	//	film.genre = Adventury;
	//}
	//else {
	//	film.genre = None;
	//}
	cout << "Enter the director's initials:\n";
	in >> film.director;
	cout << "Enter the date of release:\n";
	in >> film.date_of_release;
	cout << "Enter the duration of movie:";
	in >> film.duration;
	cout << "Enter the sum of money:";
	in >> film.sum_of_money;
	cout << "Enter the rating of movie:";
	in >> film.rating;





	return in;
}

class Filmoteka {
	int size;
	int capacity;
	Film* list;
public:
	Filmoteka() : size(0), capacity(5) {
		list = new Film[capacity];
	}
	Filmoteka(int _capacity) :
		size(0), capacity(_capacity)
	{
		list = new Film[capacity];
	}
	Filmoteka(const Filmoteka& f) :
		size(f.size), capacity(f.capacity), list(f.list)
	{}
	~Filmoteka() {
		delete[] list;
		list = nullptr;
	}

	void addF(const Film& f) {
		if (size >= capacity) {
			int new_capacity = capacity * 2;
			Film* new_list = new Film[new_capacity];
			for (int i = 0; i < capacity; i++) {
				new_list[i] = list[i];
			}
			delete[] list;
			list = new_list;
			capacity = new_capacity;
		}
		list[size] = f;
		size++;
	}

	Film* get_list() const {
		return list;
	}
	int get_size() {
		return size;
	}

	void Prlist() {
		for (int i = 0; i < size; i++) {
			std::cout << "\n" << i + 1 << ") " << list[i];
		}
	}

	void remove(int _count) {
		int index = _count - 1;
		if (index > size) {
			std::cout << "err";
		}
		else if (index < 0) {
			std::cout << "err";
		}
		else {
			for (int i = index; i < size - 1; i++) {
				list[i] = list[i + 1];
			}
			size--;
		}
	}
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choose = 0;
	Film film;
	Filmoteka F;
	int num = 0;
	int num1 = 0;
	SupportService sup("Support Service", "+79196575674", "supportservice@gmail.com");
	while (true) {
		cout << "Choose an action:\n1. Add film\n2. Check Filmoteka\n3. Remove\n4. Support Service\n5. Exit\n";
		cin >> choose;
		system("cls");
		switch (choose) {
		case 1:
			cin >> film;;
			F.addF(film);
			choose = 0;
			system("cls");
			break;
		case 2:
			F.Prlist();
			cout << "\n";
			system("pause");
			choose = 0;
			system("cls");
			break;
		case 3:
			std::cout << "Input index: ";
			std::cin >> num1;;
			F.remove(num1);
			choose = 0;
			break;
		case 4:
			cout << sup;
			system("pause");
			choose = 0;
			system("cls");
			break;
		case 5:
			return 0;
		}
		system("cls");
	}
	cout << "See you soon.";
	return 0;
}