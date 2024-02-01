section .text
	global ft_list_remove_if
	extern free

ft_list_remove_if:
	; void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))

	; Prolog
	push rbp
	mov rbp, rsp

	mov r14, rdx; compare function
	mov r15, rcx; free function

	push rdi
	push rsi

	cmp rdi, 0
	je .end

	cmp r14, 0
	je .end

	cmp r15, 0
	je .end

	mov r12, 0; previous
	mov r13, [rdi]; current

	.loop:
		cmp r13, 0
		je .end

		mov rdi, [r13]; data
		pop rsi
		call r14;

		cmp eax, 0
		jne .next
		cmp r12, 0
		je .first
		jmp .notfirst
	
	.notfirst:
		mov r8, [r13 + 8]; next
		mov [r12 + 8], r8; previous->next = current->next
		; mov rdi, [r13]
		; call r15 ; free
		; mov rdi, r13
		; call free
		jmp .loop		


	.first:
		mov r8, [r13 + 8]; next
		; mov rdi, [r13]
		; call r15 ; free
		; mov rdi, r13
		; call free
		pop rsi
		pop rdi
		mov [rdi], r8
		push rdi
		push rsi
		jmp .loop

	.next:
		mov r12, r13
		mov r13, [r13 + 8]
		jmp .loop

	.end:

		; Epilog
		pop rdi
		pop rsi

		mov rsp, rbp
		pop rbp 
