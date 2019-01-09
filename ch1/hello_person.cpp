#include <iostream>
#include <string>

int main()
{
    std::cout << "Please enter your first name: ";
    std::string name;
    std::cin >> name;
    const std::string greeting {"Hello, " + name + "!"};
    const std::string greeting_bordered {"* " + greeting + " *"};

    const std::string spaces(greeting.size(), ' ');
    const std::string second {"* " + spaces + " *"};
    const std::string first(second.size(), '*');

    std::cout << first << std::endl;
    std::cout << second << std::endl;
    std::cout << greeting_bordered << std::endl;
    std::cout << second << std::endl;
    std::cout << first << std::endl;

    const std::string hello = "Hello"; // this should work (const init literal)
    const std::string message1 = hello + ", world" + "!"; // also works (const init string + literal)

    const std::string exclam = "!"; // works, single character string literal
    //const std::string message2 = "Hello" + ", world" + exclam; // this does not work, why?
    const std::string message3 = exclam + "Hello" + ", world"; // but this works...

    return 0;
}
