section .text
	global _ft_isdigit

_ft_isdigit:
	push	rbp
	mov		rbp, rsp		; Sauvegarde de la pile
	mov		rax, 0			; int ret = 0
	cmp		rdi, '0'		; compare c et '0'
	jl		end				; Si c est inferieur a '0' -> c'est pas un digit
	cmp		rdi, '9'		; compare c et '9'
	jg		end				; Si c est superieur a '9' -> c'est pas un digit
	mov		rax, 1

end:
	leave
	ret 
