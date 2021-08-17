#include <iostream>
#include <sstream>
#include <cpr/cpr.h>

int main()
{
    cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/html"),
                               cpr::Header({{"accept", "text/html"}}));
    std::string str = r.text;

    std::string::size_type posFirst = str.find("<h1>") + 4;
    std::string::size_type posEnd = str.find("</h1>") - 1;

    if (posFirst == std::string::npos || posEnd == std::string::npos)
    {
        std::cout << "The title of the article is not defined!";
    }
    else std::cout << "The title of the article: " << str.substr(posFirst, posEnd - posFirst + 1);

}