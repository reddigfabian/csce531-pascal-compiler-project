 #    2
 #    3
 #    4
 #    5
 #    6
 #    7
 #    8
				# b_global_decl (K, alignment = 4, size = 4)
.globl K
	.data
	.align	4
	.type	K, @object
	.size	K, 4
K:
	.zero	4
				# b_global_decl (J, alignment = 4, size = 4)
.globl J
	.align	4
	.type	J, @object
	.size	J, 4
J:
	.zero	4
				# b_global_decl (I, alignment = 4, size = 4)
.globl I
	.align	4
	.type	I, @object
	.size	I, 4
I:
	.zero	4
 #    9
				# b_global_decl (Y, alignment = 4, size = 4)
.globl Y
	.align	4
	.type	Y, @object
	.size	Y, 4
Y:
	.zero	4
				# b_global_decl (X, alignment = 4, size = 4)
.globl X
	.align	4
	.type	X, @object
	.size	X, 4
X:
	.zero	4
 #   10
				# b_global_decl (D, alignment = 8, size = 8)
.globl D
	.align	8
	.type	D, @object
	.size	D, 8
D:
	.zero	8
 #   11
				# b_global_decl (C, alignment = 1, size = 1)
.globl C
	.align	1
	.type	C, @object
	.size	C, 1
C:
	.zero	1
 #   12
				# b_global_decl (B, alignment = 1, size = 1)
.globl B
	.align	1
	.type	B, @object
	.size	B, 1
B:
	.zero	1
 #   13
 #   14
 #   15
 #   16
 #   17
 #   18
 #   19
				# b_init_formal_param_offset ()
				# b_get_formal_param_offset (pointer)
				# b_get_formal_param_offset (pointer)
 #   20
 #   21
				# b_func_prologue (Swap)
	.text
.global Swap
	.type	Swap, @function
