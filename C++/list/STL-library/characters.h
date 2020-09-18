#include <iostream>
#include <list>
#include <cstring>
#include <algorithm>

#ifndef CHARACTERS_H
#define CHARACTERS_H

using namespace std;

class Patron;
class CheckedOutBook;
class Author;

class Book
{
public:
    char *title;
    Patron *patron; //指向一个具体的patron
    Book()
    {
        patron = NULL;
    }
    bool operator == (const Book& bk) const
    {
        return strcmp(title, bk.title) == 0;
    }
};

class Patron
{
public:
    char *name;
    list<CheckedOutBook> books; //指向一个借出书目的链表
    Patron()
    {}
    bool operator == (const Patron& pr) const
    {
        return strcmp(name, pr.name) == 0;
    }
};

class Author
{
public:
    Author()
    {}
    char *name;
    list<Book> books; //指向一个该作者的书目链表
    bool operator == (const Author& ar) const
    {
        return strcmp(name, ar.name) == 0;
    }
};

class CheckedOutBook
{
public:
    CheckedOutBook(list<Author>::iterator ar,list<Book>::iterator br)
    {
        author = ar;
        book = br;
    }
    list<Author>::iterator author;
    list<Book>::iterator book;
    bool operator == (const CheckedOutBook& cb) const
    {
        return strcmp(author->name , cb.author->name) == 0 && strcmp(book->title , cb.book->title) == 0;
    }
};



char *getString(const char *msg);

void includeBook();
void checkOutBook();
void returnBook();
void status();

#endif // CHARACTERS_H
