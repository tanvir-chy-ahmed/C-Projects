int _start(void){
	const char hello[] = "Hello From asm\n";
	asm volatile (
	"mov $1, %% rax\n\t" // syscall number for write
	"mov $1, %%rdi\n\t"
	"lea %0, %%rsi\n\t"
	"mov $14, %%rdx\n\t"
	"syscall\n\t"
	:
	: "m"(hello)
	: "%rax","%rdi","%rsi","%rdx"

	);
	
	asm volatile (
		"mov $60, %%rax\n\t" // Sys Exit
		"mov $0, %%rdi\n\t"
		"syscall\n\t"
		::: "%rax","%rdi"
	);
	// Never Called
	
	return 0;
}
