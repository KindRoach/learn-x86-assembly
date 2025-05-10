global add_int_asm

section .text
add_int_asm:
    ; params：
    ; rdi -> int a
    ; rsi -> int b
    ; return rax

    mov     rax, rdi        ; rax = a
    add     rax, rsi        ; rax += b
    ret
