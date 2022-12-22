#include <iostream>
#include <cmath>
#include <string>

struct vec_2d {
	double x = 0.f;
	double y = 0.f;
};

vec_2d add_vec_2d(vec_2d& vec_1, vec_2d& vec_2) {
	vec_2d vec_3;
	vec_3.x = vec_1.x + vec_2.x;
	vec_3.y = vec_1.y + vec_2.y;
	return vec_3;
}

vec_2d subtract_vec_2d(vec_2d& vec_1, vec_2d& vec_2) {
	vec_2d vec_3;
	vec_3.x = vec_1.x - vec_2.x;
	vec_3.y = vec_1.y - vec_2.y;
	return vec_3;
}

vec_2d scale_vec_2d(vec_2d& vec_1, double scalar) {
	vec_2d vec_2;
	vec_2.x = vec_1.x * scalar;
	vec_2.y = vec_1.y * scalar;
	return vec_2;
}

double length_vec_2d(vec_2d& vec_1) {
	return sqrt((vec_1.x * vec_1.x) + (vec_1.y * vec_1.y));
}

vec_2d normalize_vec_2d(vec_2d& vec_1) {
	vec_2d vec_2;
	double length = length_vec_2d(vec_1);
	vec_2.x = vec_1.x / length;
	vec_2.y = vec_1.y / length;
	return vec_2;
}

int main() {
	vec_2d vec_1, vec_2, vec_3;
	double scalar;
	std::string command;

	std::cout << "Enter coordinate for FIRST 2d-vector (x, y):" << std::endl;
	std::cin >> vec_1.x >> vec_1.y;
	std::cout << "Enter coordinate for SECOND 2d-vector (x, y):" << std::endl;
	std::cin >> vec_2.x >> vec_2.y;
	while (true) {
		std::cout << "--------------------------------------------------" << std::endl;
		std::cout << "You have commands for operations with vectors "
				  << "(add, subtract, scale, length, normalize, exit)" << std::endl;
		std::cout << "Enter command:";
		std::cin >> command;
		while (command != "add" && command != "subtract" &&
			   command != "scale" && command != "length" &&
			   command != "normalize" && command != "exit") {
			std::cout << "Enter command:";
			std::cin >> command;
		}
		std::cout << "--------------------------------------------------" << std::endl;
		if (command == "add") {
			vec_3 = add_vec_2d(vec_1, vec_2);
			std::cout << "Result: vec_3(x: " << vec_3.x << ", y: " << vec_3.y << ")" << std::endl;
		} else if (command == "subtract") {
			vec_3 = subtract_vec_2d(vec_1, vec_2);
			std::cout << "Result: vec_3(x: " << vec_3.x << ", y: " << vec_3.y << ")" << std::endl;
		} else if (command == "scale") {
			std::cout << "Input scalar value:";
			std::cin >> scalar;
			vec_3 = scale_vec_2d(vec_1, scalar);
			std::cout << "Result: vec_3(x: " << vec_3.x << ", y: " << vec_3.y << ")" << std::endl;
		} else if (command == "length") {
			std::cout << "Result: " << length_vec_2d(vec_1) << std::endl;
		} else if (command == "normalize") {
			vec_3 = normalize_vec_2d(vec_1);
			std::cout << "Result: vec_3(x: " << vec_3.x << ", y: " << vec_3.y << ")" << std::endl;
		} else if (command == "exit") {
			std::cout << "--------------------------------------------------" << std::endl;
			std::cout << "Good by!" << std::endl;
			return 0;
		}
	}
}
