global outb
global inb

outb:
mov rax, [rsp + 1 * 8]
mov rdx, [rsp + 2 * 8]
out dx,al
ret

inb:
mov rdx, [rsp + 8]
in al, dx
ret