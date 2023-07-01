#include <bitset>
#include <optional>

template <size_t STACK_SIZE>
struct vmem {
private:
	char memory[STACK_SIZE];
	std::bitset<STACK_SIZE> free = ~std::bitset<STACK_SIZE>();
	std::bitset<STACK_SIZE> mask;
public:
	template <typename T>
	std::optional<T*> allocate() {
		const int size = sizeof(T);
		const int iterSize = STACK_SIZE - size;

		for (int i = 0; i < STACK_SIZE; i++) {
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
			mask = mask >> 1;
		}

		return {};
	}
};