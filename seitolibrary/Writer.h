#ifndef ABSTRACTWRITER_H
#define ABSTRACTWRITER_H

namespace MyLibrary
{
template <class T> class Writer<T>
{
public:
    Writer();
    ~Writer();

    virtual void write(T data) = 0;
};
}

#endif // ABSTRACTWRITER_H
