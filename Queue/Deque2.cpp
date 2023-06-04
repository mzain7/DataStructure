
#include <iostream>
using namespace std;

const int SIZE=5;

struct Queue{
    int queue[SIZE];
    int Front;
    int Rear;
};


void InsertRear( Queue &q, int num );
int DeleteFront( Queue &q );
void InsertFront( Queue &q, int num );
int DeleteRear( Queue &q );
void Display( Queue &q );


int main(){

    Queue q1;

    q1.Front = -1;
    q1.Rear = -1;

    while(true){

        int num;

        cout << "\n****************************************************** \n"
             << " Enter 1 for Insert value at Rear end of the Queue \n"
             << " Enter 2 for Delete value from Front end of the Queue \n"
             << " Enter 3 for Inset value at Front end of the Queue \n"
             << " Enter 4 for Delete value from Rear end of the Queue \n"
             << " Enter 5 for Display the elements in the Queue \n"
             << " Enter 0 for Exit the Program \n"
             << "\n Enter the command : ";
        cin >> num;

        if( num==0 ){
            break;
        }

        switch(num){

        case 1:

            int num1;
            cout << "\n Enter a value to insert at Rear end : ";
            cin >> num1;
            InsertRear( q1, num1 );
            break;

        case 2:

            DeleteFront( q1 );
            break;

        case 3:

            int num2;
            cout << "\n Enter a value to insert at Front end : ";
            cin  >> num2;
            InsertFront( q1, num2 );
            break;

        case 4:
            DeleteRear( q1 );
            break;

        case 5:
            Display( q1 );
            break;

        default:
            cout << " Invalid Command\n";
            break;

        }
    }

}


void InsertRear( Queue &q, int num ){

    if( (q.Front==0 && q.Rear==SIZE-1) || q.Front==q.Rear+1 ){
        cout << "\n Queue Overflow \n";
    }
    else if( q.Rear==-1 && q.Front==-1 ){
        q.Rear = 0;
        q.Front = 0;
        q.queue[q.Rear] = num;
    }
    else if( q.Front!=0 && q.Rear==SIZE-1 ){
        q.Rear = 0;
        q.queue[q.Rear] = num;
    }
    else{
        q.Rear++;
        q.queue[q.Rear] = num;
    }
}

int DeleteFront( Queue &q ){

    int temp=0;

    if( q.Front==-1 && q.Rear==-1 ){
        cout << "\n Queue underflow \n";
    }
    else if( q.Front == q.Rear ){
        temp = q.queue[q.Front];
        q.queue[q.Front] = 0;
        q.Front = -1;
        q.Rear = -1;
    }
    else if( q.Front==SIZE-1 ){
        temp = q.queue[q.Front];
        q.queue[q.Front] = 0;
        q.Front = 0;
    }
    else{
        temp = q.queue[q.Front];
        q.queue[q.Front] = 0;
        q.Front++;
    }

    return temp;
}

void InsertFront( Queue &q, int num ){

    if( (q.Front==0 && q.Rear==SIZE-1) || q.Front==q.Rear+1 ){
        cout << "\n Queue Overflow \n";
    }
    else if( q.Rear==-1 && q.Front==-1 ){
        q.Rear = 0;
        q.Front = 0;
        q.queue[q.Front] = num;
    }
    else if( q.Front==0 && q.Rear!=SIZE-1 ){
        q.Front = SIZE-1;
        q.queue[q.Front] = num;
    }
    else{
        q.Front--;
        q.queue[q.Front] = num;
    }
}

int DeleteRear( Queue &q ){

    int temp=0;

    if( q.Front==-1 && q.Rear==-1 ){
        cout << "\n Queue underflow \n";
    }
    else if( q.Front == q.Rear ){
        temp = q.queue[q.Rear];
        q.queue[q.Rear] = 0;
        q.Front = -1;
        q.Rear = -1;
    }
    else if( q.Rear==0 ){
        temp = q.queue[q.Rear];
        q.queue[q.Rear] = 0;
        q.Rear = SIZE-1;
    }
    else{
        temp = q.queue[q.Rear];
        q.queue[q.Rear] = 0;
        q.Rear--;
    }

    return temp;
}

void Display( Queue &q ){

    cout << "\n Elements in the circular queue are " << endl;

    if( q.Front != -1 ){

        int i=q.Front;

        while( true ){

            cout << "  [" << i << "] " << q.queue[i];

            if( i==q.Rear){
                break;
            }
            else if( i==SIZE-1 ){
                i=0;
            }
            else{
                i++;
            }
        }

        cout << endl;
    }
}
