//
//  main.cpp
//  experimentando
//
//  Created by Marco Mercado Lugo on 09/08/18.
//  Copyright © 2018 Camus. All rights reserved.
//

#include <iostream>
#include <string>
#include <math.h>

void hashPow();
void addToArray(int,int);
void printArray(int);

const int ARRAY_LENGTH = 100;
int vector [ARRAY_LENGTH];

int main(int argc, const char * argv[]) {
    
    
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        vector[i] = 0;
    }
    
    for (int i = 0; i < 8; i++) {
        hashPow();
    }
    
    return 0;
}

void hashPow() {
    int num;
    std::string num1;
    std::string num2;
    std::string num_pow;
    std::string num1_last;
    std::string num2_first;
    int half;
    int index;
    
    
    std::cout << "Ingresa un numero: ";
    std::cin >> num;
    
    // Encontrar el cuadrado y convertirlo a un string
    num_pow = std::to_string(pow(num, 2));
    num_pow = num_pow.substr(0, (num_pow.length() / 2) + 1);
    
    // Encontrar la mitad
    half = num_pow.length() / 2;
    std::cout << half << std::endl;
    
    // Dividirlos en 2 variables
    num1 = num_pow.substr(0, half);
    num2 = num_pow.substr(half, num_pow.length());
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    
    // Encontrar el numero medio
    num1_last = num1[num1.length() - 1];
    num2_first = num2[0];
    
    std::cout << num1_last << std::endl;
    std::cout << num2_first << std::endl;
    
    index = std::stoi(num1_last + num2_first) + 1;
    
    std::cout << index << std::endl;
    
    // Llamar a la funcion recursiva para añadirlo al vector
    addToArray(index, num);
    
    
}

void addToArray(int index, int num) {
    if(vector[index] == 0) {
        vector[index] = num;
        printArray(ARRAY_LENGTH);
    } else {
        index = (index == ARRAY_LENGTH - 1) ? -1 : index;
        addToArray(index + 1, num);
    }
}

void printArray(int arr_length) {
    for (int i = 0; i < arr_length; i++) {
        std::cout << "Posicion " << i << ": " << vector[i] << std::endl;
    }
}
