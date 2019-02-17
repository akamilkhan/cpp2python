
char const *greet()
{
    return "Welcome to cpp2python Intro!";
}

char const *add_help()
{
    return "int add(int a, int b)";
}

int add(int a, int b)
{
    return a + b;
}

#include <boost/python.hpp>

BOOST_PYTHON_MODULE(cpp2python)
{
    using namespace boost::python;
    def("greet", greet);
    def("add_help", add_help);
    def("add", add);
}