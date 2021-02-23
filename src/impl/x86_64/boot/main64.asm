global long_mode_start

section .text
bits 64
long_mode_start:
    mov ax, 0
    mov ss, ax
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    ; print "OK"
    mov dword [0xb8000], 0x2f452f48
    mov dword [0xb8004], 0x2f452f20
    mov dword [0xb8008], 0x2f4b2f4e
    hlt