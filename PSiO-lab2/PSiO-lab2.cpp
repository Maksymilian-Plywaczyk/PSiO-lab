#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<fstream>
#include<sstream>


bool is_palindrome(std::string& word)
{
    for(int i=0; i<word.length();i++)
    {
        if (word[i] != word[word.length()-i-1])
        {
            return false;
        }
    }
    return true;
}
void find_all(std::string& sentence, char letter)
{
    size_t position = sentence.find(letter);
    do{

        std::cout << "Litera 'a' wystepuje na miejscu: " << position << std::endl;
        position = sentence.find(letter, position + 1);

    }while (position != std::string::npos);
       
}

std::string find_longest_word(std::string& expression)
{
    std::string word, longest_word;
    do {
        word = expression.substr(0, expression.find(' '));

        if (word.size() > longest_word.size())
            longest_word = word;

        expression.erase(0, word.size() + 1);
    } while (word != "");
    std::cout << "Najdluzszym slowem w zdaniu jest: " << longest_word << std::endl;
    return longest_word;
    
}
std::vector<std::string> split(std::string& sentence)
{
  
    std::vector<std::string>v;
    size_t last_position = 0;
    size_t current_position = sentence.find(' ');
    do
    {
        v.emplace_back(sentence.substr(last_position, current_position-last_position));
        last_position = current_position + 1;
        current_position = sentence.find(' ', last_position);

    } while (current_position != std::string::npos);
    v.emplace_back(sentence.substr(last_position, current_position));
    return v;
}

std::string find_and_replace(std::string& input, std::string search, std::string replace)
{
   auto searching = input.find(search);
   auto length = search.size();
    do
    {
        input.replace(searching, length, replace);
        searching = input.find(search);
    } while (searching != std::string::npos);
    
    
    return input;
}
std::vector<int> bubble_sort(std::vector<int>&sort)
{
   int rozmiar = sort.size();
   int i = 0;
   do{
       for (i = 0; i < rozmiar - 1;i++)
       {
           if (sort[i] > sort[i + 1])
           {
               std::swap(sort[i], sort[i + 1]);

           }
       }
   } while (rozmiar--);
   return sort;
}

int binary_search(const std::vector<int>& tab, int szukana_wartosc)
{
    int start = 0;
    int end = tab.size()-1;


    do {
        int mid = (start + end) / 2;
        if (szukana_wartosc==tab[mid])
        {
            return mid;
        }
        if (szukana_wartosc> tab[mid])
        {
            start = mid + 1;
        }
        else
        {            end = mid - 1;
        }    } while (start <= end);
    return std::string::npos;
}
struct Exchange_rate
{
    std::string date;
    double usd;
    double eur;
    std::string table_id;

};

std::vector<Exchange_rate>load_data(const std::string& filename)
{
    std::fstream file(filename, std::fstream::in);
    std::vector<Exchange_rate> rates;
    if (not file.is_open()) {
        std::cout << "ERRRORRRR" << std::endl;
    }
        std::string line;
        std::getline(file, line);
        while (std::getline(file, line))
        {
            std::stringstream str(line);
            Exchange_rate er;
            std::getline(str, er.date, ','); //wczytuje date (pierwszy element wiersza)
            std::string double_str;
            std::getline(str, double_str, ',');  // wczytuje kurs USD (jako tekst)
            er.usd = std::stod(double_str);      //zamiana na string->double
            std::getline(str, double_str, ',');  // wczytuje kurs EUR (jako tekst)
            er.eur = std::stod(double_str);      //zamiana na string->double
            std::getline(str, er.table_id, ','); // wczytuje ostatnią kolumnę z numerem tabeli NBP
            rates.emplace_back(er); //dodaje element do kolekcji
        }
      
        return rates;
   
    }
std::vector<Exchange_rate> sort_usd(std::vector<Exchange_rate>& rates)
{
    int rozmiar = rates.size();
    int i = 0;
    do {
        for (i = 0; i < rozmiar - 1; i++)
        {
            if (rates[i].usd > rates[i + 1].usd)
            {
                std::swap(rates[i].usd, rates[i + 1].usd);

            }
        }
    } while (rozmiar--);
   

    return rates;
  
}
std::vector<Exchange_rate> sort_eur(std::vector<Exchange_rate>& rates)
{
    int rozmiar = rates.size();
    int i = 0;
    do {
        for (i = 0; i < rozmiar - 1; i++)
        {
            if (rates[i].eur > rates[i + 1].eur)
            {
                std::swap(rates[i].eur, rates[i + 1].eur);

            }
        }
    } while (rozmiar--);

    return rates;

}
void top_usd(std::vector<Exchange_rate>& rates)
{
    sort_usd(rates); 
    std::cout << "TOP 10 USD" << std::endl;
    for (int i = rates.size() - 10; i < rates.size(); i++)
    {
        std::cout <<"Date: "<< rates[i].date <<" Price: " << rates[i].usd << std::endl;
    }

}
void top_eur(std::vector<Exchange_rate>& rates)
{
    sort_eur(rates);
    std::cout << "TOP 10 EURO" << std::endl;
    for (int i =0; i < 10 ; i++)
    {
        std::cout << "Date: " << rates[i].date << " Price: " << rates[i].usd << std::endl;
    }

}
int binary_search_usd(std::vector<Exchange_rate>& rates, double& szukana_wartosc)
{

    sort_usd(rates);
    int start = 0;
    int end = rates.size()-1;


    do {
        int mid = (start + end) / 2;
        if (rates[szukana_wartosc].usd == rates[mid].usd)
        {
                 return mid;
         
        }
        if (rates[szukana_wartosc].usd > rates[mid].usd)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
} while (start <= end);


return std::string::npos;

}
    

int main()
{
    std::string word = "racecar";
    if (is_palindrome(word)) {
        std::cout << "To palindrom!" << std::endl;
    }
    else {
        std::cout << "Nope" << std::endl;
    }
   
    std::string input = "Ala ma kota";
    find_all(input, 'a');

    std::string  expression= "Ala ma kota, kot jezdzi na Roombie";

    std::string longest = find_longest_word(expression); // "Roombie"

    std::string sentence = "Ala ma kota";
    std::vector<std::string> words = split(sentence);
    for (auto it = words.begin(); it != words.end(); it++)
        std::cout << *it << "," << std::endl;
    
    
    std::string input2 = "Ala ma kota, kot zjadl Ale!";
    std::string output = find_and_replace(input2, "kot", "hefalump");
    std::cout << output << std::endl;
    
    std::vector<int>sort = { 1,3,6,7,4,10,15,2 };
    bubble_sort(sort);
    for (auto sorting : sort)
    {
        std::cout << sorting << std::endl;
    }
    std::cout << std::endl;
    
    std::vector<int>tab = { 1,2,5,8,9,11,15};
    int pozycja=binary_search(tab, 5);

    std::cout <<"Position: " <<pozycja << std::endl;
    std::vector<Exchange_rate>rates = load_data("kursy_usd_eur.csv");
    top_usd(rates);
   std::cout<< std::endl;
    top_eur(rates);
   auto szukana_wartosc = 3.9011;
   binary_search_usd(rates, szukana_wartosc);
   std::cout << rates[szukana_wartosc].usd;
 
}

