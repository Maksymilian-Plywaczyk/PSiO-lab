#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define M_PI 3.14159265358979323846



void exercise1(std::vector<int>& vec)
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
void exercise2(std::vector<double>& values) 
{
    //std::vector<double> values = { -1.0, 100, 3.14, -999.9, 21.37 };
   
   const auto [min,max]= std::minmax_element(values.begin(), values.end());
   std::cout <<"max element: " << *max << std::endl;
   std::cout << "min element: " << *min << std::endl;

   

}
void exercise3(uint64_t B)
{
    uint64_t fact, i;
    fact = 1;
    i = 1;
    while (i <= B)
    {
        fact = fact * i;
        i++;
        
    }
    std::cout << fact << std::endl;
}

    uint64_t factorial_r(uint64_t A)
    {
        if (A <= 1) {
            return 1;
        }
        return A * factorial_r(A - 1);
    }

    int exercise5(int prime) {
        void is_prime();
        {
            if (prime <= 1)
            {
                return false;
            }
            for (int i = 2; i < prime; i++)
            {
                if (prime % i == 0)
                    return false;
            }
            return true;
        }
    }
    double leibniz_pi(double &stop_at)
    {
        double pi = 1.0;
        if(pi>=stop_at)
        for (int i = 0; i < 2000; i++)
        {
            double den = i * 2 + 3;
            if (i % 2 == 0)
            {
                pi -= (1 / den);
            }
            else {
                pi += (1 / den);
            }
        }
        double new_pi = pi * 4;
        
        return new_pi;
    }

       
int main()
{
    std::vector<int>vec(6);
    exercise1(vec);
    std::cout<<std::endl;
    std::vector<double> values = { -1.0, 100, 3.14, -999.9, 21.37 };
    exercise2(values);
    exercise3(15);
    uint64_t result = factorial_r(15);
    std::cout << result << std::endl;
    int prime_or_not_prime = 13;
    if (exercise5(prime_or_not_prime)) {
        std::cout << prime_or_not_prime << " is prime!" << std::endl;
    }else
        std::cout << prime_or_not_prime << " is not prime!" << std::endl;

    double stop_at = 0.001;
    
    double pi_approx = leibniz_pi(stop_at);
    std::cout << pi_approx << std::endl;
    std::cout << "error: " << pi_approx - M_PI << std::endl;
}

