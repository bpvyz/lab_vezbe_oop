#include <iostream>
using namespace std;

#ifndef LABOOP_BUFFER_H
#define LABOOP_BUFFER_H

class Buffer{
protected:
    int dim = 0;
    int curr = 0;
    int * arr;
public:
    Buffer(int d = 1);
    ~Buffer();
    virtual void push(int k);
    virtual void pop(int idx = 0);
    virtual void Clear();
    /*
    friend istream &operator>>(istream& input, const Buffer *ix);
    friend ostream &operator<<(ostream& output, const Buffer *ix);
    friend istream &operator>>(istream& input, const Buffer &ix);
    friend ostream &operator<<(ostream& output, const Buffer &ix);
    */
    virtual void out();
};

class QueueBuffer : public Buffer {
public:
    QueueBuffer(int dx = 0);
    void push(int k);
    void pop();
    void out();
};

class OrderedBuffer : public Buffer {
public:
    OrderedBuffer(int d = 0);
    void Clear();
    void push(int k);
    void pop();
    void sort();
    void out();
};


#endif
