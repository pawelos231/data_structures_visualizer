#include <bitset>
#include <optional>

#define VMEM_STACK_SIZE 2048

struct vmem {
private:
	char memory[VMEM_STACK_SIZE];
	std::bitset<VMEM_STACK_SIZE> free = ~std::bitset<VMEM_STACK_SIZE>();
	std::bitset<VMEM_STACK_SIZE> mask;
public:
	template <typename T>
	std::optional<T*> allocate() {
		const int size = sizeof(T);
		const int iterSize = VMEM_STACK_SIZE - size;

		for (int i = 0; i < VMEM_STACK_SIZE; i++) {
			if (i < size)
				mask.set(i);
			else
				mask.reset(i);
		}

		for (int i = 0; i < iterSize; i++) {
			if ((free & mask) == mask) {
				free |= mask;
				return new(memory + i)T;
			}
			mask >> 1;
		}

		return {};
	}
};