#include "Bits.h"

int Bits::mask = 0x1f;

Bits::Bits(int numOfBits)
{
    m_pBits = new int[numOfBits/sizeof(int) + 1];
    this->numOfBits = numOfBits;
}

Bits::~Bits()
{
    delete [] m_pBits;
}

bool Bits::Set(int arg)
{
    if (arg<0 || arg>numOfBits)
    {
        return false;
    }

    m_pBits[arg>>5] |= 1 << (arg & mask);
    return true;
}


bool Bits::Clr(int arg)
{
    if (arg<0 || arg>numOfBits)
    {
        return false;
    }

    m_pBits[arg>>5] &= ~(1 << (arg & mask));
    return true;
}


bool Bits::Test(int arg)
{
    try
    {
        if (arg<0 || arg>numOfBits)
        {
            throw std::exception();
        }
    }
    catch (std::exception e)
    {
        std::cout<<"invalid argument."<<std::endl;
        return false;
    }

    return m_pBits[arg>>5]  & (1 << (arg & mask));
}



Bits::BitsProxy::BitsProxy(int *bits, int index):m_pInnerBits(bits), m_index(index)
{

}

Bits::BitsProxy::~BitsProxy()
{

}

Bits::BitsProxy &Bits::BitsProxy::operator=(const BitsProxy &bits)
{
    if (bits.m_pInnerBits[bits.m_index>>5] & (1<<(bits.m_index & mask)))
    {
        m_pInnerBits[m_index>>5] |= 1 << (m_index & mask);
    }
    else
    {
        m_pInnerBits[m_index>>5] &= ~(1 << (m_index & mask));
    }


    return *this;
}


Bits::BitsProxy &Bits::BitsProxy::operator=(int arg)
{
    if (arg != 0)
    {
        m_pInnerBits[m_index>>5] |= 1 << (m_index & mask);
    }
    else
    {
        m_pInnerBits[m_index>>5] &= ~(1 << (m_index & mask));
    }

    return *this;
}

Bits::BitsProxy::operator int() const
{
    int nTmp = m_pInnerBits[m_index>>5];
    nTmp = nTmp>>(m_index & mask);
    nTmp &= 0x1;
    return nTmp;
}


const Bits::BitsProxy Bits::operator[](int index) const
{
    try
    {
        if (index>=numOfBits)
        {
            throw std::exception();
        }
    }
    catch (std::exception e)
    {
        std::cout<<"invalid argument."<<std::endl;
    }


    return BitsProxy((const_cast<Bits*>(this))->m_pBits, index);
}

Bits::BitsProxy Bits::operator[](int index)
{
    try
    {
        if (index>=numOfBits)
        {
            throw std::exception();
        }
    }
    catch (std::exception e)
    {
        std::cout<<"invalid argument."<<std::endl;
    }


    return BitsProxy(this->m_pBits, index);
}








