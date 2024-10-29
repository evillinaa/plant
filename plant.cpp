#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>


class Plant
{
public:
    Plant(const std::string& name, const std::string& size, int height)
        : name(name), size(size), height(height) {}

    std::string get_name() const { return name; }
    std::string get_size() const { return size; }
    int get_height() const { return height; }

protected:
    std::string name;
    std::string size;
    int height;
};


class Bush : public Plant 
{
public:
    Bush(const std::string& name, int height) : Plant(name, "маленький", height) {}
};

class Tree : public Plant
{
public:
    Tree(const std::string& name, int height) : Plant(name, "большой", height) {}

    
    virtual std::vector<std::string> collect_fruits() = 0;
};

class AppleTree : public Tree 
{
public:
    AppleTree(int height) : Tree("Яблоня", height) {}

    std::vector<std::string> collect_fruits() 
    {
        return { "Яблоко", "Яблоко" };
    }
};

class RaspberryBush : public Bush 
{
public:
    RaspberryBush(int height) : Bush("Малина", height) {}

    std::vector<std::string> collect_fruits()
    {
        return { "Малина", "Малина" };
    }
};

class BlackberryBush : public Bush 
{
public:
    BlackberryBush(int height) : Bush("Ежевика", height) {}

    std::vector<std::string> collect_fruits() 
    {
        return { "Ежевика", "Ежевика" };
    }
};

class PineTree : public Tree 
{
public:
    PineTree(int height) : Tree("Сосна", height) {}

    std::vector<std::string> collect_fruits() 
    {
        return { "Шишка", "Шишка" };
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    AppleTree appleTree(1000);
    std::cout << appleTree.get_name() << " (" << appleTree.get_size() << ", " << appleTree.get_height() << " см)" << std::endl;

    for (std::string fruit : appleTree.collect_fruits())
    {
        std::cout << fruit << std::endl;
    }

    RaspberryBush raspberryBush(50);
    std::cout << raspberryBush.get_name() << " (" << raspberryBush.get_size() << ", " << raspberryBush.get_height() << " см)" << std::endl;

    for (std::string fruit : raspberryBush.collect_fruits()) 
    {
        std::cout << fruit << std::endl;
    }

    BlackberryBush blackberryBush(50);
    std::cout << blackberryBush.get_name() << " (" << blackberryBush.get_size() << ", " << blackberryBush.get_height() << " см)" << std::endl;

    for (std::string fruit : blackberryBush.collect_fruits()) 
    {
        std::cout << fruit << std::endl;
    }

    PineTree pineTree(1500);
    std::cout << pineTree.get_name() << " (" << pineTree.get_size() << ", " << pineTree.get_height() << " см)" << std::endl;

    for (std::string fruit : pineTree.collect_fruits()) 
    {
        std::cout << fruit << std::endl;
    }

    return 0;
}