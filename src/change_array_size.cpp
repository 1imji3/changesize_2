#include <iostream>
#include <algorithm> // for std::copy

using namespace std;

void print_arr(int* arr, int size) {
	for (int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
  		cout << '\n';
}

void change_size(int*& arr, int size, int new_size) {
	int* new_arr = new int[new_size];
	int* recyclarr = arr;
	copy(arr, arr + size, new_arr);

	for (int i = 0; i < new_size; i++){
		if (i < size){
			new_arr[i] ;//新陣列的元素從舊陣列copy過來
		}
		else{
			new_arr[i] = 0;//0為多出來空間的初始值
		}
	}

	delete[] recyclarr;
	arr = new_arr;

}

int main() {
	int size = 3;
	int* arr = new int[size];

	// Inserting elements.
	for (int i = 0; i < size; i++) {
		arr[i] = i + 1;
	};

	print_arr(arr, size);  // Print initial array.

	int new_size = size * 2; //將原本陣列大小 * 2
	change_size(arr, size, new_size);
	print_arr(arr, new_size);  // Size has changed, print the new array.
}
