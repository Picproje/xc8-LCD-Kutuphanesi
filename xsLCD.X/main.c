/*******************************************************************************
 * File:   main.c                                                              *
 * Author: sigmoid                                                             *
 *                                                                             *
 * xsLCD kütüphanesi test programý                                             *
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include <xc.h>

#define _XTAL_FREQ 4000000

#include "xsLCD.h"

 // CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)


char kalp[8]={
0b00000,
0b01010,
0b10101,
0b10001,
0b01010,
0b00100,
0b00000,
0b00000,
};

void main(int argc, char** argv) {

    char i;
    ADCON1=0x07;
    lcd_baslat();
    lcd_sil();

    //1. demo
    lcd_mesajyaz(1,1,"Merhaba");
    lcd_mesajyaz(2,5,"PicProje");
    __delay_ms(5000);   //5 sn bekle.
    lcd_sil();

    //2.demo
    lcd_ozelkarakter(0,kalp);   //kalp sembolü lcd ekrana çizilir.
    lcd_mesajyaz(2,5,"PicProje");
    lcd_git(2,3);
    lcd_harfyaz(0); // kalp sembölünü çiz.
    __delay_ms(5000);   //5 sn bekle.
    lcd_sil();

    //3.demo
    //lcd_ozelkarakter(0,kalp);
    lcd_harfyaz(0);
    lcd_mesajyaz_cp(" PicProje ");
    lcd_harfyaz(0);

    while(1)
    {
        for(i=0;i<4;i++){
        __delay_ms(300);
        lcd_saga_kaydir();
        }

        for(i=0;i<4;i++){
        __delay_ms(300);
        lcd_sola_kaydir();
        }
    }


//   bu aþaðýdaki kodun çalýþmasý için #lcd_rw_aktif seçilmelidir.
//   lcd_mesajyaz(1,1,"xsLCDKutuphanesi");
//   lcd_mesajyaz(2,5,"Picproje");
//
//   while(1);
//
//    lcd_git(1,1);
//    char a=lcd_harfoku();
//    char b=lcd_harfoku();
//    char c=lcd_harfoku();
//
//    lcd_git(2,1);
//    lcd_harfyaz(a);
//    lcd_harfyaz(b);
//    lcd_harfyaz(c);
//
//    lcd_mesajyaz(2,5,"deneme");

    while(1);
}

