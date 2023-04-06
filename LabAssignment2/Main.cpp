
#include <iostream>
#include <ctime>
#include "QueueLL.h"
struct Transaction
{
    int count = 0;
    int price = 0;
    time_t time = 0;
};

int gainCalculate(Queue<Transaction> bought, Queue<Transaction> sold);

int main(int argc, char const *argv[])
{
    Queue<Transaction> bought, sold;

    int gain = 0, option = 0;
    Transaction trans;
    while (option != -1)
    {
        std::cout << "\n 1 - Buy\n 2 - Sell\n-1 - Exit\nEnter you choice: ";
        std::cin >> option;
        if(option == -1)break;

        std::cout<<"Enter quantity: ";
        std::cin>>trans.count;
        std::cout<<"Enter price $: ";
        std::cin>>trans.price;
        trans.time = time(0);

        if(option == 1){
            bought.enqueue(trans);
        }else if(option == 2){
            sold.enqueue(trans);
        }
    }


    gain = gainCalculate(bought, sold);

    std::cout <<"\n\nTotal Gain is "<< gain;

    return 0;
}

int gainCalculate(Queue<Transaction> bought, Queue<Transaction> sold)
{
    int gain = 0;
    Transaction buy, sell;
    while (!bought.isEmpty() && !sold.isEmpty())
    {
        buy = *bought.front();
        sell = *sold.front();

        if (buy.count < sell.count)
        {
            gain += buy.count * (sell.price - buy.price);
            bought.dequeue();

            sold.front()->count -= buy.count;
        }
        else
        {
            gain += sell.count * (sell.price - buy.price);
            sold.dequeue();
            if (buy.count == sell.count)
            {
                bought.dequeue();
            }
            else
            {
                bought.front()->count -= sell.count;
            }
        }
    }

    return gain;
}
