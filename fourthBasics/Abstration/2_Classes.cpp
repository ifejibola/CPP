

/*
    * In-Class initializers
    * Default argumetns to reduce the number of contructors.
    *   We can add initializers to data members:
*/

class Date
{
    int d; // default date
    int m;
    int y;
    // int d {today.d}; // default std date
    // int m{today.m};
    // int y{today.y};

public:
    Date(int, int, int); //day, month, year
    Date(int, int);      // day, month, today's year
    Date(int);           // Day, today's month and year
    Date();              // default Date: today
    Date(const char *);  // date in string representation

    int day() const { return d; }
    int month() const { return m; }
    int year() const;

    void add_year(int n); // add n years
};

int Date::year() const
{
    return ++y; // error: attempt to change member value in const function
};

void f(Date &d, const Date &cd)
{
    int i = d.year(); // OK
    d.add_year(1);    // OK

    int j = cd.year(); // OK
    cd.add_year(1);    /// error: cannot change value of a const Date
};