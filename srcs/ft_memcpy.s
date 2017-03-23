section .text
	global _ft_memcpy

_ft_memcpy:
	push	rbp
	mov		rbp, rsp	; Sauvegarde de la pile
	push	rdi			; Sauvegarde ptr dst
	mov		rcx, rdx	; i = len
	repnz	movsb		; while (*rdi != 0 && rcx != 0) { *rdi = *rsi; rdi++; rsi++ }
	pop		rax			; rax = rdi and return ptr dst 
	leave
	ret
