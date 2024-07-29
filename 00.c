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

static BOOLEAN b2=0, b3=0, b4=0;	// b2 para indicar que se ingresó la frecuencia y b3 la cantidad de saltos
static int16 temp=0,c1=0, taps=0, saltos=0, puertob[4]={0,0,0,0};

void main()
{

   pwm_off();
   output_low(PIN_C7);//para reset y enable del driver....

   while(true){

	// Primero leo la frecuencia y la cantidad de saltos

	if( !b2 || !b3 ){

		/*output_bit(PIN_A0,0);
		output_bit(PIN_A1,1);
		output_bit(PIN_A2,1);
		output_bit(PIN_A3,1);*/

		// bloque de codigo para el panel numérico

		output_a(0b00001110);	// primera fila, números del 1 al 3

		if(!input(PIN_A4)){ 
			//++c1;
			puertob[3]=puertob[2];	// para ir rotando los números en el display de 4 dígitos
			puertob[2]=puertob[1];
			puertob[1]=puertob[0];
			puertob[0]=1;		// guarda número 1
			/*if(c1<=4){ 
				puertob[c1-1]=1;//1
			}else{
				puertob[0]=puertob[1]; puertob[1]=puertob[2]; puertob[2]=puertob[3];puertob[3]=1;//1
			}*/
			output_bit(PIN_A0,1); // vuelvo 1 para la siguiente lectura
			delay_ms(200);
		}

      		if(!input(PIN_C0)){
         		//++c1;
         		puertob[3]=puertob[2];	// para ir rotando los números en el display de 4 dígitos
         		puertob[2]=puertob[1];
         		puertob[1]=puertob[0];
         		puertob[0]=2;		// guarda el número 2
         		/*if(c1<=4){ 
				puertob[c1-1]=2;//2
         		}else{
				puertob[0]=puertob[1]; puertob[1]=puertob[2]; puertob[2]=puertob[3];puertob[3]=2;//2
			}*/
			output_bit(PIN_A0,1);	// cambio a alto para la siguiente lectura
			delay_ms(200);
		}

		if(!input(PIN_C6)){
			//++c1;
			puertob[3]=puertob[2];	// para ir rotando los números en el display de 4 dígitos
			puertob[2]=puertob[1];
			puertob[1]=puertob[0];
			puertob[0]=3;		// guarda el número 3
			/*if(c1<=4){
				puertob[c1-1]=3;//3
			}else{
				puertob[0]=puertob[1]; puertob[1]=puertob[2]; puertob[2]=puertob[3];puertob[3]=3;//3
			}*/
			output_bit(PIN_A0,1);	// cambio a alto para la siguiente lectura
			delay_ms(200);
		}

		/*output_bit(PIN_A0,1);
		output_bit(PIN_A1,0);*/

		output_a(0b00001101);	// segunda fila, números del 4 al 6

		if(!input(PIN_A4)){
			//++c1;
			puertob[3]=puertob[2];
			puertob[2]=puertob[1];
			puertob[1]=puertob[0];
			puertob[0]=4;		// guarda el número 4
			/*if(c1<=4){ 
				puertob[c1-1]=4;//4
			}else{
				puertob[0]=puertob[1]; puertob[1]=puertob[2]; puertob[2]=puertob[3];puertob[3]=4;//4
			}*/
			output_bit(PIN_A1,1);	// cambio a alto para la siguiente lectura
			delay_ms(200);
		}

		if(!input(PIN_C0)){
			//++c1;
			puertob[3]=puertob[2];
			puertob[2]=puertob[1];
			puertob[1]=puertob[0];
			puertob[0]=5;		// guarda el número 5
			/*if(c1<=4){
				puertob[c1-1]=5;//5
			}else{
				puertob[0]=puertob[1]; puertob[1]=puertob[2]; puertob[2]=puertob[3];puertob[3]=5;//5
			}*/
			output_bit(PIN_A1,1);	// cambio a alto para la siguiente lectura
			delay_ms(200);
		}

		if(!input(PIN_C6)){
			//++c1;
			puertob[3]=puertob[2];
			puertob[2]=puertob[1];
			puertob[1]=puertob[0];
			puertob[0]=6;	// guarda el número 6
			/*if(c1<=4){
				puertob[c1-1]=6;//6
			}else{
				puertob[0]=puertob[1]; puertob[1]=puertob[2]; puertob[2]=puertob[3];puertob[3]=6;//6
			}*/
			output_bit(PIN_A1,1);	// cambio a alto para la siguiente lectura
			delay_ms(200);
		}

		/*output_bit(PIN_A1,1);
		output_bit(PIN_A2,0);*/

		output_a(0b00001011);	// siguiente fila, números del 7 al 9

		if(!input(PIN_A4)){
			//++c1;
			puertob[3]=puertob[2];
			puertob[2]=puertob[1];
			puertob[1]=puertob[0];
			puertob[0]=7;		// guarda el número 7
			/*if(c1<=4){
				puertob[c1-1]=7;//7
			}else{
				puertob[0]=puertob[1]; puertob[1]=puertob[2]; puertob[2]=puertob[3];puertob[3]=7;//7
			}*/
			output_bit(PIN_A2,1);	// cambio a alto para la siguiente lectura
			delay_ms(200);
		}

		if(!input(PIN_C0)){
			//++c1;
			puertob[3]=puertob[2];
			puertob[2]=puertob[1];
			puertob[1]=puertob[0];
			puertob[0]=8;		// guarda el número 8
			/*if(c1<=4){ 
				puertob[c1-1]=8;//8
			}else{
				puertob[0]=puertob[1]; puertob[1]=puertob[2]; puertob[2]=puertob[3];puertob[3]=8;//8
			}*/
			output_bit(PIN_A2,1);	// cambio a alto para la siguiente lectura
			delay_ms(200);
		}

		if(!input(PIN_C6)){
			//++c1;
			puertob[3]=puertob[2];
			puertob[2]=puertob[1];
			puertob[1]=puertob[0];
			puertob[0]=9;		// guarda el número 9
			/*if(c1<=4){
				puertob[c1-1]=9;//9
			}else{
				puertob[0]=puertob[1]; puertob[1]=puertob[2]; puertob[2]=puertob[3];puertob[3]=9;//9
			}*/
			output_bit(PIN_A2,1);	// cambio a alto para la siguiente lectura
			delay_ms(200);
		}

		/*output_bit(PIN_A2,1);
		output_bit(PIN_A3,0);*/

      		output_a(0b00000111);		// siguiente fila, cero y tecla para "Enter"

		if(!input(PIN_C0)){
			//++c1;
			puertob[3]=puertob[2];
			puertob[2]=puertob[1];
			puertob[1]=puertob[0];
			puertob[0]=0;		// guarda el número 0
			/*if(c1<=4){
				puertob[c1-1]=0;//0
			}else{
				puertob[0]=puertob[1]; puertob[1]=puertob[2]; puertob[2]=puertob[3];puertob[3]=0;//0
			}*/
			output_bit(PIN_A3,1);	// cambio a alto para la siguiente lectura
			delay_ms(200);
		}

		if(!input(PIN_C6)){
			/*if(c1==1) taps=puertob[0];
			if(c1==2) taps=puertob[0]*10+puertob[1];
			if(c1==3) taps=puertob[0]*100+puertob[1]*10+puertob[2];
			if(c1>=4) taps=puertob[0]*1000+puertob[1]*100+puertob[2]*10+puertob[3];*/

			temp=puertob[3]*1000+puertob[2]*100+puertob[1]*10+puertob[0];	// convierte número en el display a entero de 2 bytes

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
	}else{	// del if( !b2 || !b3 )

         if(b4==0){
            b4=1;
            output_high(PIN_C7);//para reset y enable del driver....
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
                  output_low(PIN_A0);//más a la derecha
                  imprimir(puertob[0]);//imprime número seleccionado
                  delay_ms(5);
                  output_high(PIN_A0);
                  output_low(PIN_A1);
                  imprimir(puertob[1]);//imprime número seleccionado
                  delay_ms(5);
                  output_high(PIN_A1);
                  output_low(PIN_A2);
                  imprimir(puertob[2]);//imprime número seleccionado
                  delay_ms(5);
                  output_high(PIN_A2);
                  output_low(PIN_A3);//más a la izquierda (miles)
                  imprimir(puertob[3]);//imprime número seleccionado
                  if(!input(PIN_C6)){
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
                     output_low(PIN_A0);//más a la derecha
                     imprimir(puertob[0]);//imprime número seleccionado
                     delay_us(temp);
                     output_high(PIN_A0);
                     output_low(PIN_A1);
                     imprimir(puertob[1]);//imprime número seleccionado
                     delay_us(temp);
                     output_high(PIN_A1);
                     output_low(PIN_A2);
                     imprimir(puertob[2]);//imprime número seleccionado
                     delay_us(temp);
                     output_high(PIN_A2);
                     output_low(PIN_A3);//más a la izquierda (miles)
                     imprimir(puertob[3]);//imprime número seleccionado
                     if(!input(PIN_C6)){
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
            output_low(PIN_C7);//para reset y enable del driver....
         }
         /*if(b5==0){
            b5=1;
            setup_timer_1(T1_INTERNAL|T1_DIV_BY_8);//Setup timer: Reloj interno, preescaler= 8
            enable_interrupts(INT_TIMER1);//Habilito interrupción particular del TIMER1
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
         //output_b(puertob);//imprime número seleccionado
         //delay_ms(200);
         /*output_high(PIN_A0);
         output_high(PIN_A1);
         output_high(PIN_A2);
         output_high(PIN_A3);*/
         output_a(0b00001111);
         /*if(c1==1){
            output_low(PIN_C0);
            imprimir(puertob[0]);//imprime número seleccionado
            delay_ms(10);
         }
         if(c1==2){
            output_low(PIN_C0);
            imprimir(puertob[1]);//imprime número seleccionado
            delay_ms(10);
            output_high(PIN_C0);
            output_low(PIN_C1);
            imprimir(puertob[0]);//imprime número seleccionado
            delay_ms(10);
         }
         if(c1==3){
            output_low(PIN_C0);
            imprimir(puertob[2]);//imprime número seleccionado
            delay_ms(8);
            output_high(PIN_C0);
            output_low(PIN_C1);
            imprimir(puertob[1]);//imprime número seleccionado
            delay_ms(8);
            output_high(PIN_C1);
            output_low(PIN_C2);
            imprimir(puertob[0]);//imprime número seleccionado
            delay_ms(8);
         }
         if(c1>=4){*/
            //output_low(PIN_A0);//más a la derecha
            output_a(0b00001110);
            imprimir(puertob[0]);//imprime número seleccionado
            delay_ms(5);
            /*output_high(PIN_A0);
            output_low(PIN_A1);*/
            output_a(0b00001101);
            imprimir(puertob[1]);//imprime número seleccionado
            delay_ms(5);
            /*output_high(PIN_A1);
            output_low(PIN_A2);*/
            output_a(0b00001011);
            imprimir(puertob[2]);//imprime número seleccionado
            delay_ms(5);
            /*output_high(PIN_A2);
            output_low(PIN_A3);*///más a la izquierda (miles)
            output_a(0b00000111);
            imprimir(puertob[3]);//imprime número seleccionado
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
