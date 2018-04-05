.class public aa
.super java/lang/Object

.field public static c [[I
.field public static b I
.field public static a [I
.method public static vinit()V
	.limit locals 100
	.limit stack 100
	bipush 2
	bipush 2
	multianewarray [[I 2
	putstatic aa/c [[I
	ldc 0
	putstatic aa/b I
	bipush 2
	multianewarray [I 1
	putstatic aa/a [I
	return
.end method
.method public <init>()V
	aload_0
	invokenonvirtual java/lang/Object/<init>()V
	return
.end method
.method public static ss(I)I
.limit locals 100
.limit stack 100
	ldc 0
	istore 1
	iload 0
	istore 1
	iload 1
	ireturn
.end method
.method public static main([Ljava/lang/String;)V
	.limit locals 100
	.limit stack 100
	invokestatic aa/vinit()V
	getstatic aa/a [I
	ldc 3
	ldc 4
	iadd
	ldc 6
	isub
	ldc 1
	isub
	ldc 10
	iastore
	getstatic aa/c [[I
	ldc 1
	ldc 100
	ldc 0
	imul
	iadd
	ldc 1
	iadd
	ldc 1
	isub
	aaload
	ldc 2
	ldc 4
	ldc 2
	idiv
	iadd
	ldc 3
	isub
	ldc 100
	iastore
	return
.end method
