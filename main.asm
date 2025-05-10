section .data
    msg db "Hello, world!", 0Ah

section .text
    global _start

_start:
    ; write(1, msg, 14)
    mov rax, 1
    mov rdi, 1
    mov rsi, msg
    mov rdx, 14
    syscall

    ; exit(0)
    mov rax, 60
    xor rdi, rdi
    syscall
