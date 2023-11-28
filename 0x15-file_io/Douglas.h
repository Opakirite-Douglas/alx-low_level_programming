#ifndef MAIN_H_
#define MAIN_H_

#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

void elf_close(int elf);
void printALXosabi(unsigned char *e_ident);
void elf_checker1(unsigned char *e_ident);
void ABIprint(unsigned char *e_ident);
void Mhyentry(unsigned long int myentry, unsigned char *e_ident);
void TOprintDtype(unsigned int type, unsigned char *e_ident);

/**
 * printALXosabi - functn simply prints the OS/ABI
 * @e_ident: just a pointer
 */

void printALXosabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * ABIprint - functn that prints the ABI version
 * @e_ident: just a pointer
 */
void ABIprint(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
	       e_ident[EI_ABIVERSION]);
}

/**
 * TOprintDtype - func that simply prints the type of an ELF header.
 * @type: This represents the type of ELF
 * @e_ident: just a pointer
 */
void TOprintDtype(unsigned int type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		type >>= 8;

	printf("  Type:                              ");

	switch (type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", type);
	}
}

/**
 * Mhyentry - this func simply prints the entry point of ELF header.
 * @myentry: This is the entry point.
 * @e_ident: just a pointer
 */
void Mhyentry(unsigned long int myentry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		myentry = ((myentry << 8) & 0xFF00FF00) |
			  ((myentry >> 8) & 0xFF00FF);
		myentry = (myentry << 16) | (myentry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)myentry);

	else
		printf("%#lx\n", myentry);
}

/**
 * elf_close - This is the func that closes the ELF file of a prog.
 * @elf: just a file descriptor
 * Description: exit code 98.
 */
void elf_close(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

#endif
