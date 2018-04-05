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
	getstatic aa/c [[I
	getstatic aa/c [[I
	ldc 1
	invokestatic aa/ss(I)I
	ldc 1
	isub
	aaload
	ldc 2
	invokestatic aa/ss(I)I
	ldc 1
	isub
	iaload
	invokestatic aa/ss(I)I
	ldc 1
	isub
	aaload
	getstatic aa/c [[I
	getstatic aa/a [I
	ldc 1
	ldc 1
	isub
	iaload
	invokestatic aa/ss(I)I
	ldc 1
	isub
	aaload
	getstatic aa/a [I
	ldc 2
	ldc 1
	isub
	iaload
	ldc 1
	isub
	iaload
	ldc 1
	isub
	getstatic aa/a [I
	getstatic aa/a [I
	getstatic aa/a [I
	ldc 1
	ldc 1
	isub
	iaload
	invokestatic aa/ss(I)I
	ldc 1
	isub
	iaload
	invokestatic aa/ss(I)I
	ldc 1
	isub
	iaload
	iastore
	return
.end method
