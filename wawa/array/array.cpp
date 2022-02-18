#include <iostream>
#include <fstream>

int main()
{
    std::ofstream writing_file;
    std::string filename = "data.txt";
    int we = 10;
    int array[2][we];
    writing_file.open(filename, std::ios::out);

    for (int i = 0; i < 10; i++)
    {
        array[0][i] = i * 10;
        array[1][i] = i * 100;
    }
    for (int i = 0; i < 10; i++)
    {
        writing_file << array[0][i] << " " << array[1][i] << std::endl;
    }
    writing_file.close();
    system("gnuplot -persist show.plt");
}