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


    // Transaction trans;
    trans.count = 10;
    trans.price = 30;
    trans.time = time(0);

    sold.push(trans);
    std::cout<<sold.front().count<<std::endl;
    std::cout<<sold.front().price<<std::endl;
    std::cout<<ctime(&sold.front().time)<<std::endl;

    Transaction buy, sell;
    while(!bought.empty() && !sold.empty()){
        buy = bought.front();
        sell = sold.front();

        if(buy.count < sell.count){
            gain += buy.count * (sell.price - buy.price);
            bought.pop();

            sold.front().count -= buy.count;
        }else{
            gain += sell.count * (sell.price - buy.price);
            sold.pop();
            if(buy.count == sell.count){
                bought.pop();
            }else{
                bought.front().count -= sell.count;
            }
        }
    }

    std::cout<<gain;


    
    return 0;
}





