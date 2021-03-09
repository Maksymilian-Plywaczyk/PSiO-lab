#include <iostream>
#include <vector>
#include <algorithm>



void zad1(std::vector<int>& vec)
{
    void fill_progressive();
    {
        for (int i = 0; i < vec.size(); i++)
        {
            vec[i] = i + 1;
        }
    }
    void print_vector();
    {
        for (auto numbers : vec)
        {
            std::cout << numbers << ",";
       }
    }
}
void zad2(std::vector<double>& values) 
{
    //std::vector<double> values = { -1.0, 100, 3.14, -999.9, 21.37 };
   
   const auto [min,max]= std::minmax_element(values.begin(), values.end());
   std::cout <<"max element: " << *max << std::endl;
   std::cout << "min element: " << *min << std::endl;

   

}

uint64_t factorial(uint64_t A)
{
    if (A <= 1) {
        return 1;
    }
    return A * factorial(A - 1);
}
    

int main()
{
    std::vector<int>vec(6);
    zad1(vec);
    std::cout<<std::endl;
    std::vector<double> values = { -1.0, 100, 3.14, -999.9, 21.37 };
    zad2(values);
    uint64_t result = factorial(15);
    std::cout << result << std::endl;
}

