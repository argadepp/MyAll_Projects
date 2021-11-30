+ Installation
	- Computer: Processor, RAM, Disk 
		--> BIOS
			- UEFI
			- Boot Priority
			- Disk - AHCI
	- Disk partitioning
		--> BIOS -- Partitioning Scheme -- MBR scheme: Max disk size = 2 TB.
			--> MBR partitioning
				-- Max 4 primary partitions
				-- 1 can be extended primary partition
					-- can create multiple partitions in extended partition 
					-- logical parts
		--> EFI -- Partitioning Scheme -- GPT scheme:
			-- GPT is compatible with MBR -- Protective MBR.
			--> GPT partitioning
				-- Max 128 primary partitions
	- Ubuntu (Linux) Installation
	- Software installations in Ubuntu

+ DAC course: 6 months
	- 24 weeks
		- 18 weeks : education
			? C Programming
			? Aptitude
			? Business communication
			? Project
			* C++ 
			+ Data Structures
			- Core Java
			- Java EE
			- Databases
			- Software Engg
			- App Security & Testing
			* Operating Systems (Linux)
			- Web Programming -- HTML, JS - , CSS, XML, JSON, PHP, ...
			- Java Script Framework -- MEAN (full-stack)
			- MS.NET
			- Parallel Programming
		- 1 week : preparation of CCEE
		- 1 week : exams (CCEE)
		- 4 weeks : project evaluation & campus preparations
	
+ Linux -- Usage
	- pwd
	- mkdir
	- cd
	- ls

	- cat filepath
	- rm filepath
	- rm -R dirpath
	- rmdir dirpath <-- for empty directories
	- cal
	- date
	- uname -a
	- mv filepath dirpath
	- cp 
	
+ C Programming
	+ Compilation of C Program:
		+ hello.c -> compiler -> hello.o -> linker -> hello.out
			a. compilation: gcc -c hello.c
			b. linking: gcc -o hello.out hello.o

	+ Compilation steps:
		- hello.c (source code)
	1. Preprocessor --> cpp | cpp.exe
		- hello.i (expanded source code)
	2. Compiler --> cc1 | cl.exe
		- hello.s (assembly code)
	3. Assembler --> as | masm.exe
		- hello.o (object code)
	4. Linker --> ld | link.exe + Library --> libc.so | msvcrt.dll
		- hello.out (executable code / program)

	+ gcc --> GNU Compiler Collection --> C, C++, ObjC, Fortran, ...
		- gcc -- GNU C Compiler
			- command internally calls all above tools (cpp, cc1, as, ld, ...)

	+ GNU --> set of open-source projects -- www.gnu.org
		- Richard Stallman
		- Projects:
			- Linux -- Linus Torvalds
			- GCC
			- GDB -- GNU Debugger
			- GNU make 
			- ...
		- GNU
			G
			N
			U -- 


