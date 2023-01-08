//
// Created by Вера Орехова on 29.12.2022.
//
#include <iostream>
#include <algorithm>


//1) Напишите функцию swap, которая меняет значения переданных аргументов
//Например, после вызова swap(a, b) в переменной a должно оказаться значение b, а в переменной b значение a
//
void task1_swap(int* a1, int* b1)
{
    int tmp = *a1;
    *a1 = *b1;
    *b1 = tmp;
}

void task1()
{
    int a = 7;
    int b = 11;
    std::cout << "a = " << a << std::endl;
    std::cout <<"b = " << b << std::endl;
    task1_swap(&a, &b);
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
}
//2) Дано число n. Требуется создать массив a из n целых чисел и указатели на первый pa и последний pla элементы этого массива.
// Нужно поменять с их помощью первый и последний элементы массива местами и вывести получившийся массив.
//
void task2()
{
    setlocale(LC_ALL, "Rus");
    int sizeOfArray;
    std::cout<<"Введите длину массива: "<<std::endl;
    std::cin>>sizeOfArray;

    int *arr = new int[sizeOfArray];  //выделеям память для массива
    for (int i = 0; i < sizeOfArray; i++)
    {
        arr[i] = rand()%100;   //заполняем пустой массив случайными числами(целыми)
    }

    //выводим исходный массив
    std::cout<<"Исходный массив чисел: "<<std::endl;
    for (int i = 0; i < sizeOfArray; i++)
    {
        std::cout<<arr[i]<<" ";
    }

    std::cout<<std::endl;

    int *pa = &arr[0];  //указатель первого эллемента
    int *pla = &arr[sizeOfArray - 1];  //указатель последнего элемента массива

    int temporary_value = *pa;
    *pa = *pla;
    *pla = temporary_value;

    // выводим полученный массив:
    std::cout<<"Полученный массив после перестановок: "<<std::endl;
    for (int i = 0; i < sizeOfArray; i++)
    {
        std::cout<<arr[i]<<" ";
    }
}

//4) Ввести массив, состоящий из 12 элементов действительного типа.
// Расположить элементы в порядке убывания.
// Определить количество происшедших при этом перестановок.
//
void task4()
{
    setlocale(LC_ALL, "Rus");
    double A[12];

    std::cout << "Введите 12 n" << std::endl;

    for (int i = 0; i < 12; ++i) // Вводим элементы массива
    {
        std::cout << "A[" << i << "]=";
        std::cin >> A[i];
    }

    int count = 0;
    for (int i = 0; i < 12; ++i) // Сортируем список, располагая элементы в порядке убывания
    {
        for (int j = 12 - 1; j > i; --j)
        {
            if (A[j] > A[j - 1])
            {
                double d = A[j - 1];
                A[j - 1] = A[j];
                A[j] = d;

                ++count;   // если элементы меняем местами, то инкрементируем count
            }
        }
    }

    std::cout << "\n\n";

    for (int k = 0; k < 12; k++) // Вывод отсортированного массива
        std::cout << A[k] << " ";
    std::cout << "\n\n" << count;
}

//3) Дан указатель: double **p = 0; Выполните следующие задания (решения можно оформлять внутри функции main):
//* создайте конструкцию, изображенную на рисунке;
//* выведите число, указанное в квадратике, на экран;
//* после этого удалите все динамические объекты.
//
void task3()
{
    double* p1 = new double(2); // Создаем указатель на ячейку с цифрой 2 (на рисунке средний кружок)
    double** p = &p1; // Создаем указатель на указатель (на рисунке левый кружок)
    std::cout << **p << "\n\n"; // Получаем значение из указателя на указатель (на рисунке квадратик справа с цифрой 2)
    delete *p; // Удаляем указатель на ячейку с цифрой 2

    task4(); // Вызываем функцию, в которой представлен код для третьей задачи
}


//5) Переписать элементы одномерного массива в другой массив такого же размера следующим образом: сначала должны идти все отрицательные элементы исходного массива, а затем все остальные.
// Использовать только один проход по исходному массиву.
// Сохранить тот порядок среди положительных и среди отрицательных элементов в результирующем массиве, который был в исходном массиве.
// Применить данный алгоритм к трем заданным массивам.
//
void task5 ()
{
    const int n = 7;  // фиксированный размер массива = 7
    int* arr = new int[n];
    int* result = new int[n];
    int* tmp_neg = new int[n];
    int* tmp_pos = new int[n];
    int count1 = 0;
    int count2 = 0;
    std::cout << "Enter the elements of array: " << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << "arr[" << i << "] = ";
        std::cin >> arr[i];

    }
    for (int i = 0; i < n; i++) {  // сначала берём все отрицательные элементы исходного массива
        if (arr[i] < 0) {
            tmp_neg[count1] = arr[i];
            count1++;
        }
        else {
            tmp_pos[count2] = arr[i];  // если элемент неотрицательный, записываем в другой массив
            count2++;
        }
    }
    for (int i = 0; i < count1; i++) {  // в результирующий массив сначала запишем отрицательные элементы
        result[i] = tmp_neg[i];
    }
    for (int i = 0; i < count2; i++) {  // затем все остальные
        result[count1+i] = tmp_pos[i];
    }
    for (int i = 0; i < n; i++)
    {
        std::cout  << result[i] << " ";  // вывод полученного массива

    }
}

