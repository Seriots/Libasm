section .text
	global ft_atoi_base
	extern ft_strlen

get_index_in_base:
	; Prototype : int get_index_in_base(char c, char *base);
	; rdi = c, rsi = base

	; Prolog
	push rbp
	mov rbp, rsp

	mov rax, 0

	.loop:
		movzx rcx, byte [rsi + rax]
		cmp cl, 0
		je .end
		cmp cl, dil
		je .end
		inc rax
		jmp .loop
	.end:
		cmp cl, 0
		jne .end2
		mov rax, -1
	.end2:

	; Epilog
	mov rsp, rbp
	pop rbp
	ret

check_base:
	; Prototype : int check_base(char *base);
	; @return : base length if valid, 0 otherwise

	; Prolog
	push rbp
	mov rbp, rsp

	mov rax, 0
	call ft_strlen

	mov rcx, 0 ; loop

	.loop:
		movzx rdx, byte [rdi + rcx]
		cmp dl, 0
		je .end
		cmp dl, byte '+'
		je .end2
		cmp dl, byte '-'
		je .end2
		cmp dl, byte ' '
		je .end2
		cmp dl, byte 9
		je .end2
		cmp dl, byte 10
		je .end2
		cmp dl, byte 11
		je .end2
		cmp dl, byte 12
		je .end2
		cmp dl, byte 13
		je .end2
		mov r8, rcx
		.inc:
			movzx r9, byte [rdi + r8 + 1]
			cmp r9, 0
			je .endinc
			cmp r9, rdx
			je .end2
			inc r8
			jmp .inc
		.end2:
		mov rax, 0
		mov rdx, 0
		jmp .end
		.endinc:
		inc rcx
		jmp .loop

	.end:
	
	; Epilog
	mov rsp, rbp
	pop rbp
	ret

	; Epilog
	mov rsp, rbp
	pop rbp
	ret

ft_atoi_base:
	; Prototype : int ft_atoi_base(char *str, char *base);
	; rdi = str, rsi = base

	; Prolog
	push rbp
	mov rbp, rsp
	
	cmp rdi, 0 ; if base is null
	je .end2

	push rdi ; save str
	mov rdi, rsi ; set first param to base


	cmp rsi, 0 ; if str is null
	je .end2

	call check_base ; check if base is valid -> no double, no sign, no whitespace
	cmp rax, 0 ; if base is invalid
	je .end2

	mov rdx, 0 ; result
	mov rcx, 0 ; loop
	mov r10, 1 ; sign
	pop r8 ; restore str

	mov r9, rax ; save base length


	; all signs are ignored
	cmp [r8], byte '+'
	jne .next
	inc rcx ; skip sign
	jmp .loop
.next:
	cmp [r8], byte '-'
	jne .loop
	inc rcx ; skip sign
	mov r10, -1 ; set sign
.loop:
	; r9 = base length, r8 = str, rsi = base
	mov rdi, [r8 + rcx] ; get char of str

	push rcx ; save rcx
	call get_index_in_base
	pop rcx ; restore rcx
	cmp rax, -1 ; if char not in base
	je .end
	
	; multiply result by base length and add index
	push rax
	mov rax, rdx
	mul r9
	mov rdx, rax
	pop rax
	add rdx, rax

	inc rcx ; next char

	jmp .loop

.end:
	cmp r10, -1
	jne .end2
	neg rdx
.end2:
	mov rax, rdx

	; Epilog
	mov rsp, rbp
	pop rbp
	ret