/*******************************************************************************
 * Kütüphane : xsLCD                                                           *
 * Yazar     : sigmoid                                                         *
 * Web       : http://www.hayaldefteri.net                                     *
 * Tarih     : 01 Mayýs 2014                                                   *
 * Versiyon  : 0.1                                                             *
 *                                                                             *
 * HD44780 karakter LCD  kütüphanesi                                            *
 ******************************************************************************/

/*      Standart LCD ayak baðlantýlarý
1: Gnd  2: Vcc  3: Vee - Kontras ayaðý
4: RS   5: RW   6: E
7: D0   8: D1   9: D2   10: D3  11: D4  12: D5  13: D6  14: D7
15: Backlight Vcc       16: Backlight Gnd                                     */

//PIC'in çalýþma frekansý
#ifndef _XTAL_FREQ
    #define _XTAL_FREQ 4000000
#endif

//#define LCDBIT8    //lcd ekrana 8bit mi eriþilecek
#define LCDBIT4    //yoksa 4 bit mi?

//#define LCDustpin     //4bit eriþilecekse hangi pinler kullanýlacak
#define LCDaltpin


//RW pini PIC'e mi yoksa Topraða mý baðlý
#define lcd_rw_aktif

//printf fonksiyonu lcd'ye yazacak mý?
#define lcdprintf_aktif

// kullanýlacak lcd ayaklar?
#define lcd_data	PORTD
#define lcd_tris	TRISD
#define lcd_rs          PORTAbits.RA0
#define lcd_tris_rs     TRISAbits.TRISA0
#define lcd_rw          PORTAbits.RA1
#define lcd_tris_rw     TRISAbits.TRISA1
#define lcd_e           PORTAbits.RA2
#define lcd_tris_e      TRISAbits.TRISA2

//fonksiyon prototipleri
void lcd_baslat(void);
void lcd_git(char satir, char sutun);
void lcd_mesajyaz(char satir, char sutun, const char *mesaj);
void lcd_mesajyaz_cp(const char *mesaj);
#ifdef lcd_rw_aktif
    void lcd_mesgulmu(void);
    char lcd_harfoku(void);
#endif
void lcd_harfyaz(char harf);
void lcd_ozelkarakter(char karakterno,char patern[8]);
void lcd_komut(char komut);
void lcd_sil(void);
void lcd_satirbasi(void);
void lcd_kursor_ac(void);
void lcd_kursor_kapat(void);
void lcd_display_ac(void);
void lcd_display_kapat(void);
void lcd_blink_ac(void);
void lcd_blink_kapat(void);
void lcd_sola_kaydir(void);
void lcd_saga_kaydir(void);
void lcd_satir1(void);
void lcd_satir2(void);
void lcd_satir3(void);
void lcd_satir4(void);
#ifdef lcdprintf_aktif
void putch(unsigned char byte);
#endif
