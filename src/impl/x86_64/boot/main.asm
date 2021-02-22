global start

section .text
bits 32
start:
    ; print "OK"
    mov dword [0xb8000], 0x2f452f48
    mov dword [0xb8004], 0x2f452f20
    mov dword [0xb8008], 0x2f4b2f4e
    hlt