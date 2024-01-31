section .text
	global ft_list_size

ft_list_size:
	; Prototype : int ft_list_size(t_list *begin_list);

	;Prolog
	push rbp
	mov rbp, rsp

	xor rax, rax

	.loop:
		cmp rdi, 0
		je .end
		inc rax
		mov rdi, [rdi + 8]
		jmp .loop
	.end:

		; Epilog
		mov rsp, rbp
		pop rbp
		ret