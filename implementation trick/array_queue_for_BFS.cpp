#include <iostream>
using namespace std;

bool condition(){
    return true;
}

bool find_condition(){
    return true;
}

int main() {
	int start;

	int order[100002]{ 0, };//visit order
	order[start] = 1;

	int Q[100002];
	int q = 0;
	Q[q++] = start;//Q.push

	for (int n=0;n<q;n++) {
		int i = Q[n];//Q.front
		int dir[3] = { i * 2,i - 1,i + 1 };//dir
		for (int k = 0;k < 3;k++) {
			if (order[dir[k]] <= 0 && condition()) {//visit and condition check
				order[dir[k]] = order[i] + 1;
				Q[q++] = dir[k];//Q.push
				if (find_condition()) {
					n = q;//break entire for loop
					break;
				}
			}
		}
	}
	q--;//Q.back index
}