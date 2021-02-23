global start

section .text
bits 32
start:
    mov esp, stack_top

    call check_multiboot
    call check_cpuid
    call check_long_mode

    ; print "OK"
    mov dword [0xb8000], 0x2f452f48
    mov dword [0xb8004], 0x2f452f20
    mov dword [0xb8008], 0x2f4b2f4e
    hlt

check_multiboot:
    cmp eax, 0x36d76289
    jne .no_multiboot
    ret

no_multiboot:
    mov al, "M"
    jmp error

check_cpuid:
    pushfd
    pop eax
    mov ecx,eax
    xor eax, 1 << 21
    push eax
    popfd
    pushfd
    pop eax


error:
    ; print "ERR: X"
    mov dword [0xb8000], 0x4f524f45
    mov dword [0xb8004], 0x4f3a4f52
    mov dword [0xb8008], 0x4f204f20
    mov byte [0xb800a], al

section .bss
stack_bottobm:
    resb 4096 * 4
stack_top: