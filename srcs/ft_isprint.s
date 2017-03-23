section .text
	global _ft_isprint

_ft_isprint:
	push	rbp
	mov		rbp, rsp	; Sauvegarde de la pile
	mov		rax, 0		; int ret = 0
	cmp		rdi, 32		; Si < 32
	jl		end			; return 0
	cmp		rdi, 127	; Si >= 127
	jge		end			; return 0
	mov		rax, 1		; return 1

end:
	leave
	ret
