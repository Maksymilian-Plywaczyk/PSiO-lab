#include <iostream>
#include <string>



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
int main()
{
    std::string word = "racecar";
    if (is_palindrome(word)) {
        std::cout << "To palindrom!" << std::endl;
    }
    else {
        std::cout << "Nope" << std::endl;
    }


    
}

