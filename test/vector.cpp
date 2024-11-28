#include <iostream>
#include <vector>
#include <list>
int main()
{
    std::vector<int>Mylist1;
    Mylist1.push_back(1);
    Mylist1.push_back(2);
    Mylist1.push_back(66);
    Mylist1.push_back(10);
    Mylist1.push_back(566);
    Mylist1.push_back(6);
    Mylist1.push_back(79);
    std::vector<int>::iterator it = Mylist1.begin();
    auto ite = Mylist1.begin() + 1;

    std::cout<< "First element is : " << *it << std::endl;
    std::cout<< "second element is : " << *ite << std::endl;
    std::cout << "First element is : " << *Mylist1.begin() << "\n";

    Mylist1.erase(Mylist1.begin(), Mylist1.begin() + 2 );
    std::cout << "First element after delete is : " << *Mylist1.begin() << "\n";

    
}