Swap:
	pushl	%ebp
	movl	%esp, %ebp
				# b_store_formal_param (pointer)
				# b_store_formal_param (pointer)
				# b_alloc_local_vars ( size = 8 )
	subl	$8, %esp
 #   22
				# b_push_loc_addr (offset = -8)
	leal	-8(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_loc_addr (offset = 8)
	leal	8(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_deref (float)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_convert (float -> double)
	flds	(%esp)
	fstpl	(%esp)
				# b_assign (double)
	fldl	(%esp)
	addl	$8, %esp
	movl	(%esp), %eax
	fstpl	(%eax)
	fstpl	(%esp)
				# b_pop ()
	addl	$8, %esp
 #   23
				# b_push_loc_addr (offset = 8)
	leal	8(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_loc_addr (offset = 12)
	leal	12(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_deref (float)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_convert (float -> double)
	flds	(%esp)
	fstpl	(%esp)
				# b_convert (double -> float)
	fldl	(%esp)
	fstps	(%esp)
				# b_assign (float)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   24
 #   25
				# b_push_loc_addr (offset = 12)
	leal	12(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_loc_addr (offset = -8)
	leal	-8(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (double)
	movl	(%esp), %eax
	fldl	(%eax)
	fstpl	(%esp)
				# b_convert (double -> float)
	fldl	(%esp)
	fstps	(%esp)
				# b_assign (float)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
				# b_func_epilogue (Swap)
	leave
	ret
	.size	Swap, .-Swap
 #   26
 #   27
 #   28
 #   29
				# b_init_formal_param_offset ()
				# b_get_formal_param_offset (pointer)
 #   30
 #   31
				# b_func_prologue (Inner1)
.global Inner1
	.type	Inner1, @function
Inner1:
	pushl	%ebp
	movl	%esp, %ebp
				# b_store_formal_param (pointer)
				# b_alloc_local_vars ( size = 4 )
	subl	$8, %esp
 #   32
				# b_push_loc_addr (offset = -4)
	leal	-4(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_ext_addr (K)
	subl	$8, %esp
	movl	$K, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   33
 #   34
				# b_alloc_arglist (12 bytes)
	subl	$16, %esp
				# b_push_const_string ("f.inner1: c = %ld; i = %ld\n")
	.section	.rodata
.LC0:
.string	"f.inner1: c = %ld; i = %ld\n"
	.text
				# b_push_ext_addr (.LC0)
	subl	$8, %esp
	movl	$.LC0, (%esp)
				# b_load_arg (pointer)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 0(%esp)
				# b_push_loc_addr (offset = 8)
	leal	8(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (signed long int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 4(%esp)
				# b_push_loc_addr (offset = -4)
	leal	-4(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (signed long int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 8(%esp)
				# b_funcall_by_name (Printf, void)
	call	Printf
	addl	$16, %esp
				# b_func_epilogue (Inner1)
	leave
	ret
	.size	Inner1, .-Inner1
 #   35
 #   36
 #   37
				# b_init_formal_param_offset ()
				# b_get_formal_param_offset (pointer)
 #   38
 #   39
				# b_func_prologue (Inner2)
.global Inner2
	.type	Inner2, @function
Inner2:
	pushl	%ebp
	movl	%esp, %ebp
				# b_store_formal_param (pointer)
				# b_alloc_local_vars ( size = 4 )
	subl	$8, %esp
 #   40
				# b_push_loc_addr (offset = -4)
	leal	-4(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_ext_addr (D)
	subl	$8, %esp
	movl	$D, (%esp)
				# b_deref (double)
	movl	(%esp), %eax
	fldl	(%eax)
	fstpl	(%esp)
				# b_convert (double -> float)
	fldl	(%esp)
	fstps	(%esp)
				# b_assign (float)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   41
				# b_push_loc_addr (offset = 8)
	leal	8(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_loc_addr (offset = 8)
	leal	8(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (1)
	movl	$1, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( + , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	addl	%ecx, %eax
	movl	%eax, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   42
				# b_alloc_arglist (16 bytes)
	subl	$16, %esp
				# b_push_const_string ("f.inner2: c = %ld; i = %e\n")
	.section	.rodata
.LC1:
.string	"f.inner2: c = %ld; i = %e\n"
	.text
				# b_push_ext_addr (.LC1)
	subl	$8, %esp
	movl	$.LC1, (%esp)
				# b_load_arg (pointer)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 0(%esp)
				# b_push_loc_addr (offset = 8)
	leal	8(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (signed long int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 4(%esp)
				# b_push_loc_addr (offset = -4)
	leal	-4(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (float)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_convert (float -> double)
	flds	(%esp)
	fstpl	(%esp)
				# b_load_arg (double)
	movl	(%esp), %eax
	movl	4(%esp), %edx
	addl	$8, %esp
	movl	%eax, 8(%esp)
	movl	%edx, 12(%esp)
				# b_funcall_by_name (Printf, void)
	call	Printf
	addl	$16, %esp
 #   43
				# b_push_ext_addr (K)
	subl	$8, %esp
	movl	$K, (%esp)
				# b_push_ext_addr (K)
	subl	$8, %esp
	movl	$K, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (1)
	movl	$1, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( - , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	subl	%ecx, %eax
	movl	%eax, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   44
 #   45
				# b_alloc_arglist (4 bytes)
	subl	$16, %esp
				# b_push_loc_addr (offset = 8)
	leal	8(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (pointer)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 0(%esp)
				# b_funcall_by_name (Inner1, void)
	call	Inner1
	addl	$16, %esp
				# b_func_epilogue (Inner2)
	leave
	ret
	.size	Inner2, .-Inner2
 #   46
 #   47
 #   48
				# b_init_formal_param_offset ()
				# b_get_formal_param_offset (signed long int)
 #   49
 #   50
				# b_func_prologue (F)
.global F
	.type	F, @function
F:
	pushl	%ebp
	movl	%esp, %ebp
				# b_store_formal_param (signed long int)
				# b_alloc_local_vars ( size = 4 )
	subl	$8, %esp
 #   51
				# b_push_loc_addr (offset = -4)
	leal	-4(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_const_int (19)
	movl	$19, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   52
				# b_alloc_arglist (12 bytes)
	subl	$16, %esp
				# b_push_const_string ("f: c = %ld; i = %ld\n")
	.section	.rodata
.LC2:
.string	"f: c = %ld; i = %ld\n"
	.text
				# b_push_ext_addr (.LC2)
	subl	$8, %esp
	movl	$.LC2, (%esp)
				# b_load_arg (pointer)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 0(%esp)
				# b_push_loc_addr (offset = 8)
	leal	8(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (signed long int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 4(%esp)
				# b_push_loc_addr (offset = -4)
	leal	-4(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (signed long int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 8(%esp)
				# b_funcall_by_name (Printf, void)
	call	Printf
	addl	$16, %esp
 #   53
				# b_alloc_arglist (4 bytes)
	subl	$16, %esp
				# b_push_loc_addr (offset = 8)
	leal	8(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_load_arg (pointer)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 0(%esp)
				# b_funcall_by_name (Inner1, void)
	call	Inner1
	addl	$16, %esp
 #   54
				# b_alloc_arglist (12 bytes)
	subl	$16, %esp
				# b_push_const_string ("f: c = %ld; i = %ld\n")
	.section	.rodata
.LC3:
.string	"f: c = %ld; i = %ld\n"
	.text
				# b_push_ext_addr (.LC3)
	subl	$8, %esp
	movl	$.LC3, (%esp)
				# b_load_arg (pointer)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 0(%esp)
				# b_push_loc_addr (offset = 8)
	leal	8(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (signed long int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 4(%esp)
				# b_push_loc_addr (offset = -4)
	leal	-4(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (signed long int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 8(%esp)
				# b_funcall_by_name (Printf, void)
	call	Printf
	addl	$16, %esp
 #   55
				# b_alloc_arglist (4 bytes)
	subl	$16, %esp
				# b_push_loc_addr (offset = 8)
	leal	8(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_load_arg (pointer)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 0(%esp)
				# b_funcall_by_name (Inner2, void)
	call	Inner2
	addl	$16, %esp
 #   56
				# b_push_loc_addr (offset = -4)
	leal	-4(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_loc_addr (offset = -4)
	leal	-4(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (1)
	movl	$1, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( + , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	addl	%ecx, %eax
	movl	%eax, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   57
 #   58
				# b_alloc_arglist (12 bytes)
	subl	$16, %esp
				# b_push_const_string ("f: c = %ld; i = %ld\n")
	.section	.rodata
.LC4:
.string	"f: c = %ld; i = %ld\n"
	.text
				# b_push_ext_addr (.LC4)
	subl	$8, %esp
	movl	$.LC4, (%esp)
				# b_load_arg (pointer)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 0(%esp)
				# b_push_loc_addr (offset = 8)
	leal	8(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (signed long int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 4(%esp)
				# b_push_loc_addr (offset = -4)
	leal	-4(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (signed long int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 8(%esp)
				# b_funcall_by_name (Printf, void)
	call	Printf
	addl	$16, %esp
				# b_func_epilogue (F)
	leave
	ret
	.size	F, .-F
 #   59
 #   60
 #   61
				# b_init_formal_param_offset ()
				# b_get_formal_param_offset (pointer)
				# b_get_formal_param_offset (pointer)
				# b_get_formal_param_offset (pointer)
				# b_get_formal_param_offset (pointer)
				# b_get_formal_param_offset (pointer)
				# b_func_prologue (Innerinner)
.global Innerinner
	.type	Innerinner, @function
Innerinner:
	pushl	%ebp
	movl	%esp, %ebp
				# b_store_formal_param (pointer)
				# b_store_formal_param (pointer)
				# b_store_formal_param (pointer)
				# b_store_formal_param (pointer)
				# b_store_formal_param (pointer)
				# b_alloc_return_value ( )
				# b_alloc_local_vars ( size = 8 )
	subl	$8, %esp
				# b_alloc_local_vars ( size = 0 )
 #   62
				# b_push_loc_addr (offset = 8)
	leal	8(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (96)
	movl	$96, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_convert (signed long int -> unsigned char)
				# b_assign (unsigned char)
	movzbl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movb	%dl, (%eax)
	movb	%dl, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   63
				# b_alloc_arglist (4 bytes)
	subl	$16, %esp
				# b_push_loc_addr (offset = 8)
	leal	8(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_deref (unsigned char)
	movl	(%esp), %eax
	movzbl	(%eax), %edx
	movb	%dl, (%esp)
				# b_convert (unsigned char -> signed long int)
	movzbl	(%esp), %eax
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_load_arg (signed long int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 0(%esp)
				# b_funcall_by_name (F, void)
	call	F
	addl	$16, %esp
 #   64
 #   65
				# b_push_ext_addr (I)
	subl	$8, %esp
	movl	$I, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_loc_addr (offset = 12)
	leal	12(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_arith_rel_op ( + , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	addl	%ecx, %eax
	movl	%eax, (%esp)
				# b_push_loc_addr (offset = 16)
	leal	16(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_arith_rel_op ( + , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	addl	%ecx, %eax
	movl	%eax, (%esp)
				# b_convert (signed long int -> double)
	fildl	(%esp)
	fstpl	(%esp)
				# b_push_ext_addr (D)
	subl	$8, %esp
	movl	$D, (%esp)
				# b_deref (double)
	movl	(%esp), %eax
	fldl	(%eax)
	fstpl	(%esp)
				# b_arith_rel_op ( + , double)
	fldl	8(%esp)
	fldl	(%esp)
	addl	$8, %esp
	faddp	%st, %st(1)
	fstpl	(%esp)
				# b_push_loc_addr (offset = 20)
	leal	20(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_deref (double)
	movl	(%esp), %eax
	fldl	(%eax)
	fstpl	(%esp)
				# b_arith_rel_op ( + , double)
	fldl	8(%esp)
	fldl	(%esp)
	addl	$8, %esp
	faddp	%st, %st(1)
	fstpl	(%esp)
				# b_push_loc_addr (offset = 24)
	leal	24(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_deref (double)
	movl	(%esp), %eax
	fldl	(%eax)
	fstpl	(%esp)
				# b_arith_rel_op ( + , double)
	fldl	8(%esp)
	fldl	(%esp)
	addl	$8, %esp
	faddp	%st, %st(1)
	fstpl	(%esp)
				# b_set_return (double)
	movl	(%esp), %eax
	movl	%eax, -8(%ebp)
	movl	4(%esp), %edx
	movl	%edx, -4(%ebp)
	addl	$8, %esp
				# b_prepare_return (double)
	fldl	-8(%ebp)
				# b_func_epilogue (Innerinner)
	leave
	ret
	.size	Innerinner, .-Innerinner
 #   66
 #   67
 #   68
				# b_init_formal_param_offset ()
				# b_get_formal_param_offset (pointer)
				# b_get_formal_param_offset (pointer)
				# b_get_formal_param_offset (pointer)
 #   69
 #   70
 #   71
				# b_func_prologue (Inner)
.global Inner
	.type	Inner, @function
Inner:
	pushl	%ebp
	movl	%esp, %ebp
				# b_store_formal_param (pointer)
				# b_store_formal_param (pointer)
				# b_store_formal_param (pointer)
				# b_alloc_local_vars ( size = 16 )
	subl	$16, %esp
 #   72
				# b_push_loc_addr (offset = -4)
	leal	-4(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_const_int (28)
	movl	$28, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   73
				# b_push_loc_addr (offset = -16)
	leal	-16(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_const_double (1.4139999999999999e+00)
	.section	.rodata
	.align	8
.LC5:
	.long	1992864825
	.long	1073127358
	.text
	fldl	.LC5
	subl	$8, %esp
	fstpl	(%esp)
				# b_assign (double)
	fldl	(%esp)
	addl	$8, %esp
	movl	(%esp), %eax
	fstpl	(%eax)
	fstpl	(%esp)
				# b_pop ()
	addl	$8, %esp
 #   74
 #   75
				# b_alloc_arglist (32 bytes)
	subl	$40, %esp
				# b_push_const_string ("g.inner1: c1 = %d; i1 = %ld; i2 = %ld; d1 = %lg; d2 = %lg\n")
	.section	.rodata
.LC6:
.string	"g.inner1: c1 = %d; i1 = %ld; i2 = %ld; d1 = %lg; d2 = %lg\n"
	.text
				# b_push_ext_addr (.LC6)
	subl	$8, %esp
	movl	$.LC6, (%esp)
				# b_load_arg (pointer)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 0(%esp)
				# b_push_loc_addr (offset = 8)
	leal	8(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_deref (unsigned char)
	movl	(%esp), %eax
	movzbl	(%eax), %edx
	movb	%dl, (%esp)
				# b_convert (unsigned char -> signed long int)
	movzbl	(%esp), %eax
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_load_arg (signed long int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 4(%esp)
				# b_push_loc_addr (offset = 12)
	leal	12(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (signed long int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 8(%esp)
				# b_push_loc_addr (offset = -4)
	leal	-4(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (signed long int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 12(%esp)
				# b_push_loc_addr (offset = 16)
	leal	16(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_deref (double)
	movl	(%esp), %eax
	fldl	(%eax)
	fstpl	(%esp)
				# b_load_arg (double)
	movl	(%esp), %eax
	movl	4(%esp), %edx
	addl	$8, %esp
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
				# b_push_loc_addr (offset = -16)
	leal	-16(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (double)
	movl	(%esp), %eax
	fldl	(%eax)
	fstpl	(%esp)
				# b_load_arg (double)
	movl	(%esp), %eax
	movl	4(%esp), %edx
	addl	$8, %esp
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
				# b_funcall_by_name (Printf, void)
	call	Printf
	addl	$40, %esp
 #   76
				# b_push_loc_addr (offset = 16)
	leal	16(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_alloc_arglist (20 bytes)
	subl	$32, %esp
				# b_push_loc_addr (offset = 8)
	leal	8(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (pointer)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 0(%esp)
				# b_push_loc_addr (offset = 12)
	leal	12(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (pointer)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 4(%esp)
				# b_push_loc_addr (offset = -4)
	leal	-4(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_load_arg (pointer)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 8(%esp)
				# b_push_loc_addr (offset = 16)
	leal	16(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (pointer)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 12(%esp)
				# b_push_loc_addr (offset = -16)
	leal	-16(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_load_arg (pointer)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 16(%esp)
				# b_funcall_by_name (Innerinner, double)
	call	Innerinner
	addl	$32, %esp
	subl	$8, %esp
	fstpl	(%esp)
				# b_assign (double)
	fldl	(%esp)
	addl	$8, %esp
	movl	(%esp), %eax
	fstpl	(%eax)
	fstpl	(%esp)
				# b_pop ()
	addl	$8, %esp
 #   77
 #   78
 #   79
				# b_alloc_arglist (32 bytes)
	subl	$40, %esp
				# b_push_const_string ("g.inner1: c1 = %d; i1 = %ld; i2 = %ld; d1 = %lg; d2 = %lg\n")
	.section	.rodata
.LC7:
.string	"g.inner1: c1 = %d; i1 = %ld; i2 = %ld; d1 = %lg; d2 = %lg\n"
	.text
				# b_push_ext_addr (.LC7)
	subl	$8, %esp
	movl	$.LC7, (%esp)
				# b_load_arg (pointer)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 0(%esp)
				# b_push_loc_addr (offset = 8)
	leal	8(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_deref (unsigned char)
	movl	(%esp), %eax
	movzbl	(%eax), %edx
	movb	%dl, (%esp)
				# b_convert (unsigned char -> signed long int)
	movzbl	(%esp), %eax
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_load_arg (signed long int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 4(%esp)
				# b_push_loc_addr (offset = 12)
	leal	12(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (signed long int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 8(%esp)
				# b_push_loc_addr (offset = -4)
	leal	-4(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (signed long int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 12(%esp)
				# b_push_loc_addr (offset = 16)
	leal	16(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_deref (double)
	movl	(%esp), %eax
	fldl	(%eax)
	fstpl	(%esp)
				# b_load_arg (double)
	movl	(%esp), %eax
	movl	4(%esp), %edx
	addl	$8, %esp
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
				# b_push_loc_addr (offset = -16)
	leal	-16(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (double)
	movl	(%esp), %eax
	fldl	(%eax)
	fstpl	(%esp)
				# b_load_arg (double)
	movl	(%esp), %eax
	movl	4(%esp), %edx
	addl	$8, %esp
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
				# b_funcall_by_name (Printf, void)
	call	Printf
	addl	$40, %esp
				# b_func_epilogue (Inner)
	leave
	ret
	.size	Inner, .-Inner
 #   80
 #   81
 #   82
				# b_init_formal_param_offset ()
				# b_get_formal_param_offset (pointer)
 #   83
 #   84
 #   85
				# b_func_prologue (G)
.global G
	.type	G, @function
G:
	pushl	%ebp
	movl	%esp, %ebp
				# b_store_formal_param (pointer)
				# b_alloc_local_vars ( size = 16 )
	subl	$16, %esp
 #   86
				# b_push_loc_addr (offset = -4)
	leal	-4(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_const_int (496)
	movl	$496, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   87
				# b_push_loc_addr (offset = -16)
	leal	-16(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_const_double (2.7100000000000000e+00)
	.section	.rodata
	.align	8
.LC8:
	.long	2061584302
	.long	1074114068
	.text
	fldl	.LC8
	subl	$8, %esp
	fstpl	(%esp)
				# b_assign (double)
	fldl	(%esp)
	addl	$8, %esp
	movl	(%esp), %eax
	fstpl	(%eax)
	fstpl	(%esp)
				# b_pop ()
	addl	$8, %esp
 #   88
				# b_push_loc_addr (offset = 8)
	leal	8(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (14)
	movl	$14, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_convert (signed long int -> unsigned char)
				# b_assign (unsigned char)
	movzbl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movb	%dl, (%eax)
	movb	%dl, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   89
				# b_alloc_arglist (20 bytes)
	subl	$24, %esp
				# b_push_const_string ("g: c1 = %d; i1 = %ld; d1 = %lg\n")
	.section	.rodata
.LC9:
.string	"g: c1 = %d; i1 = %ld; d1 = %lg\n"
	.text
				# b_push_ext_addr (.LC9)
	subl	$8, %esp
	movl	$.LC9, (%esp)
				# b_load_arg (pointer)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 0(%esp)
				# b_push_loc_addr (offset = 8)
	leal	8(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_deref (unsigned char)
	movl	(%esp), %eax
	movzbl	(%eax), %edx
	movb	%dl, (%esp)
				# b_convert (unsigned char -> signed long int)
	movzbl	(%esp), %eax
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_load_arg (signed long int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 4(%esp)
				# b_push_loc_addr (offset = -4)
	leal	-4(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (signed long int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 8(%esp)
				# b_push_loc_addr (offset = -16)
	leal	-16(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (double)
	movl	(%esp), %eax
	fldl	(%eax)
	fstpl	(%esp)
				# b_load_arg (double)
	movl	(%esp), %eax
	movl	4(%esp), %edx
	addl	$8, %esp
	movl	%eax, 12(%esp)
	movl	%edx, 16(%esp)
				# b_funcall_by_name (Printf, void)
	call	Printf
	addl	$24, %esp
 #   90
				# b_alloc_arglist (12 bytes)
	subl	$24, %esp
				# b_push_loc_addr (offset = 8)
	leal	8(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (pointer)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 0(%esp)
				# b_push_loc_addr (offset = -4)
	leal	-4(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_load_arg (pointer)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 4(%esp)
				# b_push_loc_addr (offset = -16)
	leal	-16(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_load_arg (pointer)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 8(%esp)
				# b_funcall_by_name (Inner, void)
	call	Inner
	addl	$24, %esp
 #   91
				# b_push_loc_addr (offset = 8)
	leal	8(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_loc_addr (offset = 8)
	leal	8(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_deref (unsigned char)
	movl	(%esp), %eax
	movzbl	(%eax), %edx
	movb	%dl, (%esp)
				# b_assign (unsigned char)
	movzbl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movb	%dl, (%eax)
	movb	%dl, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   92
 #   93
				# b_alloc_arglist (20 bytes)
	subl	$24, %esp
				# b_push_const_string ("g: c1 = %d; i1 = %ld; d1 = %lg\n")
	.section	.rodata
.LC10:
.string	"g: c1 = %d; i1 = %ld; d1 = %lg\n"
	.text
				# b_push_ext_addr (.LC10)
	subl	$8, %esp
	movl	$.LC10, (%esp)
				# b_load_arg (pointer)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 0(%esp)
				# b_push_loc_addr (offset = 8)
	leal	8(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_deref (unsigned char)
	movl	(%esp), %eax
	movzbl	(%eax), %edx
	movb	%dl, (%esp)
				# b_convert (unsigned char -> signed long int)
	movzbl	(%esp), %eax
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_load_arg (signed long int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 4(%esp)
				# b_push_loc_addr (offset = -4)
	leal	-4(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (signed long int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 8(%esp)
				# b_push_loc_addr (offset = -16)
	leal	-16(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (double)
	movl	(%esp), %eax
	fldl	(%eax)
	fstpl	(%esp)
				# b_load_arg (double)
	movl	(%esp), %eax
	movl	4(%esp), %edx
	addl	$8, %esp
	movl	%eax, 12(%esp)
	movl	%edx, 16(%esp)
				# b_funcall_by_name (Printf, void)
	call	Printf
	addl	$24, %esp
				# b_func_epilogue (G)
	leave
	ret
	.size	G, .-G
 #   94
 #   95
 #   96
 #   97
 #   98
 #   99
 #  100
				# b_init_formal_param_offset ()
 #  101
 #  102
 #  103
 #  104
				# b_func_prologue (Main)
.global Main
	.type	Main, @function
Main:
	pushl	%ebp
	movl	%esp, %ebp
				# b_alloc_local_vars ( size = 12 )
	subl	$16, %esp
 #  105
				# b_push_ext_addr (K)
	subl	$8, %esp
	movl	$K, (%esp)
				# b_push_const_int (19)
	movl	$19, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #  106
				# b_push_ext_addr (D)
	subl	$8, %esp
	movl	$D, (%esp)
				# b_push_ext_addr (K)
	subl	$8, %esp
	movl	$K, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (2)
	movl	$2, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( * , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	imull	%ecx, %eax
	movl	%eax, (%esp)
				# b_convert (signed long int -> double)
	fildl	(%esp)
	fstpl	(%esp)
				# b_assign (double)
	fldl	(%esp)
	addl	$8, %esp
	movl	(%esp), %eax
	fstpl	(%eax)
	fstpl	(%esp)
				# b_pop ()
	addl	$8, %esp
 #  107
				# b_push_ext_addr (C)
	subl	$8, %esp
	movl	$C, (%esp)
				# b_push_ext_addr (K)
	subl	$8, %esp
	movl	$K, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_convert (signed long int -> unsigned char)
				# b_assign (unsigned char)
	movzbl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movb	%dl, (%eax)
	movb	%dl, (%esp)
				# b_pop ()
	addl	$8, %esp
 #  108
 #  109
				# b_push_loc_addr (offset = -4)
	leal	-4(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_ext_addr (K)
	subl	$8, %esp
	movl	$K, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #  110
				# b_push_loc_addr (offset = -12)
	leal	-12(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_loc_addr (offset = -4)
	leal	-4(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_convert (signed long int -> float)
	fildl	(%esp)
	fstps	(%esp)
				# b_assign (float)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #  111
				# b_push_loc_addr (offset = -8)
	leal	-8(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_ext_addr (D)
	subl	$8, %esp
	movl	$D, (%esp)
				# b_deref (double)
	movl	(%esp), %eax
	fldl	(%eax)
	fstpl	(%esp)
				# b_convert (double -> float)
	fldl	(%esp)
	fstps	(%esp)
				# b_assign (float)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #  112
 #  113
				# b_push_loc_addr (offset = -4)
	leal	-4(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_loc_addr (offset = -4)
	leal	-4(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (3)
	movl	$3, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( + , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	addl	%ecx, %eax
	movl	%eax, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #  114
				# b_push_ext_addr (J)
	subl	$8, %esp
	movl	$J, (%esp)
				# b_push_loc_addr (offset = -4)
	leal	-4(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (2)
	movl	$2, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( - , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	subl	%ecx, %eax
	movl	%eax, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #  115
				# b_push_loc_addr (offset = -12)
	leal	-12(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_loc_addr (offset = -12)
	leal	-12(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (float)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_convert (float -> double)
	flds	(%esp)
	fstpl	(%esp)
				# b_push_const_double (1.0000000000000000e+00)
	.section	.rodata
	.align	8
.LC11:
	.long	0
	.long	1072693248
	.text
	fldl	.LC11
	subl	$8, %esp
	fstpl	(%esp)
				# b_arith_rel_op ( - , double)
	fldl	8(%esp)
	fldl	(%esp)
	addl	$8, %esp
	fsubrp	%st, %st(1)
	fstpl	(%esp)
				# b_convert (double -> float)
	fldl	(%esp)
	fstps	(%esp)
				# b_assign (float)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #  116
 #  117
				# b_alloc_arglist (44 bytes)
	subl	$56, %esp
				# b_push_const_string ("main: c = %d; d = %lg; i = %d;\nj = %d; k = %d; x = %e; y = %e\n")
	.section	.rodata
.LC12:
.string	"main: c = %d; d = %lg; i = %d;\nj = %d; k = %d; x = %e; y = %e\n"
	.text
				# b_push_ext_addr (.LC12)
	subl	$8, %esp
	movl	$.LC12, (%esp)
				# b_load_arg (pointer)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 0(%esp)
				# b_push_ext_addr (C)
	subl	$8, %esp
	movl	$C, (%esp)
				# b_deref (unsigned char)
	movl	(%esp), %eax
	movzbl	(%eax), %edx
	movb	%dl, (%esp)
				# b_convert (unsigned char -> signed long int)
	movzbl	(%esp), %eax
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_load_arg (signed long int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 4(%esp)
				# b_push_ext_addr (D)
	subl	$8, %esp
	movl	$D, (%esp)
				# b_deref (double)
	movl	(%esp), %eax
	fldl	(%eax)
	fstpl	(%esp)
				# b_load_arg (double)
	movl	(%esp), %eax
	movl	4(%esp), %edx
	addl	$8, %esp
	movl	%eax, 8(%esp)
	movl	%edx, 12(%esp)
				# b_push_loc_addr (offset = -4)
	leal	-4(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (signed long int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 16(%esp)
				# b_push_ext_addr (J)
	subl	$8, %esp
	movl	$J, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (signed long int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 20(%esp)
				# b_push_ext_addr (K)
	subl	$8, %esp
	movl	$K, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (signed long int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 24(%esp)
				# b_push_loc_addr (offset = -12)
	leal	-12(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (float)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_convert (float -> double)
	flds	(%esp)
	fstpl	(%esp)
				# b_load_arg (double)
	movl	(%esp), %eax
	movl	4(%esp), %edx
	addl	$8, %esp
	movl	%eax, 28(%esp)
	movl	%edx, 32(%esp)
				# b_push_loc_addr (offset = -8)
	leal	-8(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (float)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_convert (float -> double)
	flds	(%esp)
	fstpl	(%esp)
				# b_load_arg (double)
	movl	(%esp), %eax
	movl	4(%esp), %edx
	addl	$8, %esp
	movl	%eax, 36(%esp)
	movl	%edx, 40(%esp)
				# b_funcall_by_name (Printf, void)
	call	Printf
	addl	$56, %esp
 #  118
 #  119
				# b_alloc_arglist (4 bytes)
	subl	$8, %esp
				# b_push_ext_addr (C)
	subl	$8, %esp
	movl	$C, (%esp)
				# b_deref (unsigned char)
	movl	(%esp), %eax
	movzbl	(%eax), %edx
	movb	%dl, (%esp)
				# b_convert (unsigned char -> signed long int)
	movzbl	(%esp), %eax
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_load_arg (signed long int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 0(%esp)
				# b_funcall_by_name (F, void)
	call	F
	addl	$8, %esp
 #  120
 #  121
 #  122
				# b_alloc_arglist (44 bytes)
	subl	$56, %esp
				# b_push_const_string ("main: c = %d; d = %lg; i = %d;\nj = %d; k = %d; x = %e; y = %e\n")
	.section	.rodata
.LC13:
.string	"main: c = %d; d = %lg; i = %d;\nj = %d; k = %d; x = %e; y = %e\n"
	.text
				# b_push_ext_addr (.LC13)
	subl	$8, %esp
	movl	$.LC13, (%esp)
				# b_load_arg (pointer)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 0(%esp)
				# b_push_ext_addr (C)
	subl	$8, %esp
	movl	$C, (%esp)
				# b_deref (unsigned char)
	movl	(%esp), %eax
	movzbl	(%eax), %edx
	movb	%dl, (%esp)
				# b_convert (unsigned char -> signed long int)
	movzbl	(%esp), %eax
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_load_arg (signed long int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 4(%esp)
				# b_push_ext_addr (D)
	subl	$8, %esp
	movl	$D, (%esp)
				# b_deref (double)
	movl	(%esp), %eax
	fldl	(%eax)
	fstpl	(%esp)
				# b_load_arg (double)
	movl	(%esp), %eax
	movl	4(%esp), %edx
	addl	$8, %esp
	movl	%eax, 8(%esp)
	movl	%edx, 12(%esp)
				# b_push_loc_addr (offset = -4)
	leal	-4(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (signed long int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 16(%esp)
				# b_push_ext_addr (J)
	subl	$8, %esp
	movl	$J, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (signed long int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 20(%esp)
				# b_push_ext_addr (K)
	subl	$8, %esp
	movl	$K, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (signed long int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 24(%esp)
				# b_push_loc_addr (offset = -12)
	leal	-12(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (float)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_convert (float -> double)
	flds	(%esp)
	fstpl	(%esp)
				# b_load_arg (double)
	movl	(%esp), %eax
	movl	4(%esp), %edx
	addl	$8, %esp
	movl	%eax, 28(%esp)
	movl	%edx, 32(%esp)
				# b_push_loc_addr (offset = -8)
	leal	-8(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (float)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_convert (float -> double)
	flds	(%esp)
	fstpl	(%esp)
				# b_load_arg (double)
	movl	(%esp), %eax
	movl	4(%esp), %edx
	addl	$8, %esp
	movl	%eax, 36(%esp)
	movl	%edx, 40(%esp)
				# b_funcall_by_name (Printf, void)
	call	Printf
	addl	$56, %esp
 #  123
 #  124
				# b_alloc_arglist (4 bytes)
	subl	$8, %esp
				# b_push_ext_addr (C)
	subl	$8, %esp
	movl	$C, (%esp)
				# b_load_arg (pointer)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 0(%esp)
				# b_funcall_by_name (G, void)
	call	G
	addl	$8, %esp
 #  125
 #  126
 #  127
				# b_alloc_arglist (44 bytes)
	subl	$56, %esp
				# b_push_const_string ("main: c = %d; d = %lg; i = %d;\nj = %d; k = %d; x = %e; y = %e\n")
	.section	.rodata
.LC14:
.string	"main: c = %d; d = %lg; i = %d;\nj = %d; k = %d; x = %e; y = %e\n"
	.text
				# b_push_ext_addr (.LC14)
	subl	$8, %esp
	movl	$.LC14, (%esp)
				# b_load_arg (pointer)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 0(%esp)
				# b_push_ext_addr (C)
	subl	$8, %esp
	movl	$C, (%esp)
				# b_deref (unsigned char)
	movl	(%esp), %eax
	movzbl	(%eax), %edx
	movb	%dl, (%esp)
				# b_convert (unsigned char -> signed long int)
	movzbl	(%esp), %eax
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_load_arg (signed long int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 4(%esp)
				# b_push_ext_addr (D)
	subl	$8, %esp
	movl	$D, (%esp)
				# b_deref (double)
	movl	(%esp), %eax
	fldl	(%eax)
	fstpl	(%esp)
				# b_load_arg (double)
	movl	(%esp), %eax
	movl	4(%esp), %edx
	addl	$8, %esp
	movl	%eax, 8(%esp)
	movl	%edx, 12(%esp)
				# b_push_loc_addr (offset = -4)
	leal	-4(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (signed long int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 16(%esp)
				# b_push_ext_addr (J)
	subl	$8, %esp
	movl	$J, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (signed long int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 20(%esp)
				# b_push_ext_addr (K)
	subl	$8, %esp
	movl	$K, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (signed long int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 24(%esp)
				# b_push_loc_addr (offset = -12)
	leal	-12(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (float)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_convert (float -> double)
	flds	(%esp)
	fstpl	(%esp)
				# b_load_arg (double)
	movl	(%esp), %eax
	movl	4(%esp), %edx
	addl	$8, %esp
	movl	%eax, 28(%esp)
	movl	%edx, 32(%esp)
				# b_push_loc_addr (offset = -8)
	leal	-8(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (float)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_convert (float -> double)
	flds	(%esp)
	fstpl	(%esp)
				# b_load_arg (double)
	movl	(%esp), %eax
	movl	4(%esp), %edx
	addl	$8, %esp
	movl	%eax, 36(%esp)
	movl	%edx, 40(%esp)
				# b_funcall_by_name (Printf, void)
	call	Printf
	addl	$56, %esp
 #  128
 #  129
				# b_alloc_arglist (8 bytes)
	subl	$8, %esp
				# b_push_loc_addr (offset = -12)
	leal	-12(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_load_arg (pointer)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 0(%esp)
				# b_push_loc_addr (offset = -8)
	leal	-8(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_load_arg (pointer)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 4(%esp)
				# b_funcall_by_name (Swap, void)
	call	Swap
	addl	$8, %esp
 #  130
 #  131
 #  132
 #  133
				# b_alloc_arglist (44 bytes)
	subl	$56, %esp
				# b_push_const_string ("main: c = %d; d = %lg; i = %d;\nj = %d; k = %d; x = %e; y = %e\n")
	.section	.rodata
.LC15:
.string	"main: c = %d; d = %lg; i = %d;\nj = %d; k = %d; x = %e; y = %e\n"
	.text
				# b_push_ext_addr (.LC15)
	subl	$8, %esp
	movl	$.LC15, (%esp)
				# b_load_arg (pointer)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 0(%esp)
				# b_push_ext_addr (C)
	subl	$8, %esp
	movl	$C, (%esp)
				# b_deref (unsigned char)
	movl	(%esp), %eax
	movzbl	(%eax), %edx
	movb	%dl, (%esp)
				# b_convert (unsigned char -> signed long int)
	movzbl	(%esp), %eax
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_load_arg (signed long int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 4(%esp)
				# b_push_ext_addr (D)
	subl	$8, %esp
	movl	$D, (%esp)
				# b_deref (double)
	movl	(%esp), %eax
	fldl	(%eax)
	fstpl	(%esp)
				# b_load_arg (double)
	movl	(%esp), %eax
	movl	4(%esp), %edx
	addl	$8, %esp
	movl	%eax, 8(%esp)
	movl	%edx, 12(%esp)
				# b_push_loc_addr (offset = -4)
	leal	-4(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (signed long int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 16(%esp)
				# b_push_ext_addr (J)
	subl	$8, %esp
	movl	$J, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (signed long int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 20(%esp)
				# b_push_ext_addr (K)
	subl	$8, %esp
	movl	$K, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (signed long int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 24(%esp)
				# b_push_loc_addr (offset = -12)
	leal	-12(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (float)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_convert (float -> double)
	flds	(%esp)
	fstpl	(%esp)
				# b_load_arg (double)
	movl	(%esp), %eax
	movl	4(%esp), %edx
	addl	$8, %esp
	movl	%eax, 28(%esp)
	movl	%edx, 32(%esp)
				# b_push_loc_addr (offset = -8)
	leal	-8(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (float)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_convert (float -> double)
	flds	(%esp)
	fstpl	(%esp)
				# b_load_arg (double)
	movl	(%esp), %eax
	movl	4(%esp), %edx
	addl	$8, %esp
	movl	%eax, 36(%esp)
	movl	%edx, 40(%esp)
				# b_funcall_by_name (Printf, void)
	call	Printf
	addl	$56, %esp
				# b_func_epilogue (Main)
	leave
	ret
	.size	Main, .-Main
 #  134
 #  135
 #  136
				# b_func_prologue (main)
.global main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
 #  137
 #  138
				# b_push_ext_addr (I)
	subl	$8, %esp
	movl	$I, (%esp)
				# b_push_const_int (-60)
	movl	$-60, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #  139
				# b_push_ext_addr (D)
	subl	$8, %esp
	movl	$D, (%esp)
				# b_push_const_double (1.7320000000000000e+00)
	.section	.rodata
	.align	8
.LC16:
	.long	-1580547965
	.long	1073460805
	.text
	fldl	.LC16
	subl	$8, %esp
	fstpl	(%esp)
				# b_assign (double)
	fldl	(%esp)
	addl	$8, %esp
	movl	(%esp), %eax
	fstpl	(%eax)
	fstpl	(%esp)
				# b_pop ()
	addl	$8, %esp
 #  140
				# b_push_ext_addr (X)
	subl	$8, %esp
	movl	$X, (%esp)
				# b_push_const_double (0.0000000000000000e+00)
	.section	.rodata
	.align	8
.LC17:
	.long	0
	.long	0
	.text
	fldl	.LC17
	subl	$8, %esp
	fstpl	(%esp)
				# b_convert (double -> float)
	fldl	(%esp)
	fstps	(%esp)
				# b_assign (float)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #  141
				# b_push_ext_addr (Y)
	subl	$8, %esp
	movl	$Y, (%esp)
				# b_push_const_double (0.0000000000000000e+00)
	.section	.rodata
	.align	8
.LC18:
	.long	0
	.long	0
	.text
	fldl	.LC18
	subl	$8, %esp
	fstpl	(%esp)
				# b_convert (double -> float)
	fldl	(%esp)
	fstps	(%esp)
				# b_assign (float)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #  142
				# b_push_ext_addr (C)
	subl	$8, %esp
	movl	$C, (%esp)
				# b_push_const_int (0)
	movl	$0, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_convert (signed long int -> unsigned char)
				# b_assign (unsigned char)
	movzbl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movb	%dl, (%eax)
	movb	%dl, (%esp)
				# b_pop ()
	addl	$8, %esp
 #  143
				# b_alloc_arglist (36 bytes)
	subl	$40, %esp
				# b_push_const_string ("i = %ld; d = %lg; x = %e; y = %e; c = %d\n")
	.section	.rodata
.LC19:
.string	"i = %ld; d = %lg; x = %e; y = %e; c = %d\n"
	.text
				# b_push_ext_addr (.LC19)
	subl	$8, %esp
	movl	$.LC19, (%esp)
				# b_load_arg (pointer)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 0(%esp)
				# b_push_ext_addr (I)
	subl	$8, %esp
	movl	$I, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (signed long int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 4(%esp)
				# b_push_ext_addr (D)
	subl	$8, %esp
	movl	$D, (%esp)
				# b_deref (double)
	movl	(%esp), %eax
	fldl	(%eax)
	fstpl	(%esp)
				# b_load_arg (double)
	movl	(%esp), %eax
	movl	4(%esp), %edx
	addl	$8, %esp
	movl	%eax, 8(%esp)
	movl	%edx, 12(%esp)
				# b_push_ext_addr (X)
	subl	$8, %esp
	movl	$X, (%esp)
				# b_deref (float)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_convert (float -> double)
	flds	(%esp)
	fstpl	(%esp)
				# b_load_arg (double)
	movl	(%esp), %eax
	movl	4(%esp), %edx
	addl	$8, %esp
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
				# b_push_ext_addr (Y)
	subl	$8, %esp
	movl	$Y, (%esp)
				# b_deref (float)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_convert (float -> double)
	flds	(%esp)
	fstpl	(%esp)
				# b_load_arg (double)
	movl	(%esp), %eax
	movl	4(%esp), %edx
	addl	$8, %esp
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
				# b_push_ext_addr (C)
	subl	$8, %esp
	movl	$C, (%esp)
				# b_deref (unsigned char)
	movl	(%esp), %eax
	movzbl	(%eax), %edx
	movb	%dl, (%esp)
				# b_convert (unsigned char -> signed long int)
	movzbl	(%esp), %eax
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_load_arg (signed long int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 32(%esp)
				# b_funcall_by_name (Printf, void)
	call	Printf
	addl	$40, %esp
 #  144
				# b_alloc_arglist (0 bytes)
	subl	$8, %esp
				# b_funcall_by_name (Main, void)
	call	Main
	addl	$8, %esp
 #  145
 #  146
 #  147
				# b_alloc_arglist (36 bytes)
	subl	$40, %esp
				# b_push_const_string ("i = %ld; d = %lg; x = %e; y = %e; c = %d\n")
	.section	.rodata
.LC20:
.string	"i = %ld; d = %lg; x = %e; y = %e; c = %d\n"
	.text
				# b_push_ext_addr (.LC20)
	subl	$8, %esp
	movl	$.LC20, (%esp)
				# b_load_arg (pointer)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 0(%esp)
				# b_push_ext_addr (I)
	subl	$8, %esp
	movl	$I, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (signed long int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 4(%esp)
				# b_push_ext_addr (D)
	subl	$8, %esp
	movl	$D, (%esp)
				# b_deref (double)
	movl	(%esp), %eax
	fldl	(%eax)
	fstpl	(%esp)
				# b_load_arg (double)
	movl	(%esp), %eax
	movl	4(%esp), %edx
	addl	$8, %esp
	movl	%eax, 8(%esp)
	movl	%edx, 12(%esp)
				# b_push_ext_addr (X)
	subl	$8, %esp
	movl	$X, (%esp)
				# b_deref (float)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_convert (float -> double)
	flds	(%esp)
	fstpl	(%esp)
				# b_load_arg (double)
	movl	(%esp), %eax
	movl	4(%esp), %edx
	addl	$8, %esp
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
				# b_push_ext_addr (Y)
	subl	$8, %esp
	movl	$Y, (%esp)
				# b_deref (float)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_convert (float -> double)
	flds	(%esp)
	fstpl	(%esp)
				# b_load_arg (double)
	movl	(%esp), %eax
	movl	4(%esp), %edx
	addl	$8, %esp
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
				# b_push_ext_addr (C)
	subl	$8, %esp
	movl	$C, (%esp)
				# b_deref (unsigned char)
	movl	(%esp), %eax
	movzbl	(%eax), %edx
	movb	%dl, (%esp)
				# b_convert (unsigned char -> signed long int)
	movzbl	(%esp), %eax
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_load_arg (signed long int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 32(%esp)
				# b_funcall_by_name (Printf, void)
	call	Printf
	addl	$40, %esp
				# b_func_epilogue (main)
	leave
	ret
	.size	main, .-main
 #  148
