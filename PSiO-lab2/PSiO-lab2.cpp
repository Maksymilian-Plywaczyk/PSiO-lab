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
    std::cout << "Najdluzszym slowem w zdaniu jest: " << longest_word;
    return longest_word;
    
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

    std::string  expression= "Ala ma kota kot jezdzi na Roombie";

    std::string longest = find_longest_word(expression); // "Roombie"
}

