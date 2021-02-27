#include "print.h"
extern void outb(unsigned char value, unsigned short port);
extern unsigned char inb(unsigned short port);

void irq0_handler(void)
{
    outb(0x20, 0x20); //EOI
}

void irq1_handler(void)
{
    
    print_char(inb(0x60));
    outb(0x20, 0x20); //EOI
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