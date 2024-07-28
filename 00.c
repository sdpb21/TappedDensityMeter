#include <00.h>


void main()
{
int8 puertoa, puertob;
int1 b1;
b1=0;
puertob=puertoa=0b00000000;
   while(true){
      puertoa=input_a();
      switch(puertoa){
         case 0b01010111: puertob=0b00111111;//0
         b1=1;
         break;
         case 0b01101110: puertob=0b00000110;//1
         b1=1;
         break;
         case 0b01011110: puertob=0b01011011;//2
         b1=1;
         break;
         case 0b00111110: puertob=0b01001111;//3
         b1=1;
         break;
         case 0b01101101: puertob=0b01100110;//4
         b1=1;
         break;
         case 0b01011101: puertob=0b01101101;//5
         b1=1;
         break;
         case 0b01111101: puertob=0b00111101;//6
         b1=1;
         break;
         case 0b01101011: puertob=0b00000111;//7
         b1=1;
         break;
         case 0b01011011: puertob=0b01111111;//8
         b1=1;
         break;
         case 0b00111011: puertob=0b01101111;//9
         b1=1;
         break;
      }
      if(b1==1){
         output_b(puertob);//imprime número seleccionado
      }else{
         output_b(0xFF);//sin selección imprime cero
      }
   }
}

