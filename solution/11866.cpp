#include <iostream>
using namespace std;

class node {
public:
	node* next;
	int item;
	node(int value) : next(nullptr), item(value) {}
};

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	node* start = new node(1);
	node* present = start;
	for (int i = 2;i <= N;i++) {
		present->next = new node(i);
		present = present->next;
	}
	present->next = start;

	node* previous = present;

	for (int k = 1;k < K;k++)
		previous = previous->next;
	present = previous->next;
	cout << "<" << present->item;
	previous->next = present->next;
	delete present;

	for (int i = 1;i < N;i++) {

		for (int k = 1;k < K;k++)
			previous = previous->next;

		present = previous->next;
		cout << ", " << present->item;
		previous->next = present->next;
		delete present;
	}
	cout << ">";
}
