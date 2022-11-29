#include "Buffer.h"

/**@Buffer
 *
@constructors*/

Buffer::Buffer(int d){
    dim = d;
    arr = new int [dim];
}

Buffer::~Buffer(){
    dim = 0;
    curr = 0;
    delete[] arr;
}

QueueBuffer::QueueBuffer(int d) : Buffer(d){}
OrderedBuffer::OrderedBuffer(int d) : Buffer(d){}

/**@functions*/

void Buffer::push(int k){
    arr[curr] = k;
    curr++;
}

void QueueBuffer::push(int k){
    arr[curr] = k;
    curr++;
}

void OrderedBuffer::push(int k) {
    arr[curr] = k;
    curr++;
    this->sort();
}

void OrderedBuffer::sort(){
    int temp;
    for (int i = 0; i < curr; i++)
    {
        for (int j = 0; j + 1 < curr - i; j++)
        {
            // Swaping the elements if first one
            // is greater than second one.
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}



void Buffer::pop(int idx){
    for (int i = 0; i < curr - 1; i++) {
        arr[i] = arr[i + 1];
    }
    curr--;
}

void QueueBuffer::pop() {
    if(curr==1) {
        this->Buffer::pop();
    }
    else {
        arr[curr-1] = arr[curr];
        curr--;
    }
}

void OrderedBuffer::pop() {
    for (int i = curr/2; i < curr-1; i++) {
        arr[i] = arr[i + 1];
    }
    curr--;
}

void Buffer::Clear(){
    int bound = curr;
    for(int i = 0; i<bound; i++){
        this->pop();
    }
}

void OrderedBuffer::Clear(){
    for(int i = 0; i<curr; i++){
        arr[i] = 0;
    }
    curr = 0;
}

void Buffer::out(){
    for(int i=0; i<curr; i++)
        cout << arr[i] << endl;
}

void QueueBuffer::out(){
    this->Buffer::out();
}
void OrderedBuffer::out(){
    this->Buffer::out();
}

/**@dinamicka_zona*/
/*
istream &operator>>(istream& input, const Buffer *bx) {
    for(int i=0; i<bx->dim; i++){
        input >> bx->arr[i];
    }
    return input;
}

ostream &operator<<(ostream& output, const Buffer *ix) {
    int i,j;
    for(i=0; i<ix->dim; i++){
        for(j=0; j<ix->dim; j++){
            output << ix->arr[i][j] << " ";
        }
        output << endl;
    }
    return output;
}
*/

/**@po_vrednosti*/

/*
istream &operator>>(istream& input, const Buffer &ix) {
    int i,j;
    for(i=0; i<ix.dim; i++){
        for(j=0; j<ix.dim; j++){
            input >> ix.arr[i][j];
        }
    }
    return input;
}

ostream &operator<<(ostream& output, const Buffer &ix) {
    int i,j;
    for(i=0; i<ix.dim; i++){
        for(j=0; j<ix.dim; j++){
            output << ix.arr[i][j] << " ";
        }
        output << endl;
    }
    return output;
}
*/






