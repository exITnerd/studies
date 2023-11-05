using Car_Park_Interfaces;
using System;
using System.Collections.Specialized;

namespace Car_Park_Interfaces
{
    interface ICar
    {
        void Start();
        void Stop();
        void Drive();
        void Refuel();
    }

    interface IGasolineCar
    {
        bool InternalCombustionEngine { get; set; }
        bool GasolineTank { get; set; }
        void Start();
        void Stop();
        void DriveOnGasoline();
        void RefuelGasoline();
    }

    interface INaturalGasCar
    {
        bool InternalCombustionEngine { get; set; }
        bool NaturalGasTank { get; set; }
        void Start();
        void Stop();
        void DriveOnNaturalGas();
        void RefuelNaturalGas();
    }

    interface IElectricCar
    {
        bool ElectricEngine { get; set; }
        bool Battery { get; set; }
        void Start();
        void Stop();
        void DriveOnElectricity();
        void ChargeBattery();
    }

    class Program
    {
        public static void TestDrive(ICar car) 
        {
            car.Refuel();
            car.Refuel();
            car.Drive();
            car.Start();
            car.Start();
            car.Drive();
            car.Drive();
            car.Stop();
            car.Stop();
        }
        static void Main()
        {
            GasolineCar gasolineCar = new GasolineCar();
            Console.WriteLine("-----------Gasoline Car----------");
            TestDrive(gasolineCar);
            Console.WriteLine();

            NaturalGasCar naturalGasCar = new NaturalGasCar();
            Console.WriteLine("-----------Natural Gas Car----------");
            TestDrive(naturalGasCar);
            Console.WriteLine();

            ElectricCar electricCar = new ElectricCar();
            Console.WriteLine("-----------Electric Car----------");
            TestDrive(electricCar);
            Console.WriteLine();

            GasolineNaturalGasCar gasolineNaturalGasCar = new GasolineNaturalGasCar();
            Console.WriteLine("-----------Gasoline Natural Gas Car----------");
            TestDrive(gasolineNaturalGasCar);
            Console.WriteLine();

            GasolineElectricCar gasolineElectricCar = new GasolineElectricCar();
            Console.WriteLine("-----------Gasoline Electric Car----------");
            TestDrive(gasolineElectricCar);
            Console.WriteLine();
        }
    }
}