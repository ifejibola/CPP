#include <iostream>
#include <string>
#include <vector>
#include <sstream>
/*
    * use a using-directive to request that every name from a namespace be accessible in our
        scope without qualification.
*/

using namespace std; //make every name from std accessible

vector<string> split(const string &s)
//  split s into whitespace-separated substring
{
    vector<string> res;
    istringstream iss(s);
    for (string buf; iss >> buf;)
        res.push_back(buf);
    return res;
};

namespace Graph_lib
{
    class Shape
    {
    };
    class Line : Shape
    {
    };
    class Poly_line : Shape
    {
    }; // connected sequence of lines
    class Text : Shape
    {
    }; // text label

};
namespace Text_lib
{
    class Glyph
    {
    };
    class Word
    {
    }; // sequence of Glyphs
    class Line
    {
    }; // sequence of Words
    class Text
    {
    }; // sequence of Lines

    // File *open(const char *);                   //open text line
    Word operator+(const Line &, const Line &); // concatenate
}

using namespace Graph_lib;
using namespace Text_lib;

Glyph gl;           // Text_lib::Glyph
vector<Shape *> vs; //Graph_lib::Shape

//
namespace A
{
    int f(); // now A has member f()
};

namespace A
{
    int g(); // now A has two members, f() and g()
};
