#include <iostream>
using namespace std;

void tower_of_hanoi(int num_disks, char source, char destination, char auxiliary) {
    if (num_disks == 1) {
        std::cout << "Move disk 1 from " << source << " to " << destination << std::endl;
        return;
    }
    tower_of_hanoi(num_disks-1, source, auxiliary, destination);
    std::cout << "Move disk " << num_disks << " from " << source << " to " << destination << std::endl;
    tower_of_hanoi(num_disks-1, auxiliary, destination, source);
}

int main() {
    int num_disks;
    std::cout << "Enter the number of disks: ";
    std::cin >> num_disks;
    tower_of_hanoi(num_disks, 'A', 'C', 'B');
    return 0;
}
