; Prototype : int ft_isalnum(int c)
;

section .text
	global _ft_isalnum

_ft_isalnum:
	push rbp
	mov rbp, rsp

	cmp rdi, '0'
	jl pas_alnum
	cmp rdi, '9'
	jle est_alnum

	cmp rdi, 'A'
	jl pas_alnum
	cmp rdi, 'Z'
	jle est_alnum
	
	cmp rdi, 'a'
	jl pas_alnum
	cmp rdi, 'z'
	jg pas_alnum

est_alnum:
	mov rax, 1
	jmp fin

pas_alnum:
	mov rax, 0
	jmp fin

fin:

	leave
	ret
