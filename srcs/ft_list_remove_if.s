section .text
	global ft_list_remove_if
	extern free

ft_list_remove_if:
	; void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))

	; Prolog
	push rbp
	mov rbp, rsp

	; reserve space for local variables
	sub rsp, 128
	
	push rbx
	push r12
	push r13
	push r14
	push r15
	push rdi

	mov r14, rdx; compare function
	mov r15, rcx; free function
	mov rbx, rsi; data_ref

	cmp rdi, 0
	je .end

	cmp r14, 0
	je .end

	mov r12, 0; previous
	mov r13, [rdi]; current

	.loop:
		cmp r13, 0
		je .end

		mov rdi, [r13]; data
		mov rsi, rbx; data_ref

		call r14;

		cmp eax, 0
		jne .next
		cmp r12, 0
		je .first
		jmp .notfirst
	
	.notfirst:
		mov r8, r13; save current
		mov r13, [r13 + 8]; current->next 
		mov [r12 + 8], r13; previous->next = current->next
		
		jmp .free



	.first:
		
		mov r8, r13; save current
		mov r13, [r13 + 8]; next
		pop rdi
		mov [rdi], r13; *begin_list = next
		push rdi

		jmp .free

	.free:
		cmp r15, 0
		je .nofree
		push r8
		mov rdi, [r8]
		call r15 ; free
		pop r8
		.nofree:
			mov rdi, r8
			call free

		jmp .loop

	.next:
		mov r12, r13
		mov r13, [r13 + 8]
		jmp .loop

	.end:

	;	; Epilog
		pop rdi
		pop r15
		pop r14
		pop r13
		pop r12
		pop rbx

		add rsp, 128

		mov rsp, rbp
		pop rbp 
