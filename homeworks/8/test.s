	.file	"test.c"
	.text
	.globl	func
	.type	func, @function
func:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	8(%ebp), %eax
	subl	$9, %eax
	cmpl	$5, %eax
	ja	.L2
	movl	.L4(,%eax,4), %eax
	jmp	*%eax
	.section	.rodata
	.align 4
	.align 4
.L4:
	.long	.L3
	.long	.L5
	.long	.L6
	.long	.L7
	.long	.L8
	.long	.L9
	.text
.L3:
	movl	8(%ebp), %eax
	movl	%eax, 12(%ebp)
	jmp	.L1
.L5:
	movl	8(%ebp), %eax
	addl	$2, %eax
	movl	%eax, 12(%ebp)
	jmp	.L1
.L6:
	movl	8(%ebp), %eax
	addl	$3, %eax
	movl	%eax, 12(%ebp)
	jmp	.L1
.L7:
	movl	8(%ebp), %eax
	addl	$5, %eax
	movl	%eax, 12(%ebp)
	jmp	.L1
.L8:
	movl	8(%ebp), %eax
	addl	$7, %eax
	movl	%eax, 12(%ebp)
	jmp	.L1
.L9:
	movl	8(%ebp), %eax
	addl	$11, %eax
	movl	%eax, 12(%ebp)
	jmp	.L1
.L2:
	movl	-4(%ebp), %eax
	movl	%eax, 12(%ebp)
.L1:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	func, .-func
	.globl	myfunc
	.type	myfunc, @function
myfunc:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	8(%ebp), %eax
	subl	$10, %eax
	cmpl	$5, %eax
	ja	.L12
	movl	.L14(,%eax,4), %eax
	jmp	*%eax
	.section	.rodata
	.align 4
	.align 4
.L14:
	.long	.L13
	.long	.L15
	.long	.L16
	.long	.L16
	.long	.L17
	.long	.L18
	.text
.L13:
	movl	8(%ebp), %eax
	movl	%eax, -4(%ebp)
	jmp	.L19
.L15:
	addl	$1, 12(%ebp)
.L16:
	movl	8(%ebp), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, -4(%ebp)
	jmp	.L19
.L17:
	movl	8(%ebp), %eax
	imull	12(%ebp), %eax
	movl	%eax, -4(%ebp)
	jmp	.L19
.L18:
	movl	8(%ebp), %eax
	addl	$2, %eax
	movl	%eax, -4(%ebp)
	jmp	.L19
.L12:
	movl	$0, -4(%ebp)
.L19:
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	myfunc, .-myfunc
	.ident	"GCC: (Ubuntu 4.9.2-10ubuntu13) 4.9.2"
	.section	.note.GNU-stack,"",@progbits
