#include "raylib.h"
#include "structures/linked_list/linked_list.h"
#include <iostream>

#define LOG(x){std::cout<<x<<std::endl;}

int main(void)
{
	LinkedList<int> list;
	for (int i = 1; i <= 6; i++) {
		list.push_node(i);
	}

	LOG("elements in list:")
		list.log_nodes();
	list.delete_node(2);
	LOG("elements in list:")
		list.log_nodes();
	list.insert_node(3, 10);

	LOG("Elements in list:")
		list.log_nodes();

	return 0;
}