//6) Ввести массив, состоящий из 14 элементов действительного типа.
// Поменять местами первую половину со второй.
// Определить количество произведенных при этом перестановок.
//
void task6()
{
    srand(unsigned(time(NULL))); //функция, благодаря которой при запуске каждый раз выпадают случайные числа

    const int ARRLEN = 14, MID = ARRLEN / 2; //ARRLEN - количество элементов массива, MID - середина массива
    float* s = new float[ARRLEN];
    int moves = 0;

    for (float* i = s; i != s + ARRLEN; i++)
    {
        *i = rand() % 99 + 1; // мнимый рандомайзер числа
        std :: cout << *i << " " << std :: endl ;
    }
    std::cout <<  std :: endl;
    for (float* i = s; i != s + MID; i++)
    {
        int tmp = *i; // меняем первую половину массива со второй
        *i = *(i + MID);
        *(i + MID) = tmp;
        moves += 3; //определение количества произведенных перестановок
    }
    std::cout << std::endl;
    for (float* i = s; i != s + ARRLEN; i++)
    {
        std :: cout << *i << "  ";
    }
    std::cout << std::endl <<"Number of permutations : " << moves << std::endl;

    delete[] s;
}

//7) Определить количество локальных минимумов в заданном числовом массиве.
// (Локальный минимум в числовом массиве – это последовательность трех рядом стоящих чисел,
// в которой среднее число меньше стоящих слева и справа от него).
//
void task7()
{
    srand(unsigned(time(NULL)));//функция, благодаря которой при запуске каждый раз выпадают случайные числа

    const int ARRLEN = 10;
    int* s = new int[ARRLEN];
    int count = 0;
    for (int* i = s; i != s + ARRLEN; i++)
    {
        *i = rand() % 99 + 1; // мнимый рандомайзер
        std :: cout << *i << ' ';
    }
    std :: cout << std :: endl;
    for (int i = 0; i < ARRLEN; i++)
    {
        if (i == 0 && s[i] < s[i + 1]) count++;  // проверяем, является ли число локальным минимумом
        else if (i > 0 && i < ARRLEN - 1 && s[i] < s[i - 1] && s[i] < s[i + 1]) count++;
        else if (i == ARRLEN - 1 && s[i] < s[i - 1]) count++;
    }
    std::cout << "Local mins: " << count << std::endl;

    delete[] s;
}

//8) Дана матрица. Известно, что в каждой строке этой матрицы присутствуют два и только два нулевых элемента.
// Для каждой строки матрицы подсчитать сумму элементов, заключенных между этими двумя нулями.
// Применить функцию, рассматривающую строки матрицы как одномерные массивы.
//
void task8_help(int* s, int COLLEN)
{

    bool zero_found = false;
    int sum = 0;
    for (int i = 0; i < COLLEN; i++)
    {

        if (s[i] != 0 && zero_found) // если между нулями, прибавляем в сумму значение элемента
            sum += s[i];
        else if (s[i] == 0 && !zero_found) // если нашли ноль
            zero_found = true;
        else if (s[i] == 0 && zero_found)
        {
            std::cout << sum << std::endl;
            break;
        }
    }
}

void task8()
{
    srand(unsigned(time(NULL)));

    const int ROWLEN = 5, COLLEN = 4;
    int** s = new int* [ROWLEN];
    for (int i = 0; i < 5; i++)
        s[i] = new int[COLLEN];

    for (int i = 0; i < ROWLEN; i++)  // вводим элементы двухмерного массива
    {
        for (int j = 0; j < COLLEN; j++)
            std::cin >> s[i][j];
        task8_help(s[i], COLLEN);
    }

    for (int i = 0; i < ROWLEN; i++)
    {
        delete[] s[i];
    }
    delete[] s;
}

