section .text
	global ft_read
	extern __errno_location

ft_read:
	; Protoytpe : ssize_t (int , void *, size_t);

	mov rax, 0
	syscall

	cmp rax, 0
	jl error
	ret

error;
    mov rdi, rax            ; Sauvegarde de rax
    call __errno_location
    neg rdi           
    mov	[rax], rdi		;errno = rbx
    mov rax, -1
    ret