section .text
	global _ft_isalpha

_ft_isalpha:
	push	rbp
	mov		rbp, rsp	; Sauvegarde de la pile
	mov		rax, 0		; int ret = 0
	
	cmp		rdi, 'A'	; Si < 'A'
	jl		end			; return 0
	cmp		rdi, 'Z'	; Si <= 'Z' et >= 'A'
	jle		istrue		; return 1
	
	cmp		rdi, 'a'	; Si < 'a'
	jl		end			; return 0
	cmp		rdi, 'z'	; Si <= 'z' et >= 'a'
	jg		end			; return 0

istrue:
	mov rax, 1			; registre pour la valeur de retour
	jmp end				; FIN

end:
	leave
	ret
