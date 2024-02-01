
section .text
	global ft_list_sort

ft_list_sort:
	; Prototype void ft_list_sort(t_list **begin_list, int (*cmp)());
	; rdi = t_list **begin_list

	;Prolog
	push rbp
	mov rbp, rsp

	; Use only callee saved registers to save data
	push r12
	push r13
	push r14
	push r15

	xor rax, rax

	mov r14, rsi ; put cmp in r14
	cmp r14, 0 ; check if cmp is null
	je .end
	cmp rdi, 0 ; check if begin_list is null
	je .end
	
	mov r12, [rdi]; r12 = *begin_list
	cmp r12, 0 ; call of fonction so take care of only use callee saved registers
	je .end
	mov r13, [rdi]; r12 = *begin_list
	mov r15, r12;
	
	.loop:
		cmp r13, 0
		je .endone

		mov rdi, [r15]
		mov rsi, [r13]
		call r14
		; and eax, 0x80000000 ; mystere et boule de gomme (pourquoi ?) strcmp does not set something to aknowledge negative values sooooooo, I just check manually if the negative bit is set 
		cmp eax, 0
		jg .save
		jmp .next

	.save:
		mov r15, r13
	
	.next:
		mov r13, [r13 + 8]
		jmp .loop

	.endone:
		mov r8, [r12]
		mov r9, [r15]
		mov [r12], r9
		mov [r15], r8
		mov r12, [r12 + 8]
		cmp r12, 0
		je .end
		mov r13, [r12 + 8]
		mov r15, r12
		jmp .loop

	.end:
		; Use only callee saved registers to save data
		pop r15 
		pop r14
		pop r13
		pop r12

		; Epilog
		mov rsp, rbp
		pop rbp
		ret
