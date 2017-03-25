section .text
	global _ft_strlen

_ft_strlen:
	push	rbp
	mov		rbp, rsp	; Sauvegarde de la pile
	mov		al, 0		; char c = '\0'
	mov		r10, rdi	; void* ptr = str
	mov		rcx, ~0x0	; max size uint64
	repne	scasb		; while (*rdi != al && rcx != 0) { rdi++; rcx--; }
	dec		rdi			; ne pas compter '\0' 
	sub		rdi, r10	; size = rdi - rdx
	mov		rax, rdi	; return size
	leave
	ret
