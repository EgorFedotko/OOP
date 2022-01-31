// OOP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#define TEN 10

using namespace std;

//////////////////////////////////////////////////////////// Switch ///////////////////////////////////////////////////////

void s_switch()
{
    int a;
    double b, c;
    cout <<"Vvedite  Chislo  B" <<endl;
    cin >> b;
    cout << "Vvedite  Chislo  C" << endl;
    cin >> c;
    cout << "Select operation on numbers\t " <<b <<"\tand\t"<<c<< endl;
    cout << "1-Sum" << endl;
    cout << "2-Difference " << endl;
    cout << "3-Multiplication  " << endl;
    cout << "4-division  " << endl;
    cin >> a;

    

    switch (a)
    {
    case 1:
        cout << "B+C=" << b + c << endl;
        break;
    case 2:
        cout << "B-C=" << b - c << endl;
        break;
    case 3:
        cout << "B*C=" << b * c << endl;
        break;
    case 4:
        cout << "B-C=" << b - c << endl;
        break;


        

    default:
        throw exception("Error");
        break;
    }
}

//////////////////////////////////////////////////////////// Ромбовидное Наследование///////////////////////////////////////////////////////

class A
{
public:
    A()
    {
        cout << "Constructor A" << endl;
       
       
    }

    
};
class B:  public virtual  A
{
public:
    B() 
    {
        cout << "Constructor B" << endl;
    }
private:

};
class C : public virtual A
{
public:
    C()
    {
        cout << " Constructor C" << endl;
    }
private:

};

class W:public B,public C
{
public:
   W()
    {
       cout << " Constructor W" << endl;
    }

    
        
    
};

//////////////////////////////////////////////////////////// Реализация Инкапсуляции///////////////////////////////////////////////////////

class Auto
{
public:
    void Start()
    {
        bool Networ_kpower_supply = Voltage();

        if (Networ_kpower_supply)
        {
            cout << "Auto Start" << endl;
        }
        else
        {
            cout << "Check Voltag" << endl;
        }
    }
private:
    bool Voltage()// Пользователь не может регулировать напряжение в автомобиле
    {
        return false; 
    }
};

//////////////////////////////////////////////////////////// Реализация Полиморфизма///////////////////////////////////////////////////////

class Car
{
public:
    virtual void drive() = 0;
};
class Sports_car :public Car
{
public:
    void drive() override
    {
        cout << "Drive fast !!!" << endl;

    }
};
class Fire_engine :public Car
{
public:
    void drive() override
    {
        cout << "Ride slowly !!!" << endl;

    }
};
class Driver
{
public:
    void drive(Car* car)
    {
        car->drive();
    }

    


};

//////////////////////////////////////////////////////////// Использование Рекурсии////////////////////////////////////////////////////////

//Факториал начало 

int Factorial(int value)
{
    if (value == 1)
    {
        return 1;
    }
    if (value == 0)
    {
        return 0;
    }
    
    return  value * Factorial(value - 1);
}

//Факториал конец
//
//Числа Фибоначи начало

int Fibonachi(int value)
{
    if (value == 0)
    {
        return 0;
    }
    if (value == 1)
    {
        return 1;
    }
    return Fibonachi(value - 1) + Fibonachi(value - 2);
}

//Числа Фибоначи конец

//////////////////////////////////////////////////////////// Реализаци Композиции  и Агрегации///////////////////////////////////////////////////////

class Cap
{
public:
    string GetColor()
    {
        return color;
    }

private:
    string color = "Red";
};
class Model
{
public:
    void InsperkModel()
    {
        cout << "Моя кепка " << cap.GetColor() << " цвета" << endl;
    }

private:
    Cap cap;
};
class Human
{
public:
    void Think()
    {
        brain.Think();
    }
    void CapInspect()
    {
        cout<< "Моя кепка "<< cap.GetColor()<<" цвета "<< endl;
    }


private:
    class Brain
    {
    public:
        void Think()

        {
            cout<< "Я Думаю !!!!!"<< endl;
        }



    };

    Brain brain;
    Cap cap;
};

//////////////////////////////////////////////////////////// Перечисляемый тип enum ////////////////////////////////////////

class PC
{
public:
    enum PCState
    {
        OFF,
        ON,
        SLEEP
    };
    PCState GetState()
    {
        return State;
    }
    void SetState(PCState State)
    {
        this->State = State;
    }


private:
    PCState State;
};

enum SPEED {
    min = 150
};



int main()
{
    setlocale(LC_ALL, "Rus");

    //////////// Вызов   s_switch и try catch --- start 
    try
    {
        s_switch();

    }
    catch (const exception & ex)
    {
        cout << "exception " <<ex.what()<< endl;
    }
    //////////// Вызов   s_switch и try catch --- end

    //цикл foreach ---start
    int arr[] = { 3,5,2,6,26,26,26 };
    for (int var : arr)
    {
        cout << var << endl;
    }
    //цикл foreach --- end
   
        
    /////////////////////Рекурсия start
    //Факториал начало
    auto show=Factorial(TEN);
    cout << show << endl;
    //Факториал конец

     //Числа Фибоначи начало
    for (int i = 0; i < TEN; i++)
    {
        cout<<Fibonachi(i) << endl;

    }
    //Числа Фибоначи конец

    /////////////////////Рекурсия end

    /// Ромбовидное наследование --- start
    W();
    /// Ромбовидное наследование --- end



    //////  Инкапсуляция start
    Auto c;
    //////  Инкапсуляция end
  

   
////////////////Композиции  и Агрегации --- start
Human human;
human.Think();
human.CapInspect();
Model model;
model.InsperkModel();
////////////////Композиции  и Агрегации --- end
   


    
   ////////////// Полиморфизм --- start
   
    // Fire_engine firecar;
    Sports_car sport;
    Driver   driver;
    driver.drive(&sport);
    ////////////// Полиморфизм --- end

  ////////////// enum --- start
    PC pc;
    pc.SetState(PC::PCState::ON);
    //
    
    //
    switch (pc.GetState())
    {
    case PC::PCState::OFF:
        cout << "Выключен!" << endl;
        break;
    case PC::PCState::ON:
        cout << "Включен!" << endl;
        break;
    case PC::PCState::SLEEP:
        cout << "Спящий режим!" << endl;
        break;
    }
    ////////////// enum --- end



}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
