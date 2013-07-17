Bits
====
When I use the c++'s STL, I find the bitset must hava a const, for example, you can define:<\br>
bitset<3>;<\br>
but you can't write:<\br>
it n = 3; bitset<n><\br>
So I write it myself, in my code, I store the bit in an array, if you want to visit the first bit, you can write:<\br>
//you have a bit object bits<\br>
std::cout<<bits[1];<\br>
of course, the object can be used as left-value or right-value<\br>
if you use it as left-value, for example<\br>
int n;<\br>
bits[3] = n;<\br>
if n is 0, bits[3]==0, otherwise, bits[3]==1<\br>
