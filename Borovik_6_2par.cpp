/* Borovik_6_1par.cpp : Даны два массива: А[M] и B[N] (M и N вводятся с клавиатуры). 
Необходимо создать третий массив минимально возможного размера, 
в котором нужно собрать элементы массивов A и B, которые не являются общими для них, без повторений.
*/
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    int M{ 0 };
    int N{ 0 };
    cout << "Введите размер первого массива: ";
    cin >> M;
    cout << endl << "Введите размер второго массива: ";
    cin >> N;

    int* A = new int[M];// выделение динамической памяти под массив А получается (int A[M]{});
    int* B = new int[N];

    int* pA = A;
    int* pB = B;

    //заполняем массив А через цикл for
    for (int i = 0; i < M; i++) {
        pA[i] = rand() % 10;
    }
    //выводим массив А на экран через цикл for
    for (int i = 0; i < M; i++) {
        cout << *(pA + i) << " ";
    }
    cout << endl;
    //заполняем массив B через цикл for
    for (int i = 0; i < N; i++) {
        B[i] = rand() % 10;
    }
    //выводим массив B на экран через цикл for
    for (int i = 0; i < N; i++) {
        cout << B[i] << " ";
    }
    cout << endl;
    int size_C = M + N;
    int* C = new int[size_C] {0};
    int count = 0;
    for (int i = 0; i < M; i++) {
        //проходимся по первому массиву
        bool isAlreadyInC = false;// уже находиться в массиве С = ложь
        int x = A[i]; 
        for (int j = 0; j < count; j++) {
            if (C[j] == x) {
                isAlreadyInC = true; // если находиться в массиве, принимает значение = правда и выходит из этого цикла
                break;
            }
        }
        if (!isAlreadyInC) {// соответственно при выходе из цикла 
            C[count] = x; //записывает значение в массив
            count++; // прибавляет к счётчику 1
        }
    }
    for (int i = 0; i < N; i++) { // проходимся по второму массиву
        bool isAlreadyInC = false; // уже находиться в массиве С = ложь
        int x = B[i];
        for (int j = 0; j < count; j++) { // счётчик начинается с последнего приплюсованного значения
            if (C[j] == x) {
                isAlreadyInC = true; // если находиться в массиве, принимает значение = правда и выходит из этого цикла
                break;
            }
        }
        if (!isAlreadyInC) { // соответственно при выходе из цикла 
            C[count] = x; // записывает значение в массив (под номером счётчика)
            count++; // увеличивает значение счётчика на 1
        }
    }
    cout << "Третий массив: " << endl;
    for (int i = 0; i < count; i++) {
        cout << C[i] << " ";
    }
    cout << endl;

    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}
