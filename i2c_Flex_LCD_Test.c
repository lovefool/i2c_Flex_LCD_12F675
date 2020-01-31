//************************************************************************************ 
// LCD Display test code for "i2c_Flex_LCD" using Phillips PCF8574T 
// By Hugo Silva - Jun 06Th 2015 
// Based in the 20x4 LCD driver test code (by PCM programmer) with a few changes made 
//************************************************************************************ 
#include <12f675.h> 
#use delay (clock=4000000) 
#use i2c(Master,sda=PIN_A5, scl=PIN_A4) 
#include <i2c_Flex_LCD.h> 
#fuses NOWDT, NOMCLR, INTRC_IO, BROWNOUT, PUT

void main() {  
int i=0; 
lcd_init(); 
// lcd_backlight_led(ON); //Backligth ON 
  
 while (TRUE) { 
   lcd_clear();  //Clear Display 

   // Test the clear screen and newline commands. 
   // Also test that we can write to all 4 lines. 
   printf(lcd_putc, "\fThis is the 1st line"); 
   delay_ms(500); 
   printf(lcd_putc, "\nNext is the 2nd line"); 
   delay_ms(500); 
//   printf(lcd_putc, "\nThis is the 3rd line"); 
//   delay_ms(500); 
//   printf(lcd_putc, "\nFinally the 4th line"); 
//   delay_ms(1000); 

   // Test some additional characters. 
   printf(lcd_putc, "\fABCDEFGHIJKLMNOPQRST"); 
   delay_ms(500); 
   printf(lcd_putc, "\nabcdefghijklmnopqrst"); 
   delay_ms(500); 
//   printf(lcd_putc, "\n12345678901234567890"); 
//   delay_ms(500); 
//   printf(lcd_putc, "\n!@#$^&*(){}[]:;<>?/="); 
//   delay_ms(500); 

   // Clear the LCD. 
//   printf(lcd_putc, "\f"); 
//   delay_ms(500); 

   // Test that lcd_gotoxy() works.  Go to each of 
   // the four corners and put a number in each one, 
   // in a clockwise direction, starting with the upper 
   // left corner. 
//   lcd_gotoxy(5, 2);        
//   printf(lcd_putc, "Put a Nr. in");    
//   lcd_gotoxy(5, 3);        
//   printf(lcd_putc, "each corner"); 
//   delay_ms(500); 
//   lcd_gotoxy(1, 1);        
//   printf(lcd_putc, "1"); 
//   delay_ms(500); 
//   lcd_gotoxy(20, 1);        
//   printf(lcd_putc, "2"); 
//   delay_ms(500); 
//   lcd_gotoxy(20, 4);        
//   printf(lcd_putc, "3"); 
//   delay_ms(500); 
//   lcd_gotoxy(1, 4);        
//   printf(lcd_putc, "4");    
//   delay_ms(1000); 

// Read the character that was written in each corner 
// of the LCD and display it.   This tests the lcd_getc() 
// function.    
// The following test can only be done if we can read 
// from the LCD.  If the RW pin is not used, then the 
// LCD is in write-only mode, and we can't do this test. 
// The #ifdef statement will prevent the code from 
// being compiled, in that case. 

#ifdef USE_RW_PIN    
   // Test if lcd_getc() can read 
   // a byte from each corner. 
   b1 = lcd_getc(1,1);    
   b2 = lcd_getc(20,1);    
   b3 = lcd_getc(20,4);    
   b4 = lcd_getc(1,4);    
   lcd_gotoxy(1, 1);        
   printf(lcd_putc, "\fRead these bytes\n"); 
   printf(lcd_putc, "from the 4 corners:\n\n"); 
   printf(lcd_putc, "     %c %c %c %c", b1, b2, b3, b4);        
   delay_ms(3000); 
#endif 

/*
   // Type some characters and backspace over them. 
   printf(lcd_putc, "\f\nType characters and\n"); 
   printf(lcd_putc,   "backspace over them."); 
   delay_ms(500); 

   // Go to end of 3rd line. 
   lcd_gotoxy(20, 3);        

   // Backspace over 2nd line. 
   for(i = 0; i < 20; i++) 
      { 
       printf(lcd_putc," \b\b"); 
       delay_ms(50); 
      } 

   // Go to end of first line.                
   lcd_gotoxy(20, 2);        

   // Backspace over first line. 
   for(i = 0; i < 20; i++) 
      { 
       printf(lcd_putc," \b\b"); 
       delay_ms(50); 
      }  
*/

   }    
} 
