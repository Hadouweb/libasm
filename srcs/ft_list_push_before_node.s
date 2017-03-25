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
	global _ft_list_push_before_node

_ft_list_push_before_node:
	push	rbp
	mov		rbp, rsp
	mov		r8, rdi							; r8 = list
	mov		r9, rsi							; r9 = node
	mov		r10, rdx						; r10 = new_node
	cmp		r8, 0							; if list == NULL
	je		end								; return
	cmp		r9, 0							; if node == NULL
	je		end								; return ;
	cmp		r10, 0							; if new_node == NULL
	je		end								; return ;
	cmp		r9, r10							; if node == new_node
	je		end								; return ;
	cmp		qword [r9 + Mylink.prev], 0x0	; if node->next == NULL
	je		no_next
	jmp		have_next

no_next:
	mov		[r10 + Mylink.next], r9			; new_node->next = node
	mov		[r9 + Mylink.prev], r10			; node->prev = new_node
	mov		[r8 + Mylist.head], r10			; list->head = new_node
	add		[r8 + Mylist.size], byte 1		; list->size++
	jmp		end

have_next:
	mov		r11, [r9 + Mylink.prev]			; r11 = node->prev
	mov		[r11 + Mylink.next], r10		; r11->next = new_node
	mov		[r10 + Mylink.prev], r11		; new_node->prev = r11
	mov		[r10 + Mylink.next], r9			; new_node->next = node
	mov		[r9 + Mylink.prev], r10			; node->prev = new_node
	add		[r8 + Mylist.size], byte 1		; list->size++
	jmp		end

end:
	leave
	ret
