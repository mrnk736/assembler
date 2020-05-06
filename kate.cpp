#include <iostream>
#include <random>
#include <ctime>

using namespace std;
extern "C"{

	int newArray[5];

	const int size = 5;

	int array[size][size];
	};
 
int main()
{
	srand(time(0));
	
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			array[i][j] = 0 + rand() % 10;
			cout << array[i][j] << " ";
		}
	cout << endl;
	}

	__asm
	 (
     	R"(
       		.intel_syntax noprefix
    ;//{
		mov esi, 0				;// этот регистр будет хранить адрес элементов одномерного массива	
		mov ecx, 0				;// этот регистр будет указывать адрес элементов двумерного массива
		mov dl, 0				;// этот регистр будет считать количество пройденных строк

			StartNewLine:
		mov dh, 0				;// этот регистр считает количетсво пройденных элементов массива
		mov ebx, 0	            ;// сюда будем класть макс элемент

			Main:
		mov eax, array[ecx]	    ;// здесь будет лежать текущий (проверяемый) элемент	
		cmp eax, ebx
		jg MaxElement

		jmp Incrementing

			MaxElement:
		mov ebx, eax
		jmp Incrementing

			Incrementing:
		add ecx, 4
		add dh, 1

			CheckEndLine:
		cmp dh, 5
		jl Main

		mov newArray[esi], ebx
		add esi, 4

			CheckEndArray:
		add dl, 1
		cmp dl, 5
		jl StartNewLine
	;//}
        .att_syntax
    )"
    );


	cout << "_________" << endl;
	for (int i = 0; i < size; ++i)
	{
		cout << newArray[i] << " ";
	}

	return 0;
}
