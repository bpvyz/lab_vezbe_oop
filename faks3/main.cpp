#include "Buffer.h"
#include <iostream>
using namespace std;

int main() {
    Buffer* b1 = new Buffer(20);
    Buffer* b2 = new Buffer(20);
    Buffer* b3 = new Buffer(20);
    Buffer* b = new Buffer(1000);
    QueueBuffer* qb = new QueueBuffer(1000);
    OrderedBuffer* ob = new OrderedBuffer(1000);

    int i, j;

    for(i=1; i<=2018; i++){
        for(j=0; j<3; j++){
            b->push(rand());
            qb->push(rand());
            ob->push(rand());
        }
        for(j=0; j<2; j++){
            b->pop();
            qb->pop();
            ob->pop();
        }
        if(i % 50 == 0){
            b->Clear();
            qb->Clear();
            ob->Clear();
        }
        if(i % 77 == 0){
            cout << "Iteracija " << i << endl;
            cout << "Buffer:" << endl;
            b->out();
            cout << "Queue Buffer:" << endl;
            qb->out();
            cout << "Ordered Buffer:" << endl;
            ob->out();
        }
    }
    /*
    ifstream uldat1("../polje.txt");

    if (uldat1.good()) {
        uldat1 >> im1;
        uldat1.close();
    }

    ifstream uldat2("../polje1.txt");

    if (uldat2.good()) {
        uldat2 >> im2;
        uldat2.close();
    }


    ofstream izldat("../polje2.txt");
    if (izldat.good()) {
        izldat << im3;
        izldat.close();
    }
    */

    delete b1;
    delete b2;
    delete b3;
    delete b;
    delete qb;
    delete ob;
    return 0;
}
