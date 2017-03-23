section .text
	global _ft_memset

_ft_memset:
	push	rbp
	mov		rbp, rsp 	; Sauvegarde de la pile
	push	rdi			; Sauvegarde ptr src
	mov		rcx, rdx	; i = len
	mov		rax, rsi	; preparation pour stosb rax sera utilise comme source
	rep		stosb		; while (i-- != 0) { rdi(ptr) = rax(c); rdi++; }
	pop		rax			; rax = rdi and return
	leave
	ret
