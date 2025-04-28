#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Invalid arguments!" << std::endl;
        return (1);
    }
    std::ifstream infile(argv[1]);
    if (!infile.is_open())
    {
        std::cout << "Invalid file name!" << std::endl;
        return (1);
    }
    std::ofstream outfile((std::string)argv[1] + ".replace");
    if (!outfile.is_open())
    {
        std::cout << "Cannot create new file!" << std::endl;
        return (1);
    }
    std::string line;
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    size_t occ;
    while (getline(infile, line)) 
    {
        occ = line.find(s1);
        while (occ != std::string::npos) 
        {
            line.erase(occ, s1.length());
            line.insert(occ, s2);
            occ = line.find(s1, occ + s2.length());
        }
        outfile << line << std::endl;
    }
    outfile.close();
    infile.close();
    return (0);
}
