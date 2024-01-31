section .text
    global ft_list_push_front
	extern malloc

ft_list_push_front:
	; Prototype : void ft_list_push_front(t_list **begin_list, void *data);
    ; rdi = begin_list, rsi = data

	; Prolog
	push rbp
	mov rbp, rsp

	xor rax, rax
	push rdi
	push rsi

	mov rdi, 16
	call malloc
	
	pop rsi
	pop rdi

	mov [rax], rsi
	mov r8, [rdi]
	mov [rax + 8], r8

	mov [rdi], rax

	; Epilog
	mov rsp, rbp
	pop rbp

    ret