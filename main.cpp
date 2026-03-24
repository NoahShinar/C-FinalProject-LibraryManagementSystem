// University Library Management System
/*
Write a System in C++ to manage books and magazines in a University. The university library is
accessible to students, faculty and staff. Each person borrowing a book from the library is
assigned a maximum duration in which the loaner either has to return the book or request an
extension of 10 days at a time. All persons must register with the library before starting to
borrow books. Students are allowed to borrow a maximum of 5 books at a time, while faculty
and staff can borrow up to 10 books.

Books in the library are organized according to the Library of Congress Book classification.
Follow the following article for more information:
https://www.loc.gov/catdir/cpso/lcco/
https://en.wikipedia.org/wiki/Library_of_Congress_Classification

The Library system needs to:
• Manage lending and of books and magazines
• Manage returns of books and magazines
• Review and display Members account and List borrowed books
• List borrowed magazines
• Request an extension to a borrowed books
• Adding and removing Members to the library
• Adding and removing books to the library
• Handle fines of $1.75 per day on late books.
 */

#include <iostream>

using namespace std;

int main() {

    int choice;

    while (choice != 7) {
        cout << "1. add member" << endl;
        cout << "2. add book or magazine" << endl;
        cout << "3. borrow book or magazine" << endl;
        cout << "4. return book or magazine" << endl;
        cout << "5. view account" << endl;
        cout << "6. request extention" << endl;
        cout << "7. exit program" << endl;

        cout << "choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // add member
                break;

            case 2:
                cout << "1. book" << endl << "2. magazine" << endl;
                cin >> choice;
                if (choice == 1) {

                }
                if (choice == 2) {

                }
                else {
                    cout << "Invalid choice" << endl;
                }
                break;

            case 3:
                cout << "1. book" << endl << "2. magazine" << endl;
                cin >> choice;
                if (choice == 1) {

                }
                if (choice == 2) {

                }
                else {
                    cout << "Invalid choice" << endl;
                }
                break;

            case 4:
                cout << "1. book" << endl << "2. magazine" << endl;
                cin >> choice;
                if (choice == 1) {

                }
                if (choice == 2) {

                }
                else {
                    cout << "Invalid choice" << endl;
                }
                break;

            case 5:
                // view account
                break;

            case 6:
                // request extention
                break;

            case 7:
                break;

            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }

    return 0;
}