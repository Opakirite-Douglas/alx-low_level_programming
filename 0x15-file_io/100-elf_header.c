#include "main.h"
#include "Douglas.h"
#include <elf.h>
#include <unistd.h>

void printMagic(unsigned char *e_ident);
void printMyClass(unsigned char *e_ident);
void elf_checker1(unsigned char *e_ident);
void versionPrint(unsigned char *e_ident);
void printTHEdata(unsigned char *e_ident);
void elf_close(int elf);
void printALXosabi(unsigned char *e_ident);
void elf_checker1(unsigned char *e_ident);
void ABIprint(unsigned char *e_ident);
void Mhyentry(unsigned long int myentry, unsigned char *e_ident);
void TOprintDtype(unsigned int type, unsigned char *e_ident);

/**
 * main - This is the main func that simply displays the information
 * contained in theELF header at the start of an ELF file.
 * @argc: This represents the number of arguments
 * @argv: just an array of pointers
 * Return: 0(SUCCESS)
 * Description: exit code 98.
 */

int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o4open, r4read;

	o4open = open(argv[1], O_RDONLY);
	if (o4open == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		elf_close(o4open);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r4read = read(o4open, header, sizeof(Elf64_Ehdr));
	if (r4read == -1)
	{
		free(header);
		elf_close(o4open);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	elf_checker1(header->e_ident);
	printf("ELF Header:\n");
	printMagic(header->e_ident);
	printMyClass(header->e_ident);
	printTHEdata(header->e_ident);
	versionPrint(header->e_ident);
	printALXosabi(header->e_ident);
	ABIprint(header->e_ident);
	TOprintDtype(header->e_type, header->e_ident);
	Mhyentry(header->e_entry, header->e_ident);

	free(header);
	elf_close(o4open);
	return (0);
}

/**
 * elf_checker1 - This is the func that will check ELF files
 * @e_ident: Just a pointer
 * Description: exit code 98
 */

void elf_checker1(unsigned char *e_ident)
{
	int myInd;

	for (myInd = 0; myInd < 4; myInd++)
	{
		if (e_ident[myInd] != 127 &&
				e_ident[myInd] != 'E' &&
				e_ident[myInd] != 'L' &&
				e_ident[myInd] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * printMagic - this func simply prints the magic numbers of an ELF header.
 * @e_ident: just a pointer
 * Description: Our magic numbers separated by spaces.
 */

void printMagic(unsigned char *e_ident)
{
	int my_ind;

	printf("  Magic:   ");

	for (my_ind = 0; my_ind < EI_NIDENT; my_ind++)
	{
		printf("%02x", e_ident[my_ind]);

		if (my_ind == EI_NIDENT - 1)
		{
			printf("\n");
		}
		else
		{
			printf(" ");
		}
	}
}

/**
 * printMyClass - this func simply prints the class of an ELF header.
 * @e_ident: just a pointer
 *
 */

void printMyClass(unsigned char *e_ident)
{
	printf("  Class:                             ");

	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * printTHEdata - func that simply prints the data of an ELF header.
 * @e_ident: just a pointer
 */

void printTHEdata(unsigned char *e_ident)
{
	printf("  Data:                              ");

	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * versionPrint - To simply print the ELF header version
 * @e_ident: Just a pointer
 */

void versionPrint(unsigned char *e_ident)
{
	printf("  Version:                           %d",
	       e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}


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
	{
		printf("%#x\n", (unsigned int)myentry);
	}
	else
	{
		printf("%#lx\n", myentry);
	}
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
