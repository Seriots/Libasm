section .text
	global ft_list_sort

ft_list_sort:
	; Prototype void ft_list_sort(t_list **begin_list, int (*cmp)());
	; rdi = t_list **begin_list

	;Prolog
	push rbp
	mov rbp, rsp

	mov rcx, rsi

	mov r8, [rdi]; r8 = *begin_list
	mov r9, [r8 + 8]; r8 = *begin_list
	
	mov rdi, [r8]
	mov rsi, [r9]

	call rcx

	cmp rax, 0
	jl .end2
	jmp .end

	.end2:
	mov rax, 10
	.end:
	mov rsp, rbp
	pop rbp
	ret

