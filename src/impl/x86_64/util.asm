global outb
global inb

outb:
mov rax, rsi
mov rdx, rdi
out dx,al
ret

inb:
mov rdx, rsi
in al, dx
ret