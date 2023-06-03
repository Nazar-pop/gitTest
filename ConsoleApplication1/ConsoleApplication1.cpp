#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

class carsInStock;
class car {
	string name;
	string year;
	double volume, price;
public:
	car() : name(""), year(0), volume(0), price(0) {}

	void set() {
		cout << "Enter car name:";
		getline(cin, name);

		cout << "Enter car release year:";
		cin >> year;

		cout << "Enter car release year:";
		(cin >> price).get();
	}

	int get_price()const { return price; }

	void print()const {
		cout << string(50, '-');
		cout << "\n Car name:" << name;
		cout << "\n Car release year: " << year;
		cout << "\n Engine volume: " << volume;
		cout << "\n Car price: " << price << '\n';
		cout << string(50, '-') << "\n";
	}

	friend class carsInStock;
};

class carsInStock {
	vector<car> cars;
public:
	void add() {
		car add_car;
		add_car.set();
		cars.push_back(add_car);
	}

	void remove_car(string del_name) {
		auto it = remove_if(cars.begin(), cars.end(), del_name) {
			return del_name == x.name;
		});
		cars.erase(it, cars.end());
	}

	void sort_price() { sort(cars.begin(), cars.end()); }

	void search_by_carName(string find_name)const {
		for (auto is : cars)
			if (is.name = find_name)
				is.print();
	}

	void print() const {
		for (auto is : cars)
			is.print();
	}
};

bool operator <(const car& x1, const car& x2) {
	return x1.get_price() < x2.get_price();
}

bool operator > (const car& x1, const car& x2) {
	return x1.get_price() > x2.get_price();
}
int main() {
	int choice, i, j = 0; string car_name;
	carsInStock cis;

	cout << "Enter amount of cars:";
	(cin >> i).get();

	while ((j++) < i)
		cis.add();

	while (true) {
		cout << "\n 1 - print info";
		cout << "\n 2- add new car";
		cout << "\n 3 - remove car by name";
		cout << "\n 4 - sort by price ";
		cout << "\n 5 - search car by name\nPress 0 to exit\nYour choice : ";
		(cin >> choice).get();

		if (!choice)
			break;

		switch (choice) {
		case 1:
			cis.print();
			break;
		case 2:
			cis.add();
			break;
		case 3:
			cout << "Enter car name to delete:";
			getline(cin, car_name);

			cis.remove_car(car_name);
			break;
		case 4:
			cis.sort_price();
			break;
		case 5:
			cout << "Enter car name to search: ";
			getline(cin, car_name);

			cis.search_by_carName(car_name);
			break;
		default:
			cout << "Wrong option\n\n";
			break;
		}
	}


	return 0;
}