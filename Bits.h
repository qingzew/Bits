//author: wang
//time: 2013.7.17
#ifndef BITS_H
#define BITS_H

#include <iostream>

class Bits
{
    public:
        Bits(int numOfBits);
        virtual ~Bits();
        bool Set(int arg);
        bool Clr(int arg);
        bool Test(int arg);

        class BitsProxy
        {
            public:
                BitsProxy(int *bits, int index);
                virtual ~BitsProxy();

                BitsProxy &operator=(const BitsProxy &bits);
                BitsProxy &operator=(int arg);
                operator int() const;
            private:
                int *m_pInnerBits;
                int m_index;
                int m_size;
        };

        const BitsProxy operator[](int index) const;
        BitsProxy operator[](int index);

        friend class BitsProxy;


    protected:
    private:
        int *m_pBits;
        static int mask;
        int numOfBits;

};



#endif // BITS_H
