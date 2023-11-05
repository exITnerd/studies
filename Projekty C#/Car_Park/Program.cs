using System;
class Car
{
    public bool IsRunning { get; private set; }
    public bool IsTankFull { get; protected set; }
    public string? FuelType { get; protected set; }
    public string? CarType { get; protected set; }

    public void Start()
    {
        if (IsRunning)
        {
            Console.WriteLine("The car is already started.");
        }
        else
        {
            IsRunning = true;
            Console.WriteLine("Starting the car...");
        }
    }

    public void Stop()
    {
        if (IsRunning)
        {
            IsRunning = false;
            Console.WriteLine("Turning the engine off...");
        }
        else
        {
            Console.WriteLine("The engine is already turned off.");
        }
    }

    public void FillTank()
    {
        if (IsTankFull)
        {
            Console.WriteLine($"The tank is already full with {FuelType}.");
        }
        else
        {
            IsTankFull = true;
            Console.WriteLine($"Filling the tank with {FuelType}...");
        }
    }

    public void Drive()
    {
        if (!IsRunning)
        {
            Console.WriteLine("The car is not running.");
        }
        else if (!IsTankFull)
        {
            Console.WriteLine($"No {FuelType}. Fill it up!.");
        }
        else
        {
            Console.WriteLine($"Driving on {FuelType}...");
            IsTankFull= false;
        }
    }

    public void TestDrive()
    {
        Console.WriteLine($"\n|--- Testing the {CarType} ---|");
        FillTank();
        FillTank();
        Drive();
        Start();
        Start();
        Drive();
        Drive();
        Stop();
        Stop();
    }
}

class GasolineCar : Car
{
    public GasolineCar()
    {
        FuelType = "gasoline";
        CarType = "Gasoline Car";
    }
}

class NaturalGasCar : Car
{
    public NaturalGasCar()
    {
        FuelType = "natural gas";
        CarType = "Natural Gas Car";
    }
}

class ElectricCar : Car
{
    public ElectricCar()
    {
        FuelType = "electricity";
        CarType = "Electric Car";
    }
}

class Program
{
    static void Main()
    {
        List<Car> cars = new List<Car>
        {
            new GasolineCar(),
            new NaturalGasCar(),
            new ElectricCar()
        };

        foreach (var car in cars)
        {
            car.TestDrive();
        }
    }
}
