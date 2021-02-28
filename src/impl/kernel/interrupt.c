// https://wiki.osdev.org/Interrupts_tutorial
#include <stdint.h>
#include "print.h"
extern void outb(uint16_t port, uint8_t value);

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

static const uint16_t IDT_SIZE = 256;
struct IDT_entry IDT[256];
extern int load_idt();

extern int irq0();
extern int irq1();
extern int irq2();
extern int irq3();
extern int irq4();
extern int irq5();
extern int irq6();
extern int irq7();
extern int irq8();
extern int irq9();
extern int irq10();
extern int irq11();
extern int irq12();
extern int irq13();
extern int irq14();
extern int irq15();
extern int generic_handler();

uint64_t irq0_address;
uint64_t irq1_address;
uint64_t irq2_address;
uint64_t irq3_address;
uint64_t irq4_address;
uint64_t irq5_address;
uint64_t irq6_address;
uint64_t irq7_address;
uint64_t irq8_address;
uint64_t irq9_address;
uint64_t irq10_address;
uint64_t irq11_address;
uint64_t irq12_address;
uint64_t irq13_address;
uint64_t irq14_address;
uint64_t irq15_address;
uint64_t generic_handler_address;

void idt_init(void)
{

	irq0_address = (uint64_t)irq0;
	IDT[0x20].offset_1 = (irq1_address & 0x000000000000ffff);
	IDT[0x20].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
	IDT[0x20].ist = 0;
	IDT[0x20].type_attr = 0x8e; /* INTERRUPT_GATE */
	IDT[0x20].offset_2 = (irq1_address & 0x00000000ffff0000) >> 16;
	IDT[0x20].offset_3 = (irq1_address & 0xffffffff00000000) >> 32;

	irq1_address = (uint64_t)irq1;
	IDT[0x21].offset_1 = (irq1_address & 0x000000000000ffff);
	IDT[0x21].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
	IDT[0x21].ist = 0;
	IDT[0x21].type_attr = 0x8e; /* INTERRUPT_GATE */
	IDT[0x21].offset_3 = (irq1_address & 0xffffffff00000000) >> 32;
	IDT[0x21].offset_2 = (irq1_address & 0x00000000ffff0000) >> 16;

	irq2_address = (uint64_t)irq2;
	IDT[0x22].offset_1 = (irq2_address & 0x000000000000ffff);
	IDT[0x22].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
	IDT[0x22].ist = 0;
	IDT[0x22].type_attr = 0x8e; /* INTERRUPT_GATE */
	IDT[0x22].offset_2 = (irq2_address & 0x00000000ffff0000) >> 16;
	IDT[0x22].offset_3 = (irq2_address & 0xffffffff00000000) >> 32;

	irq3_address = (uint64_t)irq3;
	IDT[0x23].offset_1 = (irq3_address & 0x000000000000ffff);
	IDT[0x23].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
	IDT[0x23].ist = 0;
	IDT[0x23].type_attr = 0x8e; /* INTERRUPT_GATE */
	IDT[0x23].offset_2 = (irq3_address & 0x00000000ffff0000) >> 16;
	IDT[0x23].offset_3 = (irq3_address & 0xffffffff00000000) >> 32;

	irq4_address = (uint64_t)irq4;
	IDT[0x24].offset_1 = (irq4_address & 0x000000000000ffff);
	IDT[0x24].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
	IDT[0x24].ist = 0;
	IDT[0x24].type_attr = 0x8e; /* INTERRUPT_GATE */
	IDT[0x24].offset_2 = (irq4_address & 0x00000000ffff0000) >> 16;
	IDT[0x24].offset_3 = (irq4_address & 0xffffffff00000000) >> 32;

	irq5_address = (uint64_t)irq5;
	IDT[0x25].offset_1 = (irq5_address & 0x000000000000ffff);
	IDT[0x25].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
	IDT[0x25].ist = 0;
	IDT[0x25].type_attr = 0x8e; /* INTERRUPT_GATE */
	IDT[0x25].offset_2 = (irq5_address & 0x00000000ffff0000) >> 16;
	IDT[0x25].offset_3 = (irq5_address & 0xffffffff00000000) >> 32;

	irq6_address = (uint64_t)irq6;
	IDT[0x26].offset_1 = (irq6_address & 0x000000000000ffff);
	IDT[0x26].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
	IDT[0x26].ist = 0;
	IDT[0x26].type_attr = 0x8e; /* INTERRUPT_GATE */
	IDT[0x26].offset_2 = (irq6_address & 0x00000000ffff0000) >> 16;
	IDT[0x26].offset_3 = (irq6_address & 0xffffffff00000000) >> 32;

	irq7_address = (uint64_t)irq7;
	IDT[0x27].offset_1 = (irq7_address & 0x000000000000ffff);
	IDT[0x27].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
	IDT[0x27].ist = 0;
	IDT[0x27].type_attr = 0x8e; /* INTERRUPT_GATE */
	IDT[0x27].offset_2 = (irq7_address & 0x00000000ffff0000) >> 16;
	IDT[0x27].offset_3 = (irq7_address & 0xffffffff00000000) >> 32;

	irq8_address = (uint64_t)irq8;
	IDT[0x28].offset_1 = (irq8_address & 0x000000000000ffff);
	IDT[0x28].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
	IDT[0x28].ist = 0;
	IDT[0x28].type_attr = 0x8e; /* INTERRUPT_GATE */
	IDT[0x28].offset_2 = (irq8_address & 0x00000000ffff0000) >> 16;
	IDT[0x28].offset_3 = (irq8_address & 0xffffffff00000000) >> 32;

	irq9_address = (uint64_t)irq9;
	IDT[0x29].offset_1 = (irq9_address & 0x000000000000ffff);
	IDT[0x29].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
	IDT[0x29].ist = 0;
	IDT[0x29].type_attr = 0x8e; /* INTERRUPT_GATE */
	IDT[0x29].offset_2 = (irq9_address & 0x00000000ffff0000) >> 16;
	IDT[0x29].offset_3 = (irq9_address & 0xffffffff00000000) >> 32;

	irq10_address = (uint64_t)irq10;
	IDT[0x2A].offset_1 = (irq10_address & 0x000000000000ffff);
	IDT[0x2A].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
	IDT[0x2A].ist = 0;
	IDT[0x2A].type_attr = 0x8e; /* INTERRUPT_GATE */
	IDT[0x2A].offset_2 = (irq10_address & 0x00000000ffff0000) >> 16;
	IDT[0x2A].offset_3 = (irq10_address & 0xffffffff00000000) >> 32;

	irq11_address = (uint64_t)irq11;
	IDT[0x2B].offset_1 = (irq11_address & 0x000000000000ffff);
	IDT[0x2B].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
	IDT[0x2B].ist = 0;
	IDT[0x2B].type_attr = 0x8e; /* INTERRUPT_GATE */
	IDT[0x2B].offset_2 = (irq11_address & 0x00000000ffff0000) >> 16;
	IDT[0x2B].offset_3 = (irq11_address & 0xffffffff00000000) >> 32;

	irq12_address = (uint64_t)irq12;
	IDT[0x2C].offset_1 = (irq12_address & 0x000000000000ffff);
	IDT[0x2C].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
	IDT[0x2C].ist = 0;
	IDT[0x2C].type_attr = 0x8e; /* INTERRUPT_GATE */
	IDT[0x2C].offset_2 = (irq12_address & 0x00000000ffff0000) >> 16;
	IDT[0x2C].offset_3 = (irq12_address & 0xffffffff00000000) >> 32;

	irq13_address = (uint64_t)irq13;
	IDT[0x2D].offset_1 = (irq13_address & 0x000000000000ffff);
	IDT[0x2D].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
	IDT[0x2D].ist = 0;
	IDT[0x2D].type_attr = 0x8e; /* INTERRUPT_GATE */
	IDT[0x2D].offset_2 = (irq13_address & 0x00000000ffff0000) >> 16;
	IDT[0x2D].offset_3 = (irq13_address & 0xffffffff00000000) >> 32;

	irq14_address = (uint64_t)irq14;
	IDT[0x2E].offset_1 = (irq14_address & 0x000000000000ffff);
	IDT[0x2E].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
	IDT[0x2E].ist = 0;
	IDT[0x2E].type_attr = 0x8e; /* INTERRUPT_GATE */
	IDT[0x2E].offset_2 = (irq14_address & 0x00000000ffff0000) >> 16;
	IDT[0x2E].offset_3 = (irq14_address & 0xffffffff00000000) >> 32;

	irq15_address = (uint64_t)irq15;
	IDT[0x2F].offset_1 = (irq15_address & 0x000000000000ffff);
	IDT[0x2F].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
	IDT[0x2F].ist = 0;
	IDT[0x2F].type_attr = 0x8e; /* INTERRUPT_GATE */
	IDT[0x2F].offset_2 = (irq15_address & 0x00000000ffff0000) >> 16;
	IDT[0x2F].offset_3 = (irq15_address & 0xffffffff00000000) >> 32;

	for (int i = 0; i < 0x20; i++)
	{
		generic_handler_address = (uint64_t)generic_handler;
		IDT[i].offset_1 = (generic_handler_address & 0x000000000000ffff);
		IDT[i].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
		IDT[i].ist = 0;
		IDT[i].type_attr = 0x8e; /* INTERRUPT_GATE */
		IDT[i].offset_2 = (generic_handler_address & 0x00000000ffff0000) >> 16;
		IDT[i].offset_3 = (generic_handler_address & 0xffffffff00000000) >> 32;
	}

	/*     Ports
	*	 PIC1	PIC2
	*Command 0x20	0xA0
	*Data	 0x21	0xA1
	*/

	/* ICW1 - begin initialization */
	outb(0x20, 0x11);
	outb(0xA0, 0x11);

	/* ICW2 - remap offset address of IDT */
	/*
	* In x86 protected mode, we have to remap the PICs beyond 0x20 because
	* Intel have designated the first 32 interrupts as "reserved" for cpu exceptions
	*/
	outb(0x21, 0x20);
	outb(0xA1, 0x28);

	/* ICW3 - setup cascading */
	outb(0x21, 0x00);
	outb(0xA1, 0x00);

	/* ICW4 - environment info */
	outb(0x21, 0x01);
	outb(0xA1, 0x01);
	/* Initialization finished */

	/* mask interrupts */
	outb(0x21, 0xff);
	outb(0xA1, 0xff);

	uint64_t idt_address;
	uint64_t idt_ptr[2];

	/* fill the IDT descriptor */
	idt_address = (uint64_t)IDT;
	idt_ptr[0] = (sizeof(struct IDT_entry) * 8 * IDT_SIZE - 1) & 0xFFFF;
	idt_ptr[0] = idt_ptr[0] | ((idt_address & 0xFFFFFFFFFFFF) << 16);
	idt_ptr[1] = idt_address >> 48;
	print_num(idt_address);
	load_idt(idt_ptr);
	outb(0x21,0xFD);
}