#include "print.h"
extern void outb(uint8_t value, uint16_t port);
extern uint8_t inb(uint16_t port);

void irq0_handler(void)
{
    outb(0x20, 0x20); //EOI
}

void irq1_handler(void)
{
    uint8_t status;
    uint8_t keycode;
    outb(0x20, 0x20); //EOI

    status = inb(0x64);

    if(status & 0x01) {
        keycode = inb(0x60);
        if(keycode < 0)
            return;
        print_char('P');

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