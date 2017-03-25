section .data
	ok1: db "ok1", 0

section .text
	global _ft_itoa_base
	extern _malloc
	extern _ft_puts

_ft_itoa_base:
	push	rbp
	mov		rbp, rsp				; Sauvegarde de la pile
	mov		r8, rdi					; r8 = value
	push	r8						; sauvegarde de value
	mov		rdi, 12					; param 1 = 12
	call	_malloc					; rax = malloc(12)
	test	rax, rax
	jz		end
	pop		r8	
	mov		r9, rsi					; r9 = base
	mov		r10, 0					; r10 = 0 (size)
	mov		r11, rax				; r11 = str
	push	r12
	mov		r12, r11
	cmp		r8, 0					; si value < 0
	jl		is_less_zero
	je		is_zero
	push	r13
	xor		r13, r13				; r13 = 0
	push	rax						; sauvegarde de rax
	jge		way						; most common way

way:
	mov		rax, r8					; rax = value
	cmp		r13, 0
	je		loop_size				; count nb char
	pop		rax
	jmp		push_data

push_data:
	mov		[rax], byte 65	
	mov		[rax + r10], byte 66	
	jmp		end						; return str
	

is_less_zero:
	cmp		r9, 10					; si base == 10
	je		base10

is_zero:
	mov		[r12], byte 48			; *str = '0'
	mov		[r12 + 1], byte 0		; *str = '\0'
	jmp		end						; return str

base10:
	add		r10, 1					; size++

loop_size:
	add		r10, 1
	xor		rdx, rdx
	div		r9						; rax / r9 (value / base)
	cmp		rax, 0					; si rax > 0
	jg		loop_size
	add		r13, 1	
	jmp		way
	
end:
	leave
	ret	
