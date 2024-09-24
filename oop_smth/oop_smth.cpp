// oop_smth.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <optional>
#include <string>

using namespace std;
class LazyInitialisation
{
private:
    string* resource = nullptr;
    string text;
    string res;
    void load(string res)
    {
        resource = new string();
        std::ifstream in(res); 
        if (in.is_open())
        {
            while (getline(in, res))
            {
                *resource += res;
            }
        };
        in.close();     
    }
public:
    LazyInitialisation(string t) {
        text = t;
    }
    string get()
    {
        if (resource != nullptr)
            return *resource;
        load(text);
        return *resource;
    }
};
int main()
{
    LazyInitialisation L("text.txt");
    cout << L.get()<<'\n';
}

