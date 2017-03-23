section .text
	global _ft_isalnum

_ft_isalnum:
	push	rbp
	mov		rbp, rsp	; Sauvegarde de la pile
	mov		rax, 0		; int ret = 0
	
	cmp		rdi, '0'	; Si < '0' -> c'est pas un alnum
	jl		end			; return 0
	cmp		rdi, '9'	; Si <= '9' et on sait que >= '0' -> c'est un alnum
	jle		istrue		; set rax (registre de retour) puis end
	
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
