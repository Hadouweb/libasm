section .text
	global _ft_strdup
	extern _malloc

_ft_strdup:
	push	rbp
	mov		rbp, rsp	; Sauvegarde de la pile

	mov		r10, rdi	; void *ptr = ptr on param
	mov		rcx, ~0x0	; max size uint64
	mov		al, 0		; char c = '\0'
	repne	scasb		; while (*rdi != al && rcx != 0) { rdi++; rcx--; }
	sub		rdi, r10	; size(rdi) = rdi - rdx

	push	rdi			; Sauvegarde de rcx (size)
	push	r10			; Sauvegarde de r10 (ptr)

	call	_malloc		; rax = malloc(rdi) size + 1 car on a compte le '\0'
						
	; Attention a l'ordre des pop, c'est une pile...					
	pop		r10			; Recuperation de rdi
	pop		rdi			; Recuperation de r10

	mov		rcx, rdi	; i = size
	mov		rsi, r10	; Preparation pour movsb ptr src
	mov		rdi, rax	; Preparation pour movsb ptr dst
	rep		movsb		; while (rcx != 0) { *rdi = *rsi; rdi++; rsi++ }
	
	leave
	ret
