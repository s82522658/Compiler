README for the code generation project, 20141003


For all parts of the compiler project,
please see the web page

	http://people.cs.nctu.edu.tw/~wuuyang/homepage/Lecture/lecture.compiler.html

"Local On-Line Information" section for additional project material that might be helpful to your project.  Good luck.

Wuu  20141003


For the code generation part of the project, you may use appropriate assembly language as the output of your compiler. These include
	1. X86 assembly languages.
	2. MIPS assembly languages.  There is a SPIM simulator for MIPS. See related 
           information in the "Local On-Line Information" section.
	3. ARM assembly languages.  See related information in the "Local 
           On-Line Information" section.
	4. Java bytecode.  You can use Jasmin (http://jasmin.sourceforge.net/)
		>> (Quote from the Jasmin page)Jasmin is an assembler for the Java 
                   Virtual Machine. It takes ASCII descriptions of Java classes, 
                   written in a simple assembler-like syntax using the Java Virtual 
                   Machine instruction set. It converts them into binary Java class 
                   files, suitable for loading by a Java runtime system.

                   Jasmin was originally created as a companion to the book "Java 
                   Virtual Machine", written by Jon Meyer and Troy Downing and 
                   published by O'Reilly Associates. Since then, it has become the 
                   de-facto standard assembly format for Java. It is used in dozens 
                   of compiler classes throughout the world, and has been ported and 
                   cloned multiple times. For better or worse, Jasmin remains the 
                   oldest and the original Java assembler.
           You may also consult the ``Jasmin Home Page-20101122.mht'' file in the "Local 
           On-Line Information" section.
        5. LLVM (???)
        6. Other similar assembly languages.

--

 In order to use Jasmin, you compiler should generate Java "assembly" code
 Two example Java assembly code files are included in this directory:
	1. SAMPLE-test-for-JASMIN-1.j
	2. SAMPLE-test-for-JASMIN-2.j

 To run your project, you should use

	1. mycompiler.exe test00.p    (or mycompiler.exe < test00.p)
          會產生一個java byte code檔案，foo.j。

	2. java -jar jasmin.jar foo.j
	  然後利用jasmin把byte code 轉成可執行的java class程式
	  會產生 foo.class

	3. java foo
	  最後執行 foo.class
	  會印出結果，和test00.p做比對。

 For more details, see "Jasmin Instructions.pdf" and "Jasmin User Guide20120117.pdf".
--       
Code generation for Jasmin

Java (and hence Java bytecode) is an object-oriented langauage. 
Mini-Pascal is a procedural language.
To compile a mini-pascal program into a bytecode file,
you can create a single class, whose name is the same as the program name in mini-pascal.

The first two lines of the bytecode file are usually
	.class public foo
	.super java/lang/Object

All global variables in a mini-pascal program are treated as static field of the class.
	.field public static a I
	.field public static b I
	.field public static d [I
	.field public static e [F
	.field public static g F
	.field public static h F
	.field public static x F
	.field public static k [[F
	.field public static l [[I

The global variables are accessed through
	getstatic java/lang/System/out Ljava/io/PrintStream;
	putstatic foo/c I

All functions are treated as staic methods, which begin as
	.method public static addition(FF)F
	.limit locals 100
	.limit stack 100
	ldc 0.0
	fstore 2
	fload 0
	fload 1
	fadd
	fstore 2
	fload 2
	freturn
	.end method

The methods are invoked with 
	invokestatic foo/addition(FF)F

The standard initializer looks like
.method public <init>()V
	aload_0
	invokenonvirtual java/lang/Object/<init>()V
	return
.end method


The parameters and local variables are treated as local variables.

Operand stack size:
	.limit stack 100

The number of local variables:
	.limit locals 100

Jumps and labels:
	if_icmple L8
	ldc 111
	putstatic foo/a I
	goto L9
	L8:

Input can be implemented with the Scanner class.
	
Output can be implemented with (for "writeln(u)")
	getstatic java/lang/System/out Ljava/io/PrintStream;
	getstatic foo/u I
	invokestatic java/lang/String/valueOf(I)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V

	getstatic      java/lang/System/out Ljava/io/PrintStream;
	ldc            "Hello World."
	invokevirtual  java/io/PrintStream/println(Ljava/lang/String;)V

---------

