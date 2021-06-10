#include <iostream>
#include <stdexcept>
using namespace std;

/*
    * The notation of an exception is provided to help get information from the point 
        where an error is detected to a point where it can be handled.
    
    * A function that cannot cope with a problem throws an exception,
        hoping that its direct or indirect  caller can handle the problem.

    * A called component that cannot complete its assigned tast reports its failure to do so 
        by throwing an exception using a throw-expression
*/

int do_task()
{

    if (/* could perform the task*/)
        return result;
    else
        throw Some_error{};
}

void taskamster()
{
    try
    {
        auto result = do_task();
        // use result
    }
    catch (Some_error)
    {
        // failure to do_task : handle problem
    };
}

/*
    THE STANDARD LIBRARY : provides a small hierarchy of exception classes with a common
    base exception
*/
void f()
{
    try
    {
        throw E{};
    }
    catch (H)
    {
        // when do we get here
    }
};
void m()
{
    try
    {
        // do something
    }
    catch (std::exception &err) // handle every std-lib exception
    {
        // cleanup
        throw;
    };
};

// Multiple Handlers
void ff()
{
    try
    {
    }
    catch (std::ios_base::failure)
    {
        // handle any iosream error
    }
    catch (std::exception &e)
    {
        // handle any standard-lib exception
    }
    catch (...)
    {
        // handle any other exception
    }
    catch (std::bad_cast)
    {
        // handle dynamic_Cast failure
    }
};
