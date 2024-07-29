#include <00.h>
void imprimir(int16 num){
   output_low(PIN_B0);
   output_low(PIN_B1);
   output_low(PIN_B2);
   output_low(PIN_B4);
   output_low(PIN_B5);
   output_low(PIN_B6);
   output_low(PIN_B7);
   switch(num){
      case 1: output_low(PIN_B1);output_low(PIN_B2);
      break;
      case 2: output_low(PIN_B0);output_low(PIN_B1);output_low(PIN_B4);output_low(PIN_B5);output_low(PIN_B7);
      break;
      case 3: output_low(PIN_B0);output_low(PIN_B1);output_low(PIN_B2);output_low(PIN_B4);output_low(PIN_B7);
      break;
      case 4: output_low(PIN_B1);output_low(PIN_B2);output_low(PIN_B6);output_low(PIN_B7);
      break;
      case 5: output_low(PIN_B0);output_low(PIN_B2);output_low(PIN_B4);output_low(PIN_B5);output_low(PIN_B6);
      break;
      case 6: output_low(PIN_B0);output_low(PIN_B2);output_low(PIN_B4);output_low(PIN_B5);output_low(PIN_B6);output_low(PIN_B7);
      break;
      case 7: output_low(PIN_B0);output_low(PIN_B1);output_low(PIN_B2);
      break;
      case 8: output_low(PIN_B0);output_low(PIN_B1);output_low(PIN_B2);output_low(PIN_B4);output_low(PIN_B5);output_low(PIN_B6);output_low(PIN_B7);
      break;
      case 9: output_low(PIN_B0);output_low(PIN_B1);output_low(PIN_B2);output_low(PIN_B4);output_low(PIN_B6);output_low(PIN_B7);
      break;
      case 0: output_low(PIN_B0);output_low(PIN_B1);output_low(PIN_B2);output_low(PIN_B4);output_low(PIN_B5);output_low(PIN_B6);
      break;
   }
}
int16 tabla(int16 taps1){
   switch(taps1){
            case 100: return 5000;//listo
            case 101: return 4925;//listo
            case 102: return 4852;//listo
            case 103: return 4780;//listo
            case 104: return 4711;//listo
            case 105: return 4642;//listo
            case 106: return 4574;//listo
            case 107: return 4507;//listo
            case 108: return 4443;//listo
            case 109: return 4379;//listo
            case 110: return 4316;//listo
            case 111: return 4255;//listo
            case 112: return 4194;//listo
            case 113: return 4135;//listo
            case 114: return 4076;//listo
            case 115: return 4019;//listo
            case 116: return 3963;//listo
         }//fin switch taps
}
static BOOLEAN b2=0, b3=0, b4=0;
static int16 temp=0,c1=0, taps=0, saltos=0, puertob[4]={0,0,0,0};

