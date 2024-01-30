section .text
    global ft_write
    extern __errno_location

ft_write:
    ; Appel système pour écrire sur la sortie standard (1)
    ; Prototype : ssize_t (int , const void *, size_t);
    
    mov rax, 1
    syscall             ; Appel système

    cmp rax, 0          ; Si rax = 0, pas erreur
    jl .error          ; Sinon, erreur
    ret

.error:
    mov rdi, rax            ; Sauvegarde de rax
    call __errno_location
    neg rdi           
    mov	[rax], rdi		;errno = rbx
    mov rax, -1

    ret
