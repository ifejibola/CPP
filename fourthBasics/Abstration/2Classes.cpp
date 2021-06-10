
/*
    * A class is a user-defined type.
    * A class consists of a set of members. The most common kinds of members are data j
    *   members and member functions.
    * Member functions can define the meaning of initialization (creation), copy, move,
    *   and cleanup(destruction).
    * 
    * 
    * Members are accessed using .(dot) for objects and -> (arrow) for pointers.
    * 
    * Operators, such as +, !, and [], can be defined for a class.
    * A class is a namespace containing its members.
    * 
    * A struct is a class where members are by default public.
*/

class X
{
private: // the representation (implementation) is private
    int m;

public:                    // the user interface is public
    X(int i = 0) : m{i} {} //a constructor (initiazlie theh data members m)

    int mf(int i) // a member function
    {
        int old = m;
        m = i;      // set a new value
        return old; // return the old value
    };
};
X var{7}; // a variable of type X, initialized 7

int user(X var, X *ptr)
{
    int x = var.mf(7);  //access using .(dot)
    int y = ptr->mf(9); // access using -> (arrow)
    int z = var.m;      // error: cannot access private member
};

/*
    * Concept of a date using a struct.
*/

struct Date
{ // representation
    int d, m, y;
};

// Avoid this
void init_date(Date &d, int, int, int); // initialize d
void add_year(Date &d, int n);          // add n years to d
void add_month(Date &d, int n);         // add n months to d
void add_day(Date &d, int n);           // add n days to d

/*
    * There is no explicit connection between the data type, Date, and these functions.
        Such a connection can be established by declaring the functions as members :
*/

struct Date1
{
    int d, m, y;

    void init(int dd, int mm, int yy); // initialize
    void add_year(int n);              // add n years
    void add_month(int n);             // add n months
    void add_day(int n);               // add n days
};

/*
    * Function declared within a class definition are called member functions and
        and can be invoked only for a specific variable of the appropriate type
*/
Date1 my_birthday;
void f()
{
    Date1 today;

    today.init(16, 10, 1996);
    my_birthday.init(30, 12, 1950);

    Date1 tomorrow = today;
    tomorrow.add_day(1);
};

/*
    * Different structures can have member functions with the same name, we must
        specify the structure name when defining a member function.
*/
void Date1::init(int dd, int mm, int yy)
{
    d = dd;
    m = mm;
    y = yy;
};
// make a copy(default)
Date1 d1 = my_birthday; // initialization by copy
Date1 d2{my_birthday};  // initialization by copy
// or
void ff(Date1 &d)
{
    d = my_birthday;
}

/*
    Access Control
        Previous Date(Date,Date1) does not specify that those functions should be
        the only ones to depend directly on Date's respresentation

        * And the only ones to directly access objects of class Date.

        * This restriction can be expressed by using a class instead of a struct
*/

class Date2
{
    int d, m, y;

public:
    void init(int dd, int mm, int yy); // initialize

    void add_year(int n);  // add n years
    void add_month(int n); //add n months
    void add_day(int n);   // add n days
};

void Date2::add_year(int n)
{
    y += n;
};

// nonmember functions are barred form using private members
void timewrap(Date2 &d)
{
    d.y -= 200; // error: Date::y is private
};

int main()
{
    Date2 dx;
    dx.m = 3;             //error: m is private
    dx.init(25, 3, 2011); // OK
}