//9) Ввести массив, состоящий из 15 элементов целого типа.
// Упорядочить массив так, чтобы все отрицательные числа были расположены вначале по возрастанию,
// а все положительные – в конце по убыванию.
//
void task9()
{
    srand(unsigned(time(NULL)));

    int* s = new int[15];
    for (int* i = s; i != s + 15; i++) //ввод значений элементов массива
        std::cin >> *i;

    std::sort(s, s + 15);

    int start_index = 0;
    for (int i = 0; i < 15; i++)
        if (s[i] > 0) // если элементы положительные
        {
            start_index = i;
            break;
        }

    sort(s + start_index, s + 15, std::greater<>());

    for (int* i = s; i != s + 15; i++)
        std::cout << *i << " ";

    delete[] s;
}

//10) Ввести два массива действительных чисел. Определить максимальные
//элементы в каждом массиве и поменять их местами.
//
void task10()
{
    srand(unsigned(time(NULL)));

    const int ARRLEN = 10, ARRLEN1 = 5;
    int* s = new int[ARRLEN];
    int* s1 = new int[ARRLEN1];

    for (int* i = s; i != s + ARRLEN; i++)
    {
        *i = rand() % 99 + 1;
        std::cout << *i << ' ';
    }
    std::cout << std::endl;
    for (int* i = s1; i != s1 + ARRLEN1; i++)
    {
        *i = rand() % 99 + 1;
        std::cout << *i << ' ';
    }
    std::cout << std::endl;
    std::cout << std::endl;

    int* max_p = std::max_element(s, s + ARRLEN); // находим максимальные элементы
    int max = *max_p;
    int* max_p1 = std::max_element(s1, s1 + ARRLEN1);
    *max_p = *max_p1;
    *max_p1 = max;  // поменяли максимальные элементы местами

    // вывод получившихся массивов
    for (int* i = s; i != s + ARRLEN; i++)
        std::cout << *i << ' ';
    std::cout << std::endl;
    for (int* i = s1; i != s1 + ARRLEN1; i++)
        std::cout << *i << ' ';

    delete[] s;
    delete[] s1;


}

//11) Сдвинуть циклически столбцы матрицы на один столбец вправо.
//
void task11()
{
    srand(unsigned(time(NULL)));

    const int ROWLEN = 3, COLLEN = 5; // работаем с константными значениями столбцов и строк

    int** s = new int* [ROWLEN];
    int** s_sdvig = new int* [ROWLEN];

    for (int** i = s, **k = s_sdvig; i < s + ROWLEN; i++, k++)
    {
        *i = new int[COLLEN];
        *k = new int[COLLEN];
    }


    for (int** i = s; i < s + ROWLEN; i++)
    {
        for (int* j = *i; j < *i + COLLEN; j++)
        {
            *j = rand() % 99 + 1; // рандомно генерируем новый элемент и выводим его
            std::cout << *j << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;

    for (int** i = s, **k = s_sdvig; i < s + ROWLEN; i++, k++)
    {
        **k = *(*i + COLLEN - 1);
        std::cout << **k << " ";
        for (int* j = *i, *m = *k + 1; m < *k + COLLEN; j++, m++)
        {
            *m = *j; // осуществляем сдвиг
            std::cout << *m << " "; // выводим получившиеся значения
        }
        std::cout << std::endl;
    }


    for (int i = 0; i < ROWLEN; i++)
    {
        delete[] s[i];
        delete[] s_sdvig[i];
    }
    delete[] s;
    delete[] s_sdvig;


}

//12) В матрице найти строки с максимальной и минимальной суммами элементов.
//
void task12()
{
    srand(unsigned(time(NULL)));

    const int ROWLEN = 3, COLLEN = 5;

    int** s = new int* [ROWLEN];
    int max = INT32_MIN; //ограничения целочисленных типов
    int min = INT32_MAX;
    int* max_addr = *s, * min_addr = *s;

    for (int** i = s; i < s + ROWLEN; i++)
        *i = new int[COLLEN];


    for (int** i = s; i < s + ROWLEN; i++)
    {
        int sum = 0; // изначальную сумму принимаем за 0
        for (int* j = *i; j < *i + COLLEN; j++)
        {
            *j = rand() % 99 + 1;
            sum += *j; // считаем сумму элементов
            std::cout << *j << " ";
        }

        if (sum > max) // если получившаяся сумма больше максимальной, обновляем максимум
        {
            max = sum;
            max_addr = *i;
        }
        if (sum < min) // аналогично с минимумом
        {
            min = sum;
            min_addr = *i;
        }
        std::cout << std::endl;
    }

    std::cout << std::endl << "Row with max sum of elements:" << std::endl;
    for (int* i = max_addr; i < max_addr + COLLEN; i++)
        std::cout << *i << " ";
    std::cout << std::endl;
    std::cout << "Row with min sum of elements:" << std::endl;
    for (int* i = min_addr; i < min_addr + COLLEN; i++)
        std::cout << *i << " ";

    for (int i = 0; i < ROWLEN; i++)
    {
        delete[] s[i];
    }
    delete[] s;
}