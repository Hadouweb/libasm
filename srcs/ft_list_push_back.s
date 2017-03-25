struc Mylink
	.prev: resb 8
	.next: resb 8
endstruc

struc Mylist
	.link: resb 16
	.head: resb 8
	.tail: resb 8
	.size: resb 8
endstruc

section .text
	global _ft_list_push_back

_ft_list_push_back:
	push	rbp
	mov		rbp, rsp
	mov		r9, rdi							; r9 = list
	mov		r10, rsi						; r10 = link
	cmp		r9, 0							; if list == NULL
	je		end								; return
	cmp		r10, 0							; if link == NULL
	je		end								; return ;
	cmp		qword [r9 + Mylist.head], 0x0	; if list->head == null
	je		no_head					
	jmp		have_head

no_head:
	mov		[r9 + Mylist.head], r10			; list->head = link
	mov		[r9 + Mylist.tail], r10			; list->tail = link
	add		[r9 + Mylist.size], byte 1		; list->size++
	jmp 	end								; return ;

have_head:
	mov		r11, [r9 + Mylist.tail]			; r11 = list->tail
	mov		[r11 + Mylink.next], r10		; *r11 = link
	mov		[r10 + Mylink.prev], r11		; link->prev = list->tail
	mov		[r9 + Mylist.tail], r10			; list->tail = link
	add		[r9 + Mylist.size], byte 1		; list->size++
	jmp		end

end:
	leave
	ret
