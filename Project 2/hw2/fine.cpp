#include <iostream>
#include <string>
using namespace std;

int main()
{
	cout << "Defendant: ";  //This prompts the user to type in a name.//
	string personsName;
	getline(cin, personsName);

	if (personsName == "") {  //This checks if the user typed in a name correctly.//
		cout << "You must enter a defendant name.";
		cout << endl;
		return 1;
	}

	cout << "Amount paid (in thousands): ";  //This prompts the user to type in the amount paid for the bribe.//
	double amtpaid;
	cin >> amtpaid;
	cin.ignore(10000, '\n');

	if (amtpaid < 0) {  //This checks if the user typed in a valid number for the amount paid.//
		cout << "The amount paid must not be negative.";
		cout << endl;
		return 1;
	}

	cout << "Fake athlete ? (y / n) : ";  //This prompts the user to answer if the student was a fake athlete or not.//
	string response;
	getline(cin, response);

	if (response != "y" && response != "n") { //This checks if the user typed "y" or "n", which are the valid responses to this question.//
		cout << "You must enter y or n.";
		cout << endl;
		return 1;
	}

	cout << "---" << endl;

	double amtpaid1000 = (amtpaid * 1000); //The following function is the code used to calculate the amount of the fine.//
	double fine = 20000;  //The base amount of the fine is $20 thousand.//
	if (amtpaid1000 < 40000) {
		fine += (0.66 * amtpaid1000);
	}   //For up to the first $40 thousand paid to Stinger, 66% of that amount is added to the fine.//

	if (40000 <= amtpaid1000 && amtpaid1000 <= 250000) {
		fine += (0.66 * 40000);
		if (response == "n") {
			fine += 0.10 * (amtpaid1000 - 40000);
		}
		if (response == "y") {
			fine += 0.22 * (amtpaid1000 - 40000);
		}  // For up to the next $210 thousand paid (beyond the initial $40 thousand), the fine will be increased by of 10% of that additional amount paid. However, if athletic achievement was faked, the addition to the fine will be 22% of that additional amount paid instead of 10%.//

	}
	if (amtpaid1000 > 250000) {
		fine += (0.66 * 40000);
		if (response == "n") {
			fine += 0.10 * (250000 - 40000);
			fine += 0.14 * (amtpaid1000 - 250000);
		}
		if (response == "y") {
			fine += 0.22 * (250000 - 40000);
			fine += 0.14 * (amtpaid1000 - 250000);
		} // A further fine will be imposed in the amount of 14% of the amount paid to Stinger above $250 thousand.//


	}
	fine = fine / 1000.0; //This helps the program display the correct amount in thousands in the final statement.//

	cout.setf(ios::fixed);
	cout.precision(1);  //This displays two decimal places.//


	cout << "The suggested fine for " << personsName << " is $" << fine << " thousand.";
}