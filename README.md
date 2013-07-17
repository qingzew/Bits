Bits
====
When I use the c++'s STL, I find the bitset must hava a const, for example, you can define:
bitset<3>;
but you can't write:
it n = 3; bitset<n>
So I write it myself, in my code, I store the bit in an array, if you want to visit the first bit, you can write:
//you have a bit object bits
std::cout<<bits[1];
of course, the object can be used as left-value or right-value
if you use it as left-value, for example
int n;
bits[3] = n;
if n is 0, bits[3]==0, otherwise, bits[3]==1
