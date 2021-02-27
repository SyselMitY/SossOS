global irq0
global irq1
global irq2
global irq3
global irq4
global irq5
global irq6
global irq7
global irq8
global irq9
global irq10
global irq11
global irq12
global irq13
global irq14
global irq15
 
global load_idt
 
global irq0_handler
global irq1_handler
global irq2_handler
global irq3_handler
global irq4_handler
global irq5_handler
global irq6_handler
global irq7_handler
global irq8_handler
global irq9_handler
global irq10_handler
global irq11_handler
global irq12_handler
global irq13_handler
global irq14_handler
global irq15_handler
 
extern irq0_handler
extern irq1_handler
extern irq2_handler
extern irq3_handler
extern irq4_handler
extern irq5_handler
extern irq6_handler
extern irq7_handler
extern irq8_handler
extern irq9_handler
extern irq10_handler
extern irq11_handler
extern irq12_handler
extern irq13_handler
extern irq14_handler
extern irq15_handler
 

%macro pusha64 0
    push rax
    push rcx
    push rdx
    push rbx
    push rsp
    push rbp
    push rsi
    push rdi
    push r8
    push r9
    push r10
    push r11
    push r12
    push r13
    push r14
    push r15
%endmacro

%macro popa64 0
    pop r15
    pop r14
    pop r13
    pop r12
    pop r11
    pop r10
    pop r9
    pop r8
    pop rdi
    pop rsi
    pop rbp
    pop rsp
    pop rbx
    pop rdx
    pop rcx
    pop rax
%endmacro



irq0:
  pusha64
  call irq0_handler
  popa64
  iretq
 
irq1:
  pusha64
  call irq1_handler
  popa64
  iretq
 
irq2:
  pusha64
  call irq2_handler
  popa64
  iretq
 
irq3:
  pusha64
  call irq3_handler
  popa64
  iretq
 
irq4:
  pusha64
  call irq4_handler
  popa64
  iretq
 
irq5:
  pusha64
  call irq5_handler
  popa64
  iretq
 
irq6:
  pusha64
  call irq6_handler
  popa64
  iretq
 
irq7:
  pusha64
  call irq7_handler
  popa64
  iretq
 
irq8:
  pusha64
  call irq8_handler
  popa64
  iretq
 
irq9:
  pusha64
  call irq9_handler
  popa64
  iretq
 
irq10:
  pusha64
  call irq10_handler
  popa64
  iretq
 
irq11:
  pusha64
  call irq11_handler
  popa64
  iretq
 
irq12:
  pusha64
  call irq12_handler
  popa64
  iretq
 
irq13:
  pusha64
  call irq13_handler
  popa64
  iretq
 
irq14:
  pusha64
  call irq14_handler
  popa64
  iretq
 
irq15:
  pusha64
  call irq15_handler
  popa64
  iretq
 
load_idt:
	mov edx, [esp + 4]
	lidt [edx]
	sti
	ret