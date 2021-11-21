#include <iostream>
#include <vector>

#include <getopt.h>

std::vector<std::string>* handled_options = new std::vector<std::string>();

void handleHelp()
{
    std::cout << "Option --help (-h) was used." << std::endl;
}

void handleVersion()
{
    std::cout << "Option --version (-v) was used." << std::endl;
}

void handleCreate(char *arg)
{
    std::cout << "Option --create (-i) with value " << arg << " was used." << std::endl;
}

void handleSum(char *arg)
{
    if(arg == nullptr)
    {
        std::cout << "Option --sum (-s) with no optional value was used." << std::endl;
    }
    else
    {
        std::cout << "Option --sum (-s) with optional value " << arg << " was used." << std::endl;
    }
}

void handleCount()
{
    std::cout << "Option --count (-c) was used." << std::endl;
}

void handleReverse()
{
    std::cout << "Option --reverse (-r) was used." << std::endl;
}

bool isAlreadyHandled(const std::string& option_name)
{
    for(auto &argument : *handled_options)
    {
        if (option_name == argument)
        {
            return true;
        }
    }
    return false;
}

bool isOnlyOne(int options_count, const std::string& option_name)
{
    if(options_count != 2)
    {
        std::cout << "Option --" << option_name << " must be the only one in the list of parameters." << std::endl;
        return false;
    }
    return true;
}

int main(int argc, char **argv)
{
    int current_option;

    const char* short_options = "hvcri:s::";

    struct option long_options[] = {
            {"help",    no_argument, nullptr, 'h'},
            {"version", no_argument, nullptr, 'v'},
            {"create",  required_argument, nullptr, 'i'},
            {"sum",     optional_argument, nullptr, 's'},
            {"count",   no_argument, nullptr, 'c'},
            {"reverse", no_argument, nullptr, 'r'},
            {nullptr, 0, nullptr, 0}
    };

    int option_index = 0;

    while((current_option = getopt_long(argc, argv, short_options, long_options, &option_index)) != -1)
    {
        std::string option_name;

        for(struct option &element : long_options)
        {
            if(element.val == current_option)
            {
                option_name = element.name;
                break;
            }
        }

        if(!(option_name.empty()) && isAlreadyHandled(option_name))
        {
            continue;
        }
        handled_options->push_back(option_name);

        switch(current_option)
        {
            case 'h':
                if(isOnlyOne(argc, option_name))
                {
                    handleHelp();
                }
                break;

            case 'v':
                if(isOnlyOne(argc, option_name))
                {
                    handleVersion();
                }
                break;

            case 'i':
                handleCreate(optarg);
                break;

            case 's':
                handleSum(optarg);
                break;

            case 'c':
                handleCount();
                break;

            case 'r':
                handleReverse();
                break;

            case '?':
                break;

            default:
                abort();
        }
    }

    if(optind < argc)
    {
        std::cout << "Non-option argument values:" << std::endl;
        while(optind < argc)
        {
            std::cout << argv[optind++] << std::endl;
        }
    }
    else
    {
        std::cout << "No non-option argument values have been entered." << std::endl;
    }

    return 0;
}