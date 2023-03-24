#include <iostream>

class CircularQueue{
    public:
    CircularQueue(int size){
        this->size = size;
        front = -1;
        back = -1;
        queuePtr = (int*)calloc(size, sizeof(int));
    }

    bool enqueue(int val){
        if(isFull()){
            std::cout << "queue is full";
            return false;
        }else if(isEmpty()){
            front = 0;
            back = 0;
        }else{
            back = (back + 1) % size;
        }
        *(queuePtr + back) = val; 
        return true;
    }


    int dequeue(){
        int val;
        if(isEmpty()){
            std::cout << "queue is empty";
            return -1;
        }else{
            val = *(queuePtr + front);
            *(queuePtr + front) = 0;
        }

        if(front == back){
           front = -1;
           back = -1;
        }else{
            front = (front + 1) % size;
        }
        return val;
    }

    bool isFull(){
        return (back + 1)%size == front;
    }

    bool isEmpty(){
        return (front == -1);
    }

    int getSize(){
        return (size - front + back) % size + 1;
    }

    void display(){
        int temp = front;
        std::cout << std::endl;
        while(true){
            std::cout << *(queuePtr + temp) << " ";
            if(temp == back){
                break;
            }
            temp = (temp + 1) % size;

        }
    }

    void printFandB(){
        std::cout << "\nFront: " << *(queuePtr + front); 
        std::cout << "\nback: " << *(queuePtr + back);
        std::cout << std::endl << std::endl; 
    }

    private:
    int front;
    int back;
    int size;
    int* queuePtr;
};

void insert(CircularQueue*);

int main(){
    CircularQueue* q = new CircularQueue(5);
    int option = 0;
    do{
        std::cout << "\n1. Enqueue";
        std::cout << "\n2. deqeue";
        std::cout << "\n3. display";
        std::cout << "\n\n-1. Exit";
        std::cout << "\nEnter your option: ";
        std::cin >> option;
            switch(option){
            case 1:
            insert(q);
            break;
            case 2:
            q->dequeue();
            break;
            case 3:
            q->display();
            q->printFandB();
            case -1:
            break;
            default:
            std::cout << "\nPlease enter a valid option.";
        }
    }while(true);
    return 0;
}

void insert(CircularQueue* q){
    int val;
    std::cout << "Enter the value: ";
    std::cin >> val;
    q->enqueue(val);
}