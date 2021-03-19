#include <iostream>
#include <string>
#include <vector>



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
    int b = 8;
    b++;
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
        std::cout << *it << "," <<
        std::endl;
    std::string input2 = "Ala ma kota, kot zjadl Ale!";
    std::string output = find_and_replace(input2, "kot", "hefalump");
    std::cout << output;

}

