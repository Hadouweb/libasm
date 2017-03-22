section .text
	global _ft_bzero

_ft_bzero:
	push rbp
	mov rbp, rsp
	mov rax, rsi
	cmp rax, 0
	je end

loop:
	mov [rdi], byte 0
	inc rdi
	dec rax
	cmp rax, 0
	jne loop

end:
	leave
	ret
