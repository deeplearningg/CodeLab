#include <iostream>
int NumberOf1_Solution2(int i)
{
      int count = 0;
      unsigned int flag = 1;
      while(flag)
      {
            if(i & flag)
                  count ++;

            flag = flag << 1;
            std::cout << flag << std::endl;
      }

      return count;
}
int NumberOf1_Solution3(int i)
{
      int count = 0;

      while (i)
      {
            ++ count;
            i = (i - 1) & i;
      }

      return count;
}
int countBits(int value){
      int count=0;
      int bits4[]={0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4};
      while(value!=0){
        count+=bits4[value&0xf];
        value>>=4;
      }
      return count;
}//look-up table
typedef unsigned int UINT32;
const UINT32 m1  = 0x55555555;  // 01010101010101010101010101010101
const UINT32 m2  = 0x33333333;  // 00110011001100110011001100110011
const UINT32 m4  = 0x0f0f0f0f;  // 00001111000011110000111100001111
const UINT32 m8  = 0x00ff00ff;  // 00000000111111110000000011111111
const UINT32 m16 = 0x0000ffff;  // 00000000000000001111111111111111
const UINT32 h01 = 0x01010101;  // the sum of 256 to the power of 0, 1, 2, 3


int popcount_1(UINT32 x)
{
  x = (x & m1) + ((x >> 1) & m1);
  x = (x & m2) + ((x >> 2) & m2);
  x = (x & m4) + ((x >> 4) & m4);
  x = (x & m8) + ((x >> 8) & m8);
  x = (x & m16) + ((x >> 16) & m16);
  return x;
}
int main(){
    NumberOf1_Solution2(0x1);
}
