// https://wiki.osdev.org/Interrupts_tutorial
#include <stdint.h>
#include "print.h"
extern void outb(uint8_t value, unsigned short port);

void write_port(uint16_t port,uint8_t value) {
	outb(value,port);
}

struct IDT_entry
{
	uint16_t offset_1;
	uint16_t selector;
	uint8_t ist;
	uint8_t type_attr;
	uint16_t offset_2;
	uint32_t offset_3;
	uint32_t zero;
};

struct IDT_entry IDT[256];
extern int load_idt();

void idt_init(void)
{

	uint64_t keyboard_address;
	uint64_t idt_address;
	uint64_t idt_ptr[2];
	extern void irq1();
	uint16_t IDT_SIZE = 256;

	/* populate IDT entry of keyboard's interrupt */
	keyboard_address = (uint64_t)irq1;
	IDT[0x21].offset_1 = (keyboard_address & 0x000000000000ffff);
	IDT[0x21].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
	IDT[0x21].ist = 0;
	IDT[0x21].type_attr = 0x8e; /* INTERRUPT_GATE */
	IDT[0x21].offset_2 = (keyboard_address & 0x00000000ffff0000) >> 16;
	IDT[0x21].offset_3 = (keyboard_address & 0xffffffff00000000) >> 32;


	/*     Ports
	*	 PIC1	PIC2
	*Command 0x20	0xA0
	*Data	 0x21	0xA1
	*/

	/* ICW1 - begin initialization */
	write_port(0x20, 0x11);
	write_port(0xA0, 0x11);

	/* ICW2 - remap offset address of IDT */
	/*
	* In x86 protected mode, we have to remap the PICs beyond 0x20 because
	* Intel have designated the first 32 interrupts as "reserved" for cpu exceptions
	*/
	write_port(0x21, 0x20);
	write_port(0xA1, 0x28);

	/* ICW3 - setup cascading */
	write_port(0x21, 0x00);
	write_port(0xA1, 0x00);

	/* ICW4 - environment info */
	write_port(0x21, 0x01);
	write_port(0xA1, 0x01);
	/* Initialization finished */

	/* mask interrupts */
	write_port(0x21, 0xff);
	write_port(0xA1, 0xff);

	/* fill the IDT descriptor */
	idt_address = (uint64_t)IDT;
	idt_ptr[0] = (sizeof(struct IDT_entry) * 8 * IDT_SIZE - 1) & 0xFFFF;
	idt_ptr[0] = idt_ptr[0] | ((idt_address & 0xFFFFFFFFFFFF) << 16); 
	idt_ptr[1] = idt_address >> 48;
	print_num(idt_address);
	load_idt(idt_ptr);
}