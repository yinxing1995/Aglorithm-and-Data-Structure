#include <characters.h>

list<Author> catalog['Z'+1];
list<Patron> people['Z'+1];

char *getString(const char *msg)
{
    cout << msg << endl;
    char s[20];
    cin.getline(s, 21);
    char *string = new char[strlen(s)+1];
    strcpy(string, s);
    return string;// do not forget to delete.
}


void includeBook()
{
    char *authorName;
    authorName = getString("Input the author's name");
    char *bookName;
    bookName = getString("Input the book title");

    Author NewAuthor;
    Book NewBook;
    NewAuthor.name = authorName;
    NewBook.title = bookName;
    int name = authorName[0];
    list<Author>::iterator oldAuthor = find(catalog[name].begin(), catalog[name].end(), NewAuthor);
    if(oldAuthor != catalog[name].end())
    {
        oldAuthor->books.push_front(NewBook);
        delete[] authorName;
    }
    else
    {
        NewAuthor.books.push_front(NewBook);
        catalog[name].push_front(NewAuthor);
    }
}

void checkOutBook()
{
    Patron patron;
    Author author;
    Book book;
    patron.name = getString("Input the patron's name");
    int patron_name = patron.name[0];
    list<Patron>::iterator patronRef = find(people[patron_name].begin(), people[patron_name].end(), patron);
    if(patronRef == people[patron_name].end())
    {
        people[patron_name].push_front(patron);
    }
    else
    {
        delete[] patron.name;
    }
   author.name = getString("Input the author's name");
   int author_name = author.name[0];
   list<Author>::iterator authorRef = find(catalog[author_name].begin(), catalog[author_name].end(), author);
   if(authorRef != catalog[author_name].end())
   {
       book.title = getString("Input the title of book");
       list<Book>::iterator bookRef = find(authorRef->books.begin(), authorRef->books.end(), book);
       if(bookRef != authorRef->books.end())
       {
           bookRef->patron = &*patronRef;
           class CheckedOutBook checkOutBook(authorRef, bookRef);
           patronRef->books.push_front(checkOutBook);
       }
       else
       {
           cout << "Book not existed" << endl;
       }
       delete[] book.title;
   }
   else
   {
       cout << "Author not existed" << endl;
   }
   delete[] author.name;
}

void returnBook()
{
    Patron patron;
    Author author;
    Book book;
    patron.name = getString("Input the patron's name");
    int patron_name = patron.name[0];


    list<Patron>::iterator patronRef = find(people[patron_name].begin(), people[patron_name].end(), patron);
    if(patronRef == people[patron_name].end())
    {
        cout << "Patron or author not existed" << endl;
        delete[] patron.name;
        return;
    }

    author.name = getString("Input the author's name");
    int author_name = author.name[0];
    book.title = getString("Input the title of book");
    list<Author>::iterator authorRef = find(catalog[author_name].begin(), catalog[author_name].end(), author);
    list<Book>::iterator bookRef = find(authorRef->books.begin(), authorRef->books.end(), book);
    if(authorRef == catalog[author_name].end() || bookRef == authorRef->books.end())
    {
        cout << "Author or book not found" << endl;
        delete[] author.name;
        delete[] book.title;
        delete[] patron.name;
        return ;
    }

    CheckedOutBook chenckedoutbook(authorRef, bookRef);
    list<CheckedOutBook>::iterator chenckedoutbookRef = find(patronRef->books.begin(), patronRef->books.end(), chenckedoutbook);
    if(chenckedoutbookRef == patronRef->books.end())
    {
        cout << "This patron hasn't borrowed this book" << endl;
    }
    else
    {
        *&bookRef->patron = NULL;
        patronRef->books.erase(chenckedoutbookRef);
        cout << "Book returned" << endl;
    }
    delete[] author.name;
    delete[] book.title;
    delete[] patron.name;
    return;
}

void status()
{
    for(int i = 'A'; i<='Z'; i++)
    {
        if(catalog[i].empty())continue;
        for(list<Author>::iterator j = catalog[i].begin(); j != catalog[i].end(); j++)
        {
            cout << "Author__" << j->name << endl;
            if(j->books.empty())continue;
            for(list<Book>::iterator q = j->books.begin(); q != j->books.end(); q++)
            {
                cout << "Book__" << q->title;
                if(q->patron != NULL)cout << " booked by" << q->patron->name;
                cout << endl;
            }
        }
    }
}
