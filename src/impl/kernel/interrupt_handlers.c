#include "print.h"
#include "keyboard.h"
extern void outb(uint16_t port, uint8_t value);
extern uint8_t inb(uint16_t port);

void printCharmap();

void irq0_handler(void)
{
    outb(0x20, 0x20); //EOI
}

void irq1_handler(void)
{
    uint8_t status;
    uint8_t keycode;

    status = inb(0x64);

    if (status & 0x01)
    {
        keycode = inb(0x60);
        if (keycode < 0)
            return;
        
        if(keycode & 0x80) {
            keycode -= 0x80;
            keyboard_statusmap[keycode] = 0;
            printCharmap();
        }
        else {
            if(keyboard_statusmap[keycode]==0){
                keyboard_statusmap[keycode] = 1;
                printCharmap();
            }
        }

    }
    outb(0x20, 0x20); //EOI
}

void printCharmap() {
    print_clear();

        for(int i=0;i<128;i++) {
            if(i%8==0)
                print_newline();
            
            char charToPrint = keyboard_asciimap[i];
            print_char(charToPrint=='\n'?' ':charToPrint);
            print_char(':');
            print_char(keyboard_statusmap[i]?'1':'0');
            print_char(' ');
        }
}

void irq2_handler(void)
{
    outb(0x20, 0x20); //EOI
}

void irq3_handler(void)
{
    outb(0x20, 0x20); //EOI
}

void irq4_handler(void)
{
    outb(0x20, 0x20); //EOI
}

void irq5_handler(void)
{
    outb(0x20, 0x20); //EOI
}

void irq6_handler(void)
{
    outb(0x20, 0x20); //EOI
}

void irq7_handler(void)
{
    outb(0x20, 0x20); //EOI
}

void irq8_handler(void)
{
    outb(0xA0, 0x20);
    outb(0x20, 0x20); //EOI
}

void irq9_handler(void)
{
    outb(0xA0, 0x20);
    outb(0x20, 0x20); //EOI
}

void irq10_handler(void)
{
    outb(0xA0, 0x20);
    outb(0x20, 0x20); //EOI
}

void irq11_handler(void)
{
    outb(0xA0, 0x20);
    outb(0x20, 0x20); //EOI
}

void irq12_handler(void)
{
    outb(0xA0, 0x20);
    outb(0x20, 0x20); //EOI
}

void irq13_handler(void)
{
    outb(0xA0, 0x20);
    outb(0x20, 0x20); //EOI
}

void irq14_handler(void)
{
    outb(0xA0, 0x20);
    outb(0x20, 0x20); //EOI
}

void irq15_handler(void)
{
    outb(0xA0, 0x20);
    outb(0x20, 0x20); //EOI
}

void generic_handler_impl(void)
{
    outb(0xA0, 0x20);
    outb(0x20, 0x20); //EOI
}