#include <iostream>
#include <ctime>
#include <queue>

struct Transaction
{
    int count = 0;
    int price = 0;
    time_t time = 0;

};


int main(int argc, char const *argv[])
{
    std::queue<Transaction> bought, sold;

    int gain = 0;
    Transaction trans;
    trans.count = 30;
    trans.price = 25;
    trans.time = time(0);

    bought.push(trans);
    std::cout<<bought.front().count<<std::endl;
    std::cout<<bought.front().price<<std::endl;
    std::cout<<ctime(&bought.front().time)<<std::endl;

    
    return 0;
}





