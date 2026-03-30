//
// Coded by Kami I. on 3/30/26.
//

#include "Book.h"
#include <iostream>

using namespace std;

//book info and such
void displayBook (Book b)
{
  cout << "Title: " << b.title << endl;
  cout << "Author: " << b.author << endl;
  cout << "Classification: " << b.classification << endl;
  cout << "Year: " << b.yearPublished << endl;
  cout << "Borrowed Status: " << (b.isBorrowed? "Borrowed" : "Still available") << endl;
}

//book borrowing section
void borrowBook (Book &b)
{
    if (!b.isBorrowed)
    {
     b.isBorrowed = true;
        cout << "Book successfully borrowed\n";
    }
    else
    {
        cout << "Book already borrowed\n";
    }
}

//book returns (NOT MAGAZINES!!!)
void returnBook (Book &b, int currentDay, int currentMonth, int currentYear)
{
 b.isBorrowed = false;

 int lateDays = currentDay - b.dueDay;

 if (lateDays > 0)
 {
  double fine = lateDays * 1.75;
     cout << "Late return. Calculated fine: $" << fine << endl;
 }
 else
 {
  cout << "Returned on time!\n";
 }
}

//setting the due date for the books
void setDueDate (Book &b, int day, int month, int year, string accountType)
{
 int borrowDays;

 if (accountType == "Student")
 {
  borrowDays = 30;
 }
 else if (accountType == "Faculty" || accountType == "Staff")
 {
  borrowDays = 60;
 }
 else
 {
  borrowDays = 30; //default
 }
    b.dueDay = day + borrowDays;
    b.dueMonth = month;
    b.dueYear = year;
}

//extending the person's due date
void extendDueDate (Book &b)
{
 b.dueDay += 10;
    cout << "Due date extended by 10 days. Enjoy!\n";
}



