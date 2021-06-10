
// namespace declarations

/*
    When a name is frequentlly used outside its namespace, it can be a bother to
    repeatedly qualify it with its namespace name. CONSIDER:
*/

#include <string>
#include <vector>
#include <sstream>

std::vector<std::string> split(const std::string &s)
{
    // splt s into its whitespace-separated substring

    std::vector<std::string> res;
    std::istringstream iss(s);
    for (std::string buf; iss >> buf;)
        res.push_back(buf);
    return res;
};
/*
    * The repeated qulification std is tedious an ddstracting.
    * To alleviate that we can use a (using-declaration) to say that in this code string means
    *   std::string:
    * 
 * 
*/
using std::string; // use "string"to mean "Std::string"

std::vector<string> split(const string &s)
// split s into its whitespace-separated substrings
{
    std::vector<string> res;
    std::istringstream iss(s);

    for (string buf; iss >> buf;)
        res.push_back(buf);
    return res;
};

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