#include <iostream>
#include <list>
#include <cstring>

using StationList = std::list<const char*>;

void printStations(const char* year,const StationList& stations) {

	std::cout << "\n--- Yamanote Line (" << year << ") --- \n";

    std::cout << "Counterclockwise (Inner loop):\n";
	for (const char* station : stations) {
		std::cout << station << '\n';
	}

    std::cout << "Clockwise (Outer loop):\n";
	for (auto it = stations.rbegin(); it != stations.rend(); ++it) {
		std::cout << *it << '\n';
	}
}

void insertBefore(StationList& stations, const char* beforeStation, const char* newStation) {

	for (auto it = stations.begin(); it != stations.end(); ++it) {

		if (std::strcmp(*it, beforeStation) == 0) {

			stations.insert(it, newStation);

			return;
		}
	}
}

int main() {

    StationList stations1970 = {
        "Shinagawa",
        "Tamachi",
        "Hamamatsucho",
        "Shimbashi",
        "Yurakucho",
        "Tokyo",
        "Kanda",
        "Akihabara",
        "Okachimachi",
        "Ueno",
        "Uguisudani",
        "Nippori",
        "Tabata",
        "Komagome",
        "Sugamo",
        "Otsuka",
        "Ikebukuro",
        "Mejiro",
        "Takadanobaba",
        "Shin-Okubo",
        "Shinjuku",
        "Yoyogi",
        "Harajuku",
        "Shibuya",
        "Ebisu",
        "Meguro",
        "Gotanda",
        "Osaki"
    };

    StationList stations2019 = stations1970;
    insertBefore(stations2019,"Tabata","Nishi-Nippori");

	StationList stations2022 = stations2019;
	insertBefore(stations2022, "Tamachi", "Takanawa Gateway");

	printStations("1970", stations1970);
	printStations("2019", stations2019);
	printStations("2022", stations2022);

	return 0;
}