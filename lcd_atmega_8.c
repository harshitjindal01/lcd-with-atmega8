#include <io.h>
#include <delay.h>
#include <mega8.h>
#define F_XTAL 12000000L

void cmd(unsigned char a)
    {
    PORTD=0b00000001;  
    PORTB=a; 
    delay_ms(10);
    PORTD=0b00000000;
    delay_ms(10);
    } 
void lcd1(unsigned char b)
    { 
    PORTD=0b00000101; 
    PORTB =b;
    delay_ms(10);
    PORTD=0b00000100;
    delay_ms(10);
    } 
    
void string1(char *str)
{
     while(*str!='\0')
     {               
      lcd1(*str);
      str++;
     }
}

void init(){
  cmd(0x38);        //LCD initialization
  cmd(0x01);        //clear display screen
  cmd(0x0e);        //display on cursor off
  cmd(0x06);        //shift 
  cmd(0x02);        //return to home
}


void main(){
DDRB=0xFF;
DDRD=0x07;

init();

while(1)
{
cmd(0x83);
string1("code by");
cmd(0xC4);
string1("harshit jindal");
delay_ms(100);

cmd(0x01);
}

}
