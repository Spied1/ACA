#include <iostream>
#include"matrix.cpp"
#include <fstream>
#include <string>



void write_in_file(std::string file_name, const matrix& matrix)
{
    std::ofstream file(file_name);

    std::string text = matrix.get_string();

    std::cout << text;

    file << text << std::endl;

    file.close();
}



matrix read_file(std::string filename)
{
    
}

int main() {
    matrix first(10,10);
    first.init_matrix();

    std::string filename = "C:/Users/Spied/Desktop/example.txt";

    

    write_in_file(filename, first);

    return 0;
}


int main() {
    std::string filename = "C:/Users/Spied/Desktop/example.txt";

    std::ifstream file(filename);


    std::string line;
    int n{};
    int m{};

    while (std::getline(file, line)) {
        std::cout << line << std::endl;
        if (n == 0)
        {
            for (int i = 0; i < line.size(); ++i)
            {
                if (line[i] != ' ')
                {
                    m++;
                }
            }
        }
        n++;
    }
    

    file.close();

    std::ifstream file1(filename);
    matrix mat(n, m - 1);
    
    size_t k = 0;
    size_t l = 0;

    while (std::getline(file1, line))
    {
        //std::cout << line << std::endl;
        if (n == 0)
        {
            for (int i = 0; i < line.size(); ++i)
            {
                if (line[i] != ' ')
                {
                    mat[n][k] = line[i] - '0';
                    k++;
                }
            }
        }
        l++;
    }

    mat.print();
    file1.close();

    return 0;
}