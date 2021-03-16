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

    
}