void main()
{
   pwm_off();
   output_low(PIN_A7);//para reset y enable del driver....
   while(true){
      if( !b2 || !b3 ){
      output_bit(PIN_A0,0);
      output_bit(PIN_A1,1);
      output_bit(PIN_A2,1);
      output_bit(PIN_A3,1);
      //output_a(0b00001110);
      if(!input(PIN_A4)){ 
         //++c1;
         puertob[3]=puertob[2];
         puertob[2]=puertob[1];
         puertob[1]=puertob[0];
         puertob[0]=1;
         /*if(c1<=4){ 
            puertob[c1-1]=1;//1
         }else{
            puertob[0]=puertob[1]; puertob[1]=puertob[2]; puertob[2]=puertob[3];puertob[3]=1;//1
         }*/
         output_bit(PIN_A0,1);
         delay_ms(200);
      }
      if(!input(PIN_A5)){
         //++c1;
         puertob[3]=puertob[2];
         puertob[2]=puertob[1];
         puertob[1]=puertob[0];
         puertob[0]=2;
         /*if(c1<=4){ 
            puertob[c1-1]=2;//2
         }else{
            puertob[0]=puertob[1]; puertob[1]=puertob[2]; puertob[2]=puertob[3];puertob[3]=2;//2
         }*/
         output_bit(PIN_A0,1);
         delay_ms(200);
      }
      if(!input(PIN_A6)){
         //++c1;
         puertob[3]=puertob[2];
         puertob[2]=puertob[1];
         puertob[1]=puertob[0];
         puertob[0]=3;
         /*if(c1<=4){ 
            puertob[c1-1]=3;//3
         }else{
            puertob[0]=puertob[1]; puertob[1]=puertob[2]; puertob[2]=puertob[3];puertob[3]=3;//3
         }*/
         output_bit(PIN_A0,1);
         delay_ms(200);
      }
      output_bit(PIN_A0,1);
      output_bit(PIN_A1,0);
      //output_a(0b00001101);
      if(!input(PIN_A4)){
         //++c1;
         puertob[3]=puertob[2];
         puertob[2]=puertob[1];
         puertob[1]=puertob[0];
         puertob[0]=4;
         /*if(c1<=4){ 
            puertob[c1-1]=4;//4
         }else{
            puertob[0]=puertob[1]; puertob[1]=puertob[2]; puertob[2]=puertob[3];puertob[3]=4;//4
         }*/
         output_bit(PIN_A1,1);
         delay_ms(200);
      }
      if(!input(PIN_A5)){
         //++c1;
         puertob[3]=puertob[2];
         puertob[2]=puertob[1];
         puertob[1]=puertob[0];
         puertob[0]=5;
         /*if(c1<=4){ 
            puertob[c1-1]=5;//5
         }else{
            puertob[0]=puertob[1]; puertob[1]=puertob[2]; puertob[2]=puertob[3];puertob[3]=5;//5
         }*/
         output_bit(PIN_A1,1);
         delay_ms(200);
      }
      if(!input(PIN_A6)){
         //++c1;
         puertob[3]=puertob[2];
         puertob[2]=puertob[1];
         puertob[1]=puertob[0];
         puertob[0]=6;
         /*if(c1<=4){ 
            puertob[c1-1]=6;//6
         }else{
            puertob[0]=puertob[1]; puertob[1]=puertob[2]; puertob[2]=puertob[3];puertob[3]=6;//6
         }*/
         output_bit(PIN_A1,1);
         delay_ms(200);
      }
      output_bit(PIN_A1,1);
      output_bit(PIN_A2,0);
      //output_a(0b00001011);
      if(!input(PIN_A4)){
         //++c1;
         puertob[3]=puertob[2];
         puertob[2]=puertob[1];
         puertob[1]=puertob[0];
         puertob[0]=7;
         /*if(c1<=4){ 
            puertob[c1-1]=7;//7
         }else{
            puertob[0]=puertob[1]; puertob[1]=puertob[2]; puertob[2]=puertob[3];puertob[3]=7;//7
         }*/
         output_bit(PIN_A2,1);
         delay_ms(200);
      }
      if(!input(PIN_A5)){
         //++c1;
         puertob[3]=puertob[2];
         puertob[2]=puertob[1];
         puertob[1]=puertob[0];
         puertob[0]=8;
         /*if(c1<=4){ 
            puertob[c1-1]=8;//8
         }else{
            puertob[0]=puertob[1]; puertob[1]=puertob[2]; puertob[2]=puertob[3];puertob[3]=8;//8
         }*/
         output_bit(PIN_A2,1);
         delay_ms(200);
      }
      if(!input(PIN_A6)){
         //++c1;
         puertob[3]=puertob[2];
         puertob[2]=puertob[1];
         puertob[1]=puertob[0];
         puertob[0]=9;
         /*if(c1<=4){ 
            puertob[c1-1]=9;//9
         }else{
            puertob[0]=puertob[1]; puertob[1]=puertob[2]; puertob[2]=puertob[3];puertob[3]=9;//9
         }*/
         output_bit(PIN_A2,1);
         delay_ms(200);
      }
      output_bit(PIN_A2,1);
      output_bit(PIN_A3,0);
      //output_a(0b00000111);
      if(!input(PIN_A5)){
         //++c1;
         puertob[3]=puertob[2];
         puertob[2]=puertob[1];
         puertob[1]=puertob[0];
         puertob[0]=0;
         /*if(c1<=4){ 
            puertob[c1-1]=0;//0
         }else{
            puertob[0]=puertob[1]; puertob[1]=puertob[2]; puertob[2]=puertob[3];puertob[3]=0;//0
         }*/
         output_bit(PIN_A3,1);
         delay_ms(200);
      }
      if(!input(PIN_A6)){
         /*if(c1==1) taps=puertob[0];
         if(c1==2) taps=puertob[0]*10+puertob[1];
         if(c1==3) taps=puertob[0]*100+puertob[1]*10+puertob[2];
         if(c1>=4) taps=puertob[0]*1000+puertob[1]*100+puertob[2]*10+puertob[3];*/
         temp=puertob[3]*1000+puertob[2]*100+puertob[1]*10+puertob[0];
         if(b2==1){
            saltos=temp;
            b3=1;
            temp=tabla(taps);
         }
         if( temp>=100 && temp<=300 && b2==0 ){ 
            b2=1;
            taps=temp;
         }
         //if( !b2 || !b3 ) puertob[0]=puertob[1]=puertob[2]=puertob[3]=0;
         output_bit(PIN_A3,1);
         delay_ms(200);
         //pwm_off();
         //output_low(PIN_C7);//para reset y enable del driver....
      }
      }else{
         if(b4==0){
            b4=1;
            output_high(PIN_A7);//para reset y enable del driver....
            pwm_set_frequency(8000);//1600 para 1 tap por segundo
            pwm_set_duty_percent(500);
            while(saltos>0){//while saltos
               pwm_on();
               --saltos;
               puertob[3]=saltos/1000;
               puertob[2]=(saltos-puertob[3]*1000)/100;
               puertob[1]=(saltos-puertob[3]*1000-puertob[2]*100)/10;
               puertob[0]=saltos-puertob[3]*1000-puertob[2]*100-puertob[1]*10;
               for(c1=0;c1<10;++c1){
                  output_low(PIN_A0);//m\E1s a la derecha
                  imprimir(puertob[0]);//imprime n\FAmero seleccionado
                  delay_ms(5);
                  output_high(PIN_A0);
                  output_low(PIN_A1);
                  imprimir(puertob[1]);//imprime n\FAmero seleccionado
                  delay_ms(5);
                  output_high(PIN_A1);
                  output_low(PIN_A2);
                  imprimir(puertob[2]);//imprime n\FAmero seleccionado
                  delay_ms(5);
                  output_high(PIN_A2);
                  output_low(PIN_A3);//m\E1s a la izquierda (miles)
                  imprimir(puertob[3]);//imprime n\FAmero seleccionado
                  if(!input(PIN_A6)){
                     saltos=0;
                     c1=10;
                     puertob[0]=puertob[1]=puertob[2]=puertob[3]=0;
                  }
                  delay_us(4930);
                  output_high(PIN_A3);
               }
               if( taps<=147 ){
                  pwm_off();
                  for(c1=0;c1<20;++c1){//for 2
                     output_low(PIN_A0);//m\E1s a la derecha
                     imprimir(puertob[0]);//imprime n\FAmero seleccionado
                     delay_us(temp);
                     output_high(PIN_A0);
                     output_low(PIN_A1);
                     imprimir(puertob[1]);//imprime n\FAmero seleccionado
                     delay_us(temp);
                     output_high(PIN_A1);
                     output_low(PIN_A2);
                     imprimir(puertob[2]);//imprime n\FAmero seleccionado
                     delay_us(temp);
                     output_high(PIN_A2);
                     output_low(PIN_A3);//m\E1s a la izquierda (miles)
                     imprimir(puertob[3]);//imprime n\FAmero seleccionado
                     if(!input(PIN_A6)){
                        saltos=0;
                        c1=20;
                        puertob[0]=puertob[1]=puertob[2]=puertob[3]=0;
                     }
                     delay_us(temp);
                     output_high(PIN_A3);
                  }//fin for 2
               }else{//fin if (taps<=275 )
                  pwm_off();
                  delay_us(temp);
               }//fin else
            }// fin while saltos
            b2=b3=b4=0;
            output_low(PIN_A7);//para reset y enable del driver....
         }
         /*if(b5==0){
            b5=1;
            setup_timer_1(T1_INTERNAL|T1_DIV_BY_8);//Setup timer: Reloj interno, preescaler= 8
            enable_interrupts(INT_TIMER1);//Habilito interrupci\F3n particular del TIMER1
            enable_interrupts(GLOBAL);//Habilito interrupciones globales
            set_timer1(3036);//Carga del TMR1
         }
         if(b6==1 && taps>saltos){
            b6=0;
            puertob[3]=saltos/1000;
            puertob[2]=(saltos-puertob[3]*1000)/100;
            puertob[1]=(saltos-puertob[3]*1000-puertob[2]*100)/10;
            puertob[0]=saltos-puertob[3]*1000-puertob[2]*100-puertob[1]*10;
            if(saltos==0){
               pwm_off();
               output_low(PIN_C7);//para reset y enable del driver....
               b2=b3=b4=b5=0;
            }
            if(c1==1) puertob[0]=saltos;
            if(c1==2){
               puertob[0]=saltos/10;
               puertob[1]=saltos-puertob[0]*10;
            }
            if(c1==3){
               puertob[0]=saltos/100;
               puertob[1]=(saltos-puertob[0]*100)/10;
               puertob[2]=saltos-puertob[0]*100-puertob[1]*10;
            }
            if(c1>=4){
               puertob[0]=saltos/1000;
               puertob[1]=(saltos-puertob[0]*1000)/100;
               puertob[2]=(saltos-puertob[0]*1000-puertob[1]*100)/10;
               puertob[3]=saltos-puertob[0]*1000-puertob[1]*100-puertob[2]*10;
            }
         }*/
      }
      /*if(puertob[0]!=0) b1=1;
      if(b1==1){*/
         //output_b(puertob);//imprime n\FAmero seleccionado
         //delay_ms(200);
         output_high(PIN_A0);
         output_high(PIN_A1);
         output_high(PIN_A2);
         output_high(PIN_A3);
         //output_a(0b00001111);
         /*if(c1==1){
            output_low(PIN_C0);
            imprimir(puertob[0]);//imprime n\FAmero seleccionado
            delay_ms(10);
         }
         if(c1==2){
            output_low(PIN_C0);
            imprimir(puertob[1]);//imprime n\FAmero seleccionado
            delay_ms(10);
            output_high(PIN_C0);
            output_low(PIN_C1);
            imprimir(puertob[0]);//imprime n\FAmero seleccionado
            delay_ms(10);
         }
         if(c1==3){
            output_low(PIN_C0);
            imprimir(puertob[2]);//imprime n\FAmero seleccionado
            delay_ms(8);
            output_high(PIN_C0);
            output_low(PIN_C1);
            imprimir(puertob[1]);//imprime n\FAmero seleccionado
            delay_ms(8);
            output_high(PIN_C1);
            output_low(PIN_C2);
            imprimir(puertob[0]);//imprime n\FAmero seleccionado
            delay_ms(8);
         }
         if(c1>=4){*/
            output_low(PIN_A0);//m\E1s a la derecha
            imprimir(puertob[0]);//imprime n\FAmero seleccionado
            delay_ms(5);
            output_high(PIN_A0);
            output_low(PIN_A1);
            imprimir(puertob[1]);//imprime n\FAmero seleccionado
            delay_ms(5);
            output_high(PIN_A1);
            output_low(PIN_A2);
            imprimir(puertob[2]);//imprime n\FAmero seleccionado
            delay_ms(5);
            output_high(PIN_A2);
            output_low(PIN_A3);//m\E1s a la izquierda (miles)
            imprimir(puertob[3]);//imprime n\FAmero seleccionado
            delay_ms(5);
         //}
      /*}else{
        if(on==0){ 
         output_low(PIN_C0);//parpadeo inicial para verificar que todos prenden
         output_low(PIN_C1);
         output_low(PIN_C2);
         output_low(PIN_C3);
         imprimir(0);//prende todos
         delay_ms(200);//pausa
         output_high(PIN_C0);//se apagan todos
         output_high(PIN_C1);
         output_high(PIN_C2);
         output_high(PIN_C3);
         delay_ms(200);//pausa
         output_low(PIN_C0);
         output_low(PIN_C1);
         output_low(PIN_C2);
         output_low(PIN_C3);
         imprimir(0);//prende todos
         delay_ms(200);//pausa
         output_high(PIN_C0);//apaga todos
         output_high(PIN_C1);
         output_high(PIN_C2);
         output_high(PIN_C3);
         delay_ms(200);//pausa
         on=1;
        }
         output_low(PIN_C0);//habilita primero de la izquierda!
         output_high(PIN_C1);
         output_high(PIN_C2);
         output_high(PIN_C3);
         imprimir(0);//display con un solo cero
         delay_ms(10);
      }*/
   }//fin while(true)
}

