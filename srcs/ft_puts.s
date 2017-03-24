%define MACH_SYSCALL(nb)	0x2000000 | nb
%define WRITE				4

section .data
	eol: db 10							; '\n'
	null_text: db "(null)", 10			; "(null)"
			.len: equ $ - null_text

section .text
	global _ft_puts
	extern _ft_strlen

_ft_puts:
	push	rbp
	mov		rbp, rsp					; sauvegarde de la pile
	cmp		rdi, 0						; if null
    je		end							; END
    mov		r8, rdi						; r8 = rdi
    cmp		byte [r8], 0				; if *ptr == 0
	je		ptr_is_null					; END
	push	rdi							; sauvegarde du param
	call	_ft_strlen					; rax = len
	mov		rdi, 1						; param 1 = stdout
	pop		rsi							; param 2 = ptr
	mov		rdx, rax					; param 3 = size
	mov		rax, MACH_SYSCALL(WRITE)	; write(rdi, rsi, rdx);
	syscall
	mov		rdi, 1						; param 1 = stdout
	lea		rsi, [rel eol]				; param 2 = ptr de '\n'
	mov		rdx, 1						; param 3 = size
	mov		rax, MACH_SYSCALL(WRITE)	; write(rdi, rsi, rdx)
	syscall

ptr_is_null:
	mov		rdi, 1						; param 1 = stdout
	lea		rsi, [rel null_text]		; param 2 = ptr de '\n'
	mov		rdx, null_text.len			; param 3 = size
	mov		rax, MACH_SYSCALL(WRITE)	; write(rdi, rsi, rdx)
	syscall
	jmp		end

end:
	leave
	ret
