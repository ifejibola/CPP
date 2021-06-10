

/*
    * A member can be declared withina namespace definition
        and defined later using the namespace-name :: member-name notation

    * Members of a namespace must be introduced using this notation:
*/

namespace namespace - name{
                          // delaration and definitions
                      };

namespace Parser
{
    double expr(bool); // declaration
    double term(bool);
    double prim(bool);

};

double val = Parser::expr(); //use

double Parser ::expr(bool b) // definition
{
}

/*
    * We cannot declare a new member of a namespace outside a namespace definition using the 
    qualifier syntax. 
*/

void Parser::logical(bool); // error: no logocial() in Parser
double Parser::trem(bool);  // error : no trem() in Parser (misspelling)
double Parser::prim(int);   // error : Parser:: prim() takes a bool argument(wrong type)

/*
    *  A namespace is a scope.
    *   The larger a program is, the more useful namespaces are to express logical separation 
    *       of its parts
    * 
    * The global scope is a namespace and can be explicitly referred to using :: 
    *  
*/
int f(); // global function

int g()
{
    int f; // local variable; hides the global function
    f();   // error: we can't call an int
    ::f(); // OK: call the global function
}