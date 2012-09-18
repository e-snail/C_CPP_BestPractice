#include <iostream>
#include <string>

using namespace std;

int calculate_steps(int step_level) {

	if (step_level == 1) {
		return 1;
	} else if (step_level == 2) {
		return 2;
	}

	return calculate_steps(step_level - 2) + calculate_steps(step_level - 1);

}

int main(int argc, char** argv) {

	int s = calculate_steps(10);
	cout <<"Total method of steps: " <<s <<"\n";

	return 0;
}
