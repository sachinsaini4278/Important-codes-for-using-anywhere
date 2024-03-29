#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// Function to find the number of days
// between given two dates
int daysBetweenDates(string date1, string date2)
{
	stringstream ss(date1 + "-" + date2);
	int year, month, day;
	char hyphen;

	// Parse the first date into seconds
	ss >> year >> hyphen >> month >> hyphen >> day;
	struct tm starttm = { 0, 0, 0, day,
						month - 1, year - 1900 };
	time_t start = mktime(&starttm);

	// Parse the second date into seconds
	ss >> hyphen >> year >> hyphen
		>> month >> hyphen >> day;
	struct tm endtm = { 0, 0, 0, day,
						month - 1, year - 1900 };
	time_t end = mktime(&endtm);

	// Find out the difference and divide it
	// by 86400 to get the number of days
	return abs(end - start) / 86400;
}
std::string getCurrentDate()
{
    time_t t = time(NULL);
    tm* ltm = localtime(&t);
    std::stringstream date;
    date << ltm->tm_mday
         << "-"
         << 1 + ltm->tm_mon
         << "-"
         << 1900 + ltm->tm_year
        //  << " "
        //  << 1 + ltm->tm_hour
        //  << ":"
        //  << 1 + ltm->tm_min
        //  << ":"
        //  << 1 + ltm->tm_sec
        ;
    return date.str();    
}

// Driver code
int main()
{
	string str1 = "2022-03-12";
	string str2 = "2022-03-01";
	cout << daysBetweenDates(str1, str2);
	return 0;
}
