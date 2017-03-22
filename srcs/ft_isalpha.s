; Ptototype : int ft_isalpha(int c)
;

section .text
	global _ft_isalpha

_ft_isalpha:
	push rbp			;
	mov rbp, rsp		;

	cmp rdi, 'A'		;
	jl pas_lettre		; if (c < 'A') goto pas_lettre;
	cmp rdi, 'Z'		;
	jle est_lettre		; if (c <= 'Z') goto est_lettre;

	cmp rdi, 'a'		;
	jl pas_lettre		; if (c < 'a') goto pas_lettre;
	cmp rdi, 'z'		;
	jg pas_lettre		; if (c <= 'z') goto pas_lettre;

est_lettre:
	mov rax, 1
	jmp fin

pas_lettre:
	mov rax, 0
	jmp fin

fin:
	leave
	ret
